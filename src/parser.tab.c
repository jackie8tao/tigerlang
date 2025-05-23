/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

#include <stdio.h>
#include <stdlib.h>
#include <err.h>
#include <tigerdef.h>
#include <stuff.h>
#include <lex.h>
#include <ast.h>
#include <scope.h>
#include <symdict.h>

void yyerror(const char* msg)
{
    errmsg("row: %d, col: %d, msg: %s", yylloc.first_line, yylloc.first_column, msg);
    exit(ERR_YACC);
}

#line 89 "parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_TK_ARRAY = 3,                   /* TK_ARRAY  */
  YYSYMBOL_TK_NIL = 4,                     /* TK_NIL  */
  YYSYMBOL_TK_INT = 5,                     /* TK_INT  */
  YYSYMBOL_TK_STR = 6,                     /* TK_STR  */
  YYSYMBOL_TK_VAR = 7,                     /* TK_VAR  */
  YYSYMBOL_TK_TYPE = 8,                    /* TK_TYPE  */
  YYSYMBOL_TK_LET = 9,                     /* TK_LET  */
  YYSYMBOL_TK_END = 10,                    /* TK_END  */
  YYSYMBOL_TK_FUNCTION = 11,               /* TK_FUNCTION  */
  YYSYMBOL_TK_IN = 12,                     /* TK_IN  */
  YYSYMBOL_TK_OF = 13,                     /* TK_OF  */
  YYSYMBOL_TK_IF = 14,                     /* TK_IF  */
  YYSYMBOL_TK_THEN = 15,                   /* TK_THEN  */
  YYSYMBOL_TK_ELSE = 16,                   /* TK_ELSE  */
  YYSYMBOL_TK_BREAK = 17,                  /* TK_BREAK  */
  YYSYMBOL_TK_DO = 18,                     /* TK_DO  */
  YYSYMBOL_TK_WHILE = 19,                  /* TK_WHILE  */
  YYSYMBOL_TK_FOR = 20,                    /* TK_FOR  */
  YYSYMBOL_TK_TO = 21,                     /* TK_TO  */
  YYSYMBOL_TK_COMMA = 22,                  /* TK_COMMA  */
  YYSYMBOL_TK_COLON = 23,                  /* TK_COLON  */
  YYSYMBOL_TK_SEMICOLON = 24,              /* TK_SEMICOLON  */
  YYSYMBOL_TK_LPAREN = 25,                 /* TK_LPAREN  */
  YYSYMBOL_TK_RPAREN = 26,                 /* TK_RPAREN  */
  YYSYMBOL_TK_LBRACKET = 27,               /* TK_LBRACKET  */
  YYSYMBOL_TK_RBRACKET = 28,               /* TK_RBRACKET  */
  YYSYMBOL_TK_LBRACE = 29,                 /* TK_LBRACE  */
  YYSYMBOL_TK_RBRACE = 30,                 /* TK_RBRACE  */
  YYSYMBOL_TK_DOT = 31,                    /* TK_DOT  */
  YYSYMBOL_TK_PLUS = 32,                   /* TK_PLUS  */
  YYSYMBOL_TK_MINUS = 33,                  /* TK_MINUS  */
  YYSYMBOL_TK_MULTI = 34,                  /* TK_MULTI  */
  YYSYMBOL_TK_DIV = 35,                    /* TK_DIV  */
  YYSYMBOL_TK_EQU = 36,                    /* TK_EQU  */
  YYSYMBOL_TK_NEQU = 37,                   /* TK_NEQU  */
  YYSYMBOL_TK_LT = 38,                     /* TK_LT  */
  YYSYMBOL_TK_LEQU = 39,                   /* TK_LEQU  */
  YYSYMBOL_TK_GT = 40,                     /* TK_GT  */
  YYSYMBOL_TK_GEQU = 41,                   /* TK_GEQU  */
  YYSYMBOL_TK_AND = 42,                    /* TK_AND  */
  YYSYMBOL_TK_OR = 43,                     /* TK_OR  */
  YYSYMBOL_TK_ASSIGN = 44,                 /* TK_ASSIGN  */
  YYSYMBOL_TK_IDENT = 45,                  /* TK_IDENT  */
  YYSYMBOL_TK_INTEGER = 46,                /* TK_INTEGER  */
  YYSYMBOL_TK_STRING = 47,                 /* TK_STRING  */
  YYSYMBOL_UMINUS = 48,                    /* UMINUS  */
  YYSYMBOL_YYACCEPT = 49,                  /* $accept  */
  YYSYMBOL_stmt = 50,                      /* stmt  */
  YYSYMBOL_entersc = 51,                   /* entersc  */
  YYSYMBOL_leavesc = 52,                   /* leavesc  */
  YYSYMBOL_expr = 53,                      /* expr  */
  YYSYMBOL_exprseq = 54,                   /* exprseq  */
  YYSYMBOL_exprlist = 55,                  /* exprlist  */
  YYSYMBOL_fieldlist = 56,                 /* fieldlist  */
  YYSYMBOL_lvalue = 57,                    /* lvalue  */
  YYSYMBOL_index = 58,                     /* index  */
  YYSYMBOL_declist = 59,                   /* declist  */
  YYSYMBOL_dec = 60,                       /* dec  */
  YYSYMBOL_typedec = 61,                   /* typedec  */
  YYSYMBOL_typeid = 62,                    /* typeid  */
  YYSYMBOL_vardec = 63,                    /* vardec  */
  YYSYMBOL_funcdec = 64,                   /* funcdec  */
  YYSYMBOL_typefields = 65                 /* typefields  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if 1

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  27
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   277

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  17
/* YYNRULES -- Number of rules.  */
#define YYNRULES  63
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  152

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   303


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    68,    68,    73,    74,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    98,    99,   103,   107,   108,   109,
     110,   114,   115,   118,   123,   127,   130,   135,   139,   142,
     149,   155,   158,   164,   170,   175,   178,   183,   189,   190,
     191,   194,   199,   204,   211,   215,   216,   219,   223,   229,
     234,   241,   246,   252
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  static const char *const yy_sname[] =
  {
  "end of file", "error", "invalid token", "TK_ARRAY", "TK_NIL", "TK_INT",
  "TK_STR", "TK_VAR", "TK_TYPE", "TK_LET", "TK_END", "TK_FUNCTION",
  "TK_IN", "TK_OF", "TK_IF", "TK_THEN", "TK_ELSE", "TK_BREAK", "TK_DO",
  "TK_WHILE", "TK_FOR", "TK_TO", "TK_COMMA", "TK_COLON", "TK_SEMICOLON",
  "TK_LPAREN", "TK_RPAREN", "TK_LBRACKET", "TK_RBRACKET", "TK_LBRACE",
  "TK_RBRACE", "TK_DOT", "TK_PLUS", "TK_MINUS", "TK_MULTI", "TK_DIV",
  "TK_EQU", "TK_NEQU", "TK_LT", "TK_LEQU", "TK_GT", "TK_GEQU", "TK_AND",
  "TK_OR", "TK_ASSIGN", "TK_IDENT", "TK_INTEGER", "TK_STRING", "UMINUS",
  "$accept", "stmt", "entersc", "leavesc", "expr", "exprseq", "exprlist",
  "fieldlist", "lvalue", "index", "declist", "dec", "typedec", "typeid",
  "vardec", "funcdec", "typefields", YY_NULLPTR
  };
  return yy_sname[yysymbol];
}
#endif

#define YYPACT_NINF (-87)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      83,   -87,   -87,   -87,   -87,   -87,   -87,    83,    83,    41,
     -87,   -87,     9,   234,   -29,    87,    83,    83,     3,   234,
      -6,   -87,    83,    83,     8,    10,   -87,   -87,    83,    83,
      83,    83,    83,    83,    83,    83,    83,    83,    83,    83,
      83,    15,    18,   -87,    98,   -87,   -87,   -87,   -87,   117,
     155,   -19,    83,   -87,   234,    45,   206,    33,   -11,    50,
      40,    40,   -87,   -87,    90,    90,    90,    90,    90,    90,
     142,   142,   234,   -20,    47,    31,    83,   -87,    83,    83,
      83,   234,    83,   -87,    30,    83,    39,   -87,    83,   -87,
       1,    83,    44,    68,     2,   129,   234,   190,   234,    83,
     -87,   234,    60,   222,   -87,   -87,   -87,    57,   234,    91,
      62,   -87,    62,   -87,    83,   -87,   -87,    83,   234,    83,
      50,    83,     1,    88,    -9,    64,   -87,   234,   167,   234,
     234,   -87,     1,    67,   -87,    22,   -87,    83,   -87,    92,
       1,    83,   234,     1,    77,   234,   -87,   -87,    83,   -87,
     234,   -87
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     7,     3,     3,    31,     3,     3,    35,     0,    45,
       6,     5,     0,     2,    20,     0,     0,     0,     0,    33,
       0,    21,    38,     0,    41,     0,    42,     1,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     3,     0,    46,    48,    49,    50,     0,
       0,     0,     0,    24,    36,     0,     0,     0,     0,    45,
       8,     9,    10,    11,    12,    13,    17,    16,    14,    15,
      18,    19,    22,     0,     0,     0,    35,    47,     0,     0,
       0,    34,     0,    23,    45,     0,     0,    25,     0,    43,
       0,     0,     0,     0,     0,     4,     4,     0,    37,     0,
      44,    39,     0,     0,    55,    56,    54,     0,    57,     0,
      63,    51,    63,     4,     0,    27,    29,     0,    26,     0,
      45,     0,     0,     0,     0,     0,    32,     4,     0,    40,
      58,    53,     0,     0,    52,     0,    28,     0,    61,     0,
       0,     0,     4,     0,     0,     4,    30,    62,     0,    60,
       4,    59
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -87,   -87,    -1,   -86,     0,    42,   -87,   -87,   -87,    -8,
     -87,    76,   -87,   -78,   -87,   -87,    14
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,    12,    15,   115,    19,    20,    55,    58,    14,   100,
      44,    45,    46,   107,    47,    48,   124
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      13,    26,    16,    90,    17,    18,   104,   105,    21,    27,
     116,    86,   113,   133,   111,    40,    49,    50,    52,    87,
      53,   134,    54,    56,    91,    80,    52,   126,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,   136,    75,    99,   131,   140,   106,   109,    51,   104,
     105,    89,    81,    57,   138,    59,   146,    88,   141,   149,
      73,    25,   144,    74,   151,   147,    22,    82,    23,    85,
      24,    83,    25,   110,    30,    31,    93,    88,    95,    96,
      97,    25,    98,    92,   102,   101,   133,     1,   103,   106,
     135,   108,     2,   112,    41,    42,   119,     3,    43,   118,
       4,   121,     5,     6,   122,    41,    42,   123,     7,    43,
      76,   132,   139,   148,   127,   143,     8,   128,    94,   129,
      77,   130,    28,    29,    30,    31,   125,     0,     9,    10,
      11,     0,    78,     0,     0,     0,     0,   142,     0,     0,
       0,   145,     0,     0,     0,   114,     0,     0,   150,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    79,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,     0,   137,     0,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,   117,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    84,     0,     0,     0,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
     120,     0,     0,     0,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39
};

static const yytype_int16 yycheck[] =
{
       0,     9,     3,    23,     5,     6,     5,     6,     8,     0,
      96,    22,    10,    22,    92,    44,    16,    17,    24,    30,
      26,    30,    22,    23,    44,    44,    24,   113,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,   127,    43,    13,   122,    23,    45,     3,    45,     5,
       6,    59,    52,    45,   132,    45,   142,    27,    36,   145,
      45,    31,   140,    45,   150,   143,    25,    22,    27,    36,
      29,    26,    31,    29,    34,    35,    45,    27,    78,    79,
      80,    31,    82,    36,    45,    85,    22,     4,    88,    45,
      26,    91,     9,    25,     7,     8,    36,    14,    11,    99,
      17,    44,    19,    20,    13,     7,     8,    45,    25,    11,
      12,    23,    45,    36,   114,    23,    33,   117,    76,   119,
      44,   121,    32,    33,    34,    35,   112,    -1,    45,    46,
      47,    -1,    15,    -1,    -1,    -1,    -1,   137,    -1,    -1,
      -1,   141,    -1,    -1,    -1,    16,    -1,    -1,   148,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    18,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    -1,    18,    -1,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    28,    -1,    -1,    -1,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      28,    -1,    -1,    -1,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     4,     9,    14,    17,    19,    20,    25,    33,    45,
      46,    47,    50,    53,    57,    51,    51,    51,    51,    53,
      54,    53,    25,    27,    29,    31,    58,     0,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,     7,     8,    11,    59,    60,    61,    63,    64,    53,
      53,    45,    24,    26,    53,    55,    53,    45,    56,    45,
      53,    53,    53,    53,    53,    53,    53,    53,    53,    53,
      53,    53,    53,    45,    45,    51,    12,    60,    15,    18,
      44,    53,    22,    26,    28,    36,    22,    30,    27,    58,
      23,    44,    36,    45,    54,    53,    53,    53,    53,    13,
      58,    53,    45,    53,     5,     6,    45,    62,    53,     3,
      29,    62,    25,    10,    16,    52,    52,    21,    53,    36,
      28,    44,    13,    45,    65,    65,    52,    53,    53,    53,
      53,    62,    23,    22,    30,    26,    52,    18,    62,    45,
      23,    36,    53,    23,    62,    53,    52,    62,    36,    52,
      53,    52
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    49,    50,    51,    52,    53,    53,    53,    53,    53,
      53,    53,    53,    53,    53,    53,    53,    53,    53,    53,
      53,    53,    53,    53,    53,    53,    53,    53,    53,    53,
      53,    53,    53,    54,    54,    54,    55,    55,    55,    56,
      56,    56,    57,    58,    58,    58,    59,    59,    60,    60,
      60,    61,    61,    61,    62,    62,    62,    63,    63,    64,
      64,    65,    65,    65
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     0,     1,     1,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       1,     2,     3,     4,     3,     4,     6,     6,     8,     6,
      10,     1,     7,     1,     3,     0,     1,     3,     0,     3,
       5,     0,     2,     3,     4,     0,     1,     2,     1,     1,
       1,     4,     6,     6,     1,     1,     1,     4,     6,    11,
       9,     3,     5,     0
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YYLOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YYLOCATION_PRINT

#  if defined YY_LOCATION_PRINT

   /* Temporary convenience wrapper in case some people defined the
      undocumented and private YY_LOCATION_PRINT macros.  */
#   define YYLOCATION_PRINT(File, Loc)  YY_LOCATION_PRINT(File, *(Loc))

#  elif defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
}

#   define YYLOCATION_PRINT  yy_location_print_

    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT(File, Loc)  YYLOCATION_PRINT(File, &(Loc))

#  else

#   define YYLOCATION_PRINT(File, Loc) ((void) 0)
    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT  YYLOCATION_PRINT

#  endif
# endif /* !defined YYLOCATION_PRINT */


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (yylocationp);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YYLOCATION_PRINT (yyo, yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)],
                       &(yylsp[(yyi + 1) - (yynrhs)]));
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
  YYLTYPE *yylloc;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
  if (!yypact_value_is_default (yyn))
    {
      /* Start YYX at -YYN if negative to avoid negative indexes in
         YYCHECK.  In other words, skip the first -YYN actions for
         this state because they are default actions.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;
      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yyx;
      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif



static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yystrlen (yysymbol_name (yyarg[yyi]));
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp = yystpcpy (yyp, yysymbol_name (yyarg[yyi++]));
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YY_USE (yyvaluep);
  YY_USE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

    /* The location stack: array, bottom, top.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls = yylsa;
    YYLTYPE *yylsp = yyls;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[3];

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  yylsp[0] = yylloc;
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      yyerror_range[1] = yylloc;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* stmt: expr  */
#line 68 "parser.y"
           {
    (yyval.ast) = (yyvsp[0].ast);
    ast_set_root((yyval.ast));
}
#line 1598 "parser.tab.c"
    break;

  case 3: /* entersc: %empty  */
#line 73 "parser.y"
                       { scope_create(); }
#line 1604 "parser.tab.c"
    break;

  case 4: /* leavesc: %empty  */
#line 74 "parser.y"
                       { scope_close(); }
#line 1610 "parser.tab.c"
    break;

  case 5: /* expr: TK_STRING  */
#line 76 "parser.y"
                { (yyval.ast) = ast_create_string((yyvsp[0].sval)); }
#line 1616 "parser.tab.c"
    break;

  case 6: /* expr: TK_INTEGER  */
#line 77 "parser.y"
                 { (yyval.ast) = ast_create_int((yyvsp[0].ival)); }
#line 1622 "parser.tab.c"
    break;

  case 7: /* expr: TK_NIL  */
#line 78 "parser.y"
             { (yyval.ast) = ast_create_nil(); }
#line 1628 "parser.tab.c"
    break;

  case 8: /* expr: expr TK_PLUS expr  */
#line 79 "parser.y"
                        { (yyval.ast) = ast_create_binory(TK_PLUS, (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1634 "parser.tab.c"
    break;

  case 9: /* expr: expr TK_MINUS expr  */
#line 80 "parser.y"
                         { (yyval.ast) = ast_create_binory(TK_MINUS, (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1640 "parser.tab.c"
    break;

  case 10: /* expr: expr TK_MULTI expr  */
#line 81 "parser.y"
                         { (yyval.ast) = ast_create_binory(TK_MULTI, (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1646 "parser.tab.c"
    break;

  case 11: /* expr: expr TK_DIV expr  */
#line 82 "parser.y"
                       { (yyval.ast) = ast_create_binory(TK_DIV, (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1652 "parser.tab.c"
    break;

  case 12: /* expr: expr TK_EQU expr  */
#line 83 "parser.y"
                       { (yyval.ast) = ast_create_binory(TK_EQU, (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1658 "parser.tab.c"
    break;

  case 13: /* expr: expr TK_NEQU expr  */
#line 84 "parser.y"
                        { (yyval.ast) = ast_create_binory(TK_NEQU, (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1664 "parser.tab.c"
    break;

  case 14: /* expr: expr TK_GT expr  */
#line 85 "parser.y"
                      { (yyval.ast) = ast_create_binory(TK_GT, (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1670 "parser.tab.c"
    break;

  case 15: /* expr: expr TK_GEQU expr  */
#line 86 "parser.y"
                        { (yyval.ast) = ast_create_binory(TK_GEQU, (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1676 "parser.tab.c"
    break;

  case 16: /* expr: expr TK_LEQU expr  */
#line 87 "parser.y"
                        { (yyval.ast) = ast_create_binory(TK_LEQU, (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1682 "parser.tab.c"
    break;

  case 17: /* expr: expr TK_LT expr  */
#line 88 "parser.y"
                      { (yyval.ast) = ast_create_binory(TK_LT, (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1688 "parser.tab.c"
    break;

  case 18: /* expr: expr TK_AND expr  */
#line 89 "parser.y"
                       { (yyval.ast) = ast_create_binory(TK_AND, (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1694 "parser.tab.c"
    break;

  case 19: /* expr: expr TK_OR expr  */
#line 90 "parser.y"
                      { (yyval.ast) = ast_create_binory(TK_OR, (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1700 "parser.tab.c"
    break;

  case 20: /* expr: lvalue  */
#line 91 "parser.y"
             { (yyval.ast) = (yyvsp[0].ast); }
#line 1706 "parser.tab.c"
    break;

  case 21: /* expr: TK_MINUS expr  */
#line 92 "parser.y"
                                 { (yyval.ast) = ast_create_unary(TK_MINUS, (yyvsp[0].ast)); }
#line 1712 "parser.tab.c"
    break;

  case 22: /* expr: lvalue TK_ASSIGN expr  */
#line 93 "parser.y"
                            { (yyval.ast) = ast_create_assign((yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1718 "parser.tab.c"
    break;

  case 23: /* expr: TK_IDENT TK_LPAREN exprlist TK_RPAREN  */
#line 94 "parser.y"
                                            { 
        ast_node_t* ident = ast_create_ident((yyvsp[-3].sym)->txt, scope_current(), yylloc.first_line, yylloc.first_column);
        (yyval.ast) = ast_create_fncall(ident, (yyvsp[-1].ast)); 
      }
#line 1727 "parser.tab.c"
    break;

  case 24: /* expr: TK_LPAREN exprseq TK_RPAREN  */
#line 98 "parser.y"
                                  { (yyval.ast) = (yyvsp[-1].ast); }
#line 1733 "parser.tab.c"
    break;

  case 25: /* expr: TK_IDENT TK_LBRACE fieldlist TK_RBRACE  */
#line 99 "parser.y"
                                             { 
        ast_node_t* ident = ast_create_ident(strdup((yyvsp[-3].sym)->txt), scope_current(), yylloc.first_line, yylloc.first_column);
        (yyval.ast) = ast_create_struct(ident, (yyvsp[-1].ast)); 
      }
#line 1742 "parser.tab.c"
    break;

  case 26: /* expr: TK_IDENT TK_LBRACKET expr TK_RBRACKET TK_OF expr  */
#line 103 "parser.y"
                                                       { 
        ast_node_t* ident = ast_create_ident(strdup((yyvsp[-5].sym)->txt), scope_current(), yylloc.first_line, yylloc.first_column);
        (yyval.ast) = ast_create_arrinit(ident, (yyvsp[-3].ast), (yyvsp[0].ast)); 
      }
#line 1751 "parser.tab.c"
    break;

  case 27: /* expr: TK_IF entersc expr TK_THEN expr leavesc  */
#line 107 "parser.y"
                                              { (yyval.ast) = ast_create_if((yyvsp[-3].ast), (yyvsp[-1].ast), NULL); }
#line 1757 "parser.tab.c"
    break;

  case 28: /* expr: TK_IF entersc expr TK_THEN expr TK_ELSE expr leavesc  */
#line 108 "parser.y"
                                                           { (yyval.ast) = ast_create_if((yyvsp[-5].ast), (yyvsp[-3].ast), (yyvsp[-1].ast)); }
#line 1763 "parser.tab.c"
    break;

  case 29: /* expr: TK_WHILE entersc expr TK_DO expr leavesc  */
#line 109 "parser.y"
                                               { (yyval.ast) = ast_create_while((yyvsp[-3].ast), (yyvsp[-1].ast)); }
#line 1769 "parser.tab.c"
    break;

  case 30: /* expr: TK_FOR entersc TK_IDENT TK_ASSIGN expr TK_TO expr TK_DO expr leavesc  */
#line 110 "parser.y"
                                                                           { 
        ast_node_t* ident = ast_create_ident(strdup((yyvsp[-7].sym)->txt), scope_current(), yylloc.first_line, yylloc.first_column);
        (yyval.ast) = ast_create_for(ident, (yyvsp[-5].ast), (yyvsp[-3].ast), (yyvsp[-1].ast)); 
      }
#line 1778 "parser.tab.c"
    break;

  case 31: /* expr: TK_BREAK  */
#line 114 "parser.y"
               { (yyval.ast) = ast_create_break(); }
#line 1784 "parser.tab.c"
    break;

  case 32: /* expr: TK_LET entersc declist TK_IN exprseq TK_END leavesc  */
#line 115 "parser.y"
                                                          { (yyval.ast) = ast_create_let((yyvsp[-4].ast), (yyvsp[-2].ast)); }
#line 1790 "parser.tab.c"
    break;

  case 33: /* exprseq: expr  */
#line 118 "parser.y"
              { 
    ast_node_t* exprseq = ast_create_exprseq();
    ast_append_exprseq(exprseq, (yyvsp[0].ast));
    (yyval.ast) = exprseq;
   }
#line 1800 "parser.tab.c"
    break;

  case 34: /* exprseq: exprseq TK_SEMICOLON expr  */
#line 123 "parser.y"
                              {
    ast_append_exprseq((yyvsp[-2].ast), (yyvsp[0].ast));
    (yyval.ast) = (yyvsp[-2].ast);
  }
#line 1809 "parser.tab.c"
    break;

  case 35: /* exprseq: %empty  */
#line 127 "parser.y"
                  { (yyval.ast) = NULL; }
#line 1815 "parser.tab.c"
    break;

  case 36: /* exprlist: expr  */
#line 130 "parser.y"
               { 
    ast_node_t* exprlist = ast_create_exprlist();
    ast_append_exprlist(exprlist, (yyvsp[0].ast));
    (yyval.ast) = exprlist;
    }
#line 1825 "parser.tab.c"
    break;

  case 37: /* exprlist: exprlist TK_COMMA expr  */
#line 135 "parser.y"
                           {
    ast_append_exprlist((yyvsp[-2].ast), (yyvsp[0].ast));
    (yyval.ast) = (yyvsp[-2].ast);
  }
#line 1834 "parser.tab.c"
    break;

  case 38: /* exprlist: %empty  */
#line 139 "parser.y"
                  { (yyval.ast) = NULL; }
#line 1840 "parser.tab.c"
    break;

  case 39: /* fieldlist: TK_IDENT TK_EQU expr  */
#line 142 "parser.y"
                                {
      ast_node_t* ident = ast_create_ident(strdup((yyvsp[-2].sym)->txt), scope_current(), yylloc.first_line, yylloc.first_column);
      ast_node_t* fieldef = ast_create_fieldef(ident, (yyvsp[0].ast));
      ast_node_t* fieldlist = ast_create_fieldlist();
      ast_append_fieldlist(fieldlist, fieldef);
      (yyval.ast) = fieldlist;
    }
#line 1852 "parser.tab.c"
    break;

  case 40: /* fieldlist: fieldlist TK_COMMA TK_IDENT TK_EQU expr  */
#line 149 "parser.y"
                                            {
    ast_node_t* ident = ast_create_ident(strdup((yyvsp[-2].sym)->txt), scope_current(), yylloc.first_line, yylloc.first_column);
    ast_node_t* fieldef = ast_create_fieldef(ident, (yyvsp[0].ast));
    ast_append_fieldlist((yyvsp[-4].ast), fieldef);
    (yyval.ast) = (yyvsp[-4].ast);
  }
#line 1863 "parser.tab.c"
    break;

  case 41: /* fieldlist: %empty  */
#line 155 "parser.y"
                  { (yyval.ast) = NULL; }
#line 1869 "parser.tab.c"
    break;

  case 42: /* lvalue: TK_IDENT index  */
#line 158 "parser.y"
                       {
    ast_node_t* ident = ast_create_ident(strdup((yyvsp[-1].sym)->txt), scope_current(), yylloc.first_line, yylloc.first_column);
    (yyval.ast) = ast_create_lvalue(ident, (yyvsp[0].ast));
  }
#line 1878 "parser.tab.c"
    break;

  case 43: /* index: TK_DOT TK_IDENT index  */
#line 164 "parser.y"
                             {
      ast_node_t* ident = ast_create_ident(strdup((yyvsp[-1].sym)->txt), scope_current(), yylloc.first_line, yylloc.first_column);
      ast_node_t* ident_index = ast_create_ident_index(ident);
      ast_append_index(ident_index, (yyvsp[0].ast));
      (yyval.ast) = ident_index;
    }
#line 1889 "parser.tab.c"
    break;

  case 44: /* index: TK_LBRACKET expr TK_RBRACKET index  */
#line 170 "parser.y"
                                       {
      ast_node_t* arr_index = ast_create_arr_index((yyvsp[-2].ast));
      ast_append_index(arr_index, (yyvsp[0].ast));
      (yyval.ast) = arr_index;
  }
#line 1899 "parser.tab.c"
    break;

  case 45: /* index: %empty  */
#line 175 "parser.y"
                  { (yyval.ast) = NULL; }
#line 1905 "parser.tab.c"
    break;

  case 46: /* declist: dec  */
#line 178 "parser.y"
             {
    ast_node_t* declist = ast_create_declist();
    ast_append_declist(declist, (yyvsp[0].ast));
    (yyval.ast) = declist;
  }
#line 1915 "parser.tab.c"
    break;

  case 47: /* declist: declist dec  */
#line 183 "parser.y"
                {
    ast_append_declist((yyvsp[-1].ast), (yyvsp[0].ast));
    (yyval.ast) = (yyvsp[-1].ast);
  }
#line 1924 "parser.tab.c"
    break;

  case 48: /* dec: typedec  */
#line 189 "parser.y"
             { (yyval.ast) = (yyvsp[0].ast); }
#line 1930 "parser.tab.c"
    break;

  case 49: /* dec: vardec  */
#line 190 "parser.y"
             { (yyval.ast) = (yyvsp[0].ast); }
#line 1936 "parser.tab.c"
    break;

  case 50: /* dec: funcdec  */
#line 191 "parser.y"
              { (yyval.ast) = (yyvsp[0].ast); }
#line 1942 "parser.tab.c"
    break;

  case 51: /* typedec: TK_TYPE TK_IDENT TK_EQU typeid  */
#line 194 "parser.y"
                                        {
      ast_node_t* ident = ast_create_ident(strdup((yyvsp[-2].sym)->txt), scope_current(), yylloc.first_line, yylloc.first_column);
      ast_node_t* typedec = ast_create_typedec(AstIdentTypeDec, ident, (yyvsp[0].ast));
      (yyval.ast) = typedec;
    }
#line 1952 "parser.tab.c"
    break;

  case 52: /* typedec: TK_TYPE TK_IDENT TK_EQU TK_LBRACE typefields TK_RBRACE  */
#line 199 "parser.y"
                                                             {
      ast_node_t* ident = ast_create_ident(strdup((yyvsp[-4].sym)->txt), scope_current(), yylloc.first_line, yylloc.first_column);
      ast_node_t* typedec = ast_create_typedec(AstStTypeDec, ident, (yyvsp[-1].ast));
      (yyval.ast) = typedec;
    }
#line 1962 "parser.tab.c"
    break;

  case 53: /* typedec: TK_TYPE TK_IDENT TK_EQU TK_ARRAY TK_OF typeid  */
#line 204 "parser.y"
                                                    {
      ast_node_t* ident = ast_create_ident(strdup((yyvsp[-4].sym)->txt), scope_current(), yylloc.first_line, yylloc.first_column);
      ast_node_t* typedec = ast_create_typedec(AstArrTypeDec, ident, (yyvsp[0].ast));
      (yyval.ast) = typedec;
    }
#line 1972 "parser.tab.c"
    break;

  case 54: /* typeid: TK_IDENT  */
#line 211 "parser.y"
                 { 
      ast_node_t* ident = ast_create_ident(strdup((yyvsp[0].sym)->txt), scope_current(), yylloc.first_line, yylloc.first_column);
      (yyval.ast) = ast_create_ident_typeid(ident); 
    }
#line 1981 "parser.tab.c"
    break;

  case 55: /* typeid: TK_INT  */
#line 215 "parser.y"
             { (yyval.ast) = ast_create_int_typeid(); }
#line 1987 "parser.tab.c"
    break;

  case 56: /* typeid: TK_STR  */
#line 216 "parser.y"
             { (yyval.ast) = ast_create_str_typeid(); }
#line 1993 "parser.tab.c"
    break;

  case 57: /* vardec: TK_VAR TK_IDENT TK_ASSIGN expr  */
#line 219 "parser.y"
                                       {
      ast_node_t* ident = ast_create_ident(strdup((yyvsp[-2].sym)->txt), scope_current(), yylloc.first_line, yylloc.first_column);
      (yyval.ast) = ast_create_vardec(ident, NULL, (yyvsp[0].ast));
    }
#line 2002 "parser.tab.c"
    break;

  case 58: /* vardec: TK_VAR TK_IDENT TK_COLON typeid TK_ASSIGN expr  */
#line 223 "parser.y"
                                                     {
      ast_node_t* ident = ast_create_ident(strdup((yyvsp[-4].sym)->txt), scope_current(), yylloc.first_line, yylloc.first_column);
      (yyval.ast) = ast_create_vardec(ident, (yyvsp[-2].ast), (yyvsp[0].ast));
    }
#line 2011 "parser.tab.c"
    break;

  case 59: /* funcdec: TK_FUNCTION entersc TK_IDENT TK_LPAREN typefields TK_RPAREN TK_COLON typeid TK_EQU expr leavesc  */
#line 229 "parser.y"
                                                                                                         {
      ast_node_t* ident = ast_create_ident(strdup((yyvsp[-8].sym)->txt), scope_current(), yylloc.first_line, yylloc.first_column);
      ast_node_t* fn = ast_create_fndef(ident, (yyvsp[-6].ast), (yyvsp[-3].ast), (yyvsp[-1].ast));
      (yyval.ast) = fn;
    }
#line 2021 "parser.tab.c"
    break;

  case 60: /* funcdec: TK_FUNCTION entersc TK_IDENT TK_LPAREN typefields TK_RPAREN TK_EQU expr leavesc  */
#line 234 "parser.y"
                                                                                      {
      ast_node_t* ident = ast_create_ident(strdup((yyvsp[-6].sym)->txt), scope_current(), yylloc.first_line, yylloc.first_column);
      ast_node_t* fn = ast_create_fndef(ident, (yyvsp[-4].ast), NULL, (yyvsp[-1].ast));
      (yyval.ast) = fn;
    }
#line 2031 "parser.tab.c"
    break;

  case 61: /* typefields: TK_IDENT TK_COLON typeid  */
#line 241 "parser.y"
                                     { 
    ast_node_t* ident = ast_create_ident(strdup((yyvsp[-2].sym)->txt), scope_current(), yylloc.first_line, yylloc.first_column);
    ast_node_t* typefields = ast_create_typefields(ident, (yyvsp[0].ast));
    (yyval.ast) = typefields;
  }
#line 2041 "parser.tab.c"
    break;

  case 62: /* typefields: typefields TK_COMMA TK_IDENT TK_COLON typeid  */
#line 246 "parser.y"
                                                 {
    ast_node_t* ident = ast_create_ident(strdup((yyvsp[-2].sym)->txt), scope_current(), yylloc.first_line, yylloc.first_column);
    ast_node_t* typefields = ast_create_typefields(ident, (yyvsp[0].ast));
    ast_append_typefields((yyvsp[-4].ast), typefields);
    (yyval.ast) = (yyvsp[-4].ast);
  }
#line 2052 "parser.tab.c"
    break;

  case 63: /* typefields: %empty  */
#line 252 "parser.y"
                  { (yyval.ast) = NULL; }
#line 2058 "parser.tab.c"
    break;


#line 2062 "parser.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yytoken, &yylloc};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
    }

  yyerror_range[1] = yylloc;
  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, &yylloc);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  ++yylsp;
  YYLLOC_DEFAULT (*yylsp, yyerror_range, 2);

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 255 "parser.y"

