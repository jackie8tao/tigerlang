#include <lex.h>
#include <parser.h>
#include <stdio.h>
#include <stuff.h>
#include <stxtree.h>
#include <symdict.h>
#include <tigerdef.h>

// read input files, then print result
int main(int argc, char **argv) {
  if (argc < 2) {
    perror("empyt input files");
    return ERR_ARGS;
  }

  yydebug = 1;

  FILE *fp;
  fp = fopen(argv[1], "r");
  if (!fp) {
    errmsg("cannot open file %s", argv[1]);
    return ERR_SYSTEM;
  }
  yyin = fp;

  stxtree_init();

  int errcode;
  if ((errcode = yyparse()) > 0) {
    errmsg("syntax parse error: %d", errcode);
    return ERR_YACC;
  }

  return SUCC;
}