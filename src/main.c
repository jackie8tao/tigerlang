#include <stdio.h>
#include <symtable.h>
#include <tigerdef.h>
#include <stuff.h>
#include <lex.h>
#include <parser.h>
#include <stxtree.h>

// read input files, then print result
int main(int argc, char **argv)
{
  if (argc < 2)
  {
    perror("empyt input files");
    return ERR_ARGS;
  }

  // yydebug = 1;

  FILE *fp;
  fp = fopen(argv[1], "r");
  if (!fp)
  {
    errmsg("cannot open file %s", argv[1]);
    return ERR_SYSTEM;
  }
  yyin = fp;

  sym_table_init();
  stxtree_init();

  int errcode;
  if ((errcode = yyparse()) > 0)
  {
    errmsg("syntax parse error: %d", errcode);
    return ERR_YACC;
  }

  stxtree_show_node(TK_TYPE);

  return SUCC;
}