%{
#include <stdio.h>
#include <stdlib.h>
#include <err.h>
#include <tigerdef.h>
#include <stuff.h>
#include <lex.h>
#include <stxtree.h>
#include <scope.h>
#include <symdict.h>

void yyerror(const char* msg)
{
    errmsg(msg);
    exit(ERR_YACC);
}
%}

%union {
    int ival;
    char* sval;
    struct stxnode* ast;
    struct symval* sym;
}

%token YYEOF
%token TK_ARRAY TK_NIL TK_INT TK_STR
%token TK_VAR TK_TYPE TK_LET TK_END TK_FUNCTION TK_IN TK_OF
%token TK_IF TK_THEN TK_ELSE TK_BREAK TK_DO TK_WHILE TK_FOR TK_TO 
%token TK_COMMA TK_COLON TK_SEMICOLON 
%token TK_LPAREN TK_RPAREN TK_LBRACKET TK_RBRACKET TK_LBRACE TK_RBRACE TK_DOT
%token TK_PLUS TK_MINUS TK_MULTI TK_DIV 
%token TK_EQU TK_NEQU TK_LT TK_LEQU TK_GT TK_GEQU TK_AND TK_OR 
%token TK_ASSIGN

%token <sym> TK_IDENT
%token <ival> TK_INTEGER
%token <sval> TK_STRING

%precedence TK_THEN
%precedence TK_ELSE

%define parse.error detailed
%define parse.trace

%nonassoc TK_AND TK_OR
%nonassoc TK_EQU TK_NEQU TK_GT TK_GEQU TK_LT TK_LEQU
%left TK_MULTI TK_DIV TK_MINUS TK_PLUS
%right UMINUS
%precedence PREFER

%type <ast> expr
%type <ast> exprsfx
%type <ast> binoper 
%type <ast> primaryexpr
%type <ast> lvalue
%type <ast> exprlist
%type <ast> exprlistsfx
%type <ast> exprseq
%type <ast> exprseqsfx
%type <ast> fieldlistsfx
%type <ast> indexlist
%type <ast> declist
%type <ast> typefields
%type <ast> typefieldsfx
%type <ast> typeid
%type <ast> fieldlist
%type <ast> typeval
%type <ast> typedec
%type <ast> dec
%type <ast> index
%type <ast> vardec
%type <ast> funcdec
%type <ast> typefield
%type <ast> stmt;


%%

stmt: expr {
    $$ = $1;
    stxtree_t* gtree = stxtree_get();
    gtree->root = $$;
}

entersc: /* epsilon */ { scope_create(); };
leavesc: /* epsilon */ { scope_close(); };

expr: primaryexpr exprsfx {
    stxtree_append_node($1, $2);
    $$ = $1;
};

exprsfx: binoper expr { 
    stxnode_t* opnode = $1;
    stxtree_append_node(opnode, $2);
    $$ = opnode;
 }
    | /* epsilon */ {
        $$ = stxtree_create_node(YYEMPTY);
    }
    ;

primaryexpr: TK_STRING  { $$ = stxtree_create_string_node($1); }
    | TK_INTEGER { $$ = stxtree_create_integer_node($1); }
    | TK_NIL { $$ = stxtree_create_node(TK_NIL); }
    | lvalue {
        $$ = $1;
    }
    | TK_MINUS expr %prec UMINUS { 
        stxnode_t* msnode = stxtree_create_node(TK_MINUS);
        stxtree_append_node(msnode, $2);
        $$ = msnode;
    }
    | lvalue TK_ASSIGN expr {
        stxnode_t* assnode = stxtree_create_node(TK_ASSIGN);
        stxtree_append_node(assnode, $1);
        stxtree_append_node(assnode, $3);
        $$ = assnode;
    }
    | TK_IDENT TK_LPAREN exprlist TK_RPAREN {
        stxnode_t* idnode = stxtree_create_ident_node($1->txt);
        scope_t* sc = scope_current();
        idnode->sc = sc;
        stxnode_t* lparen = stxtree_create_node(TK_LPAREN);
        stxnode_t* rparen = stxtree_create_node(TK_RPAREN);
        stxtree_append_node(idnode, lparen);
        stxtree_append_node(idnode, $3);
        stxtree_append_node(idnode, rparen);
        $$ = idnode;
    }
    | TK_LPAREN exprseq TK_RPAREN {
        $$ = $2; // 这里有点问题
    }
    | TK_IDENT TK_LBRACE fieldlist TK_RBRACE {
        stxnode_t* idnode = stxtree_create_ident_node($1->txt);
        scope_t* sc = scope_current();
        scope_add_sym(sc, $1);
        idnode->sc = sc;
        stxnode_t* lbrace = stxtree_create_node(TK_LBRACE);
        stxnode_t* rbrace = stxtree_create_node(TK_RBRACE);
        stxtree_append_node(idnode, lbrace);
        stxtree_append_node(idnode, $3);
        stxtree_append_node(idnode, rbrace);
        $$ = idnode;
    }
    | TK_IDENT TK_LBRACKET expr TK_RBRACKET TK_OF expr {
        stxnode_t* idnode = stxtree_create_ident_node($1->txt);
        scope_t* sc = scope_current();
        scope_add_sym(sc, $1);
        idnode->sc = sc;
        stxnode_t* lbracket = stxtree_create_node(TK_LBRACKET);
        stxnode_t* rbracket = stxtree_create_node(TK_RBRACKET);
        stxnode_t* ofnode = stxtree_create_node(TK_OF);
        stxtree_append_node(idnode, lbracket);
        stxtree_append_node(idnode, $3);
        stxtree_append_node(idnode, rbracket);
        stxtree_append_node(idnode, ofnode);
        stxtree_append_node(idnode, $6);
        $$ = idnode;
    }
    | TK_IF entersc expr TK_THEN expr leavesc {
        stxnode_t* ifnode = stxtree_create_node(TK_IF);
        stxnode_t* thnode = stxtree_create_node(TK_THEN);
        stxtree_append_node(thnode, $5);
        stxtree_append_node(ifnode, $3);
        stxtree_append_node(ifnode, thnode);
        $$ = ifnode;
    }
    | TK_IF entersc expr TK_THEN expr TK_ELSE expr leavesc {
        stxnode_t* ifnode = stxtree_create_node(TK_IF);
        stxnode_t* thnode = stxtree_create_node(TK_THEN);
        stxnode_t* elnode = stxtree_create_node(TK_ELSE);
        stxtree_append_node(elnode, $7);
        stxtree_append_node(thnode, $5);
        stxtree_append_node(ifnode, $3);
        stxtree_append_node(ifnode, thnode);
        stxtree_append_node(ifnode, elnode);
        $$ = ifnode;
    }
    | TK_WHILE entersc expr TK_DO expr leavesc {
        stxnode_t* whnode = stxtree_create_node(TK_WHILE);
        stxnode_t* donode = stxtree_create_node(TK_DO);
        stxtree_append_node(whnode, $3);
        stxtree_append_node(donode, $5);
        stxtree_append_node(whnode, donode);
        $$ = whnode;
    }
    | TK_FOR entersc TK_IDENT TK_ASSIGN expr TK_TO expr TK_DO expr leavesc {
        stxnode_t* fornode = stxtree_create_node(TK_FOR);
        stxnode_t* assnode = stxtree_create_node(TK_ASSIGN);
        stxnode_t* idnode = stxtree_create_ident_node($3->txt);
        scope_t* cur_sc = scope_current();
        scope_add_sym(cur_sc, $3);
        idnode->sc = scope_current();
        stxnode_t* tonode = stxtree_create_node(TK_TO);
        stxtree_append_node(tonode, $5);
        stxtree_append_node(tonode, $7);
        stxtree_append_node(assnode, idnode);
        stxtree_append_node(assnode, tonode);
        stxnode_t* donode = stxtree_create_node(TK_DO);
        stxtree_append_node(donode, $9);
        stxtree_append_node(fornode, assnode);
        stxtree_append_node(fornode, donode);
        $$ = fornode;
    }
    | TK_BREAK { $$ = stxtree_create_node(TK_BREAK); }
    | TK_LET entersc declist TK_IN exprseq TK_END leavesc {
        stxnode_t* letnode = stxtree_create_node(TK_LET);
        stxnode_t* innode = stxtree_create_node(TK_IN);
        stxnode_t* endnode = stxtree_create_node(TK_END);
        stxtree_append_node(letnode, $3);
        stxtree_append_node(letnode, innode);
        stxtree_append_node(letnode, $5);
        stxtree_append_node(letnode, endnode);
        $$ = letnode;
    }
    ;


exprseq: expr exprseqsfx {
    stxtree_append_node($1, $2);
    $$ = $1;
}
    | /* epsilon */ { $$ = stxtree_create_node(YYEMPTY); }
    ;

exprseqsfx: TK_SEMICOLON expr exprseqsfx {
    stxnode_t* scnode = stxtree_create_node(TK_SEMICOLON);
    stxtree_append_node($2, $3);
    stxtree_append_node(scnode, $2);
    $$ = scnode;
}
    | /* epsilon */ { $$ = stxtree_create_node(YYEMPTY); }
    ;

exprlist: expr exprlistsfx {
    stxtree_append_node($1, $2);
    $$ = $1;
}
    | /* epsilon */ { $$ = stxtree_create_node(YYEMPTY); }
    ;

exprlistsfx: TK_COMMA expr exprlistsfx {
    stxnode_t* cmnode = stxtree_create_node(TK_COMMA);
    stxtree_append_node($2, $3);
    stxtree_append_node(cmnode, $2);
    $$ = cmnode;
}
    | /* epsilon */ { $$ = stxtree_create_node(YYEMPTY); }
    ;

fieldlist: TK_IDENT TK_EQU expr fieldlistsfx {
    stxtree_append_node($3, $4);
    stxnode_t* equnode = stxtree_create_node(TK_EQU);
    stxnode_t* idnode = stxtree_create_ident_node($1->txt);
    scope_t* sc = scope_current();
    scope_add_sym(sc, $1);
    idnode->sc = sc;
    stxtree_append_node(equnode, idnode);
    stxtree_append_node(equnode, $3);
    $$ = equnode;
}
    ;

fieldlistsfx: TK_COMMA TK_IDENT TK_EQU expr fieldlistsfx {
    stxnode_t* cmnode = stxtree_create_node(TK_COMMA);
    stxnode_t* idnode = stxtree_create_ident_node($2->txt);
    stxnode_t* equnode = stxtree_create_node(TK_EQU);
    scope_t* sc = scope_current();
    scope_add_sym(sc, $2);
    idnode->sc = sc;
    stxtree_append_node($4, $5);
    stxtree_append_node(equnode, idnode);
    stxtree_append_node(equnode, $4);
    stxtree_append_node(cmnode, equnode);
    $$ = cmnode;
}
    | /* epsilon */ {  $$ = stxtree_create_node(YYEMPTY); }
    ;

lvalue: TK_IDENT indexlist {
    stxnode_t* idnode = stxtree_create_ident_node($1->txt);
    scope_t* sc = scope_current();
    scope_add_sym(sc, $1);
    idnode->sc = sc;
    stxtree_append_node(idnode, $2);
    $$ = idnode;
}
    ;

indexlist: index indexlist {
    stxtree_append_node($1, $2);
    $$ = $1;
}
    | /* epsilon */ {  $$ = stxtree_create_node(YYEMPTY); }
    ;

index: TK_DOT TK_IDENT {
    stxnode_t* dotnode = stxtree_create_node(TK_DOT);
    stxnode_t* idnode = stxtree_create_ident_node($2->txt);
    scope_t* sc = scope_current();
    scope_add_sym(sc, $2);
    idnode->sc = sc;
    stxtree_append_node(dotnode, idnode);
    $$ = dotnode;
}
    | TK_LBRACKET expr TK_RBRACKET {
        stxnode_t* lbracket = stxtree_create_node(TK_LBRACKET);
        stxtree_append_node(lbracket, $2);
        $$ = lbracket;
    }
    ;

declist: dec declist {
    stxtree_append_node($1, $2);
    $$ = $1;
}
    | /* epsilon */ { $$ = stxtree_create_node(YYEMPTY); }
    ;

dec: typedec { $$ = $1; }
    | vardec { $$ = $1; }
    | funcdec { $$ = $1; }
    ;

typedec: TK_TYPE typeid TK_EQU typeval {
    stxnode_t* typenode = stxtree_create_node(TK_TYPE);
    stxnode_t* equnode = stxtree_create_node(TK_EQU);
    stxtree_append_node(equnode, $4);
    stxtree_append_node(equnode, $2);
    stxtree_append_node(typenode, equnode);
    $$ = typenode;
}
    ;

typeval: typeid { $$ = $1; }
    | TK_LBRACE typefields TK_RBRACE {
        stxnode_t* lbrace = stxtree_create_node(TK_LBRACE);
        stxtree_append_node(lbrace, $2);
        $$ = lbrace;
    }
    | TK_ARRAY TK_OF typeid {
        stxnode_t* arraynode = stxtree_create_node(TK_ARRAY);
        stxnode_t* ofnode = stxtree_create_node(TK_OF);
        stxtree_append_node(ofnode, $3);
        stxtree_append_node(arraynode, ofnode);
        $$ = arraynode;
    }
    ;

typeid: TK_IDENT { 
  stxnode_t* idnode = stxtree_create_ident_node($1->txt); 
  scope_t* sc = scope_current();
  scope_add_sym(sc, $1);
  idnode->sc = sc;
}
    | TK_INT { $$ = stxtree_create_node(TK_INT); }
    | TK_STR { $$ = stxtree_create_node(TK_STR); }
    ;

vardec: TK_VAR TK_IDENT TK_ASSIGN expr {
    stxnode_t* varnode = stxtree_create_node(TK_VAR);
    stxnode_t* idnode = stxtree_create_ident_node($2->txt);
    scope_t* sc = scope_current();
    scope_add_sym(sc, $2);
    idnode->sc = sc;
    stxnode_t* assnode = stxtree_create_node(TK_ASSIGN);
    stxtree_append_node(assnode, idnode);
    stxtree_append_node(assnode, $4);
    stxtree_append_node(varnode, assnode);
    $$ = varnode;
}
    | TK_VAR TK_IDENT TK_COLON typeid TK_ASSIGN expr {
        stxnode_t* varnode = stxtree_create_node(TK_VAR);
        stxnode_t* idnode = stxtree_create_ident_node($2->txt);
        scope_t* sc = scope_current();
        scope_add_sym(sc, $2);
        idnode->sc = sc;
        stxnode_t* assnode = stxtree_create_node(TK_ASSIGN);
        stxtree_append_node(idnode, $4);
        stxtree_append_node(assnode, idnode);
        stxtree_append_node(assnode, $6);
        stxtree_append_node(varnode, assnode);
        $$ = varnode;
    }
    ;

funcdec: TK_FUNCTION entersc TK_IDENT TK_LPAREN typefields TK_RPAREN TK_COLON typeid TK_EQU expr leavesc {
    stxnode_t* fnnode = stxtree_create_node(TK_FUNCTION);
    stxnode_t* idnode = stxtree_create_ident_node($3->txt);
    scope_t* sc = scope_current();
    scope_add_sym(sc, $3);
    idnode->sc = sc;
    stxnode_t* lparen = stxtree_create_node(TK_LPAREN);
    stxnode_t* rparen = stxtree_create_node(TK_RPAREN);
    stxnode_t* clnode = stxtree_create_node(TK_COLON);
    stxnode_t* equnode = stxtree_create_node(TK_EQU);
    stxtree_append_node(clnode, $8);
    stxtree_append_node(equnode, $10);
    stxtree_append_node(fnnode, idnode);
    stxtree_append_node(fnnode, lparen);
    stxtree_append_node(fnnode, $5);
    stxtree_append_node(fnnode, rparen);
    stxtree_append_node(fnnode, clnode);
    stxtree_append_node(fnnode, equnode);
    $$ = fnnode;
}
    | TK_FUNCTION entersc TK_IDENT TK_LPAREN typefields TK_RPAREN TK_EQU expr leavesc {
        stxnode_t* fnnode = stxtree_create_node(TK_FUNCTION);
        stxnode_t* idnode = stxtree_create_ident_node($3->txt);
        scope_t* sc = scope_current();
        scope_add_sym(sc, $3);
        idnode->sc = sc;
        stxnode_t* lparen = stxtree_create_node(TK_LPAREN);
        stxnode_t* rparen = stxtree_create_node(TK_RPAREN);
        stxnode_t* equnode = stxtree_create_node(TK_EQU);
        stxtree_append_node(equnode, $8);
        stxtree_append_node(fnnode, idnode);
        stxtree_append_node(fnnode, lparen);
        stxtree_append_node(fnnode, $5);
        stxtree_append_node(fnnode, rparen);
        stxtree_append_node(fnnode, equnode);
        $$ = fnnode;
    }
    ;

typefields: typefield typefieldsfx {
    stxtree_append_node($1, $2);
    $$ = $1;
}
    | /* epsilon */ { $$ = stxtree_create_node(YYEMPTY); }
    ;

typefieldsfx: TK_COMMA typefield typefieldsfx {
    stxnode_t* cmnode = stxtree_create_node(TK_COMMA);
    stxtree_append_node($2, $3);
    stxtree_append_node(cmnode, $2);
    $$ = cmnode;
}
    | /* epsilon */ { $$ = stxtree_create_node(YYEMPTY); }
    ;

typefield: TK_IDENT TK_COLON typeid {
    stxnode_t* idnode = stxtree_create_ident_node($1->txt);
    scope_t* sc = scope_current();
    scope_add_sym(sc, $1);
    idnode->sc = sc;
    stxnode_t* clnode = stxtree_create_node(TK_COLON);
    stxtree_append_node(clnode, $3);
    stxtree_append_node(idnode, clnode);
    $$ = idnode;
}
    ;

binoper: TK_PLUS { $$ = stxtree_create_node(TK_PLUS); }
    | TK_MULTI { $$ = stxtree_create_node(TK_MULTI); }
    | TK_MINUS { $$ = stxtree_create_node(TK_MINUS); }
    | TK_DIV { $$ = stxtree_create_node(TK_DIV); }
    | TK_EQU { $$ = stxtree_create_node(TK_EQU); }
    | TK_NEQU { $$ = stxtree_create_node(TK_NEQU); }
    | TK_LT { $$ = stxtree_create_node(TK_LT); }
    | TK_GT { $$ = stxtree_create_node(TK_GT); }
    | TK_LEQU { $$ = stxtree_create_node(TK_LEQU); }
    | TK_GEQU { $$ = stxtree_create_node(TK_GEQU); }
    | TK_AND { $$ = stxtree_create_node(TK_AND); }
    | TK_OR { $$ = stxtree_create_node(TK_OR); }
    ;

%%
