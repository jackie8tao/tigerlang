%{
#include <stdio.h>
#include <stdlib.h>
#include <err.h>
#include <tigerdef.h>
#include <stuff.h>
#include <lex.h>

void yyerror(const char* msg)
{
    errmsg(msg);
    exit(ERR_YACC);
}
%}

%token YYEOF
%token TK_ARRAY TK_NIL
%token TK_VAR TK_TYPE TK_LET TK_END TK_FUNCTION TK_IN TK_OF
%token TK_IF TK_THEN TK_ELSE TK_BREAK TK_DO TK_WHILE TK_FOR TK_TO 
%token TK_COMMA TK_COLON TK_SEMICOLON 
%token TK_LPAREN TK_RPAREN TK_LBRACKET TK_RBRACKET TK_LBRACE TK_RBRACE TK_DOT
%token TK_PLUS TK_MINUS TK_MULTI TK_DIV 
%token TK_EQU TK_NEQU TK_LT TK_LEQU TK_GT TK_GEQU TK_AND TK_OR 
%token TK_ASSIGN

%union {
    char* sym;
    int ival;
    char* sval;
}

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

%%

expr: primaryexpr exprsfx
    ;

exprsfx: binoper expr
    | /* epsilon */
    ;

primaryexpr: TK_STRING  {printf("\"%s\"\n", $<sval>1);}
    | TK_INTEGER {printf("%d\n", $<ival>1);}
    | TK_NIL
    | lvalue
    | TK_MINUS expr %prec UMINUS
    | lvalue TK_ASSIGN expr
    | TK_IDENT TK_LPAREN exprlist TK_RPAREN
    | TK_LPAREN exprseq TK_RPAREN
    | TK_IDENT TK_LBRACE fieldlist TK_RBRACE
    | TK_IDENT TK_LBRACKET expr TK_RBRACKET TK_OF expr
    | TK_IF expr TK_THEN expr
    | TK_IF expr TK_THEN expr TK_ELSE expr
    | TK_WHILE expr TK_DO expr
    | TK_FOR TK_IDENT TK_ASSIGN expr TK_TO expr TK_DO expr
    | TK_BREAK
    | TK_LET declist TK_IN exprseq TK_END
    ;


exprseq: expr exprseqsfx
    | /* epsilon */
    ;

exprseqsfx: TK_SEMICOLON expr exprseqsfx
    | /* epsilon */
    ;

exprlist: expr exprlistsfx
    | /* epsilon */
    ;

exprlistsfx: TK_COMMA expr exprlistsfx
    | /* epsilon */
    ;

fieldlist: TK_IDENT TK_EQU expr fieldlistsfx
    ;

fieldlistsfx: TK_COMMA TK_IDENT TK_EQU expr fieldlistsfx
    | /* epsilon */
    ;

lvalue: TK_IDENT indexlist
    ;

indexlist: index indexlist
    | /* epsilon */
    ;

index: TK_DOT TK_IDENT 
    | TK_LBRACKET expr TK_RBRACKET
    ;

declist: dec declist
    | /* epsilon */
    ;

dec: typedec
    | vardec
    | funcdec
    ;

typedec: TK_TYPE TK_IDENT TK_EQU typeval
    ;

typeval: TK_IDENT
    | TK_LBRACE typefields TK_RBRACE
    | TK_ARRAY TK_OF TK_IDENT
    ;

vardec: TK_VAR TK_IDENT TK_ASSIGN expr
    | TK_VAR TK_IDENT TK_COLON TK_IDENT TK_ASSIGN expr
    ;

funcdec: TK_FUNCTION TK_IDENT TK_LPAREN typefields TK_RPAREN TK_COLON TK_IDENT TK_EQU expr
    | TK_FUNCTION TK_IDENT TK_LPAREN typefields TK_RPAREN TK_EQU expr
    ;

typefields: typefield typefieldsfx
    | /* epsilon */
    ;

typefieldsfx: TK_COMMA typefield typefieldsfx
    | /* epsilon */
    ;

typefield: TK_IDENT TK_COLON TK_IDENT
    ;

binoper: TK_PLUS
    | TK_MULTI
    | TK_MINUS
    | TK_DIV
    | TK_EQU
    | TK_NEQU
    | TK_LT
    | TK_GT
    | TK_LEQU
    | TK_GEQU
    | TK_AND
    | TK_OR
    ;

%%
