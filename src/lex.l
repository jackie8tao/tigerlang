%{
#include <token.h>
#include <tigerdef.h>
#include <string.h>
#include <stdio.h>
#include <symtable.h>
#include <stdlib.h>

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
ws  [:space:]+
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
{integer} { return TK_INTEGER; }
{comment} {;}
'array' { return TK_ARRAY; }
'break' { return TK_BREAK; }
'do' { return TK_DO; }
'else' { return TK_ELSE; }
'end' { return TK_END; }
'for' { return TK_FOR; }
'function' { return TK_FUNCTION; }
'if' { return TK_IF; }
'in' { return TK_IN; }
'let' { return TK_LET; }
'nil' { return TK_NIL; }
'of' { return TK_OF; }
'then' { return TK_THEN; }
'to' { return TK_TO; }
'type' { return TK_TYPE; }
'var' { return TK_VAR; }
'while' { return TK_WHILE; }
',' { return TK_COMMA; }
':' { return TK_COLON; }
';' { return TK_SEMICOLON; }
\( { return TK_LPAREN; }
\) { return TK_RPAREN; }
\[ { return TK_LBRACKET; }
\] { return TK_RBRACKET; }
\{ { return TK_LBRACE; }
\} { return TK_RBRACE; }
\. { return TK_DOT; }
\+ { return TK_PLUS; }
\- { return TK_MINUS; }
\* { return TK_MULTI; }
\/ { return TK_DIV; }
= { return TK_EQU; }
\<\> { return TK_NEQU; }
\< { return TK_LT; }
\<= { return TK_LEQU; }
\> { return TK_GT; }
\>= { return TK_GEQU; }
& { return TK_AND; }
'|' { return TK_OR; }
:= { return TK_ASSIGN; }

{ident} {
    sym_entry_t* entry = (sym_entry_t*)malloc(sizeof(sym_entry_t));
    entry->type = TK_IDENT;
    entry->token = strdup(yytext);
    entry->lineno = yylineno;
    sym_table_append(entry);
    return TK_IDENT; 
    }

%%

int yywrap() 
{
    return 1;
}