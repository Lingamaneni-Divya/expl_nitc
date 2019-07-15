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
#line 1 "task1.y" /* yacc.c:339  */

	#include<stdio.h>
	#include"task1.h"
	#include"task1.c"
	int yylex(void);
	int yyerror(char const*);
	int yywrap();
	FILE *fp,*yyin;
	int currtype;

#line 77 "y.tab.c" /* yacc.c:339  */

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
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    NUM = 258,
    VAR = 259,
    MESG = 260,
    PLUS = 261,
    MINUS = 262,
    MUL = 263,
    DIV = 264,
    MOD = 265,
    GT = 266,
    LT = 267,
    GE = 268,
    LE = 269,
    EE = 270,
    NE = 271,
    PBEGIN = 272,
    PEND = 273,
    READ = 274,
    WRITE = 275,
    IF = 276,
    THEN = 277,
    ELSE = 278,
    ENDIF = 279,
    WHILE = 280,
    DO = 281,
    ENDWHILE = 282,
    CONTINUE = 283,
    BREAK = 284,
    DECL = 285,
    ENDDECL = 286,
    INT = 287,
    STR = 288,
    RETURN = 289,
    MAINFN = 290,
    ANDTK = 291,
    ORTK = 292,
    NOTTK = 293
  };
#endif
/* Tokens.  */
#define NUM 258
#define VAR 259
#define MESG 260
#define PLUS 261
#define MINUS 262
#define MUL 263
#define DIV 264
#define MOD 265
#define GT 266
#define LT 267
#define GE 268
#define LE 269
#define EE 270
#define NE 271
#define PBEGIN 272
#define PEND 273
#define READ 274
#define WRITE 275
#define IF 276
#define THEN 277
#define ELSE 278
#define ENDIF 279
#define WHILE 280
#define DO 281
#define ENDWHILE 282
#define CONTINUE 283
#define BREAK 284
#define DECL 285
#define ENDDECL 286
#define INT 287
#define STR 288
#define RETURN 289
#define MAINFN 290
#define ANDTK 291
#define ORTK 292
#define NOTTK 293

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 12 "task1.y" /* yacc.c:355  */

	struct tnode *tnode;
	struct Gsymbol *Gsymbol;
	struct Paramstruct *paramstruct;
      

#line 200 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 217 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  12
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   378

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  31
/* YYNRULES -- Number of rules.  */
#define YYNRULES  81
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  186

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   293

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
      43,    44,     2,     2,    40,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    39,
       2,    47,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    41,     2,    42,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    45,     2,    46,     2,     2,     2,     2,
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
      35,    36,    37,    38
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    28,    28,    29,    30,    33,    35,    39,    40,    43,
      46,    47,    50,    51,    52,    53,    58,    59,    61,    62,
      63,    64,    66,    67,    69,    75,    76,    78,    79,    81,
      83,    84,    86,    87,    89,    90,    94,    96,   102,   103,
     106,   107,   108,   109,   110,   111,   112,   113,   116,   117,
     119,   121,   122,   124,   126,   129,   133,   136,   137,   138,
     139,   140,   142,   143,   144,   145,   146,   147,   149,   150,
     151,   153,   154,   155,   156,   157,   158,   160,   161,   165,
     166,   168
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUM", "VAR", "MESG", "PLUS", "MINUS",
  "MUL", "DIV", "MOD", "GT", "LT", "GE", "LE", "EE", "NE", "PBEGIN",
  "PEND", "READ", "WRITE", "IF", "THEN", "ELSE", "ENDIF", "WHILE", "DO",
  "ENDWHILE", "CONTINUE", "BREAK", "DECL", "ENDDECL", "INT", "STR",
  "RETURN", "MAINFN", "ANDTK", "ORTK", "NOTTK", "';'", "','", "'['", "']'",
  "'('", "')'", "'{'", "'}'", "'='", "$accept", "Program", "GdeclBlock",
  "Gdecllist", "Gdecl", "Gvarlist", "Gvar", "FDefBlock", "Fdef",
  "ParamList", "Param", "LdeclBlock", "LDecList", "LDecl", "Lvarlist",
  "Type", "MainBlock", "Body", "RetStmt", "Slist", "Stmt", "InputStmt",
  "OutputStmt", "AssgStmt", "IfStmt", "WhileStmt", "FuncStmt", "expr",
  "Fcall", "ArgList", "Sarray", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,    59,
      44,    91,    93,    40,    41,   123,   125,    61
};
# endif

#define YYPACT_NINF -108

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-108)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      76,    80,  -108,  -108,    21,     3,   -33,  -108,  -108,    85,
    -108,    37,  -108,     3,  -108,     2,  -108,   -36,  -108,  -108,
      56,    42,  -108,  -108,  -108,    88,   124,   129,    13,  -108,
      37,    16,   125,   133,  -108,    33,  -108,   167,  -108,   131,
      35,   -14,  -108,     3,  -108,  -108,   -14,   132,   349,    89,
     161,   135,  -108,   161,   140,   -14,    23,   139,   144,   145,
     146,   151,   175,   304,  -108,  -108,  -108,  -108,  -108,  -108,
    -108,   176,   169,  -108,    92,  -108,   213,   172,  -108,   173,
    -108,   161,   174,     7,    15,     7,   217,     7,     7,     7,
    -108,  -108,     7,   207,  -108,  -108,     7,  -108,  -108,  -108,
     100,  -108,  -108,   180,  -108,  -108,   126,  -108,     7,   197,
    -108,  -108,  -108,   290,    36,   234,    66,   183,    18,   136,
     147,   245,   189,   279,  -108,   225,  -108,   186,     7,     7,
       7,     7,     7,     7,     7,     7,     7,     7,     7,     7,
       7,     7,  -108,     7,  -108,  -108,   192,   193,   198,   157,
     210,  -108,  -108,  -108,  -108,  -108,   156,   156,  -108,  -108,
    -108,    95,    95,    95,    95,    95,    95,    95,    95,    95,
     290,  -108,  -108,  -108,   349,   349,   316,   327,   349,   199,
     223,   338,  -108,  -108,   224,  -108
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,    32,    33,     0,     0,     0,     4,     6,     0,
       8,     0,     1,     0,    17,     0,     3,     0,     5,     7,
      12,     0,    11,    16,     2,     0,     0,     0,     0,     9,
       0,     0,     0,     0,    15,     0,    23,     0,    10,     0,
       0,     0,    13,     0,    14,    24,     0,     0,     0,     0,
       0,     0,    22,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    39,    40,    41,    42,    43,    44,
      45,     0,     0,    26,     0,    28,     0,     0,    35,     0,
      21,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      46,    47,     0,     0,    38,    56,     0,    25,    27,    31,
       0,    34,    20,     0,    19,    73,    72,    74,     0,     0,
      76,    75,    77,    80,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    29,     0,    18,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    81,     0,    78,    51,     0,     0,     0,     0,
       0,    37,    36,    52,    30,    71,    57,    58,    59,    60,
      61,    65,    64,    63,    62,    66,    67,    68,    69,    70,
      79,    48,    49,    50,     0,     0,     0,     0,     0,     0,
       0,     0,    54,    55,     0,    53
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -108,  -108,  -108,  -108,   255,  -108,   235,  -108,   253,   236,
     226,     6,  -108,   194,  -108,     4,     9,    19,  -108,  -107,
     -62,  -108,  -108,  -108,  -108,  -108,  -108,   -45,   -40,  -108,
     -48
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     4,     5,     9,    10,    21,    22,    13,    14,    35,
      36,    50,    74,    75,   100,    37,     7,    51,    93,    63,
      64,    65,    66,    67,    68,    69,    70,   109,   110,   114,
     111
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      72,    94,    17,    48,     6,    11,    25,    26,    71,    15,
     105,   106,   107,    11,    16,    72,    49,    15,   105,   106,
     107,    12,    24,    71,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,     2,     3,    17,   117,   113,
     115,    20,   118,   119,   120,     2,     3,   121,     2,     3,
     108,   123,    53,    76,   139,   140,   141,    34,   108,   112,
      39,    81,   148,   127,    83,    54,    84,   176,   177,    77,
      85,   181,    79,    43,    82,    43,   143,    44,    76,    47,
     144,    29,    30,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,    27,   170,    28,
     103,   128,   129,   130,   131,   132,     1,    83,     2,     3,
     146,     8,     2,     3,    94,    94,    18,     2,     3,    94,
      73,     2,     3,    97,     2,     3,    72,    72,    72,    72,
      72,    31,    33,    72,    71,    71,    71,    71,    71,   124,
     125,    71,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   130,   131,   132,    83,    32,    84,
      41,    45,   139,   140,   141,    42,    46,    55,    48,   174,
     149,    78,    86,   139,   140,   141,    80,    87,    88,    89,
      90,   150,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,    91,    95,    96,    99,   101,   102,
     104,   116,   139,   140,   141,   122,   126,   147,   152,   154,
     155,   171,   172,   139,   140,   141,   175,   173,   182,   142,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   183,   185,    19,    38,    23,    40,    98,    52,
     139,   140,   141,   145,     0,     0,     0,     0,     0,     0,
       0,   139,   140,   141,   151,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,     0,    56,     0,
       0,     0,     0,     0,     0,   139,   140,   141,   153,     0,
      56,     0,     0,    57,    58,    59,   139,   140,   141,    60,
       0,    56,    61,    62,     0,    57,    58,    59,    92,   178,
     179,    60,    56,     0,    61,    62,    57,    58,    59,     0,
       0,     0,    60,    56,   180,    61,    62,    57,    58,    59,
       0,     0,   184,    60,     0,     0,    61,    62,    57,    58,
      59,     0,     0,     0,    60,     0,     0,    61,    62
};

static const yytype_int16 yycheck[] =
{
      48,    63,    35,    17,     0,     1,     4,    43,    48,     5,
       3,     4,     5,     9,     5,    63,    30,    13,     3,     4,
       5,     0,    13,    63,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    32,    33,    35,    86,    84,
      85,     4,    87,    88,    89,    32,    33,    92,    32,    33,
      43,    96,    46,    49,    36,    37,    38,    44,    43,    44,
      44,    55,    44,   108,    41,    46,    43,   174,   175,    50,
      47,   178,    53,    40,    55,    40,    40,    44,    74,    44,
      44,    39,    40,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,    41,   143,    43,
      81,     6,     7,     8,     9,    10,    30,    41,    32,    33,
      44,    31,    32,    33,   176,   177,    31,    32,    33,   181,
      31,    32,    33,    31,    32,    33,   174,   175,   176,   177,
     178,    43,     3,   181,   174,   175,   176,   177,   178,    39,
      40,   181,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,     8,     9,    10,    41,    44,    43,
      45,     4,    36,    37,    38,    42,    45,    45,    17,    22,
      44,    46,    43,    36,    37,    38,    46,    43,    43,    43,
      39,    44,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    39,    39,    47,     4,    46,    46,
      46,     4,    36,    37,    38,    18,    46,    44,    39,     4,
      44,    39,    39,    36,    37,    38,    26,    39,    39,    42,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    39,    39,     9,    30,    13,    31,    74,    43,
      36,    37,    38,    39,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    36,    37,    38,    39,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    -1,     4,    -1,
      -1,    -1,    -1,    -1,    -1,    36,    37,    38,    39,    -1,
       4,    -1,    -1,    19,    20,    21,    36,    37,    38,    25,
      -1,     4,    28,    29,    -1,    19,    20,    21,    34,    23,
      24,    25,     4,    -1,    28,    29,    19,    20,    21,    -1,
      -1,    -1,    25,     4,    27,    28,    29,    19,    20,    21,
      -1,    -1,    24,    25,    -1,    -1,    28,    29,    19,    20,
      21,    -1,    -1,    -1,    25,    -1,    -1,    28,    29
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    30,    32,    33,    49,    50,    63,    64,    31,    51,
      52,    63,     0,    55,    56,    63,    64,    35,    31,    52,
       4,    53,    54,    56,    64,     4,    43,    41,    43,    39,
      40,    43,    44,     3,    44,    57,    58,    63,    54,    44,
      57,    45,    42,    40,    44,     4,    45,    44,    17,    30,
      59,    65,    58,    59,    65,    45,     4,    19,    20,    21,
      25,    28,    29,    67,    68,    69,    70,    71,    72,    73,
      74,    76,    78,    31,    60,    61,    63,    65,    46,    65,
      46,    59,    65,    41,    43,    47,    43,    43,    43,    43,
      39,    39,    34,    66,    68,    39,    47,    31,    61,     4,
      62,    46,    46,    65,    46,     3,     4,     5,    43,    75,
      76,    78,    44,    75,    77,    75,     4,    78,    75,    75,
      75,    75,    18,    75,    39,    40,    46,    75,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    36,
      37,    38,    42,    40,    44,    39,    44,    44,    44,    44,
      44,    39,    39,    39,     4,    44,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    39,    39,    39,    22,    26,    67,    67,    23,    24,
      27,    67,    39,    39,    24,    39
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    48,    49,    49,    49,    50,    50,    51,    51,    52,
      53,    53,    54,    54,    54,    54,    55,    55,    56,    56,
      56,    56,    57,    57,    58,    59,    59,    60,    60,    61,
      62,    62,    63,    63,    64,    64,    65,    66,    67,    67,
      68,    68,    68,    68,    68,    68,    68,    68,    69,    69,
      70,    71,    71,    72,    72,    73,    74,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    76,    76,    77,
      77,    78
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     2,     1,     3,     2,     2,     1,     3,
       3,     1,     1,     4,     4,     3,     2,     1,     9,     8,
       8,     7,     3,     1,     2,     3,     2,     2,     1,     3,
       3,     1,     1,     1,     8,     7,     5,     3,     2,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     5,     5,
       5,     4,     4,    10,     8,     8,     2,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     1,     1,     1,     1,     1,     3,     4,     3,
       1,     4
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
        case 5:
#line 33 "task1.y" /* yacc.c:1646  */
    {print_Gsymbol_table();
					}
#line 1458 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 35 "task1.y" /* yacc.c:1646  */
    {print_Gsymbol_table();
					}
#line 1465 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 39 "task1.y" /* yacc.c:1646  */
    { }
#line 1471 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 40 "task1.y" /* yacc.c:1646  */
    { }
#line 1477 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 43 "task1.y" /* yacc.c:1646  */
    {/*currtype=nulltype;*/ }
#line 1483 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 46 "task1.y" /* yacc.c:1646  */
    { }
#line 1489 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 47 "task1.y" /* yacc.c:1646  */
    { }
#line 1495 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 50 "task1.y" /* yacc.c:1646  */
    {GInstall((yyvsp[0].tnode)->varname,currtype,1,NULL);}
#line 1501 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 51 "task1.y" /* yacc.c:1646  */
    {GInstall((yyvsp[-3].tnode)->varname,currtype,(yyvsp[-1].tnode)->val,NULL);}
#line 1507 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 52 "task1.y" /* yacc.c:1646  */
    {GInstall((yyvsp[-3].tnode)->varname,currtype,-1,(yyvsp[-1].paramstruct));}
#line 1513 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 53 "task1.y" /* yacc.c:1646  */
    {GInstall((yyvsp[-2].tnode)->varname,currtype,-1,NULL);}
#line 1519 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 66 "task1.y" /* yacc.c:1646  */
    {(yyval.paramstruct)=PInstall((yyvsp[-2].paramstruct),(yyvsp[0].paramstruct));}
#line 1525 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 67 "task1.y" /* yacc.c:1646  */
    {(yyval.paramstruct)=(yyvsp[0].paramstruct);}
#line 1531 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 69 "task1.y" /* yacc.c:1646  */
    {//printf("type:%d\n",currtype);
					(yyval.paramstruct)=create_param_node((yyvsp[0].tnode)->varname,currtype);
					
					}
#line 1540 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 86 "task1.y" /* yacc.c:1646  */
    {currtype=inttype;}
#line 1546 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 87 "task1.y" /* yacc.c:1646  */
    {currtype=inttype;}
#line 1552 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 136 "task1.y" /* yacc.c:1646  */
    {(yyval.tnode)=create_tree(0,inttype,"+",aop_node,(yyvsp[-2].tnode),NULL,(yyvsp[0].tnode));}
#line 1558 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 137 "task1.y" /* yacc.c:1646  */
    {(yyval.tnode)=create_tree(0,inttype,"-",aop_node,(yyvsp[-2].tnode),NULL,(yyvsp[0].tnode));}
#line 1564 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 138 "task1.y" /* yacc.c:1646  */
    {(yyval.tnode)=create_tree(0,inttype,"*",aop_node,(yyvsp[-2].tnode),NULL,(yyvsp[0].tnode));}
#line 1570 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 139 "task1.y" /* yacc.c:1646  */
    {(yyval.tnode)=create_tree(0,inttype,"/",aop_node,(yyvsp[-2].tnode),NULL,(yyvsp[0].tnode));}
#line 1576 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 140 "task1.y" /* yacc.c:1646  */
    {(yyval.tnode)=create_tree(0,inttype,"%",aop_node,(yyvsp[-2].tnode),NULL,(yyvsp[0].tnode));}
#line 1582 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 142 "task1.y" /* yacc.c:1646  */
    {(yyval.tnode)=create_tree(0,booltype,"<=",lop_node,(yyvsp[-2].tnode),NULL,(yyvsp[0].tnode));}
#line 1588 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 143 "task1.y" /* yacc.c:1646  */
    {(yyval.tnode)=create_tree(0,booltype,">=",lop_node,(yyvsp[-2].tnode),NULL,(yyvsp[0].tnode));}
#line 1594 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 144 "task1.y" /* yacc.c:1646  */
    {(yyval.tnode)=create_tree(0,booltype,"<",lop_node,(yyvsp[-2].tnode),NULL,(yyvsp[0].tnode));}
#line 1600 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 145 "task1.y" /* yacc.c:1646  */
    {(yyval.tnode)=create_tree(0,booltype,">",lop_node,(yyvsp[-2].tnode),NULL,(yyvsp[0].tnode));}
#line 1606 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 146 "task1.y" /* yacc.c:1646  */
    {(yyval.tnode)=create_tree(0,booltype,"==",lop_node,(yyvsp[-2].tnode),NULL,(yyvsp[0].tnode));}
#line 1612 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 147 "task1.y" /* yacc.c:1646  */
    {(yyval.tnode)=create_tree(0,booltype,"!=",lop_node,(yyvsp[-2].tnode),NULL,(yyvsp[0].tnode));}
#line 1618 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 149 "task1.y" /* yacc.c:1646  */
    {(yyval.tnode)=create_tree(0,booltype,"&&",lop_node,(yyvsp[-2].tnode),NULL,(yyvsp[0].tnode));}
#line 1624 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 150 "task1.y" /* yacc.c:1646  */
    {(yyval.tnode)=create_tree(0,booltype,"||",lop_node,(yyvsp[-2].tnode),NULL,(yyvsp[0].tnode));}
#line 1630 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 151 "task1.y" /* yacc.c:1646  */
    {(yyval.tnode)=create_tree(0,booltype,"!",lop_node,(yyvsp[-2].tnode),NULL,(yyvsp[0].tnode));}
#line 1636 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 153 "task1.y" /* yacc.c:1646  */
    {(yyval.tnode)=(yyvsp[-1].tnode);}
#line 1642 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 154 "task1.y" /* yacc.c:1646  */
    {(yyval.tnode)=(yyvsp[0].tnode);}
#line 1648 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 155 "task1.y" /* yacc.c:1646  */
    {(yyval.tnode)=(yyvsp[0].tnode);}
#line 1654 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 156 "task1.y" /* yacc.c:1646  */
    {(yyval.tnode)=(yyvsp[0].tnode);}
#line 1660 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 157 "task1.y" /* yacc.c:1646  */
    {(yyval.tnode)=(yyvsp[0].tnode);}
#line 1666 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 158 "task1.y" /* yacc.c:1646  */
    {(yyval.tnode)=(yyvsp[0].tnode);}
#line 1672 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1676 "y.tab.c" /* yacc.c:1646  */
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
#line 170 "task1.y" /* yacc.c:1906  */

int yyerror(char const *s)
{
	printf("yyerror %s",s);
}
int main(int argc, char *argv[])
{
	if(argc==2)
	{
		char *filename;
		int n=strlen(argv[1]);
		filename=(char *) malloc(n *sizeof(char));
		strcpy(filename,argv[1]);
		printf("filename:%s\n",filename);
		yyin=fopen(filename,"r");
			
	}
	else
	{	
		yyin=fopen("task1.txt","r");
	}	
	fp=fopen("task1.xsm","w");
	
	fprintf(fp,"%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n",0,2056,0,0,0,0,0,0); 
	fclose(fp);
	yyparse();
	return 0;
}
	
