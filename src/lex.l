%{
#include <token.h>
%}

letter [a-zA-Z]
num [0-9]
ident {letter}+({letter}|{num})*
integer {num}+

%%

"array" {}
"break" {}
"do" {}
"else" {}
"end" {}
"for" {}
"function" {}
"if" {}
"in" {}
"let" {}
"nil" {}
"of" {}
"then" {}
"to" {}
"type" {}
"var" {}
"while" {}
"," {}
":" {}
";" {}
"(" {}
")" {}
"[" {}
"]" {}
"{" {}
"}" {}
"." {}
"+" {}
"-" {}
"*" {}
"/" {}
"=" {}
"<>" {}
"<" {}
"<=" {}
">" {}
">=" {}
"&" {}
"|" {}
":=" {}
{ident} {}
{integer} {}

%%
