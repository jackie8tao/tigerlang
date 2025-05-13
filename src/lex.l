%{
#include <parser.h>
#include <tigerdef.h>
#include <string.h>
#include <stdio.h>
#include <symtable.h>
#include <stdlib.h>
#include <stxtree.h>

char tiger_str[MAX_STR_SIZE];
int tiger_str_leng;

static void tiger_str_reset() 
{
    for (int i=0; i<MAX_STR_SIZE; i++) 
    {
        tiger_str[i] = '\0';
    }
}

static void tiger_str_append(const char* src, int length)
{
    int cur_len = (int)strlen(tiger_str);
    if (cur_len+ length > MAX_STR_SIZE) 
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

ident [[:alpha:]]+([[:alpha:]]|[[:digit:]]|_)*
integer [[:digit:]]+
ws  [[:space:]]+
comment (\/\*).*(\*\/)
newline [\n|\r|\r\n]

%x STR

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
{ws} {;}
{newline} { yylineno++; }
{integer} { 
    yylval.ival = atoi(yytext); 
    yylval.tokentype = TK_INTEGER; 
    return TK_INTEGER; 
    }
{comment} {;}
array { yylval.tokentype = TK_ARRAY; return TK_ARRAY; }
break { yylval.tokentype = TK_BREAK; return TK_BREAK; }
do { yylval.tokentype = TK_DO; return TK_DO; }
else { yylval.tokentype = TK_ELSE; return TK_ELSE; }
end { yylval.tokentype = TK_END; return TK_END; }
for { yylval.tokentype = TK_FOR; return TK_FOR; }
function { yylval.tokentype = TK_FUNCTION; return TK_FUNCTION; }
if { yylval.tokentype = TK_IF; return TK_IF; }
in { yylval.tokentype = TK_IN; return TK_IN; }
let { yylval.tokentype = TK_LET; return TK_LET; }
nil { yylval.tokentype = TK_NIL; return TK_NIL; }
of { yylval.tokentype = TK_OF; return TK_OF; }
then { yylval.tokentype = TK_THEN; return TK_THEN; }
to { yylval.tokentype = TK_DO; return TK_TO; }
type { yylval.tokentype = TK_TYPE; return TK_TYPE; }
var { yylval.tokentype = TK_VAR; return TK_VAR; }
while { yylval.tokentype = TK_WHILE; return TK_WHILE; }
str { yylval.tokentype = TK_STR; return TK_STR; }
int { yylval.tokentype = TK_INT; return TK_INT; }
, { yylval.tokentype = TK_COMMA; return TK_COMMA; }
:= { yylval.tokentype = TK_ASSIGN; return TK_ASSIGN; }
: { yylval.tokentype = TK_COLON; return TK_COLON; }
; { yylval.tokentype = TK_SEMICOLON; return TK_SEMICOLON; }
\( { yylval.tokentype = TK_LPAREN; return TK_LPAREN; }
\) { yylval.tokentype = TK_RPAREN; return TK_RPAREN; }
\[ { yylval.tokentype = TK_LBRACKET; return TK_LBRACKET; }
\] { yylval.tokentype = TK_RBRACKET; return TK_RBRACKET; }
\{ { yylval.tokentype = TK_LBRACE; return TK_LBRACE; }
\} { yylval.tokentype = TK_RBRACE; return TK_RBRACE; }
\. { yylval.tokentype = TK_DOT; return TK_DOT; }
\+ { yylval.tokentype = TK_PLUS; return TK_PLUS; }
\- { yylval.tokentype = TK_MINUS; return TK_MINUS; }
\* { yylval.tokentype = TK_MULTI; return TK_MULTI; }
\/ { yylval.tokentype = TK_DIV; return TK_DIV; }
= { yylval.tokentype = TK_EQU; return TK_EQU; }
\<\> { yylval.tokentype = TK_NEQU; return TK_NEQU; }
\< { yylval.tokentype = TK_LT; return TK_LT; }
\<= { yylval.tokentype = TK_LEQU; return TK_LEQU; }
\> { yylval.tokentype = TK_GT; return TK_GT; }
\>= { yylval.tokentype = TK_GEQU; return TK_GEQU; }
& { yylval.tokentype = TK_AND; return TK_AND; }
'|' { yylval.tokentype = TK_OR; return TK_OR; }
{ident} {
    sym_entry_t* entry = (sym_entry_t*)malloc(sizeof(sym_entry_t));
    entry->type = TK_IDENT;
    entry->token = strdup(yytext);
    entry->lineno = yylineno;
    sym_table_append(entry);

    yylval.sym = strdup(yytext);
    yylval.tokentype = TK_IDENT;

    return TK_IDENT; 
    }

%%

int yywrap() 
{
    return 1;
}