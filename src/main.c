#include <stdio.h>
#include <symtable.h>
#include <err.h>
#include <stuff.h>
#include <lex.h>
#include <parser.h>

// read input files, then print result
int main(int argc, char **argv)
{
  sym_table_init();
  if (argc < 2)
  {
    perror("empyt input files");
    return ERR_ARGS;
  }

  yydebug=1;

  FILE *fp;
  for (int i = 1; i < argc; i++)
  {
    fp = fopen(argv[i], "r");
    if (!fp)
    {
      errmsg("cannot open file %s", argv[i]);
      return ERR_SYSTEM;
    }
    yyin = fp;

    // int yytype;
    // while((yytype = yylex()) > 0)
    // {
    //   printf("yytext: %s, yylineno: %d, yytype: %d\n", yytext, yylineno, yytype);
    // }

    int errcode;
    if ((errcode = yyparse()) > 0)
    {
      errmsg("syntax parse error: %d", errcode);
      return ERR_YACC;
    }
  }

  return SUCC;
}