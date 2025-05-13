%{
#include <stdio.h>
#include <stdlib.h>
#include <err.h>
#include <tigerdef.h>
#include <stuff.h>
#include <lex.h>
#include <stxtree.h>

void yyerror(const char* msg)
{
    errmsg(msg);
    exit(ERR_YACC);
}
%}

%union {
    char* sym;
    int ival;
    char* sval;
    struct stxnode* astnode;
    int tokentype;   
}

%token YYEOF
%token <tokentype> TK_ARRAY TK_NIL TK_INT TK_STR
%token <tokentype> TK_VAR TK_TYPE TK_LET TK_END TK_FUNCTION TK_IN TK_OF
%token <tokentype> TK_IF TK_THEN TK_ELSE TK_BREAK TK_DO TK_WHILE TK_FOR TK_TO 
%token <tokentype> TK_COMMA TK_COLON TK_SEMICOLON 
%token <tokentype> TK_LPAREN TK_RPAREN TK_LBRACKET TK_RBRACKET TK_LBRACE TK_RBRACE TK_DOT
%token <tokentype> TK_PLUS TK_MINUS TK_MULTI TK_DIV 
%token <tokentype> TK_EQU TK_NEQU TK_LT TK_LEQU TK_GT TK_GEQU TK_AND TK_OR 
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

%type <astnode> expr
%type <astnode> exprsfx
%type <astnode> binoper 
%type <astnode> primaryexpr
%type <astnode> lvalue
%type <astnode> exprlist
%type <astnode> exprlistsfx
%type <astnode> exprseq
%type <astnode> exprseqsfx
%type <astnode> fieldlistsfx
%type <astnode> indexlist
%type <astnode> declist
%type <astnode> typefields
%type <astnode> typefieldsfx
%type <astnode> typeid


%%

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
        $$ = NULL;
    }
    ;

primaryexpr: TK_STRING  { $$ = stxtree_create_string_node($<sval>1); }
    | TK_INTEGER { $$ = stxtree_create_integer_node($<ival>1); }
    | TK_NIL { $$ = stxtree_create_nil_node(); }
    | lvalue
    | TK_MINUS expr %prec UMINUS { 
        stxnode_t* msnode = stxtree_create_unary_minus_node();
        stxtree_append_node(msnode, $2);
    }
    | lvalue TK_ASSIGN expr {
        stxnode_t* assnode = stxtree_create_assign_node();
        stxtree_append_node(assnode, $1);
        stxtree_append_node(assnode, $3);
    }
    | TK_IDENT TK_LPAREN exprlist TK_RPAREN {

    }
    | TK_LPAREN exprseq TK_RPAREN
    | TK_IDENT TK_LBRACE fieldlist TK_RBRACE
    | TK_IDENT TK_LBRACKET expr TK_RBRACKET TK_OF expr
    | TK_IF expr TK_THEN expr
    | TK_IF expr TK_THEN expr TK_ELSE expr
    | TK_WHILE expr TK_DO expr
    | TK_FOR TK_IDENT TK_ASSIGN expr TK_TO expr TK_DO expr
    | TK_BREAK { $$ = stxtree_create_break_node(); }
    | TK_LET declist TK_IN exprseq TK_END
    ;


exprseq: expr exprseqsfx
    | /* epsilon */ { $$ = NULL; }
    ;

exprseqsfx: TK_SEMICOLON expr exprseqsfx
    | /* epsilon */ { $$ = NULL; }
    ;

exprlist: expr exprlistsfx
    | /* epsilon */ { $$ = NULL; }
    ;

exprlistsfx: TK_COMMA expr exprlistsfx
    | /* epsilon */ { $$ = NULL; }
    ;

fieldlist: TK_IDENT TK_EQU expr fieldlistsfx
    ;

fieldlistsfx: TK_COMMA TK_IDENT TK_EQU expr fieldlistsfx
    | /* epsilon */ {  $$ = NULL; }
    ;

lvalue: TK_IDENT indexlist
    ;

indexlist: index indexlist
    | /* epsilon */ {  $$ = NULL; }
    ;

index: TK_DOT TK_IDENT 
    | TK_LBRACKET expr TK_RBRACKET
    ;

declist: dec declist
    | /* epsilon */ { $$ = NULL; }
    ;

dec: typedec
    | vardec
    | funcdec
    ;

typedec: TK_TYPE typeid TK_EQU typeval
    ;

typeval: typeid
    | TK_LBRACE typefields TK_RBRACE
    | TK_ARRAY TK_OF typeid
    ;

typeid: TK_IDENT { $$ = stxtree_create_ident_node($<sym>1); }
    | TK_INT {}
    | TK_STR {}
    ;

vardec: TK_VAR TK_IDENT TK_ASSIGN expr
    | TK_VAR TK_IDENT TK_COLON typeid TK_ASSIGN expr
    ;

funcdec: TK_FUNCTION TK_IDENT TK_LPAREN typefields TK_RPAREN TK_COLON typeid TK_EQU expr
    | TK_FUNCTION TK_IDENT TK_LPAREN typefields TK_RPAREN TK_EQU expr
    ;

typefields: typefield typefieldsfx
    | /* epsilon */ { $$ = NULL; }
    ;

typefieldsfx: TK_COMMA typefield typefieldsfx
    | /* epsilon */ { $$ = NULL; }
    ;

typefield: TK_IDENT TK_COLON typeid
    ;

binoper: TK_PLUS { $$ = stxtree_create_binoper_node($<tokentype>1); }
    | TK_MULTI { $$ = stxtree_create_binoper_node($<tokentype>1); }
    | TK_MINUS { $$ = stxtree_create_binoper_node($<tokentype>1); }
    | TK_DIV { $$ = stxtree_create_binoper_node($<tokentype>1); }
    | TK_EQU { $$ = stxtree_create_binoper_node($<tokentype>1); }
    | TK_NEQU { $$ = stxtree_create_binoper_node($<tokentype>1); }
    | TK_LT { $$ = stxtree_create_binoper_node($<tokentype>1); }
    | TK_GT { $$ = stxtree_create_binoper_node($<tokentype>1); }
    | TK_LEQU { $$ = stxtree_create_binoper_node($<tokentype>1); }
    | TK_GEQU { $$ = stxtree_create_binoper_node($<tokentype>1); }
    | TK_AND { $$ = stxtree_create_binoper_node($<tokentype>1); }
    | TK_OR { $$ = stxtree_create_binoper_node($<tokentype>1); }
    ;

%%
