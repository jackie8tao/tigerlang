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
#include <stxtree.h>
#include <scope.h>
#include <symdict.h>

void yyerror(const char* msg)
{
    errmsg(msg);
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
  YYSYMBOL_PREFER = 49,                    /* PREFER  */
  YYSYMBOL_YYACCEPT = 50,                  /* $accept  */
  YYSYMBOL_stmt = 51,                      /* stmt  */
  YYSYMBOL_entersc = 52,                   /* entersc  */
  YYSYMBOL_leavesc = 53,                   /* leavesc  */
  YYSYMBOL_expr = 54,                      /* expr  */
  YYSYMBOL_exprsfx = 55,                   /* exprsfx  */
  YYSYMBOL_primaryexpr = 56,               /* primaryexpr  */
  YYSYMBOL_exprseq = 57,                   /* exprseq  */
  YYSYMBOL_exprseqsfx = 58,                /* exprseqsfx  */
  YYSYMBOL_exprlist = 59,                  /* exprlist  */
  YYSYMBOL_exprlistsfx = 60,               /* exprlistsfx  */
  YYSYMBOL_fieldlist = 61,                 /* fieldlist  */
  YYSYMBOL_fieldlistsfx = 62,              /* fieldlistsfx  */
  YYSYMBOL_lvalue = 63,                    /* lvalue  */
  YYSYMBOL_indexlist = 64,                 /* indexlist  */
  YYSYMBOL_index = 65,                     /* index  */
  YYSYMBOL_declist = 66,                   /* declist  */
  YYSYMBOL_dec = 67,                       /* dec  */
  YYSYMBOL_typedec = 68,                   /* typedec  */
  YYSYMBOL_typeval = 69,                   /* typeval  */
  YYSYMBOL_typeid = 70,                    /* typeid  */
  YYSYMBOL_vardec = 71,                    /* vardec  */
  YYSYMBOL_funcdec = 72,                   /* funcdec  */
  YYSYMBOL_typefields = 73,                /* typefields  */
  YYSYMBOL_typefieldsfx = 74,              /* typefieldsfx  */
  YYSYMBOL_typefield = 75,                 /* typefield  */
  YYSYMBOL_binoper = 76                    /* binoper  */
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
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  29
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   148

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  50
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  72
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  152

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   304


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
      45,    46,    47,    48,    49
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    80,    80,    86,    87,    89,    94,    99,   104,   105,
     106,   107,   110,   115,   121,   132,   135,   147,   162,   170,
     181,   189,   207,   208,   221,   225,   228,   234,   237,   241,
     244,   250,   253,   266,   279,   282,   292,   296,   299,   308,
     315,   319,   322,   323,   324,   327,   337,   338,   343,   352,
     358,   359,   362,   374,   389,   409,   428,   432,   435,   441,
     444,   456,   457,   458,   459,   460,   461,   462,   463,   464,
     465,   466,   467
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
  "PREFER", "$accept", "stmt", "entersc", "leavesc", "expr", "exprsfx",
  "primaryexpr", "exprseq", "exprseqsfx", "exprlist", "exprlistsfx",
  "fieldlist", "fieldlistsfx", "lvalue", "indexlist", "index", "declist",
  "dec", "typedec", "typeval", "typeid", "vardec", "funcdec", "typefields",
  "typefieldsfx", "typefield", "binoper", YY_NULLPTR
  };
  return yy_sname[yysymbol];
}
#endif

#define YYPACT_NINF (-94)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      16,   -94,   -94,   -94,   -94,   -94,   -94,    16,    16,    39,
     -94,   -94,    12,   -94,    86,   -25,    64,    16,    16,   -24,
      -2,    13,   -94,    16,    16,    -5,     2,   -94,     1,   -94,
     -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,
     -94,   -94,   -94,    16,    16,     5,    -3,   -94,    15,    64,
     -94,   -94,   -94,    23,    28,    10,    16,   -94,   -94,    36,
      33,    32,    31,    43,   -94,    16,   -94,   -94,   -94,   -18,
     -94,   -94,   -94,    38,    24,    16,   -94,    16,    16,    16,
      -2,    16,   -94,   -94,    63,    16,   -94,    52,    -3,    16,
       8,    57,    73,    68,   -94,    65,   -94,    36,    16,    66,
     -94,    46,   -94,    74,    47,   -94,   -94,    47,   -94,    16,
     -94,   -94,    16,   -94,   -94,    48,   -94,    16,    -3,    71,
      61,    75,    69,   -94,   -94,    78,    67,   -94,   -94,    -3,
     -94,    47,   -94,    -7,   -94,    16,    16,   -94,    75,    -3,
      16,   -94,    66,   -94,    70,   -94,   -94,   -94,    16,   -94,
     -94,   -94
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    10,     3,     3,    22,     3,     3,    25,     0,    37,
       9,     8,     0,     2,     7,    11,    41,     0,     0,     0,
      27,     0,    12,    29,     0,     0,     0,    35,    37,     1,
      61,    63,    62,    64,    65,    66,    67,    69,    68,    70,
      71,    72,     5,     0,     0,     0,     0,     3,     0,    41,
      42,    43,    44,     0,     0,     0,     0,    24,    15,    31,
       0,     0,     0,     0,    38,     0,    36,     6,    13,     0,
      50,    51,    49,     0,     0,    25,    40,     0,     0,     0,
      27,     0,    28,    14,    39,     0,    16,     0,     0,     0,
       0,     0,     0,     4,     4,     0,    26,    31,     0,    34,
      39,     0,    52,     0,    57,    45,    46,    57,     4,     0,
      18,    20,     0,    30,    17,     0,    32,     0,     0,     0,
       0,    59,     0,    23,     4,     0,     0,    53,    48,     0,
      47,     0,    56,     0,    19,     0,     0,    60,    59,     0,
       0,     4,    34,    58,     0,     4,    21,    33,     0,    55,
       4,    54
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -94,   -94,     4,   -93,     0,   -94,   -94,    25,    19,   -94,
       7,   -94,   -41,   -94,    77,   -94,    53,   -94,   -94,   -94,
     -84,   -94,   -94,     3,   -31,   -23,   -94
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    12,    16,   110,    20,    42,    14,    21,    57,    60,
      82,    63,   116,    15,    27,    28,    48,    49,    50,   105,
      73,    51,    52,   120,   132,   121,    43
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      13,   111,    70,    71,   101,    88,   106,    17,    22,    18,
      19,   103,    29,    70,    71,   123,   139,    53,    54,    44,
       1,    55,    56,    59,    61,     2,    89,    75,    65,   140,
       3,   134,    26,     4,   128,     5,     6,   104,    77,    58,
      62,     7,    72,    67,    68,   137,    78,    64,   146,     8,
      69,    74,   149,    72,    79,   144,    80,   151,    81,    83,
      84,     9,    10,    11,    23,    87,    24,    85,    25,    91,
      26,    45,    46,    86,    90,    47,    98,    93,    94,    95,
     100,    97,   107,   108,   109,    99,   112,   118,   115,   102,
     117,   130,   119,   126,   129,   133,   135,   131,   114,    96,
      92,   147,    76,   136,   113,    66,   148,   143,   138,   124,
     122,     0,   125,     0,     0,     0,     0,   127,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
       0,     0,     0,     0,     0,   141,   142,     0,     0,     0,
     145,     0,     0,     0,     0,     0,     0,     0,   150
};

static const yytype_int16 yycheck[] =
{
       0,    94,     5,     6,    88,    23,    90,     3,     8,     5,
       6,     3,     0,     5,     6,   108,    23,    17,    18,    44,
       4,    45,    24,    23,    24,     9,    44,    12,    27,    36,
      14,   124,    31,    17,   118,    19,    20,    29,    15,    26,
      45,    25,    45,    43,    44,   129,    18,    45,   141,    33,
      45,    47,   145,    45,    44,   139,    56,   150,    22,    26,
      28,    45,    46,    47,    25,    65,    27,    36,    29,    45,
      31,     7,     8,    30,    36,    11,    13,    77,    78,    79,
      28,    81,    25,    10,    16,    85,    21,    13,    22,    89,
      44,    30,    45,    45,    23,    26,    18,    22,    98,    80,
      75,   142,    49,    36,    97,    28,    36,   138,   131,   109,
     107,    -1,   112,    -1,    -1,    -1,    -1,   117,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      -1,    -1,    -1,    -1,    -1,   135,   136,    -1,    -1,    -1,
     140,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   148
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     4,     9,    14,    17,    19,    20,    25,    33,    45,
      46,    47,    51,    54,    56,    63,    52,    52,    52,    52,
      54,    57,    54,    25,    27,    29,    31,    64,    65,     0,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    55,    76,    44,     7,     8,    11,    66,    67,
      68,    71,    72,    54,    54,    45,    24,    58,    26,    54,
      59,    54,    45,    61,    45,    27,    64,    54,    54,    45,
       5,     6,    45,    70,    52,    12,    66,    15,    18,    44,
      54,    22,    60,    26,    28,    36,    30,    54,    23,    44,
      36,    45,    57,    54,    54,    54,    58,    54,    13,    54,
      28,    70,    54,     3,    29,    69,    70,    25,    10,    16,
      53,    53,    21,    60,    54,    22,    62,    44,    13,    45,
      73,    75,    73,    53,    54,    54,    45,    54,    70,    23,
      30,    22,    74,    26,    53,    18,    36,    70,    75,    23,
      36,    54,    54,    74,    70,    54,    53,    62,    36,    53,
      54,    53
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    50,    51,    52,    53,    54,    55,    55,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    56,
      56,    56,    56,    56,    57,    57,    58,    58,    59,    59,
      60,    60,    61,    62,    62,    63,    64,    64,    65,    65,
      66,    66,    67,    67,    67,    68,    69,    69,    69,    70,
      70,    70,    71,    71,    72,    72,    73,    73,    74,    74,
      75,    76,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    76
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     0,     2,     2,     0,     1,     1,
       1,     1,     2,     3,     4,     3,     4,     6,     6,     8,
       6,    10,     1,     7,     2,     0,     3,     0,     2,     0,
       3,     0,     4,     5,     0,     2,     2,     0,     2,     3,
       2,     0,     1,     1,     1,     4,     1,     3,     3,     1,
       1,     1,     4,     6,    11,     9,     2,     0,     3,     0,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1
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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
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
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
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
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
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
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
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

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

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

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
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
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* stmt: expr  */
#line 80 "parser.y"
           {
    (yyval.ast) = (yyvsp[0].ast);
    stxtree_t* gtree = stxtree_get();
    gtree->root = (yyval.ast);
}
#line 1474 "parser.tab.c"
    break;

  case 3: /* entersc: %empty  */
#line 86 "parser.y"
                       { scope_create(); }
#line 1480 "parser.tab.c"
    break;

  case 4: /* leavesc: %empty  */
#line 87 "parser.y"
                       { scope_close(); }
#line 1486 "parser.tab.c"
    break;

  case 5: /* expr: primaryexpr exprsfx  */
#line 89 "parser.y"
                          {
    stxtree_append_node((yyvsp[-1].ast), (yyvsp[0].ast));
    (yyval.ast) = (yyvsp[-1].ast);
}
#line 1495 "parser.tab.c"
    break;

  case 6: /* exprsfx: binoper expr  */
#line 94 "parser.y"
                      { 
    stxnode_t* opnode = (yyvsp[-1].ast);
    stxtree_append_node(opnode, (yyvsp[0].ast));
    (yyval.ast) = opnode;
 }
#line 1505 "parser.tab.c"
    break;

  case 7: /* exprsfx: %empty  */
#line 99 "parser.y"
                    {
        (yyval.ast) = stxtree_create_node(YYEMPTY);
    }
#line 1513 "parser.tab.c"
    break;

  case 8: /* primaryexpr: TK_STRING  */
#line 104 "parser.y"
                        { (yyval.ast) = stxtree_create_string_node((yyvsp[0].sval)); }
#line 1519 "parser.tab.c"
    break;

  case 9: /* primaryexpr: TK_INTEGER  */
#line 105 "parser.y"
                 { (yyval.ast) = stxtree_create_integer_node((yyvsp[0].ival)); }
#line 1525 "parser.tab.c"
    break;

  case 10: /* primaryexpr: TK_NIL  */
#line 106 "parser.y"
             { (yyval.ast) = stxtree_create_node(TK_NIL); }
#line 1531 "parser.tab.c"
    break;

  case 11: /* primaryexpr: lvalue  */
#line 107 "parser.y"
             {
        (yyval.ast) = (yyvsp[0].ast);
    }
#line 1539 "parser.tab.c"
    break;

  case 12: /* primaryexpr: TK_MINUS expr  */
#line 110 "parser.y"
                                 { 
        stxnode_t* msnode = stxtree_create_node(TK_MINUS);
        stxtree_append_node(msnode, (yyvsp[0].ast));
        (yyval.ast) = msnode;
    }
#line 1549 "parser.tab.c"
    break;

  case 13: /* primaryexpr: lvalue TK_ASSIGN expr  */
#line 115 "parser.y"
                            {
        stxnode_t* assnode = stxtree_create_node(TK_ASSIGN);
        stxtree_append_node(assnode, (yyvsp[-2].ast));
        stxtree_append_node(assnode, (yyvsp[0].ast));
        (yyval.ast) = assnode;
    }
#line 1560 "parser.tab.c"
    break;

  case 14: /* primaryexpr: TK_IDENT TK_LPAREN exprlist TK_RPAREN  */
#line 121 "parser.y"
                                            {
        stxnode_t* idnode = stxtree_create_ident_node((yyvsp[-3].sym)->txt);
        scope_t* sc = scope_current();
        idnode->sc = sc;
        stxnode_t* lparen = stxtree_create_node(TK_LPAREN);
        stxnode_t* rparen = stxtree_create_node(TK_RPAREN);
        stxtree_append_node(idnode, lparen);
        stxtree_append_node(idnode, (yyvsp[-1].ast));
        stxtree_append_node(idnode, rparen);
        (yyval.ast) = idnode;
    }
#line 1576 "parser.tab.c"
    break;

  case 15: /* primaryexpr: TK_LPAREN exprseq TK_RPAREN  */
#line 132 "parser.y"
                                  {
        (yyval.ast) = (yyvsp[-1].ast); // 这里有点问题
    }
#line 1584 "parser.tab.c"
    break;

  case 16: /* primaryexpr: TK_IDENT TK_LBRACE fieldlist TK_RBRACE  */
#line 135 "parser.y"
                                             {
        stxnode_t* idnode = stxtree_create_ident_node((yyvsp[-3].sym)->txt);
        scope_t* sc = scope_current();
        scope_add_sym(sc, (yyvsp[-3].sym));
        idnode->sc = sc;
        stxnode_t* lbrace = stxtree_create_node(TK_LBRACE);
        stxnode_t* rbrace = stxtree_create_node(TK_RBRACE);
        stxtree_append_node(idnode, lbrace);
        stxtree_append_node(idnode, (yyvsp[-1].ast));
        stxtree_append_node(idnode, rbrace);
        (yyval.ast) = idnode;
    }
#line 1601 "parser.tab.c"
    break;

  case 17: /* primaryexpr: TK_IDENT TK_LBRACKET expr TK_RBRACKET TK_OF expr  */
#line 147 "parser.y"
                                                       {
        stxnode_t* idnode = stxtree_create_ident_node((yyvsp[-5].sym)->txt);
        scope_t* sc = scope_current();
        scope_add_sym(sc, (yyvsp[-5].sym));
        idnode->sc = sc;
        stxnode_t* lbracket = stxtree_create_node(TK_LBRACKET);
        stxnode_t* rbracket = stxtree_create_node(TK_RBRACKET);
        stxnode_t* ofnode = stxtree_create_node(TK_OF);
        stxtree_append_node(idnode, lbracket);
        stxtree_append_node(idnode, (yyvsp[-3].ast));
        stxtree_append_node(idnode, rbracket);
        stxtree_append_node(idnode, ofnode);
        stxtree_append_node(idnode, (yyvsp[0].ast));
        (yyval.ast) = idnode;
    }
#line 1621 "parser.tab.c"
    break;

  case 18: /* primaryexpr: TK_IF entersc expr TK_THEN expr leavesc  */
#line 162 "parser.y"
                                              {
        stxnode_t* ifnode = stxtree_create_node(TK_IF);
        stxnode_t* thnode = stxtree_create_node(TK_THEN);
        stxtree_append_node(thnode, (yyvsp[-1].ast));
        stxtree_append_node(ifnode, (yyvsp[-3].ast));
        stxtree_append_node(ifnode, thnode);
        (yyval.ast) = ifnode;
    }
#line 1634 "parser.tab.c"
    break;

  case 19: /* primaryexpr: TK_IF entersc expr TK_THEN expr TK_ELSE expr leavesc  */
#line 170 "parser.y"
                                                           {
        stxnode_t* ifnode = stxtree_create_node(TK_IF);
        stxnode_t* thnode = stxtree_create_node(TK_THEN);
        stxnode_t* elnode = stxtree_create_node(TK_ELSE);
        stxtree_append_node(elnode, (yyvsp[-1].ast));
        stxtree_append_node(thnode, (yyvsp[-3].ast));
        stxtree_append_node(ifnode, (yyvsp[-5].ast));
        stxtree_append_node(ifnode, thnode);
        stxtree_append_node(ifnode, elnode);
        (yyval.ast) = ifnode;
    }
#line 1650 "parser.tab.c"
    break;

  case 20: /* primaryexpr: TK_WHILE entersc expr TK_DO expr leavesc  */
#line 181 "parser.y"
                                               {
        stxnode_t* whnode = stxtree_create_node(TK_WHILE);
        stxnode_t* donode = stxtree_create_node(TK_DO);
        stxtree_append_node(whnode, (yyvsp[-3].ast));
        stxtree_append_node(donode, (yyvsp[-1].ast));
        stxtree_append_node(whnode, donode);
        (yyval.ast) = whnode;
    }
#line 1663 "parser.tab.c"
    break;

  case 21: /* primaryexpr: TK_FOR entersc TK_IDENT TK_ASSIGN expr TK_TO expr TK_DO expr leavesc  */
#line 189 "parser.y"
                                                                           {
        stxnode_t* fornode = stxtree_create_node(TK_FOR);
        stxnode_t* assnode = stxtree_create_node(TK_ASSIGN);
        stxnode_t* idnode = stxtree_create_ident_node((yyvsp[-7].sym)->txt);
        scope_t* cur_sc = scope_current();
        scope_add_sym(cur_sc, (yyvsp[-7].sym));
        idnode->sc = scope_current();
        stxnode_t* tonode = stxtree_create_node(TK_TO);
        stxtree_append_node(tonode, (yyvsp[-5].ast));
        stxtree_append_node(tonode, (yyvsp[-3].ast));
        stxtree_append_node(assnode, idnode);
        stxtree_append_node(assnode, tonode);
        stxnode_t* donode = stxtree_create_node(TK_DO);
        stxtree_append_node(donode, (yyvsp[-1].ast));
        stxtree_append_node(fornode, assnode);
        stxtree_append_node(fornode, donode);
        (yyval.ast) = fornode;
    }
#line 1686 "parser.tab.c"
    break;

  case 22: /* primaryexpr: TK_BREAK  */
#line 207 "parser.y"
               { (yyval.ast) = stxtree_create_node(TK_BREAK); }
#line 1692 "parser.tab.c"
    break;

  case 23: /* primaryexpr: TK_LET entersc declist TK_IN exprseq TK_END leavesc  */
#line 208 "parser.y"
                                                          {
        stxnode_t* letnode = stxtree_create_node(TK_LET);
        stxnode_t* innode = stxtree_create_node(TK_IN);
        stxnode_t* endnode = stxtree_create_node(TK_END);
        stxtree_append_node(letnode, (yyvsp[-4].ast));
        stxtree_append_node(letnode, innode);
        stxtree_append_node(letnode, (yyvsp[-2].ast));
        stxtree_append_node(letnode, endnode);
        (yyval.ast) = letnode;
    }
#line 1707 "parser.tab.c"
    break;

  case 24: /* exprseq: expr exprseqsfx  */
#line 221 "parser.y"
                         {
    stxtree_append_node((yyvsp[-1].ast), (yyvsp[0].ast));
    (yyval.ast) = (yyvsp[-1].ast);
}
#line 1716 "parser.tab.c"
    break;

  case 25: /* exprseq: %empty  */
#line 225 "parser.y"
                    { (yyval.ast) = stxtree_create_node(YYEMPTY); }
#line 1722 "parser.tab.c"
    break;

  case 26: /* exprseqsfx: TK_SEMICOLON expr exprseqsfx  */
#line 228 "parser.y"
                                         {
    stxnode_t* scnode = stxtree_create_node(TK_SEMICOLON);
    stxtree_append_node((yyvsp[-1].ast), (yyvsp[0].ast));
    stxtree_append_node(scnode, (yyvsp[-1].ast));
    (yyval.ast) = scnode;
}
#line 1733 "parser.tab.c"
    break;

  case 27: /* exprseqsfx: %empty  */
#line 234 "parser.y"
                    { (yyval.ast) = stxtree_create_node(YYEMPTY); }
#line 1739 "parser.tab.c"
    break;

  case 28: /* exprlist: expr exprlistsfx  */
#line 237 "parser.y"
                           {
    stxtree_append_node((yyvsp[-1].ast), (yyvsp[0].ast));
    (yyval.ast) = (yyvsp[-1].ast);
}
#line 1748 "parser.tab.c"
    break;

  case 29: /* exprlist: %empty  */
#line 241 "parser.y"
                    { (yyval.ast) = stxtree_create_node(YYEMPTY); }
#line 1754 "parser.tab.c"
    break;

  case 30: /* exprlistsfx: TK_COMMA expr exprlistsfx  */
#line 244 "parser.y"
                                       {
    stxnode_t* cmnode = stxtree_create_node(TK_COMMA);
    stxtree_append_node((yyvsp[-1].ast), (yyvsp[0].ast));
    stxtree_append_node(cmnode, (yyvsp[-1].ast));
    (yyval.ast) = cmnode;
}
#line 1765 "parser.tab.c"
    break;

  case 31: /* exprlistsfx: %empty  */
#line 250 "parser.y"
                    { (yyval.ast) = stxtree_create_node(YYEMPTY); }
#line 1771 "parser.tab.c"
    break;

  case 32: /* fieldlist: TK_IDENT TK_EQU expr fieldlistsfx  */
#line 253 "parser.y"
                                             {
    stxtree_append_node((yyvsp[-1].ast), (yyvsp[0].ast));
    stxnode_t* equnode = stxtree_create_node(TK_EQU);
    stxnode_t* idnode = stxtree_create_ident_node((yyvsp[-3].sym)->txt);
    scope_t* sc = scope_current();
    scope_add_sym(sc, (yyvsp[-3].sym));
    idnode->sc = sc;
    stxtree_append_node(equnode, idnode);
    stxtree_append_node(equnode, (yyvsp[-1].ast));
    (yyval.ast) = equnode;
}
#line 1787 "parser.tab.c"
    break;

  case 33: /* fieldlistsfx: TK_COMMA TK_IDENT TK_EQU expr fieldlistsfx  */
#line 266 "parser.y"
                                                         {
    stxnode_t* cmnode = stxtree_create_node(TK_COMMA);
    stxnode_t* idnode = stxtree_create_ident_node((yyvsp[-3].sym)->txt);
    stxnode_t* equnode = stxtree_create_node(TK_EQU);
    scope_t* sc = scope_current();
    scope_add_sym(sc, (yyvsp[-3].sym));
    idnode->sc = sc;
    stxtree_append_node((yyvsp[-1].ast), (yyvsp[0].ast));
    stxtree_append_node(equnode, idnode);
    stxtree_append_node(equnode, (yyvsp[-1].ast));
    stxtree_append_node(cmnode, equnode);
    (yyval.ast) = cmnode;
}
#line 1805 "parser.tab.c"
    break;

  case 34: /* fieldlistsfx: %empty  */
#line 279 "parser.y"
                    {  (yyval.ast) = stxtree_create_node(YYEMPTY); }
#line 1811 "parser.tab.c"
    break;

  case 35: /* lvalue: TK_IDENT indexlist  */
#line 282 "parser.y"
                           {
    stxnode_t* idnode = stxtree_create_ident_node((yyvsp[-1].sym)->txt);
    scope_t* sc = scope_current();
    scope_add_sym(sc, (yyvsp[-1].sym));
    idnode->sc = sc;
    stxtree_append_node(idnode, (yyvsp[0].ast));
    (yyval.ast) = idnode;
}
#line 1824 "parser.tab.c"
    break;

  case 36: /* indexlist: index indexlist  */
#line 292 "parser.y"
                           {
    stxtree_append_node((yyvsp[-1].ast), (yyvsp[0].ast));
    (yyval.ast) = (yyvsp[-1].ast);
}
#line 1833 "parser.tab.c"
    break;

  case 37: /* indexlist: %empty  */
#line 296 "parser.y"
                    {  (yyval.ast) = stxtree_create_node(YYEMPTY); }
#line 1839 "parser.tab.c"
    break;

  case 38: /* index: TK_DOT TK_IDENT  */
#line 299 "parser.y"
                       {
    stxnode_t* dotnode = stxtree_create_node(TK_DOT);
    stxnode_t* idnode = stxtree_create_ident_node((yyvsp[0].sym)->txt);
    scope_t* sc = scope_current();
    scope_add_sym(sc, (yyvsp[0].sym));
    idnode->sc = sc;
    stxtree_append_node(dotnode, idnode);
    (yyval.ast) = dotnode;
}
#line 1853 "parser.tab.c"
    break;

  case 39: /* index: TK_LBRACKET expr TK_RBRACKET  */
#line 308 "parser.y"
                                   {
        stxnode_t* lbracket = stxtree_create_node(TK_LBRACKET);
        stxtree_append_node(lbracket, (yyvsp[-1].ast));
        (yyval.ast) = lbracket;
    }
#line 1863 "parser.tab.c"
    break;

  case 40: /* declist: dec declist  */
#line 315 "parser.y"
                     {
    stxtree_append_node((yyvsp[-1].ast), (yyvsp[0].ast));
    (yyval.ast) = (yyvsp[-1].ast);
}
#line 1872 "parser.tab.c"
    break;

  case 41: /* declist: %empty  */
#line 319 "parser.y"
                    { (yyval.ast) = stxtree_create_node(YYEMPTY); }
#line 1878 "parser.tab.c"
    break;

  case 42: /* dec: typedec  */
#line 322 "parser.y"
             { (yyval.ast) = (yyvsp[0].ast); }
#line 1884 "parser.tab.c"
    break;

  case 43: /* dec: vardec  */
#line 323 "parser.y"
             { (yyval.ast) = (yyvsp[0].ast); }
#line 1890 "parser.tab.c"
    break;

  case 44: /* dec: funcdec  */
#line 324 "parser.y"
              { (yyval.ast) = (yyvsp[0].ast); }
#line 1896 "parser.tab.c"
    break;

  case 45: /* typedec: TK_TYPE typeid TK_EQU typeval  */
#line 327 "parser.y"
                                       {
    stxnode_t* typenode = stxtree_create_node(TK_TYPE);
    stxnode_t* equnode = stxtree_create_node(TK_EQU);
    stxtree_append_node(equnode, (yyvsp[0].ast));
    stxtree_append_node(equnode, (yyvsp[-2].ast));
    stxtree_append_node(typenode, equnode);
    (yyval.ast) = typenode;
}
#line 1909 "parser.tab.c"
    break;

  case 46: /* typeval: typeid  */
#line 337 "parser.y"
                { (yyval.ast) = (yyvsp[0].ast); }
#line 1915 "parser.tab.c"
    break;

  case 47: /* typeval: TK_LBRACE typefields TK_RBRACE  */
#line 338 "parser.y"
                                     {
        stxnode_t* lbrace = stxtree_create_node(TK_LBRACE);
        stxtree_append_node(lbrace, (yyvsp[-1].ast));
        (yyval.ast) = lbrace;
    }
#line 1925 "parser.tab.c"
    break;

  case 48: /* typeval: TK_ARRAY TK_OF typeid  */
#line 343 "parser.y"
                            {
        stxnode_t* arraynode = stxtree_create_node(TK_ARRAY);
        stxnode_t* ofnode = stxtree_create_node(TK_OF);
        stxtree_append_node(ofnode, (yyvsp[0].ast));
        stxtree_append_node(arraynode, ofnode);
        (yyval.ast) = arraynode;
    }
#line 1937 "parser.tab.c"
    break;

  case 49: /* typeid: TK_IDENT  */
#line 352 "parser.y"
                 { 
  stxnode_t* idnode = stxtree_create_ident_node((yyvsp[0].sym)->txt); 
  scope_t* sc = scope_current();
  scope_add_sym(sc, (yyvsp[0].sym));
  idnode->sc = sc;
}
#line 1948 "parser.tab.c"
    break;

  case 50: /* typeid: TK_INT  */
#line 358 "parser.y"
             { (yyval.ast) = stxtree_create_node(TK_INT); }
#line 1954 "parser.tab.c"
    break;

  case 51: /* typeid: TK_STR  */
#line 359 "parser.y"
             { (yyval.ast) = stxtree_create_node(TK_STR); }
#line 1960 "parser.tab.c"
    break;

  case 52: /* vardec: TK_VAR TK_IDENT TK_ASSIGN expr  */
#line 362 "parser.y"
                                       {
    stxnode_t* varnode = stxtree_create_node(TK_VAR);
    stxnode_t* idnode = stxtree_create_ident_node((yyvsp[-2].sym)->txt);
    scope_t* sc = scope_current();
    scope_add_sym(sc, (yyvsp[-2].sym));
    idnode->sc = sc;
    stxnode_t* assnode = stxtree_create_node(TK_ASSIGN);
    stxtree_append_node(assnode, idnode);
    stxtree_append_node(assnode, (yyvsp[0].ast));
    stxtree_append_node(varnode, assnode);
    (yyval.ast) = varnode;
}
#line 1977 "parser.tab.c"
    break;

  case 53: /* vardec: TK_VAR TK_IDENT TK_COLON typeid TK_ASSIGN expr  */
#line 374 "parser.y"
                                                     {
        stxnode_t* varnode = stxtree_create_node(TK_VAR);
        stxnode_t* idnode = stxtree_create_ident_node((yyvsp[-4].sym)->txt);
        scope_t* sc = scope_current();
        scope_add_sym(sc, (yyvsp[-4].sym));
        idnode->sc = sc;
        stxnode_t* assnode = stxtree_create_node(TK_ASSIGN);
        stxtree_append_node(idnode, (yyvsp[-2].ast));
        stxtree_append_node(assnode, idnode);
        stxtree_append_node(assnode, (yyvsp[0].ast));
        stxtree_append_node(varnode, assnode);
        (yyval.ast) = varnode;
    }
#line 1995 "parser.tab.c"
    break;

  case 54: /* funcdec: TK_FUNCTION entersc TK_IDENT TK_LPAREN typefields TK_RPAREN TK_COLON typeid TK_EQU expr leavesc  */
#line 389 "parser.y"
                                                                                                         {
    stxnode_t* fnnode = stxtree_create_node(TK_FUNCTION);
    stxnode_t* idnode = stxtree_create_ident_node((yyvsp[-8].sym)->txt);
    scope_t* sc = scope_current();
    scope_add_sym(sc, (yyvsp[-8].sym));
    idnode->sc = sc;
    stxnode_t* lparen = stxtree_create_node(TK_LPAREN);
    stxnode_t* rparen = stxtree_create_node(TK_RPAREN);
    stxnode_t* clnode = stxtree_create_node(TK_COLON);
    stxnode_t* equnode = stxtree_create_node(TK_EQU);
    stxtree_append_node(clnode, (yyvsp[-3].ast));
    stxtree_append_node(equnode, (yyvsp[-1].ast));
    stxtree_append_node(fnnode, idnode);
    stxtree_append_node(fnnode, lparen);
    stxtree_append_node(fnnode, (yyvsp[-6].ast));
    stxtree_append_node(fnnode, rparen);
    stxtree_append_node(fnnode, clnode);
    stxtree_append_node(fnnode, equnode);
    (yyval.ast) = fnnode;
}
#line 2020 "parser.tab.c"
    break;

  case 55: /* funcdec: TK_FUNCTION entersc TK_IDENT TK_LPAREN typefields TK_RPAREN TK_EQU expr leavesc  */
#line 409 "parser.y"
                                                                                      {
        stxnode_t* fnnode = stxtree_create_node(TK_FUNCTION);
        stxnode_t* idnode = stxtree_create_ident_node((yyvsp[-6].sym)->txt);
        scope_t* sc = scope_current();
        scope_add_sym(sc, (yyvsp[-6].sym));
        idnode->sc = sc;
        stxnode_t* lparen = stxtree_create_node(TK_LPAREN);
        stxnode_t* rparen = stxtree_create_node(TK_RPAREN);
        stxnode_t* equnode = stxtree_create_node(TK_EQU);
        stxtree_append_node(equnode, (yyvsp[-1].ast));
        stxtree_append_node(fnnode, idnode);
        stxtree_append_node(fnnode, lparen);
        stxtree_append_node(fnnode, (yyvsp[-4].ast));
        stxtree_append_node(fnnode, rparen);
        stxtree_append_node(fnnode, equnode);
        (yyval.ast) = fnnode;
    }
#line 2042 "parser.tab.c"
    break;

  case 56: /* typefields: typefield typefieldsfx  */
#line 428 "parser.y"
                                   {
    stxtree_append_node((yyvsp[-1].ast), (yyvsp[0].ast));
    (yyval.ast) = (yyvsp[-1].ast);
}
#line 2051 "parser.tab.c"
    break;

  case 57: /* typefields: %empty  */
#line 432 "parser.y"
                    { (yyval.ast) = stxtree_create_node(YYEMPTY); }
#line 2057 "parser.tab.c"
    break;

  case 58: /* typefieldsfx: TK_COMMA typefield typefieldsfx  */
#line 435 "parser.y"
                                              {
    stxnode_t* cmnode = stxtree_create_node(TK_COMMA);
    stxtree_append_node((yyvsp[-1].ast), (yyvsp[0].ast));
    stxtree_append_node(cmnode, (yyvsp[-1].ast));
    (yyval.ast) = cmnode;
}
#line 2068 "parser.tab.c"
    break;

  case 59: /* typefieldsfx: %empty  */
#line 441 "parser.y"
                    { (yyval.ast) = stxtree_create_node(YYEMPTY); }
#line 2074 "parser.tab.c"
    break;

  case 60: /* typefield: TK_IDENT TK_COLON typeid  */
#line 444 "parser.y"
                                    {
    stxnode_t* idnode = stxtree_create_ident_node((yyvsp[-2].sym)->txt);
    scope_t* sc = scope_current();
    scope_add_sym(sc, (yyvsp[-2].sym));
    idnode->sc = sc;
    stxnode_t* clnode = stxtree_create_node(TK_COLON);
    stxtree_append_node(clnode, (yyvsp[0].ast));
    stxtree_append_node(idnode, clnode);
    (yyval.ast) = idnode;
}
#line 2089 "parser.tab.c"
    break;

  case 61: /* binoper: TK_PLUS  */
#line 456 "parser.y"
                 { (yyval.ast) = stxtree_create_node(TK_PLUS); }
#line 2095 "parser.tab.c"
    break;

  case 62: /* binoper: TK_MULTI  */
#line 457 "parser.y"
               { (yyval.ast) = stxtree_create_node(TK_MULTI); }
#line 2101 "parser.tab.c"
    break;

  case 63: /* binoper: TK_MINUS  */
#line 458 "parser.y"
               { (yyval.ast) = stxtree_create_node(TK_MINUS); }
#line 2107 "parser.tab.c"
    break;

  case 64: /* binoper: TK_DIV  */
#line 459 "parser.y"
             { (yyval.ast) = stxtree_create_node(TK_DIV); }
#line 2113 "parser.tab.c"
    break;

  case 65: /* binoper: TK_EQU  */
#line 460 "parser.y"
             { (yyval.ast) = stxtree_create_node(TK_EQU); }
#line 2119 "parser.tab.c"
    break;

  case 66: /* binoper: TK_NEQU  */
#line 461 "parser.y"
              { (yyval.ast) = stxtree_create_node(TK_NEQU); }
#line 2125 "parser.tab.c"
    break;

  case 67: /* binoper: TK_LT  */
#line 462 "parser.y"
            { (yyval.ast) = stxtree_create_node(TK_LT); }
#line 2131 "parser.tab.c"
    break;

  case 68: /* binoper: TK_GT  */
#line 463 "parser.y"
            { (yyval.ast) = stxtree_create_node(TK_GT); }
#line 2137 "parser.tab.c"
    break;

  case 69: /* binoper: TK_LEQU  */
#line 464 "parser.y"
              { (yyval.ast) = stxtree_create_node(TK_LEQU); }
#line 2143 "parser.tab.c"
    break;

  case 70: /* binoper: TK_GEQU  */
#line 465 "parser.y"
              { (yyval.ast) = stxtree_create_node(TK_GEQU); }
#line 2149 "parser.tab.c"
    break;

  case 71: /* binoper: TK_AND  */
#line 466 "parser.y"
             { (yyval.ast) = stxtree_create_node(TK_AND); }
#line 2155 "parser.tab.c"
    break;

  case 72: /* binoper: TK_OR  */
#line 467 "parser.y"
            { (yyval.ast) = stxtree_create_node(TK_OR); }
#line 2161 "parser.tab.c"
    break;


#line 2165 "parser.tab.c"

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
          = {yyssp, yytoken};
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
                      yytoken, &yylval);
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


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
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

#line 470 "parser.y"

