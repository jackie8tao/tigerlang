%{
#include <token.h>
%}

letter [a-zA-Z]
num [0-9]
ident {letter}+({letter}|{num}|_)*
integer {num}+
ws  (\s)+
string ^\".*\"$

%%

{ws} {;}
"\r\n" {;}
"array" { return TK_ARRAY; }
"break" { return TK_BREAK; }
"do" { return TK_DO; }
"else" { return TK_ELSE; }
"end" { return TK_END; }
"for" { return TK_FOR; }
"function" { return TK_FUNCTION; }
"if" { return TK_IF; }
"in" { return TK_IN; }
"let" { return TK_LET; }
"nil" { return TK_NIL; }
"of" { return TK_OF; }
"then" { return TK_THEN; }
"to" { return TK_TO; }
"type" { return TK_TYPE; }
"var" { return TK_VAR; }
"while" { return TK_WHILE; }
"," { return TK_COMMA; }
":" { return TK_COLON; }
";" { return TK_SEMICOLON; }
"(" { return TK_LPAREN; }
")" { return TK_RPAREN; }
"[" { return TK_LBRACKET; }
"]" { return TK_RBRACKET; }
"{" { return TK_LBRACE; }
"}" { return TK_RBRACE; }
"." { return TK_DOT; }
"+" { return TK_PLUS; }
"-" { return TK_MINUS; }
"*" { return TK_MULTI; }
"/" { return TK_DIV; }
"=" { return TK_EQU; }
"<>" { return TK_NEQU; }
"<" { return TK_LT; }
"<=" { return TK_LEQU; }
">" { return TK_GT; }
">=" { return TK_GEQU; }
"&" { return TK_AND; }
"|" { return TK_OR; }
":=" { return TK_ASSIGN; }
{ident} { return TK_IDENT; }
{integer} { return TK_INTEGER; }
{string} {return TK_STRING; }

%%

int yywrap() {
    return 1;
}