#include <stdio.h>

// definitions in lex.yy.c file
extern FILE* yyin; 
extern char* yytext;
extern int yylineno;
extern int yylex(void);

int main(int argc, char **argv) {
  printf("Hello World\n");
  return 0;
}