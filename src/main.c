#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

// definitions in lex.yy.c file
extern FILE* yyin; 
extern char* yytext;
extern int yylineno;
extern int yylex(void);

// print error message
void errmsg(const char* format, ...) {
  char errmsg[128];
  va_list args;
  va_start(args, format);
  if (vsprintf(errmsg, format, args)<0) {
    perror("cannot format error message");
    exit(-99);
  }
  va_end(args);
  perror(errmsg);
  return;
}

// read input files, then print result
int main(int argc, char **argv) {
  if (argc < 2) {
    perror("empyt input files");
    return -1;
  }

  FILE* fp;
  for (int i=0; i<argc; i++) {
    fp = fopen(argv[i], "r");
    if (!fp) {
      errmsg("cannot open file %s", argv[i]);
      return -2;
    }
    yyin = fp;
    yylineno = 0;

    while(yylex() != EOF) {
      printf("lineno: %d, token: %s\n", yylineno, yytext);
    }
  }

  return 0;
}