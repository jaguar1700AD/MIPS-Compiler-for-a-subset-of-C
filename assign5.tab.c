/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "assign5.y" /* yacc.c:339  */

#include <stdio.h>	
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "symbol_table.h"
#include "expressions.h"
#include "code_store.h"
#include "case_helper.h"

int type; // The current variable declaration type
struct symbol_table* table = NULL;
struct depth_type* cont;


#line 83 "assign5.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "assign5.tab.h".  */
#ifndef YY_YY_ASSIGN5_TAB_H_INCLUDED
# define YY_YY_ASSIGN5_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    TYPE_INT = 258,
    TYPE_FLOAT = 259,
    NAME = 260,
    NUM_INT = 261,
    NUM_FLOAT = 262,
    LESS = 263,
    GREATER = 264,
    EQUAL = 265,
    LESS_EQUAL = 266,
    GREATER_EQUAL = 267,
    NOT_EQUAL = 268,
    IS_EQUAL = 269,
    AND = 270,
    OR = 271,
    NOT = 272,
    PLUS = 273,
    MINUS = 274,
    MUL = 275,
    DIV = 276,
    MOD = 277,
    SEMI = 278,
    COMMA = 279,
    COLON = 280,
    LB = 281,
    RB = 282,
    LC = 283,
    RC = 284,
    KEY_MAIN = 285,
    KEY_VOID = 286,
    KEY_RETURN = 287,
    KEY_BREAK = 288,
    KEY_DEFAULT = 289,
    KEY_IF = 290,
    KEY_ELSE = 291,
    KEY_SWITCH = 292,
    KEY_CASE = 293,
    KEY_FOR = 294,
    KEY_WHILE = 295
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 19 "assign5.y" /* yacc.c:355  */

	float num_f;
	int num_i;
	char* str;
	struct exprn* EXPRN;
	struct code_store* CODE_STORE;
	struct Hcase* HCASE;
	struct Hcase_list* HCASE_LIST;

#line 174 "assign5.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_ASSIGN5_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 191 "assign5.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  22
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   213

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  18
/* YYNRULES -- Number of rules.  */
#define YYNRULES  51
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  97

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   295

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
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
      35,    36,    37,    38,    39,    40
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    63,    63,    74,    85,    92,    99,   106,   119,   130,
     130,   139,   148,   149,   153,   181,   182,   183,   184,   185,
     207,   237,   239,   238,   255,   267,   267,   269,   276,   289,
     293,   298,   298,   304,   312,   320,   328,   336,   344,   352,
     360,   368,   376,   384,   392,   400,   408,   416,   424,   432,
     440,   448
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TYPE_INT", "TYPE_FLOAT", "NAME",
  "NUM_INT", "NUM_FLOAT", "LESS", "GREATER", "EQUAL", "LESS_EQUAL",
  "GREATER_EQUAL", "NOT_EQUAL", "IS_EQUAL", "AND", "OR", "NOT", "PLUS",
  "MINUS", "MUL", "DIV", "MOD", "SEMI", "COMMA", "COLON", "LB", "RB", "LC",
  "RC", "KEY_MAIN", "KEY_VOID", "KEY_RETURN", "KEY_BREAK", "KEY_DEFAULT",
  "KEY_IF", "KEY_ELSE", "KEY_SWITCH", "KEY_CASE", "KEY_FOR", "KEY_WHILE",
  "$accept", "CASE", "DEFAULT", "CASE_LIST", "SWITCH", "$@1", "PROG",
  "STATEMENT_LIST", "STATEMENT", "BLOCK", "$@2", "ASSIGN", "DATA_TYPE",
  "VAR_DEC_ASSIGN", "VAR_DEC_ASSIGN_LIST", "VAR_DEC", "$@3", "E", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295
};
# endif

#define YYPACT_NINF -41

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-41)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      12,   -41,   -41,     0,   -10,    13,    15,    22,   -41,    59,
     -41,    12,   -41,    45,   -41,    52,    39,   -41,    12,    39,
      39,    39,   -41,   -41,   -41,    87,   -41,   -41,   -41,   -41,
      39,    39,    39,   126,    69,    58,    75,    92,    89,    85,
     -41,   156,   -16,   109,    39,    39,    39,    39,    39,    39,
      39,    39,    39,    39,    39,    39,    39,   -41,    12,    88,
      12,    39,    87,   -41,   183,     3,   191,   176,   171,   141,
     156,    42,   151,   -16,   -13,    93,   -41,    90,   -41,   -41,
     126,   -41,    12,    94,   -41,   127,    94,   117,   118,   -41,
     130,   129,    12,    12,   -41,   -41,   -41
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    25,    26,     0,    22,     0,     0,     0,    15,     0,
      11,    13,    18,     0,    31,     0,     0,    21,     0,     0,
       0,     0,     1,    12,    17,     0,    16,    51,    49,    50,
       0,     0,     0,    24,     0,     0,     0,     0,    27,    30,
      32,    46,    48,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    23,     0,     0,
       0,     0,     0,    47,    38,    39,    40,    41,    42,    43,
      44,    45,    33,    34,    35,    36,    37,    19,     9,    14,
      28,    29,     0,     0,    20,     0,     8,     6,     0,     7,
       0,     0,     3,     5,    10,     2,     4
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -41,   -41,   -41,    80,   -41,   -41,   -41,   -11,   -40,   -41,
     -41,   -41,   -41,   -41,   119,   -41,   -41,   -18
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    86,    91,    87,     8,    83,     9,    10,    11,    12,
      18,    13,    14,    39,    40,    15,    25,    33
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      23,    35,    36,    37,    54,    55,    56,    34,    55,    56,
      16,    44,    41,    42,    43,     1,     2,     3,    77,    17,
      79,    52,    53,    54,    55,    56,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    19,
       4,    20,    84,    80,    27,    28,    29,     5,    21,     6,
      44,    45,     7,    46,    47,    48,    30,    50,    31,    22,
      52,    53,    54,    55,    56,    32,    44,    45,    24,    46,
      47,    48,    49,    50,    51,    26,    52,    53,    54,    55,
      56,    95,    96,    44,    45,    58,    46,    47,    48,    49,
      50,    51,    38,    52,    53,    54,    55,    56,    57,    61,
      44,    45,    59,    46,    47,    48,    49,    50,    51,    62,
      52,    53,    54,    55,    56,    56,    78,    44,    45,    60,
      46,    47,    48,    49,    50,    51,    82,    52,    53,    54,
      55,    56,    85,    88,    44,    45,    63,    46,    47,    48,
      49,    50,    51,    92,    52,    53,    54,    55,    56,    44,
      45,    90,    46,    47,    48,    93,    50,    51,    94,    52,
      53,    54,    55,    56,    44,    45,    89,    46,    47,    48,
      53,    54,    55,    56,    52,    53,    54,    55,    56,    44,
      45,    81,    46,    47,    44,    45,     0,    46,     0,    52,
      53,    54,    55,    56,    52,    53,    54,    55,    56,    44,
      45,    52,    53,    54,    55,    56,     0,     0,     0,    52,
      53,    54,    55,    56
};

static const yytype_int8 yycheck[] =
{
      11,    19,    20,    21,    20,    21,    22,    18,    21,    22,
      10,     8,    30,    31,    32,     3,     4,     5,    58,    29,
      60,    18,    19,    20,    21,    22,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    26,
      28,    26,    82,    61,     5,     6,     7,    35,    26,    37,
       8,     9,    40,    11,    12,    13,    17,    15,    19,     0,
      18,    19,    20,    21,    22,    26,     8,     9,    23,    11,
      12,    13,    14,    15,    16,    23,    18,    19,    20,    21,
      22,    92,    93,     8,     9,    27,    11,    12,    13,    14,
      15,    16,     5,    18,    19,    20,    21,    22,    29,    10,
       8,     9,    27,    11,    12,    13,    14,    15,    16,    24,
      18,    19,    20,    21,    22,    22,    28,     8,     9,    27,
      11,    12,    13,    14,    15,    16,    36,    18,    19,    20,
      21,    22,    38,     6,     8,     9,    27,    11,    12,    13,
      14,    15,    16,    25,    18,    19,    20,    21,    22,     8,
       9,    34,    11,    12,    13,    25,    15,    16,    29,    18,
      19,    20,    21,    22,     8,     9,    86,    11,    12,    13,
      19,    20,    21,    22,    18,    19,    20,    21,    22,     8,
       9,    62,    11,    12,     8,     9,    -1,    11,    -1,    18,
      19,    20,    21,    22,    18,    19,    20,    21,    22,     8,
       9,    18,    19,    20,    21,    22,    -1,    -1,    -1,    18,
      19,    20,    21,    22
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,    28,    35,    37,    40,    45,    47,
      48,    49,    50,    52,    53,    56,    10,    29,    51,    26,
      26,    26,     0,    48,    23,    57,    23,     5,     6,     7,
      17,    19,    26,    58,    48,    58,    58,    58,     5,    54,
      55,    58,    58,    58,     8,     9,    11,    12,    13,    14,
      15,    16,    18,    19,    20,    21,    22,    29,    27,    27,
      27,    10,    24,    27,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    58,    58,    49,    28,    49,
      58,    55,    36,    46,    49,    38,    42,    44,     6,    44,
      34,    43,    25,    25,    29,    48,    48
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    41,    42,    42,    43,    43,    43,    44,    44,    46,
      45,    47,    48,    48,    49,    49,    49,    49,    49,    49,
      49,    50,    51,    50,    52,    53,    53,    54,    54,    55,
      55,    57,    56,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    58
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     4,     3,     3,     2,     0,     2,     1,     0,
       9,     1,     2,     1,     5,     1,     2,     2,     1,     5,
       7,     2,     0,     4,     3,     1,     1,     1,     3,     3,
       1,     0,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     3,     2,     1,
       1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
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
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
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
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
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
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
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
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
        case 2:
#line 64 "assign5.y" /* yacc.c:1646  */
    {
	char* label = get_new_label();
	struct code* new_code = code_new("label", NULL, NULL, label);
	new_code->next = (yyvsp[0].CODE_STORE)->startP;
	(yyval.HCASE) = Hcase_new(label, (yyvsp[-2].num_i), new_code, (yyvsp[0].CODE_STORE)->endP);

	printf(" \n ....CASE..... \n");
	code_print((yyval.HCASE)->startP);
	printf(" \n ............. \n");
}
#line 1366 "assign5.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 75 "assign5.y" /* yacc.c:1646  */
    {
	char* label = get_new_label();
	struct code* new_code = code_new("label", NULL, NULL, label);
	(yyval.HCASE) = Hcase_new(label, (yyvsp[-1].num_i), new_code, new_code);

	printf(" \n ....CASE..... \n");
	code_print((yyval.HCASE)->startP);
	printf(" \n ............. \n");
}
#line 1380 "assign5.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 86 "assign5.y" /* yacc.c:1646  */
    {
	char* label = get_new_label();
	struct code* new_code = code_new("label", NULL, NULL, label);
	new_code->next = (yyvsp[0].CODE_STORE)->startP;
	(yyval.HCASE) = Hcase_new(label, -1, new_code, (yyvsp[0].CODE_STORE)->endP);
}
#line 1391 "assign5.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 93 "assign5.y" /* yacc.c:1646  */
    {
	char* label = get_new_label();
	struct code* new_code = code_new("label", NULL, NULL, label);
	(yyval.HCASE) = Hcase_new(label, -1, new_code, new_code);
}
#line 1401 "assign5.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 99 "assign5.y" /* yacc.c:1646  */
    {
	char* label = get_new_label();
	struct code* new_code = code_new("label", NULL, NULL, label);
	(yyval.HCASE) = Hcase_new(label, -1, new_code, new_code);
}
#line 1411 "assign5.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 107 "assign5.y" /* yacc.c:1646  */
    {
	char temp[10];
	sprintf(temp, "%d", (yyvsp[-1].HCASE)->a);
	struct code* new_code = code_new("!=", NULL, temp, (yyvsp[0].HCASE_LIST)->start_label);
	new_code->next = (yyvsp[-1].HCASE)->startP->next;
	(yyvsp[-1].HCASE)->startP->next = new_code;
	struct code_list* new_list = code_list_new(new_code);
	new_list->next = (yyvsp[0].HCASE_LIST)->var_codes;
	while((yyvsp[-1].HCASE)->endP->next != NULL) (yyvsp[-1].HCASE)->endP = (yyvsp[-1].HCASE)->endP->next;
	(yyvsp[-1].HCASE)->endP->next = (yyvsp[0].HCASE_LIST)->startP;
	(yyval.HCASE_LIST) = Hcase_list_new((yyvsp[-1].HCASE)->label, new_list, (yyvsp[0].HCASE_LIST)->default_jump_code, (yyvsp[-1].HCASE)->startP, (yyvsp[0].HCASE_LIST)->endP);
}
#line 1428 "assign5.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 120 "assign5.y" /* yacc.c:1646  */
    {
	char temp[10];
	sprintf(temp, "%d", (yyvsp[0].HCASE)->a);
	struct code* new_code = code_new("!=", NULL, temp, NULL);
	new_code->next = (yyvsp[0].HCASE)->startP->next;
	(yyvsp[0].HCASE)->startP->next = new_code;
	while((yyvsp[0].HCASE)->endP->next != NULL) (yyvsp[0].HCASE)->endP = (yyvsp[0].HCASE)->endP->next;
	(yyval.HCASE_LIST) = Hcase_list_new((yyvsp[0].HCASE)->label, code_list_new(new_code), new_code, (yyvsp[0].HCASE)->startP, (yyvsp[0].HCASE)->endP);
}
#line 1442 "assign5.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 130 "assign5.y" /* yacc.c:1646  */
    {table = sym_table_new(table);}
#line 1448 "assign5.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 131 "assign5.y" /* yacc.c:1646  */
    {
	exprn_type_cast((yyvsp[-6].EXPRN), 0);
	Hcase_backpatch((yyvsp[-2].HCASE_LIST), (yyvsp[-6].EXPRN)->store_var, (yyvsp[-1].HCASE)->label);
	(yyvsp[-6].EXPRN)->last_line_P->next = (yyvsp[-2].HCASE_LIST)->startP;
	(yyvsp[-2].HCASE_LIST)->endP->next = (yyvsp[-1].HCASE)->startP;
	(yyval.CODE_STORE) = code_store_init((yyvsp[-6].EXPRN)->codeP, (yyvsp[-1].HCASE)->endP, NULL);
}
#line 1460 "assign5.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 140 "assign5.y" /* yacc.c:1646  */
    {
	(yyval.CODE_STORE) = code_store_copy_init((yyvsp[0].CODE_STORE));

	printf(" \n ....PROG..... \n");
	code_print((yyval.CODE_STORE)->startP);
	printf(" \n ............. \n");
}
#line 1472 "assign5.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 148 "assign5.y" /* yacc.c:1646  */
    {(yyval.CODE_STORE) = code_store_concat_init((yyvsp[-1].CODE_STORE), (yyvsp[0].CODE_STORE));}
#line 1478 "assign5.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 149 "assign5.y" /* yacc.c:1646  */
    {(yyval.CODE_STORE) = code_store_copy_init((yyvsp[0].CODE_STORE));}
#line 1484 "assign5.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 154 "assign5.y" /* yacc.c:1646  */
    {
	exprn_type_cast((yyvsp[-2].EXPRN), 2);

	char* true_label = get_new_label();
	char* false_label = get_new_label();
	char* begin_label = get_new_label();
	struct code* true_label_line = code_new("label", NULL, NULL, true_label);
	struct code* false_label_line = code_new("label", NULL, NULL, false_label);
	struct code* begin_label_line = code_new("label", NULL, NULL, begin_label);
	struct code* jump_line = code_new("goto", NULL, NULL, begin_label);

	// Insert new codes in between old codes
	assert((yyvsp[-2].EXPRN)->last_line_P->next == NULL && (yyvsp[0].CODE_STORE)->endP->next == NULL);
	begin_label_line->next = (yyvsp[-2].EXPRN)->codeP;
	(yyvsp[-2].EXPRN)->last_line_P->next = true_label_line;
	true_label_line->next = (yyvsp[0].CODE_STORE)->startP;
	(yyvsp[0].CODE_STORE)->endP->next = jump_line;
	jump_line->next = false_label_line;

	code_list_backpatch((yyvsp[-2].EXPRN)->true_jump_lines, true_label);
	code_list_backpatch((yyvsp[-2].EXPRN)->false_jump_lines, false_label);
	codeP_list_backpatch((yyvsp[-2].EXPRN)->true_jumpPs, true_label_line);
	codeP_list_backpatch((yyvsp[-2].EXPRN)->false_jumpPs, false_label_line);
	
	(yyval.CODE_STORE) = code_store_init(begin_label_line, false_label_line, NULL);

}
#line 1516 "assign5.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 182 "assign5.y" /* yacc.c:1646  */
    {(yyval.CODE_STORE) = code_store_copy_init((yyvsp[-1].CODE_STORE));}
#line 1522 "assign5.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 183 "assign5.y" /* yacc.c:1646  */
    {(yyval.CODE_STORE) = code_store_copy_init((yyvsp[-1].CODE_STORE));}
#line 1528 "assign5.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 184 "assign5.y" /* yacc.c:1646  */
    {(yyval.CODE_STORE) = code_store_copy_init((yyvsp[0].CODE_STORE));}
#line 1534 "assign5.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 186 "assign5.y" /* yacc.c:1646  */
    {
	exprn_type_cast((yyvsp[-2].EXPRN), 2);

	char* true_label = get_new_label();
	char* false_label = get_new_label();
	struct code* true_label_line = code_new("label", NULL, NULL, true_label);
	struct code* false_label_line = code_new("label", NULL, NULL, false_label);

	// Insert new codes in between old codes
	assert((yyvsp[-2].EXPRN)->last_line_P->next == NULL && (yyvsp[0].CODE_STORE)->endP->next == NULL);
	(yyvsp[-2].EXPRN)->last_line_P->next = true_label_line;
	true_label_line->next = (yyvsp[0].CODE_STORE)->startP;
	(yyvsp[0].CODE_STORE)->endP->next = false_label_line;

	code_list_backpatch((yyvsp[-2].EXPRN)->true_jump_lines, true_label);
	code_list_backpatch((yyvsp[-2].EXPRN)->false_jump_lines, false_label);
	codeP_list_backpatch((yyvsp[-2].EXPRN)->true_jumpPs, true_label_line);
	codeP_list_backpatch((yyvsp[-2].EXPRN)->false_jumpPs, false_label_line);
	
	(yyval.CODE_STORE) = code_store_init((yyvsp[-2].EXPRN)->codeP, false_label_line, NULL);
}
#line 1560 "assign5.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 208 "assign5.y" /* yacc.c:1646  */
    {
	exprn_type_cast((yyvsp[-4].EXPRN), 2);

	char* true_label = get_new_label();
	char* false_label = get_new_label();
	char* final_label = get_new_label();
	struct code* true_label_line = code_new("label", NULL, NULL, true_label);
	struct code* false_label_line = code_new("label", NULL, NULL, false_label);
	struct code* final_label_line = code_new("label", NULL, NULL, final_label);
	struct code* jump_line = code_new("goto", NULL, NULL, final_label);

	// Insert new codes in between old codes
	assert((yyvsp[-4].EXPRN)->last_line_P->next == NULL && (yyvsp[-2].CODE_STORE)->endP->next == NULL && (yyvsp[0].CODE_STORE)->endP->next == NULL);
	(yyvsp[-4].EXPRN)->last_line_P->next = true_label_line;
	true_label_line->next = (yyvsp[-2].CODE_STORE)->startP;
	(yyvsp[-2].CODE_STORE)->endP->next = jump_line;
	jump_line->next = false_label_line;
	false_label_line->next = (yyvsp[0].CODE_STORE)->startP;
	(yyvsp[0].CODE_STORE)->endP->next = final_label_line;

	code_list_backpatch((yyvsp[-4].EXPRN)->true_jump_lines, true_label);
	code_list_backpatch((yyvsp[-4].EXPRN)->false_jump_lines, false_label);
	codeP_list_backpatch((yyvsp[-4].EXPRN)->true_jumpPs, true_label_line);
	codeP_list_backpatch((yyvsp[-4].EXPRN)->false_jumpPs, false_label_line);
	
	(yyval.CODE_STORE) = code_store_init((yyvsp[-4].EXPRN)->codeP, final_label_line, NULL);
}
#line 1592 "assign5.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 237 "assign5.y" /* yacc.c:1646  */
    {(yyval.CODE_STORE) = code_store_init(NULL, NULL, NULL);}
#line 1598 "assign5.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 239 "assign5.y" /* yacc.c:1646  */
    {
	sym_table_print(table);
	table = sym_table_new(table);
}
#line 1607 "assign5.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 244 "assign5.y" /* yacc.c:1646  */
    { 
	(yyval.CODE_STORE) = code_store_copy_init((yyvsp[-1].CODE_STORE)); 
	sym_table_print(table);
	table = table->parent;
	sym_table_print(table);
	printf(" \n ....BLOCK..... \n");
	code_print((yyval.CODE_STORE)->startP);
	printf(" \n ............. \n");
}
#line 1621 "assign5.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 256 "assign5.y" /* yacc.c:1646  */
    {
	cont = sym_table_search(table, (yyvsp[-2].str));
	if (cont == NULL){printf("Variable '%s' not found in current scope\n", (yyvsp[-2].str)); exit(1);}

	exprn_type_cast((yyvsp[0].EXPRN), type);
	char* var = get_user_var((yyvsp[-2].str), cont->depth);
	struct code* new_code = code_new("assign", (yyvsp[0].EXPRN)->store_var, NULL, var);\
	(yyvsp[0].EXPRN)->last_line_P->next = new_code;
	(yyval.CODE_STORE) = code_store_init((yyvsp[0].EXPRN)->codeP, new_code, var);
}
#line 1636 "assign5.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 267 "assign5.y" /* yacc.c:1646  */
    {(yyval.num_i) = 0;}
#line 1642 "assign5.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 267 "assign5.y" /* yacc.c:1646  */
    {(yyval.num_i) = 1;}
#line 1648 "assign5.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 270 "assign5.y" /* yacc.c:1646  */
    {
	cont = sym_table_search(table, (yyvsp[0].str));
	if (cont != NULL && cont->depth == table->depth){printf("Variable '%s' already declared in current scope\n", (yyvsp[0].str)); exit(1);}
	sym_table_insert(table, (yyvsp[0].str), type);
	(yyval.CODE_STORE) = code_store_init(NULL, NULL, NULL);
}
#line 1659 "assign5.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 277 "assign5.y" /* yacc.c:1646  */
    {
	exprn_type_cast((yyvsp[0].EXPRN), type);
	char* var = get_user_var((yyvsp[-2].str), table->depth);
	struct code* new_code = code_new("assign", (yyvsp[0].EXPRN)->store_var, NULL, var);\
	(yyvsp[0].EXPRN)->last_line_P->next = new_code;
	(yyval.CODE_STORE) = code_store_init((yyvsp[0].EXPRN)->codeP, new_code, var);

	cont = sym_table_search(table, (yyvsp[-2].str));
	if (cont != NULL && cont->depth == table->depth){printf("Variable '%s' already declared in current scope\n", (yyvsp[-2].str)); exit(1);}
	sym_table_insert(table, (yyvsp[-2].str), type);
}
#line 1675 "assign5.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 290 "assign5.y" /* yacc.c:1646  */
    {
	(yyval.CODE_STORE) = code_store_concat_init((yyvsp[-2].CODE_STORE), (yyvsp[0].CODE_STORE));
}
#line 1683 "assign5.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 294 "assign5.y" /* yacc.c:1646  */
    {
	(yyval.CODE_STORE) = code_store_copy_init((yyvsp[0].CODE_STORE));
}
#line 1691 "assign5.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 298 "assign5.y" /* yacc.c:1646  */
    {type = (yyvsp[0].num_i);}
#line 1697 "assign5.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 299 "assign5.y" /* yacc.c:1646  */
    {
	(yyval.CODE_STORE) = code_store_copy_init((yyvsp[0].CODE_STORE));
}
#line 1705 "assign5.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 305 "assign5.y" /* yacc.c:1646  */
    {	
	(yyval.EXPRN) = exprn_init_null();
	exprn_operate((yyval.EXPRN), (yyvsp[-2].EXPRN), (yyvsp[0].EXPRN), "+");
	printf(" \n ....+..... \n");
	code_print((yyval.EXPRN)->codeP);
	printf(" \n ............. \n");
}
#line 1717 "assign5.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 313 "assign5.y" /* yacc.c:1646  */
    {	
	(yyval.EXPRN) = exprn_init_null();
	exprn_operate((yyval.EXPRN), (yyvsp[-2].EXPRN), (yyvsp[0].EXPRN), "-");
	printf(" \n ....-..... \n");
	code_print((yyval.EXPRN)->codeP);
	printf(" \n ............. \n");
}
#line 1729 "assign5.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 321 "assign5.y" /* yacc.c:1646  */
    {	
	(yyval.EXPRN) = exprn_init_null();
	exprn_operate((yyval.EXPRN), (yyvsp[-2].EXPRN), (yyvsp[0].EXPRN), "*");
	printf(" \n ....*..... \n");
	code_print((yyval.EXPRN)->codeP);
	printf(" \n ............. \n");
}
#line 1741 "assign5.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 329 "assign5.y" /* yacc.c:1646  */
    {	
	(yyval.EXPRN) = exprn_init_null();
	exprn_operate((yyval.EXPRN), (yyvsp[-2].EXPRN), (yyvsp[0].EXPRN), "/");
	printf(" \n ...../.... \n");
	code_print((yyval.EXPRN)->codeP);
	printf(" \n ............. \n");
}
#line 1753 "assign5.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 337 "assign5.y" /* yacc.c:1646  */
    {	
	(yyval.EXPRN) = exprn_init_null();
	exprn_operate((yyval.EXPRN), (yyvsp[-2].EXPRN), (yyvsp[0].EXPRN), "%");
	printf(" \n ....MOD..... \n");
	code_print((yyval.EXPRN)->codeP);
	printf(" \n ............. \n");
}
#line 1765 "assign5.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 345 "assign5.y" /* yacc.c:1646  */
    {	
	(yyval.EXPRN) = exprn_init_null();
	exprn_operate((yyval.EXPRN), (yyvsp[-2].EXPRN), (yyvsp[0].EXPRN), "<");
	printf(" \n .....<.... \n");
	code_print((yyval.EXPRN)->codeP);
	printf(" \n ............. \n");
}
#line 1777 "assign5.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 353 "assign5.y" /* yacc.c:1646  */
    {
	(yyval.EXPRN) = exprn_init_null();
	exprn_operate((yyval.EXPRN), (yyvsp[-2].EXPRN), (yyvsp[0].EXPRN), ">");
	printf(" \n .....>.... \n");
	code_print((yyval.EXPRN)->codeP);
	printf(" \n ............. \n");
}
#line 1789 "assign5.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 361 "assign5.y" /* yacc.c:1646  */
    {
	(yyval.EXPRN) = exprn_init_null();
	exprn_operate((yyval.EXPRN), (yyvsp[-2].EXPRN), (yyvsp[0].EXPRN), "<=");
	printf(" \n ....<=..... \n");
	code_print((yyval.EXPRN)->codeP);
	printf(" \n ............. \n");
}
#line 1801 "assign5.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 369 "assign5.y" /* yacc.c:1646  */
    {
	(yyval.EXPRN) = exprn_init_null();
	exprn_operate((yyval.EXPRN), (yyvsp[-2].EXPRN), (yyvsp[0].EXPRN), ">=");
	printf(" \n .....>=.... \n");
	code_print((yyval.EXPRN)->codeP);
	printf(" \n ............. \n");
}
#line 1813 "assign5.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 377 "assign5.y" /* yacc.c:1646  */
    {
	(yyval.EXPRN) = exprn_init_null();
	exprn_operate((yyval.EXPRN), (yyvsp[-2].EXPRN), (yyvsp[0].EXPRN), "!=");
	printf(" \n .....!=.... \n");
	code_print((yyval.EXPRN)->codeP);
	printf(" \n ............. \n");
}
#line 1825 "assign5.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 385 "assign5.y" /* yacc.c:1646  */
    {
	(yyval.EXPRN) = exprn_init_null();
	exprn_operate((yyval.EXPRN), (yyvsp[-2].EXPRN), (yyvsp[0].EXPRN), "==");
	printf(" \n ....==..... \n");
	code_print((yyval.EXPRN)->codeP);
	printf(" \n ............. \n");
}
#line 1837 "assign5.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 393 "assign5.y" /* yacc.c:1646  */
    {
	(yyval.EXPRN) = exprn_init_null();
	exprn_operate((yyval.EXPRN), (yyvsp[-2].EXPRN), (yyvsp[0].EXPRN), "&&");
	printf(" \n .....&&.... \n");
	code_print((yyval.EXPRN)->codeP);
	printf(" \n ............. \n");
}
#line 1849 "assign5.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 401 "assign5.y" /* yacc.c:1646  */
    {
	(yyval.EXPRN) = exprn_init_null();
	exprn_operate((yyval.EXPRN), (yyvsp[-2].EXPRN), (yyvsp[0].EXPRN), "||");
	printf(" \n ....||..... \n");
	code_print((yyval.EXPRN)->codeP);
	printf(" \n ............. \n");
}
#line 1861 "assign5.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 409 "assign5.y" /* yacc.c:1646  */
    {
	(yyval.EXPRN) = exprn_init_null();
	exprn_operate((yyval.EXPRN), (yyvsp[0].EXPRN), NULL, "!");
	printf(" \n .....!.... \n");
	code_print((yyval.EXPRN)->codeP);
	printf(" \n ............. \n");
}
#line 1873 "assign5.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 417 "assign5.y" /* yacc.c:1646  */
    {
	(yyval.EXPRN) = exprn_init_null();
	exprn_operate((yyval.EXPRN), (yyvsp[-1].EXPRN), NULL, "()");
	printf(" \n ....()..... \n");
	code_print((yyval.EXPRN)->codeP);
	printf(" \n ............. \n");
}
#line 1885 "assign5.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 425 "assign5.y" /* yacc.c:1646  */
    {
	(yyval.EXPRN) = exprn_init_null();
	exprn_operate((yyval.EXPRN), (yyvsp[0].EXPRN), NULL, "-()");
	printf(" \n ....-()..... \n");
	code_print((yyval.EXPRN)->codeP);
	printf(" \n ............. \n");
}
#line 1897 "assign5.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 433 "assign5.y" /* yacc.c:1646  */
    {
	(yyval.EXPRN) = exprn_init_null();
	exprn_init_with_int_value((yyval.EXPRN), (yyvsp[0].num_i));
	printf(" \n ....NUM_INT..... \n");
	code_print((yyval.EXPRN)->codeP);
	printf(" \n ............. \n");
}
#line 1909 "assign5.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 441 "assign5.y" /* yacc.c:1646  */
    {
	(yyval.EXPRN) = exprn_init_null();
	exprn_init_with_float_value((yyval.EXPRN), (yyvsp[0].num_f));
	printf(" \n ....NUM_FLOAT..... \n");
	code_print((yyval.EXPRN)->codeP);
	printf(" \n ............. \n");
}
#line 1921 "assign5.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 449 "assign5.y" /* yacc.c:1646  */
    {
	(yyval.EXPRN) = exprn_init_null();
	cont = sym_table_search(table, (yyvsp[0].str));
	if (cont == NULL) {printf("Variable %s undeclared\n", (yyvsp[0].str)); exit(1);}
	char* user_var = get_user_var((yyvsp[0].str), cont->depth);
	exprn_init_with_name((yyval.EXPRN), user_var, cont->type);

	printf(" \n ....NAME..... \n");
	code_print((yyval.EXPRN)->codeP);
	printf(" \n ............. \n");
}
#line 1937 "assign5.tab.c" /* yacc.c:1646  */
    break;


#line 1941 "assign5.tab.c" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
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
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 462 "assign5.y" /* yacc.c:1906  */


int main(int argc, char** argv)
{
	setvbuf(stdout, NULL, _IONBF, 0);
	// int tok;
	// while(tok = yylex()) 
	// {
	// 	printf("%d", tok);
	// 	if(tok == NUM_INT) printf(" = %d\n", yylval.num_i);
	// 	else if(tok == NUM_FLOAT) printf(" = %f\n", yylval.num_f);
	// 	else if(tok == NAME) printf(" = %s\n", yylval.str);
	// 	else printf("\n"); 
	// }

	type = -1;
	table = sym_table_new(NULL);;
	yyparse();
}

yyerror(const char* s)
{
	fprintf(stderr, "error: %s\n", s);
}



