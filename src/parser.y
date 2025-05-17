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

%locations
%define parse.error detailed
%define parse.trace

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

%type <ast> stmt
%type <ast> expr
%type <ast> lvalue
%type <ast> exprlist
%type <ast> exprseq
%type <ast> fieldlist
%type <ast> declist
%type <ast> typefields
%type <ast> typeid
%type <ast> type
%type <ast> typedec
%type <ast> dec
%type <ast> vardec
%type <ast> funcdec
%type <ast> typefield
%type <ast> valexpr
%type <ast> logicoper
%type <ast> mathoper
%type <ast> index


%nonassoc TK_AND TK_OR
%nonassoc TK_EQU TK_NEQU TK_GT TK_GEQU TK_LT TK_LEQU
%left TK_MINUS TK_PLUS
%left TK_MULTI TK_DIV
%nonassoc UMINUS

%%

stmt: expr {
    $$ = $1;
}

entersc: /* epsilon */ { scope_create(); };
leavesc: /* epsilon */ { scope_close(); };

expr: valexpr {}
    | expr mathoper expr {}
    | expr logicoper expr {}
    | lvalue { $$ = $1; }
    | TK_MINUS expr %prec UMINUS { }
    | lvalue TK_ASSIGN expr { }
    | TK_IDENT TK_LPAREN exprlist TK_RPAREN {}
    | TK_LPAREN exprseq TK_RPAREN { }
    | TK_IDENT TK_LBRACE fieldlist TK_RBRACE { }
    | TK_IDENT TK_LBRACKET expr TK_RBRACKET TK_OF expr {}
    | TK_IF entersc expr TK_THEN expr leavesc {}
    | TK_IF entersc expr TK_THEN expr TK_ELSE expr leavesc {}
    | TK_WHILE entersc expr TK_DO expr leavesc {}
    | TK_FOR entersc TK_IDENT TK_ASSIGN expr TK_TO expr TK_DO expr leavesc {}
    | TK_BREAK { }
    | TK_LET entersc declist TK_IN exprseq TK_END leavesc {}
    ;

valexpr: TK_STRING {}
  | TK_INTEGER {}
  | TK_NIL {}
  ;

exprseq: expr {}
  | exprseq TK_SEMICOLON expr {}
  | /* epsilon */ {}
  ;

exprlist: expr {} 
  | exprlist TK_COMMA expr {}
  | /* epsilon */ {}
  ;

fieldlist: TK_IDENT TK_EQU expr {}
  | fieldlist TK_COMMA TK_IDENT TK_EQU expr {}
  | /* epsilon */ {}
  ;

lvalue: TK_IDENT index {} 
  ;

index: TK_DOT TK_IDENT index {}
  | TK_LBRACKET expr TK_RBRACKET index {}
  | /* epsilon */ {}
  ;

declist: dec {}
  | declist dec {}
  ;

dec: typedec { $$ = $1; }
    | vardec { $$ = $1; }
    | funcdec { $$ = $1; }
    ;

typedec: TK_TYPE typeid TK_EQU type {}
    ;

type: typeid { $$ = $1; }
    | TK_LBRACE typefields TK_RBRACE {}
    | TK_ARRAY TK_OF typeid {}
    ;

typeid: TK_IDENT { }
    | TK_INT { }
    | TK_STR { }
    ;

vardec: TK_VAR TK_IDENT TK_ASSIGN expr {}
    | TK_VAR TK_IDENT TK_COLON typeid TK_ASSIGN expr {}
    ;

funcdec: TK_FUNCTION entersc TK_IDENT TK_LPAREN typefields TK_RPAREN TK_COLON typeid TK_EQU expr leavesc {}
    | TK_FUNCTION entersc TK_IDENT TK_LPAREN typefields TK_RPAREN TK_EQU expr leavesc {}
    ;

typefields: typefield {}
  | typefields TK_COMMA typefield {}
  | /* epsilon */ {}
  ;

typefield: TK_IDENT TK_COLON typeid {};

mathoper: TK_PLUS { }
    | TK_MULTI { }
    | TK_MINUS { }
    | TK_DIV { }
    ;

logicoper: TK_EQU { }
    | TK_NEQU { }
    | TK_LT { }
    | TK_GT { }
    | TK_LEQU { }
    | TK_GEQU { }
    | TK_AND { }
    | TK_OR { }
    ;

%%
