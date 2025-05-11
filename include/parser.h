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
    TK_VAR = 260,                  /* TK_VAR  */
    TK_TYPE = 261,                 /* TK_TYPE  */
    TK_LET = 262,                  /* TK_LET  */
    TK_END = 263,                  /* TK_END  */
    TK_FUNCTION = 264,             /* TK_FUNCTION  */
    TK_IN = 265,                   /* TK_IN  */
    TK_OF = 266,                   /* TK_OF  */
    TK_IF = 267,                   /* TK_IF  */
    TK_THEN = 268,                 /* TK_THEN  */
    TK_ELSE = 269,                 /* TK_ELSE  */
    TK_BREAK = 270,                /* TK_BREAK  */
    TK_DO = 271,                   /* TK_DO  */
    TK_WHILE = 272,                /* TK_WHILE  */
    TK_FOR = 273,                  /* TK_FOR  */
    TK_TO = 274,                   /* TK_TO  */
    TK_COMMA = 275,                /* TK_COMMA  */
    TK_COLON = 276,                /* TK_COLON  */
    TK_SEMICOLON = 277,            /* TK_SEMICOLON  */
    TK_LPAREN = 278,               /* TK_LPAREN  */
    TK_RPAREN = 279,               /* TK_RPAREN  */
    TK_LBRACKET = 280,             /* TK_LBRACKET  */
    TK_RBRACKET = 281,             /* TK_RBRACKET  */
    TK_LBRACE = 282,               /* TK_LBRACE  */
    TK_RBRACE = 283,               /* TK_RBRACE  */
    TK_DOT = 284,                  /* TK_DOT  */
    TK_PLUS = 285,                 /* TK_PLUS  */
    TK_MINUS = 286,                /* TK_MINUS  */
    TK_MULTI = 287,                /* TK_MULTI  */
    TK_DIV = 288,                  /* TK_DIV  */
    TK_EQU = 289,                  /* TK_EQU  */
    TK_NEQU = 290,                 /* TK_NEQU  */
    TK_LT = 291,                   /* TK_LT  */
    TK_LEQU = 292,                 /* TK_LEQU  */
    TK_GT = 293,                   /* TK_GT  */
    TK_GEQU = 294,                 /* TK_GEQU  */
    TK_AND = 295,                  /* TK_AND  */
    TK_OR = 296,                   /* TK_OR  */
    TK_ASSIGN = 297,               /* TK_ASSIGN  */
    TK_IDENT = 298,                /* TK_IDENT  */
    TK_INTEGER = 299,              /* TK_INTEGER  */
    TK_STRING = 300,               /* TK_STRING  */
    UMINUS = 301,                  /* UMINUS  */
    MAXPRIV = 302                  /* MAXPRIV  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 27 "parser.y"

    char* sym;
    int ival;
    char* sval;

#line 117 "/Users/taodingfei/Dev/tigerlang/include/parser.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_USERS_TAODINGFEI_DEV_TIGERLANG_INCLUDE_PARSER_H_INCLUDED  */
