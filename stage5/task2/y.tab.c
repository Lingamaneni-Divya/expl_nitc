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
	int currtype=nulltype;
	int Gdecl_end_flag=0;
	int rettype;
	struct Paramstruct *p;

#line 80 "y.tab.c" /* yacc.c:339  */

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
#line 15 "task1.y" /* yacc.c:355  */

	struct tnode *tnode;
	struct Gsymbol *Gsymbol;
	struct Paramstruct *paramstruct;
	struct Typenode *typenode;
      

#line 204 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 221 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  14
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   362

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  37
/* YYNRULES -- Number of rules.  */
#define YYNRULES  88
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  188

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
static const yytype_uint16 yyrline[] =
{
       0,    34,    34,    35,    36,    39,    43,    49,    50,    53,
      56,    57,    60,    61,    62,    63,    68,    69,    71,    81,
      92,    93,    95,   101,   106,   108,   114,   115,   117,   118,
     120,   122,   123,   125,   129,   134,   137,   141,   143,   146,
     148,   149,   164,   182,   184,   191,   192,   195,   196,   197,
     198,   199,   200,   201,   202,   205,   206,   208,   210,   211,
     213,   215,   218,   222,   225,   226,   227,   228,   229,   231,
     232,   233,   234,   235,   236,   238,   239,   240,   242,   243,
     244,   245,   246,   247,   249,   250,   254,   257,   259
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
  "NameParam", "ParamList", "PL", "Param", "LdeclBlock", "LDecList",
  "LDecl", "Lvarlist", "Type", "Paramtype", "Rettype", "FuncName", "Main",
  "MainBlock", "Body", "RetStmt", "Slist", "Stmt", "InputStmt",
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

#define YYPACT_NINF -82

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-82)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      68,    38,   -82,   -82,    25,   -12,     0,   -82,   -82,   -82,
     -82,    86,   -82,    43,   -82,   -12,   -82,    -5,     2,   -82,
     -82,    54,   -82,   -82,     8,    84,   -82,   -82,   -82,   -15,
     -82,    59,   100,   110,   -20,   -82,    43,   333,   128,   135,
      99,     6,   108,   113,   -82,   -82,   -82,   118,   123,   -82,
     189,   -82,   -24,   151,   155,   157,   158,   160,   163,   288,
     -82,   -82,   -82,   -82,   -82,   -82,   -82,   165,   162,   -82,
     156,   -82,   201,   164,   -82,   -82,   167,   -15,   -82,   -82,
      75,   -82,    29,    24,    29,   231,    29,    29,    29,   -82,
     -82,    29,   219,   -82,   -82,    29,   -82,   -82,   -82,    98,
     -82,   -82,   135,   190,   -82,   -82,    69,   -82,    29,   170,
     -82,   -82,   -82,   207,   194,   218,    65,   195,    67,    78,
     120,   252,   202,   263,   -82,   236,   196,   -82,   159,    29,
      29,    29,    29,    29,    29,    29,    29,    29,    29,    29,
      29,    29,    29,   -82,    29,   -82,   -82,   209,   210,   211,
     224,   225,   -82,   -82,   -82,   -82,   -82,   -82,   182,   182,
     -82,   -82,   -82,    36,    36,    36,    36,    36,    36,    36,
      36,    36,   -82,   -82,   -82,   -82,   333,   333,   300,   311,
     333,   213,   214,   322,   -82,   -82,   241,   -82
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,    37,    38,     0,     0,     0,     4,     6,    33,
      34,     0,     8,     0,     1,     0,    17,     0,     0,     3,
      40,     0,     5,     7,    12,     0,    11,    16,     2,     0,
      39,     0,     0,     0,     0,     9,     0,     0,     0,     0,
       0,     0,     0,     0,    35,    36,    15,     0,    22,    24,
       0,    10,     0,     0,     0,     0,     0,     0,     0,     0,
      46,    47,    48,    49,    50,    51,    52,     0,     0,    27,
       0,    29,     0,     0,    19,    21,     0,     0,    13,    14,
       0,    25,     0,     0,     0,     0,     0,     0,     0,    53,
      54,     0,     0,    45,    63,     0,    26,    28,    32,     0,
      18,    20,     0,     0,    23,    80,    79,    81,     0,     0,
      83,    82,    84,    87,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    30,     0,     0,    42,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    88,     0,    85,    58,     0,     0,     0,
       0,     0,    44,    43,    59,    31,    41,    78,    64,    65,
      66,    67,    68,    72,    71,    70,    69,    73,    74,    75,
      76,    77,    86,    55,    56,    57,     0,     0,     0,     0,
       0,     0,     0,     0,    61,    62,     0,    60
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -82,   -82,   -82,   -82,   270,   -82,   246,   -82,   268,   -82,
     243,   -82,   205,   216,   -82,   217,   -82,   -34,   -82,   286,
     -82,   -82,    11,   -36,   -82,   -81,   -58,   -82,   -82,   -82,
     -82,   -82,   -82,   -77,   -29,   150,   -37
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     4,     5,    11,    12,    25,    26,    15,    16,    17,
      47,    48,    49,    39,    70,    71,    99,    13,    50,    18,
      31,    21,     7,    40,    92,    59,    60,    61,    62,    63,
      64,    65,    66,   113,   110,   114,   111
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      68,    93,    37,    73,    72,   109,    30,   115,    67,   118,
     119,   120,    44,    45,   121,    38,    19,    82,   123,    83,
       2,     3,    68,    84,    46,    14,    28,   105,   106,   107,
      67,   128,   105,   106,   107,    20,    72,    20,    44,    45,
      29,   103,   129,   130,   131,   132,   133,    24,   117,    33,
      75,    34,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   126,   108,   112,     8,
       9,    10,   108,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   178,   179,    32,     1,   183,
       2,     3,    41,   140,   141,   142,    82,    44,    45,   147,
      82,   149,    83,    43,   140,   141,   142,    22,     9,    10,
      93,    93,   150,    35,    36,    93,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   124,   125,    68,
      68,    68,    68,    68,    42,    74,    68,    67,    67,    67,
      67,    67,    37,    77,    67,    78,   140,   141,   142,    69,
       9,    10,    79,    80,   151,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,    96,     9,    10,
     131,   132,   133,    81,    85,   140,   141,   142,    86,    89,
      87,    88,    90,   157,    94,    98,   140,   141,   142,    95,
     100,   101,   143,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   116,   127,   122,   145,   148,
     155,   153,   156,   140,   141,   142,   176,   144,   173,   174,
     175,   177,   184,   185,   140,   141,   142,   146,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     187,    23,    51,    27,    76,   104,     6,    97,   140,   141,
     142,   152,    52,   102,   172,     0,     0,     0,     0,   140,
     141,   142,   154,     0,    52,     0,     0,    53,    54,    55,
       0,     0,     0,    56,     0,    52,    57,    58,     0,    53,
      54,    55,    91,   180,   181,    56,    52,     0,    57,    58,
      53,    54,    55,     0,     0,     0,    56,    52,   182,    57,
      58,    53,    54,    55,     0,     0,   186,    56,     0,     0,
      57,    58,    53,    54,    55,     0,     0,     0,    56,     0,
       0,    57,    58
};

static const yytype_int16 yycheck[] =
{
      37,    59,    17,    39,    38,    82,     4,    84,    37,    86,
      87,    88,    32,    33,    91,    30,     5,    41,    95,    43,
      32,    33,    59,    47,    44,     0,    15,     3,     4,     5,
      59,   108,     3,     4,     5,    35,    70,    35,    32,    33,
      45,    77,     6,     7,     8,     9,    10,     4,    85,    41,
      44,    43,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   102,    43,    44,    31,
      32,    33,    43,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,   176,   177,    43,    30,   180,
      32,    33,    43,    36,    37,    38,    41,    32,    33,    44,
      41,    44,    43,     3,    36,    37,    38,    31,    32,    33,
     178,   179,    44,    39,    40,   183,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    39,    40,   176,
     177,   178,   179,   180,    44,    46,   183,   176,   177,   178,
     179,   180,    17,    45,   183,    42,    36,    37,    38,    31,
      32,    33,    44,    40,    44,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    31,    32,    33,
       8,     9,    10,     4,    43,    36,    37,    38,    43,    39,
      43,    43,    39,    44,    39,     4,    36,    37,    38,    47,
      46,    44,    42,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,     4,    46,    18,    44,    44,
       4,    39,    46,    36,    37,    38,    22,    40,    39,    39,
      39,    26,    39,    39,    36,    37,    38,    39,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      39,    11,    36,    15,    41,    80,     0,    70,    36,    37,
      38,    39,     4,    77,   144,    -1,    -1,    -1,    -1,    36,
      37,    38,    39,    -1,     4,    -1,    -1,    19,    20,    21,
      -1,    -1,    -1,    25,    -1,     4,    28,    29,    -1,    19,
      20,    21,    34,    23,    24,    25,     4,    -1,    28,    29,
      19,    20,    21,    -1,    -1,    -1,    25,     4,    27,    28,
      29,    19,    20,    21,    -1,    -1,    24,    25,    -1,    -1,
      28,    29,    19,    20,    21,    -1,    -1,    -1,    25,    -1,
      -1,    28,    29
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    30,    32,    33,    49,    50,    67,    70,    31,    32,
      33,    51,    52,    65,     0,    55,    56,    57,    67,    70,
      35,    69,    31,    52,     4,    53,    54,    56,    70,    45,
       4,    68,    43,    41,    43,    39,    40,    17,    30,    61,
      71,    43,    44,     3,    32,    33,    44,    58,    59,    60,
      66,    54,     4,    19,    20,    21,    25,    28,    29,    73,
      74,    75,    76,    77,    78,    79,    80,    82,    84,    31,
      62,    63,    65,    71,    46,    44,    58,    45,    42,    44,
      40,     4,    41,    43,    47,    43,    43,    43,    43,    39,
      39,    34,    72,    74,    39,    47,    31,    63,     4,    64,
      46,    44,    61,    71,    60,     3,     4,     5,    43,    81,
      82,    84,    44,    81,    83,    81,     4,    84,    81,    81,
      81,    81,    18,    81,    39,    40,    71,    46,    81,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      36,    37,    38,    42,    40,    44,    39,    44,    44,    44,
      44,    44,    39,    39,    39,     4,    46,    44,    81,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      81,    81,    83,    39,    39,    39,    22,    26,    73,    73,
      23,    24,    27,    73,    39,    39,    24,    39
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    48,    49,    49,    49,    50,    50,    51,    51,    52,
      53,    53,    54,    54,    54,    54,    55,    55,    56,    56,
      57,    57,    58,    59,    59,    60,    61,    61,    62,    62,
      63,    64,    64,    65,    65,    66,    66,    67,    67,    68,
      69,    70,    70,    71,    72,    73,    73,    74,    74,    74,
      74,    74,    74,    74,    74,    75,    75,    76,    77,    77,
      78,    78,    79,    80,    81,    81,    81,    81,    81,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      81,    81,    81,    81,    82,    82,    83,    83,    84
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     2,     1,     3,     2,     2,     1,     3,
       3,     1,     1,     4,     4,     3,     2,     1,     5,     4,
       5,     4,     1,     3,     1,     2,     3,     2,     2,     1,
       3,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     8,     7,     5,     3,     2,     1,     1,     1,     1,
       1,     1,     1,     2,     2,     5,     5,     5,     4,     4,
      10,     8,     8,     2,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     1,
       1,     1,     1,     1,     3,     4,     3,     1,     4
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
#line 34 "task1.y" /* yacc.c:1646  */
    { }
#line 1460 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 35 "task1.y" /* yacc.c:1646  */
    { }
#line 1466 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 36 "task1.y" /* yacc.c:1646  */
    { }
#line 1472 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 39 "task1.y" /* yacc.c:1646  */
    {
						print_Gsymbol_table();
					 	Gdecl_end_flag=1;
					}
#line 1481 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 43 "task1.y" /* yacc.c:1646  */
    {
						print_Gsymbol_table();
						Gdecl_end_flag=1;
					}
#line 1490 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 49 "task1.y" /* yacc.c:1646  */
    { }
#line 1496 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 50 "task1.y" /* yacc.c:1646  */
    { }
#line 1502 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 53 "task1.y" /* yacc.c:1646  */
    { }
#line 1508 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 56 "task1.y" /* yacc.c:1646  */
    { }
#line 1514 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 57 "task1.y" /* yacc.c:1646  */
    { }
#line 1520 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 60 "task1.y" /* yacc.c:1646  */
    {GInstall((yyvsp[0].tnode)->varname,currtype,1,NULL);}
#line 1526 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 61 "task1.y" /* yacc.c:1646  */
    {GInstall((yyvsp[-3].tnode)->varname,currtype,(yyvsp[-1].tnode)->val,NULL);}
#line 1532 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 62 "task1.y" /* yacc.c:1646  */
    {GInstall((yyvsp[-3].tnode)->varname,currtype,-1,(yyvsp[-1].paramstruct));}
#line 1538 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 63 "task1.y" /* yacc.c:1646  */
    {GInstall((yyvsp[-2].tnode)->varname,currtype,-1,NULL);}
#line 1544 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 72 "task1.y" /* yacc.c:1646  */
    { 
				
				
				print_Lsymbol_table(func_name);
				printf("ABSTRACT SYNTAX TREE FOR %s Function\n",func_name);
				printf("---------------------------------------\n");
				preorder((yyvsp[-1].tnode));
				reset_Lsymbol_table();
			}
#line 1558 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 82 "task1.y" /* yacc.c:1646  */
    { 
				
				
				print_Lsymbol_table(func_name);
				printf("ABSTRACT SYNTAX TREE FOR %s Function\n",func_name);
				printf("---------------------------------------\n");
				preorder((yyvsp[-1].tnode));
				reset_Lsymbol_table();
			}
#line 1572 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 92 "task1.y" /* yacc.c:1646  */
    {name_equivalence((yyvsp[-4].typenode)->type,(yyvsp[-3].tnode)->varname,(yyvsp[-1].paramstruct)); }
#line 1578 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 93 "task1.y" /* yacc.c:1646  */
    {name_equivalence((yyvsp[-3].typenode)->type,(yyvsp[-2].tnode)->varname,NULL); }
#line 1584 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 95 "task1.y" /* yacc.c:1646  */
    {	(yyval.paramstruct)=(yyvsp[0].paramstruct);
				if(Gdecl_end_flag==1)
				createLsymbolEntries((yyval.paramstruct));

			}
#line 1594 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 101 "task1.y" /* yacc.c:1646  */
    { //printf("This is formation of paramlist\n");
				(yyval.paramstruct)=PInstall((yyvsp[-2].paramstruct),(yyvsp[0].paramstruct));
			/*DOUBT!!!!!! WHY EVEN PRINT STATEMENT IS WORKING HERE*/
					
			}
#line 1604 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 106 "task1.y" /* yacc.c:1646  */
    {(yyval.paramstruct)=(yyvsp[0].paramstruct);}
#line 1610 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 108 "task1.y" /* yacc.c:1646  */
    {
					(yyval.paramstruct)=create_param_node((yyvsp[0].tnode)->varname,(yyvsp[-1].typenode)->type);
				}
#line 1618 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 114 "task1.y" /* yacc.c:1646  */
    { }
#line 1624 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 115 "task1.y" /* yacc.c:1646  */
    { }
#line 1630 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 117 "task1.y" /* yacc.c:1646  */
    { }
#line 1636 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 118 "task1.y" /* yacc.c:1646  */
    { }
#line 1642 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 120 "task1.y" /* yacc.c:1646  */
    { }
#line 1648 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 122 "task1.y" /* yacc.c:1646  */
    {LInstall((yyvsp[0].tnode)->varname,currtype);}
#line 1654 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 123 "task1.y" /* yacc.c:1646  */
    {LInstall((yyvsp[0].tnode)->varname,currtype);}
#line 1660 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 125 "task1.y" /* yacc.c:1646  */
    {
				(yyval.typenode)=create_typenode(inttype);
				currtype=(yyval.typenode)->type;
			}
#line 1669 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 129 "task1.y" /* yacc.c:1646  */
    {
				(yyval.typenode)=create_typenode(strtype);
				currtype=(yyval.typenode)->type;
			}
#line 1678 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 134 "task1.y" /* yacc.c:1646  */
    {(yyval.typenode)=create_typenode(inttype);
		  			
		}
#line 1686 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 137 "task1.y" /* yacc.c:1646  */
    {(yyval.typenode)=create_typenode(strtype);
						
			}
#line 1694 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 141 "task1.y" /* yacc.c:1646  */
    {(yyval.typenode)=create_typenode(inttype);
			rettype=inttype;}
#line 1701 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 143 "task1.y" /* yacc.c:1646  */
    {(yyval.typenode)=create_typenode(strtype);
		rettype=strtype;}
#line 1708 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 146 "task1.y" /* yacc.c:1646  */
    {(yyval.tnode)=(yyvsp[0].tnode);strcpy(func_name,(yyvsp[0].tnode)->varname);}
#line 1714 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 148 "task1.y" /* yacc.c:1646  */
    {strcpy(func_name,"MAIN");}
#line 1720 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 150 "task1.y" /* yacc.c:1646  */
    { 
				if((yyvsp[-7].typenode)->type!=inttype)
				{
				printf("Function main expects integer return type");
				exit(1);
				}
				
				print_Lsymbol_table("MAIN");
				printf("ABSTRACT SYNTAX TREE FOR MAIN Function\n");
				printf("---------------------------------------\n");
				preorder((yyvsp[-1].tnode));
				reset_Lsymbol_table();
				
		}
#line 1739 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 165 "task1.y" /* yacc.c:1646  */
    { 
				if((yyvsp[-6].typenode)->type!=inttype)
				{
				printf("Function main expects integer return type");
				exit(1);
				}

				print_Lsymbol_table("MAIN");
				printf("ABSTRACT SYNTAX TREE FOR MAIN Function\n");
				printf("---------------------------------------\n");
				preorder((yyvsp[-1].tnode));
				reset_Lsymbol_table();
				
		}
#line 1758 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 182 "task1.y" /* yacc.c:1646  */
    {(yyval.tnode)=create_tree(0,nulltype,NULL,conn_node,(yyvsp[-3].tnode),NULL,(yyvsp[-2].tnode));}
#line 1764 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 184 "task1.y" /* yacc.c:1646  */
    {(yyval.tnode)=create_tree(0,(yyvsp[-1].tnode)->type,func_name,ret_node,(yyvsp[-1].tnode),NULL,NULL);
			}
#line 1771 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 191 "task1.y" /* yacc.c:1646  */
    {(yyval.tnode)=create_tree(0,nulltype,NULL,conn_node,(yyvsp[-1].tnode),NULL,(yyvsp[0].tnode));}
#line 1777 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 192 "task1.y" /* yacc.c:1646  */
    {(yyval.tnode)=(yyvsp[0].tnode);}
#line 1783 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 195 "task1.y" /* yacc.c:1646  */
    {(yyval.tnode)=(yyvsp[0].tnode);}
#line 1789 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 196 "task1.y" /* yacc.c:1646  */
    {(yyval.tnode)=(yyvsp[0].tnode);}
#line 1795 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 197 "task1.y" /* yacc.c:1646  */
    {(yyval.tnode)=(yyvsp[0].tnode);}
#line 1801 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 198 "task1.y" /* yacc.c:1646  */
    {(yyval.tnode)=(yyvsp[0].tnode);}
#line 1807 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 199 "task1.y" /* yacc.c:1646  */
    {(yyval.tnode)=(yyvsp[0].tnode);}
#line 1813 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 200 "task1.y" /* yacc.c:1646  */
    {(yyval.tnode)=(yyvsp[0].tnode);}
#line 1819 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 201 "task1.y" /* yacc.c:1646  */
    {(yyval.tnode)=create_tree(0,nulltype,NULL,continue_node,NULL,NULL,NULL);}
#line 1825 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 202 "task1.y" /* yacc.c:1646  */
    {(yyval.tnode)=create_tree(0,nulltype,NULL,break_node,NULL,NULL,NULL);}
#line 1831 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 205 "task1.y" /* yacc.c:1646  */
    {(yyval.tnode)=create_tree(0,nulltype,NULL,read_node,(yyvsp[-2].tnode),NULL,NULL);}
#line 1837 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 206 "task1.y" /* yacc.c:1646  */
    {(yyval.tnode)=create_tree(0,nulltype,NULL,read_node,(yyvsp[-2].tnode),NULL,NULL);}
#line 1843 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 208 "task1.y" /* yacc.c:1646  */
    {(yyval.tnode)=create_tree(0,nulltype,NULL,write_node,(yyvsp[-2].tnode),NULL,NULL);}
#line 1849 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 210 "task1.y" /* yacc.c:1646  */
    {(yyval.tnode)=create_tree(0,nulltype,"=",assg_node,(yyvsp[-3].tnode),NULL,(yyvsp[-1].tnode));}
#line 1855 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 211 "task1.y" /* yacc.c:1646  */
    {(yyval.tnode)=create_tree(0,nulltype,"=",assg_node,(yyvsp[-3].tnode),NULL,(yyvsp[-1].tnode));}
#line 1861 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 214 "task1.y" /* yacc.c:1646  */
    {(yyval.tnode)=create_tree(0,nulltype,NULL,if_node,(yyvsp[-7].tnode),(yyvsp[-4].tnode),(yyvsp[-2].tnode));}
#line 1867 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 216 "task1.y" /* yacc.c:1646  */
    {(yyval.tnode)=create_tree(0,nulltype,NULL,if_node,(yyvsp[-5].tnode),(yyvsp[-2].tnode),NULL);}
#line 1873 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 219 "task1.y" /* yacc.c:1646  */
    {(yyval.tnode)=create_tree(0,nulltype,NULL,while_node,(yyvsp[-5].tnode),NULL,(yyvsp[-2].tnode));}
#line 1879 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 222 "task1.y" /* yacc.c:1646  */
    {(yyval.tnode)=(yyvsp[-1].tnode);}
#line 1885 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 225 "task1.y" /* yacc.c:1646  */
    {(yyval.tnode)=create_tree(0,inttype,"+",aop_node,(yyvsp[-2].tnode),NULL,(yyvsp[0].tnode));}
#line 1891 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 226 "task1.y" /* yacc.c:1646  */
    {(yyval.tnode)=create_tree(0,inttype,"-",aop_node,(yyvsp[-2].tnode),NULL,(yyvsp[0].tnode));}
#line 1897 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 227 "task1.y" /* yacc.c:1646  */
    {(yyval.tnode)=create_tree(0,inttype,"*",aop_node,(yyvsp[-2].tnode),NULL,(yyvsp[0].tnode));}
#line 1903 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 228 "task1.y" /* yacc.c:1646  */
    {(yyval.tnode)=create_tree(0,inttype,"/",aop_node,(yyvsp[-2].tnode),NULL,(yyvsp[0].tnode));}
#line 1909 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 229 "task1.y" /* yacc.c:1646  */
    {(yyval.tnode)=create_tree(0,inttype,"%",aop_node,(yyvsp[-2].tnode),NULL,(yyvsp[0].tnode));}
#line 1915 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 231 "task1.y" /* yacc.c:1646  */
    {(yyval.tnode)=create_tree(0,booltype,"<=",lop_node,(yyvsp[-2].tnode),NULL,(yyvsp[0].tnode));}
#line 1921 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 232 "task1.y" /* yacc.c:1646  */
    {(yyval.tnode)=create_tree(0,booltype,">=",lop_node,(yyvsp[-2].tnode),NULL,(yyvsp[0].tnode));}
#line 1927 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 233 "task1.y" /* yacc.c:1646  */
    {(yyval.tnode)=create_tree(0,booltype,"<",lop_node,(yyvsp[-2].tnode),NULL,(yyvsp[0].tnode));}
#line 1933 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 234 "task1.y" /* yacc.c:1646  */
    {(yyval.tnode)=create_tree(0,booltype,">",lop_node,(yyvsp[-2].tnode),NULL,(yyvsp[0].tnode));}
#line 1939 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 235 "task1.y" /* yacc.c:1646  */
    {(yyval.tnode)=create_tree(0,booltype,"==",lop_node,(yyvsp[-2].tnode),NULL,(yyvsp[0].tnode));}
#line 1945 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 236 "task1.y" /* yacc.c:1646  */
    {(yyval.tnode)=create_tree(0,booltype,"!=",lop_node,(yyvsp[-2].tnode),NULL,(yyvsp[0].tnode));}
#line 1951 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 238 "task1.y" /* yacc.c:1646  */
    {(yyval.tnode)=create_tree(0,booltype,"&&",lop_node,(yyvsp[-2].tnode),NULL,(yyvsp[0].tnode));}
#line 1957 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 239 "task1.y" /* yacc.c:1646  */
    {(yyval.tnode)=create_tree(0,booltype,"||",lop_node,(yyvsp[-2].tnode),NULL,(yyvsp[0].tnode));}
#line 1963 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 240 "task1.y" /* yacc.c:1646  */
    {(yyval.tnode)=create_tree(0,booltype,"!",lop_node,(yyvsp[-2].tnode),NULL,(yyvsp[0].tnode));}
#line 1969 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 242 "task1.y" /* yacc.c:1646  */
    {(yyval.tnode)=(yyvsp[-1].tnode);}
#line 1975 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 243 "task1.y" /* yacc.c:1646  */
    {(yyval.tnode)=(yyvsp[0].tnode);}
#line 1981 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 244 "task1.y" /* yacc.c:1646  */
    {(yyval.tnode)=(yyvsp[0].tnode);}
#line 1987 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 245 "task1.y" /* yacc.c:1646  */
    {(yyval.tnode)=(yyvsp[0].tnode);}
#line 1993 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 246 "task1.y" /* yacc.c:1646  */
    {(yyval.tnode)=(yyvsp[0].tnode);}
#line 1999 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 247 "task1.y" /* yacc.c:1646  */
    {(yyval.tnode)=(yyvsp[0].tnode);}
#line 2005 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 249 "task1.y" /* yacc.c:1646  */
    {(yyval.tnode)=create_tree(0,nulltype,(yyvsp[-2].tnode)->varname,func_node,NULL,NULL,NULL);}
#line 2011 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 250 "task1.y" /* yacc.c:1646  */
    {(yyval.tnode)=create_tree(0,nulltype,(yyvsp[-3].tnode)->varname,func_node,(yyvsp[-1].tnode),NULL,NULL);}
#line 2017 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 254 "task1.y" /* yacc.c:1646  */
    {(yyvsp[-2].tnode)->middle=(yyvsp[0].tnode);
				  (yyval.tnode)=(yyvsp[-2].tnode);
				 	}
#line 2025 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 257 "task1.y" /* yacc.c:1646  */
    {(yyval.tnode)=(yyvsp[0].tnode);}
#line 2031 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 259 "task1.y" /* yacc.c:1646  */
    {(yyval.tnode)=create_tree(0,(yyvsp[-3].tnode)->type,(yyvsp[-3].tnode)->varname,arr_node,(yyvsp[-1].tnode),NULL,NULL);}
#line 2037 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2041 "y.tab.c" /* yacc.c:1646  */
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
#line 261 "task1.y" /* yacc.c:1906  */

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
	
