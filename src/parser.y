%{
#include <stdio.h>
#include <stdlib.h>
#include <err.h>
#include <tigerdef.h>
#include <stuff.h>
#include <lex.h>
#include <ast.h>
#include <scope.h>
#include <symdict.h>

void yyerror(const char* msg)
{
    errmsg("row: %d, col: %d, msg: %s", yylloc.first_line, yylloc.first_column, msg);
    exit(ERR_YACC);
}
%}

%locations
%define parse.error detailed
%define parse.trace

%union {
    int ival;
    char* sval;
    struct ast_node* ast;
    struct tokeninfo* sym;
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

%type <ast> stmt
%type <ast> expr
%type <ast> lvalue
%type <ast> exprlist
%type <ast> exprseq
%type <ast> fieldlist
%type <ast> declist
%type <ast> typefields
%type <ast> typeid
%type <ast> typedec
%type <ast> dec
%type <ast> vardec
%type <ast> funcdec
%type <ast> index


%left TK_AND TK_OR
%left TK_EQU TK_NEQU TK_GT TK_GEQU TK_LT TK_LEQU
%left TK_MINUS TK_PLUS
%left TK_MULTI TK_DIV
%nonassoc UMINUS

%%

stmt: expr {
    $$ = $1;
}

entersc: /* epsilon */ { scope_create(); };
leavesc: /* epsilon */ { scope_close(); };

expr: TK_STRING { $$ = ast_create_string($1); }
    | TK_INTEGER { $$ = ast_create_int($1); }
    | TK_NIL { $$ = ast_create_nil(); }
    | expr TK_PLUS expr { $$ = ast_create_binory(TK_PLUS, $1, $3); }
    | expr TK_MINUS expr { $$ = ast_create_binory(TK_MINUS, $1, $3); }
    | expr TK_MULTI expr { $$ = ast_create_binory(TK_MULTI, $1, $3); }
    | expr TK_DIV expr { $$ = ast_create_binory(TK_DIV, $1, $3); }
    | expr TK_EQU expr { $$ = ast_create_binory(TK_EQU, $1, $3); }
    | expr TK_NEQU expr { $$ = ast_create_binory(TK_NEQU, $1, $3); }
    | expr TK_GT expr { $$ = ast_create_binory(TK_GT, $1, $3); }
    | expr TK_GEQU expr { $$ = ast_create_binory(TK_GEQU, $1, $3); }
    | expr TK_LEQU expr { $$ = ast_create_binory(TK_LEQU, $1, $3); }
    | expr TK_LT expr { $$ = ast_create_binory(TK_LT, $1, $3); }
    | expr TK_AND expr { $$ = ast_create_binory(TK_AND, $1, $3); }
    | expr TK_OR expr { $$ = ast_create_binory(TK_OR, $1, $3); }
    | lvalue { $$ = $1; }
    | TK_MINUS expr %prec UMINUS { $$ = ast_create_unary(TK_MINUS, $2); }
    | lvalue TK_ASSIGN expr { $$ = ast_create_assign($1, $3); }
    | TK_IDENT TK_LPAREN exprlist TK_RPAREN { 
        ast_node_t* ident = ast_create_ident($1->txt, scope_current(), yylloc.first_line, yylloc.first_column);
        $$ = ast_create_fncall(ident, $3); 
      }
    | TK_LPAREN exprseq TK_RPAREN { $$ = $2; }
    | TK_IDENT TK_LBRACE fieldlist TK_RBRACE { 
        ast_node_t* ident = ast_create_ident(strdup($1->txt), scope_current(), yylloc.first_line, yylloc.first_column);
        $$ = ast_create_struct(ident, $3); 
      }
    | TK_IDENT TK_LBRACKET expr TK_RBRACKET TK_OF expr { 
        ast_node_t* ident = ast_create_ident(strdup($1->txt), scope_current(), yylloc.first_line, yylloc.first_column);
        $$ = ast_create_arrinit(ident, $3, $6); 
      }
    | TK_IF entersc expr TK_THEN expr leavesc { $$ = ast_create_if($3, $5, NULL); }
    | TK_IF entersc expr TK_THEN expr TK_ELSE expr leavesc { $$ = ast_create_if($3, $5, $7); }
    | TK_WHILE entersc expr TK_DO expr leavesc { $$ = ast_create_while($3, $5); }
    | TK_FOR entersc TK_IDENT TK_ASSIGN expr TK_TO expr TK_DO expr leavesc { 
        ast_node_t* ident = ast_create_ident(strdup($3->txt), scope_current(), yylloc.first_line, yylloc.first_column);
        $$ = ast_create_for(ident, $5, $7, $9); 
      }
    | TK_BREAK { $$ = ast_create_break(); }
    | TK_LET entersc declist TK_IN exprseq TK_END leavesc { $$ = ast_create_let($3, $5); }
    ;

exprseq: expr { 
    ast_node_t* exprseq = ast_create_exprseq();
    ast_append_exprseq(exprseq, $1);
    $$ = exprseq;
   }
  | exprseq TK_SEMICOLON expr {
    ast_append_exprseq($1, $3);
    $$ = $1;
  }
  | /* epsilon */ { $$ = NULL; }
  ;

exprlist: expr { 
    ast_node_t* exprlist = ast_create_exprlist();
    ast_append_exprlist(exprlist, $1);
    $$ = exprlist;
    } 
  | exprlist TK_COMMA expr {
    ast_append_exprlist($1, $3);
    $$ = $1;
  }
  | /* epsilon */ { $$ = NULL; }
  ;

fieldlist: TK_IDENT TK_EQU expr {
      ast_node_t* fieldef = ast_create_fieldef(strdup($1->txt), $3);
      ast_node_t* fieldlist = ast_create_fieldlist();
      ast_append_fieldlist(fieldlist, fieldef);
      $$ = fieldlist;
    }
  | fieldlist TK_COMMA TK_IDENT TK_EQU expr {
    ast_node_t* fieldef = ast_create_fieldef(strdup($3->txt), $5);
    ast_append_fieldlist($1, fieldef);
    $$ = $1;
  }
  | /* epsilon */ { $$ = NULL; }
  ;

lvalue: TK_IDENT index {
    ast_node_t* ident = ast_create_ident(strdup($1->txt), scope_current(), yylloc.first_line, yylloc.first_column);
    $$ = ast_create_lvalue(ident, $2);
  } 
  ;

index: TK_DOT TK_IDENT index {
      ast_node_t* ident = ast_create_ident(strdup($2->txt), scope_current(), yylloc.first_line, yylloc.first_column);
      ast_node_t* ident_index = ast_create_ident_index(ident);
      ast_append_index(ident_index, $3);
      $$ = ident_index;
    }
  | TK_LBRACKET expr TK_RBRACKET index {
      ast_node_t* arr_index = ast_create_arr_index($2);
      ast_append_index(arr_index, $4);
      $$ = arr_index;
  }
  | /* epsilon */ { $$ = NULL; }
  ;

declist: dec {
    ast_node_t* declist = ast_create_declist();
    ast_append_declist(declist, $1);
    $$ = declist;
  }
  | declist dec {
    ast_append_declist($1, $2);
    $$ = $1;
  }
  ;

dec: typedec { $$ = $1; }
    | vardec { $$ = $1; }
    | funcdec { $$ = $1; }
    ;

typedec: TK_TYPE TK_IDENT TK_EQU typeid {
      ast_node_t* ident = ast_create_ident(strdup($2->txt), scope_current(), yylloc.first_line, yylloc.first_column);
      ast_node_t* typedec = ast_create_typedec(AstIdentTypeDec, ident, $4);
      $$ = typedec;
    } 
    | TK_TYPE TK_IDENT TK_EQU TK_LBRACE typefields TK_RBRACE {
      ast_node_t* ident = ast_create_ident(strdup($2->txt), scope_current(), yylloc.first_line, yylloc.first_column);
      ast_node_t* typedec = ast_create_typedec(AstStTypeDec, ident, $5);
      $$ = typedec;
    } 
    | TK_TYPE TK_IDENT TK_EQU TK_ARRAY TK_OF typeid {
      ast_node_t* ident = ast_create_ident(strdup($2->txt), scope_current(), yylloc.first_line, yylloc.first_column);
      ast_node_t* typedec = ast_create_typedec(AstArrTypeDec, ident, $6);
      $$ = typedec;
    }
    ;

typeid: TK_IDENT { 
      ast_node_t* ident = ast_create_ident(strdup($1->txt), scope_current(), yylloc.first_line, yylloc.first_column);
      $$ = ast_create_ident_typeid(ident); 
    }
    | TK_INT { $$ = ast_create_int_typeid(); }
    | TK_STR { $$ = ast_create_str_typeid(); }
    ;

vardec: TK_VAR TK_IDENT TK_ASSIGN expr {
      ast_node_t* ident = ast_create_ident(strdup($2->txt), scope_current(), yylloc.first_line, yylloc.first_column);
      $$ = ast_create_vardec(ident, NULL, $4);
    }
    | TK_VAR TK_IDENT TK_COLON typeid TK_ASSIGN expr {
      ast_node_t* ident = ast_create_ident(strdup($2->txt), scope_current(), yylloc.first_line, yylloc.first_column);
      $$ = ast_create_vardec(ident, $4, $6);
    }
    ;

funcdec: TK_FUNCTION entersc TK_IDENT TK_LPAREN typefields TK_RPAREN TK_COLON typeid TK_EQU expr leavesc {
      ast_node_t* ident = ast_create_ident(strdup($3->txt), scope_current(), yylloc.first_line, yylloc.first_column);
      ast_node_t* fn = ast_create_fndef(ident, $5, $8, $10);
      $$ = fn;
    }
    | TK_FUNCTION entersc TK_IDENT TK_LPAREN typefields TK_RPAREN TK_EQU expr leavesc {
      ast_node_t* ident = ast_create_ident(strdup($3->txt), scope_current(), yylloc.first_line, yylloc.first_column);
      ast_node_t* fn = ast_create_fndef(ident, $5, NULL, $8);
      $$ = fn;
    }
    ;

typefields: TK_IDENT TK_COLON typeid { 
    ast_node_t* ident = ast_create_ident(strdup($1->txt), scope_current(), yylloc.first_line, yylloc.first_column);
    ast_node_t* typefields = ast_create_typefields(ident, $3);
    $$ = typefields;
  }
  | typefields TK_COMMA TK_IDENT TK_COLON typeid {
    ast_node_t* ident = ast_create_ident(strdup($3->txt), scope_current(), yylloc.first_line, yylloc.first_column);
    ast_node_t* typefields = ast_create_typefields(ident, $5);
    ast_append_typefields($1, typefields);
    $$ = $1;
  }
  | /* epsilon */ { $$ = NULL; }
  ;

%%
