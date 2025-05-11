%{
#include <token.h>
%}

%token YYEOF
%token TK_IDENT TK_INTEGER TK_STRING
%token TK_ARRAY TK_NIL
%token TK_VAR TK_TYPE TK_LET TK_END TK_FUNCTION TK_IN TK_OF
%token TK_IF TK_THEN TK_ELSE TK_BREAK TK_DO TK_WHILE TK_FOR TK_TO 
%token TK_COMMA TK_COLON TK_SEMICOLON 
%token TK_LPAREN TK_RPAREN TK_LBRACKET TK_RBRACKET TK_LBRACE TK_RBRACE TK_DOT
%token TK_PLUS TK_MINUS TK_MULTI TK_DIV 
%token TK_EQU TK_NEQU TK_LT TK_LEQU TK_GT TK_GEQU TK_AND TK_OR 
%token TK_ASSIGN


%%

stmt: expr stmtsfx
    ;

stmtsfx: binoper expr stmtsfx
    | /* epsilon */
    ;


expr : TK_STRING
    | TK_INTEGER
    | TK_NIL
    | lvalue
    | TK_MINUS expr
    | lvalue TK_ASSIGN expr
    | TK_IDENT TK_LPAREN exprlist TK_RPAREN
    | TK_LPAREN exprseq TK_RPAREN
    | TK_IDENT TK_LBRACE fieldlist TK_RBRACE
    | TK_IDENT TK_LBRACKET expr TK_OF expr
    | TK_IF expr TK_THEN expr
    | TK_IF expr TK_THEN expr TK_ELSE expr
    | TK_WHILE expr TK_DO expr
    | TK_FOR TK_IDENT TK_ASSIGN TK_TO expr TK_DO expr
    | TK_BREAK
    | TK_LET declist TK_IN exprseq TK_END
    ;


exprseq: expr exprseq-suffix
    ;

exprseq-suffix: TK_SEMICOLON expr exprseq-suffix
    | /* epsilon */
    ;

exprlist: expr exprlist-suffix
    ;

exprlist-suffix: TK_COMMA expr exprlist-suffix
    | /* epsilon */
    ;

fieldlist: TK_IDENT TK_EQU expr fieldlist-suffix
    ;

fieldlist-suffix: TK_COMMA TK_IDENT TK_EQU expr fieldlist-suffix
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

typefields: typefield typefields-suffix
    ;

typefields-suffix: TK_COMMA typefield typefields-suffix
    | /* epsilon */
    ;

typefield: TK_IDENT TK_COLON TK_IDENT
    ;

vardec: TK_VAR TK_IDENT TK_ASSIGN expr
    | TK_VAR TK_IDENT TK_COLON TK_IDENT TK_ASSIGN expr
    ;

funcdec: TK_FUNCTION TK_IDENT TK_LPAREN typefields TK_RPAREN TK_EQU expr
    | TK_FUNCTION TK_IDENT TK_LPAREN typefields TK_RPAREN TK_COLON TK_IDENT TK_EQU expr
    ;

binoper: TK_PLUS
    | TK_MINUS
    | TK_MULTI
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
