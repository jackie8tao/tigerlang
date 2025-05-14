#include <stuff.h>
#include <stdarg.h>
#include <stdlib.h>
#include <tigerdef.h>
#include <stdio.h>
#include <parser.h>

// print error message
void errmsg(const char *format, ...)
{
  char errmsg[128];
  va_list args;
  va_start(args, format);
  if (vsprintf(errmsg, format, args) < 0)
  {
    perror("cannot format error message");
    exit(ERR_SYSTEM);
  }
  va_end(args);

  perror(errmsg);
  return;
}

const char *token_type_to_str(yytoken_kind_t token_type)
{
  char *tokenstr;
  switch (token_type)
  {
  case TK_ARRAY:
    tokenstr = "array";
    break;
  case TK_NIL:
    tokenstr = "nil";
    break;
  case TK_INT:
    tokenstr = "int";
    break;
  case TK_STR:
    tokenstr = "str";
    break;
  case TK_VAR:
    tokenstr = "var";
    break;
  case TK_TYPE:
    tokenstr = "type";
    break;
  case TK_LET:
    tokenstr = "let";
    break;
  case TK_END:
    tokenstr = "end";
    break;
  case TK_FUNCTION:
    tokenstr = "function";
    break;
  case TK_IN:
    tokenstr = "in";
    break;
  case TK_OF:
    tokenstr = "of";
    break;
  case TK_IF:
    tokenstr = "if";
    break;
  case TK_THEN:
    tokenstr = "then";
    break;
  case TK_BREAK:
    tokenstr = "break";
    break;
  case TK_DO:
    tokenstr = "do";
    break;
  case TK_WHILE:
    tokenstr = "while";
    break;
  case TK_FOR:
    tokenstr = "for";
    break;
  case TK_TO:
    tokenstr = "to";
    break;
  case TK_COMMA:
    tokenstr = ",";
    break;
  case TK_COLON:
    tokenstr = ":";
    break;
  case TK_SEMICOLON:
    tokenstr = ";";
    break;
  case TK_LPAREN:
    tokenstr = "(";
    break;
  case TK_RPAREN:
    tokenstr = ")";
    break;
  case TK_LBRACKET:
    tokenstr = "[";
    break;
  case TK_RBRACKET:
    tokenstr = "]";
    break;
  case TK_LBRACE:
    tokenstr = "(";
    break;
  case TK_RBRACE:
    tokenstr = ")";
    break;
  case TK_DOT:
    tokenstr = ".";
    break;
  case TK_PLUS:
    tokenstr = "+";
    break;
  case TK_MINUS:
    tokenstr = "-";
    break;
  case TK_MULTI:
    tokenstr = "*";
    break;
  case TK_DIV:
    tokenstr = "/";
    break;
  case TK_EQU:
    tokenstr = "=";
    break;
  case TK_NEQU:
    tokenstr = "!=";
    break;
  case TK_LT:
    tokenstr = "<";
    break;
  case TK_LEQU:
    tokenstr = "<=";
    break;
  case TK_GT:
    tokenstr = ">";
    break;
  case TK_GEQU:
    tokenstr = ">=";
    break;
  case TK_AND:
    tokenstr = "&";
    break;
  case TK_OR:
    tokenstr = "|";
    break;
  case TK_ASSIGN:
    tokenstr = ":=";
    break;
  default:
    errmsg("invalid token type");
    exit(ERR_SYSTEM);
    break;
  }

  return tokenstr;
}