%{
#include <parser.h>
#include <tigerdef.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stxtree.h>
#include <symdict.h>

static int yycolno = 0;

#define YY_USER_ACTION \
  yylloc.first_line = yylineno; \
  yylloc.first_column = yycolno; \
  yylloc.last_line = yylineno; \
  yylloc.last_column = yycolno + yyleng - 1;


char tiger_str[STRING_MAX_SIZE];
int tiger_str_leng;

static void tiger_str_reset() 
{
    for (int i=0; i<STRING_MAX_SIZE; i++) 
    {
        tiger_str[i] = '\0';
    }
}

static void tiger_str_append(const char* src, int length)
{
    int cur_len = (int)strlen(tiger_str);
    if (cur_len+ length > STRING_MAX_SIZE) 
    {
        perror("tiger string length is too long");
        exit(-1);
    }

    for (int i=0; i<length; i++) 
    {
        tiger_str[cur_len+i] = src[i];
    }
    return;
}
%}

%x STR
%option yylineno

%%

\"  {
    tiger_str_reset();
    tiger_str_leng = 0;
    BEGIN(STR);
}

<STR>\" {
    yyleng = tiger_str_leng;
    yytext = strdup(tiger_str);
    yylval.sval = strdup(tiger_str);
    BEGIN(INITIAL);
    return TK_STRING;
    }

<STR>"\\[n|t|\"|\\]*" {
    tiger_str_append(yytext, yyleng);
    tiger_str_leng += yyleng;
    }

<STR>[^\"]* {
    tiger_str_append(yytext, yyleng);
    tiger_str_leng += yyleng;
    }
[[:blank:]]+ { yycolno += yyleng; }
[\r\n|\n|\r] { yycolno=0; }
[[:digit:]]+ { 
    yylval.ival = atoi(yytext);
    yycolno += yyleng; 
    return TK_INTEGER; 
    }
(\/\*).*(\*\/) {;}
array { yycolno += yyleng; return TK_ARRAY; }
break { yycolno += yyleng; return TK_BREAK; }
do { yycolno += yyleng; return TK_DO; }
else { yycolno += yyleng; return TK_ELSE; }
end { yycolno += yyleng; return TK_END; }
for { yycolno += yyleng; return TK_FOR; }
function { yycolno += yyleng; return TK_FUNCTION; }
if { yycolno += yyleng; return TK_IF; }
in { yycolno += yyleng; return TK_IN; }
let { yycolno += yyleng; return TK_LET; }
nil { yycolno += yyleng; return TK_NIL; }
of { yycolno += yyleng; return TK_OF; }
then { yycolno += yyleng; return TK_THEN; }
to { yycolno += yyleng; return TK_TO; }
type { yycolno += yyleng; return TK_TYPE; }
var { yycolno += yyleng; return TK_VAR; }
while { yycolno += yyleng; return TK_WHILE; }
str { yycolno += yyleng; return TK_STR; }
int { yycolno += yyleng; return TK_INT; }
, { yycolno += yyleng; return TK_COMMA; }
:= { yycolno += yyleng; return TK_ASSIGN; }
: { yycolno += yyleng; return TK_COLON; }
; { yycolno += yyleng; return TK_SEMICOLON; }
\( { yycolno += yyleng; return TK_LPAREN; }
\) { yycolno += yyleng; return TK_RPAREN; }
\[ { yycolno += yyleng; return TK_LBRACKET; }
\] { yycolno += yyleng; return TK_RBRACKET; }
\{ { yycolno += yyleng; return TK_LBRACE; }
\} { yycolno += yyleng; return TK_RBRACE; }
\. { yycolno += yyleng; return TK_DOT; }
\+ { yycolno += yyleng; return TK_PLUS; }
\- { yycolno += yyleng; return TK_MINUS; }
\* { yycolno += yyleng; return TK_MULTI; }
\/ { yycolno += yyleng; return TK_DIV; }
= { yycolno += yyleng; return TK_EQU; }
\<\> { yycolno += yyleng; return TK_NEQU; }
\< { yycolno += yyleng; return TK_LT; }
\<= { yycolno += yyleng; return TK_LEQU; }
\> { yycolno += yyleng; return TK_GT; }
\>= { yycolno += yyleng; return TK_GEQU; }
& { yycolno += yyleng; return TK_AND; }
'|' { yycolno += yyleng; return TK_OR; }
[[:alpha:]]+([[:alpha:]]|[[:digit:]]|_)* {
    char* txt = strdup(yytext);
    yylval.sym = symdict_create_tokeninfo(yylineno, yycolno, txt);
    yycolno += yyleng; 
    return TK_IDENT; 
    }

%%

int yywrap() 
{
    return 1;
}