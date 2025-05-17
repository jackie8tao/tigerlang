/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_USERS_TAODINGFEI_DEV_TIGERLANG_INCLUDE_PARSER_H_INCLUDED
# define YY_YY_USERS_TAODINGFEI_DEV_TIGERLANG_INCLUDE_PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    TK_ARRAY = 258,                /* TK_ARRAY  */
    TK_NIL = 259,                  /* TK_NIL  */
    TK_INT = 260,                  /* TK_INT  */
    TK_STR = 261,                  /* TK_STR  */
    TK_VAR = 262,                  /* TK_VAR  */
    TK_TYPE = 263,                 /* TK_TYPE  */
    TK_LET = 264,                  /* TK_LET  */
    TK_END = 265,                  /* TK_END  */
    TK_FUNCTION = 266,             /* TK_FUNCTION  */
    TK_IN = 267,                   /* TK_IN  */
    TK_OF = 268,                   /* TK_OF  */
    TK_IF = 269,                   /* TK_IF  */
    TK_THEN = 270,                 /* TK_THEN  */
    TK_ELSE = 271,                 /* TK_ELSE  */
    TK_BREAK = 272,                /* TK_BREAK  */
    TK_DO = 273,                   /* TK_DO  */
    TK_WHILE = 274,                /* TK_WHILE  */
    TK_FOR = 275,                  /* TK_FOR  */
    TK_TO = 276,                   /* TK_TO  */
    TK_COMMA = 277,                /* TK_COMMA  */
    TK_COLON = 278,                /* TK_COLON  */
    TK_SEMICOLON = 279,            /* TK_SEMICOLON  */
    TK_LPAREN = 280,               /* TK_LPAREN  */
    TK_RPAREN = 281,               /* TK_RPAREN  */
    TK_LBRACKET = 282,             /* TK_LBRACKET  */
    TK_RBRACKET = 283,             /* TK_RBRACKET  */
    TK_LBRACE = 284,               /* TK_LBRACE  */
    TK_RBRACE = 285,               /* TK_RBRACE  */
    TK_DOT = 286,                  /* TK_DOT  */
    TK_PLUS = 287,                 /* TK_PLUS  */
    TK_MINUS = 288,                /* TK_MINUS  */
    TK_MULTI = 289,                /* TK_MULTI  */
    TK_DIV = 290,                  /* TK_DIV  */
    TK_EQU = 291,                  /* TK_EQU  */
    TK_NEQU = 292,                 /* TK_NEQU  */
    TK_LT = 293,                   /* TK_LT  */
    TK_LEQU = 294,                 /* TK_LEQU  */
    TK_GT = 295,                   /* TK_GT  */
    TK_GEQU = 296,                 /* TK_GEQU  */
    TK_AND = 297,                  /* TK_AND  */
    TK_OR = 298,                   /* TK_OR  */
    TK_ASSIGN = 299,               /* TK_ASSIGN  */
    TK_IDENT = 300,                /* TK_IDENT  */
    TK_INTEGER = 301,              /* TK_INTEGER  */
    TK_STRING = 302,               /* TK_STRING  */
    UMINUS = 303                   /* UMINUS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 23 "parser.y"

    int ival;
    char* sval;
    struct ast_node* ast;
    struct symval* sym;

#line 119 "/Users/taodingfei/Dev/tigerlang/include/parser.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;

int yyparse (void);


#endif /* !YY_YY_USERS_TAODINGFEI_DEV_TIGERLANG_INCLUDE_PARSER_H_INCLUDED  */
