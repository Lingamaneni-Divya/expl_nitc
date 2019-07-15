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
	int yyerror(char const *s);
	int yywrap();
	FILE *fp,*yyin;
	int size;
	struct Typetable *currtype;
	int Gdecl_end_flag=0;

#line 79 "y.tab.c" /* yacc.c:339  */

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
    NOTTK = 293,
    TYPE = 294,
    ENDTYPE = 295,
    NULLTK = 296,
    ALLOC = 297,
    INITIALIZE = 298,
    FREE = 299
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
#define TYPE 294
#define ENDTYPE 295
#define NULLTK 296
#define ALLOC 297
#define INITIALIZE 298
#define FREE 299

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 14 "task1.y" /* yacc.c:355  */

	struct tnode *tnode;
	struct Gsymbol *Gsymbol;
	struct Paramstruct *paramstruct;
	struct Typetable *Typetable;
	//struct Typenode *typenode;
      

#line 216 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 233 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  7
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   472

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  55
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  47
/* YYNRULES -- Number of rules.  */
#define YYNRULES  115
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  240

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   299

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
      51,    52,     2,     2,    48,     2,    54,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    47,
       2,    53,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    49,     2,    50,     2,     2,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    36,    36,    37,    38,    42,    43,    45,    46,    49,
      49,    59,    60,    62,    64,    65,    66,    71,    81,    92,
      93,    96,    99,   100,   103,   107,   110,   114,   119,   124,
     125,   127,   132,   133,   134,   139,   140,   142,   152,   163,
     167,   172,   173,   174,   175,   177,   178,   180,   181,   183,
     185,   186,   188,   192,   196,   201,   203,   214,   226,   231,
     240,   243,   246,   247,   248,   249,   250,   251,   252,   253,
     256,   261,   265,   269,   274,   279,   285,   291,   297,   306,
     309,   314,   318,   323,   329,   331,   337,   346,   352,   357,
     363,   369,   376,   382,   388,   394,   400,   406,   413,   419,
     425,   432,   433,   434,   435,   436,   437,   438,   439,   441,
     463,   485,   491,   500,   507,   513
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
  "RETURN", "MAINFN", "ANDTK", "ORTK", "NOTTK", "TYPE", "ENDTYPE",
  "NULLTK", "ALLOC", "INITIALIZE", "FREE", "'{'", "'}'", "';'", "','",
  "'['", "']'", "'('", "')'", "'='", "'.'", "$accept", "Program",
  "TypeDefBlock", "TypeDefList", "TypeDef", "$@1", "FieldDeclList",
  "FieldDecl", "TypeName", "GdeclBlock", "Gdecllist", "Gdecl", "Gvarlist",
  "Gvar", "ParamList", "PL", "Param", "ParamTypeName", "FDefBlock", "Fdef",
  "NameParam", "FuncName", "RetTypeName", "LdeclBlock", "LDecList",
  "LDecl", "Lvarlist", "Type", "Main", "MainBlock", "Body", "RetStmt",
  "Slist", "Stmt", "InputStmt", "OutputStmt", "AssgStmt", "dexpr",
  "IfStmt", "WhileStmt", "FuncStmt", "FreeStmt", "expr", "Field", "Fcall",
  "ArgList", "Sarray", YY_NULLPTR
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
     295,   296,   297,   298,   299,   123,   125,    59,    44,    91,
      93,    40,    41,    61,    46
};
# endif

#define YYPACT_NINF -125

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-125)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -31,    19,    33,    13,    -9,     7,  -125,  -125,    38,    14,
       6,  -125,  -125,  -125,  -125,  -125,  -125,  -125,  -125,   136,
    -125,    53,  -125,    25,  -125,    14,  -125,     6,  -125,    47,
      92,  -125,   218,  -125,  -125,    24,    15,  -125,    48,  -125,
    -125,   -12,  -125,    58,  -125,  -125,  -125,   106,  -125,   122,
     157,    20,  -125,    53,   114,   396,   188,   153,   128,    22,
    -125,  -125,   134,   138,  -125,  -125,  -125,  -125,   141,   170,
    -125,   219,  -125,   -12,   102,   173,   177,   179,   180,   185,
     186,   183,   374,  -125,  -125,  -125,  -125,  -125,  -125,  -125,
    -125,    52,   191,   182,  -125,   213,  -125,   235,   194,  -125,
    -125,   190,  -125,  -125,  -125,   243,  -125,   153,   197,    63,
      -1,    56,   244,   245,    63,    63,    63,  -125,  -125,   273,
      63,   260,  -125,    63,   275,  -125,    63,  -125,  -125,  -125,
     100,  -125,  -125,  -125,   234,  -125,  -125,   -19,  -125,    63,
    -125,    63,   247,   227,  -125,  -125,  -125,   435,   -35,   231,
     236,   238,   258,  -125,    41,    89,   237,   109,   121,   189,
      90,   175,   300,   239,   312,  -125,   354,  -125,   284,  -125,
     156,   200,    63,    63,    63,    63,    63,    63,    63,    63,
      63,    63,    63,    63,    63,  -125,    63,  -125,   240,   241,
    -125,  -125,   249,   251,   252,   253,   268,   265,   254,   255,
    -125,  -125,  -125,  -125,  -125,  -125,   103,   103,  -125,  -125,
    -125,   156,   156,   156,   156,   156,   156,   156,   156,   435,
    -125,  -125,  -125,  -125,  -125,  -125,   396,   396,  -125,  -125,
     352,   313,   396,   256,   257,   385,  -125,  -125,   282,  -125
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       6,     0,     0,     0,     0,     0,     8,     1,     0,     0,
       0,     4,     9,     5,     7,    54,    18,    52,    53,     0,
      20,     0,    55,     0,    44,    42,    43,     0,    36,     0,
       0,     3,     0,    17,    19,    24,     0,    23,     0,    35,
       2,     0,    41,     0,    16,    14,    15,     0,    12,     0,
       0,     0,    21,     0,     0,     0,     0,     0,     0,     0,
      10,    11,     0,     0,    34,    32,    33,    27,     0,    28,
      30,     0,    22,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    61,    62,    63,    64,    65,    66,    67,
      68,     0,     0,     0,    46,     0,    48,     0,     0,    38,
      40,     0,    13,    25,    26,     0,    31,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    69,    70,     0,
       0,     0,    60,     0,     0,    84,     0,    45,    47,    51,
       0,    37,    39,    29,     0,    57,   103,   102,   104,     0,
     107,     0,     0,   108,   106,   105,   111,   114,     0,     0,
       0,     0,     0,   109,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   110,     0,    49,     0,    56,
     100,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   115,     0,   112,     0,     0,
      78,    75,     0,     0,     0,     0,     0,     0,     0,     0,
      59,    58,    77,    76,    50,   101,    87,    88,    89,    90,
      91,    95,    94,    93,    92,    96,    97,    98,    99,   113,
      79,    80,    71,    73,    72,    74,     0,     0,    86,    85,
       0,     0,     0,     0,     0,     0,    82,    83,     0,    81
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -125,  -125,  -125,  -125,   325,  -125,  -125,   288,  -125,  -125,
    -125,   320,  -125,   278,   285,  -125,   246,  -125,  -125,   316,
    -125,  -125,  -125,   272,  -125,   259,  -125,   -47,  -125,     2,
     -51,  -125,  -124,   -81,  -125,  -125,  -125,  -125,  -125,  -125,
    -125,  -125,   -95,   -55,   -41,  -125,   -48
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     5,     6,    32,    47,    48,    49,    10,
      19,    20,    36,    37,    68,    69,    70,    71,    27,    28,
      29,    43,    30,    57,    95,    96,   130,    21,    23,    11,
      58,   121,    82,    83,    84,    85,    86,   151,    87,    88,
      89,    90,   142,   143,   144,   148,   145
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      91,   122,   136,   137,   138,    55,    98,    93,     1,    97,
      24,     4,    31,   186,    92,   147,   152,   187,    56,   157,
     158,   159,   108,     4,    64,   162,    64,    91,   164,    40,
     109,   166,   110,     7,    93,   112,    12,   139,    25,    26,
     140,    92,    15,     8,   170,     9,   171,    13,    97,    22,
     141,   146,    65,    66,    65,    66,   134,    35,   155,   136,
     137,   138,    52,    53,   161,   156,   136,   137,   138,    16,
      17,    18,    67,    50,   100,    51,    38,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     109,   219,    41,   192,   139,   112,    42,   140,   149,   150,
      54,   139,   230,   231,   140,   123,   124,   141,   235,    59,
      44,   174,   175,   176,   141,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,    62,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,    45,    46,
      15,   193,   198,   124,   112,   183,   184,   167,   168,   122,
     122,   109,    60,   110,   122,   111,   112,   183,   184,    73,
      63,   195,   172,   173,   174,   175,   176,    33,    17,    18,
      55,    91,    91,   196,    99,    91,    91,    91,    93,    93,
      91,   102,    93,    93,    93,    92,    92,    93,   103,    92,
      92,    92,    15,   104,    92,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,    15,   105,    94,
      17,    18,    44,   106,   113,   183,   184,   199,   114,   124,
     115,   116,   117,   118,   119,   126,   183,   184,   125,   129,
     131,   197,   132,   135,   127,    17,    18,    64,   153,   154,
      45,    46,   205,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,    65,    66,   160,   163,   165,
     169,   124,   188,   183,   184,   190,   201,   189,   204,   194,
     226,   227,   220,   221,   183,   184,   222,   185,   223,   224,
     225,   228,   229,   236,   237,   191,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,    74,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   239,
      14,    72,    75,    76,    77,    61,   183,   184,    78,    34,
     234,    79,    80,    39,   101,   107,     0,   200,   183,   184,
       0,   133,     0,     0,   128,     0,    74,    81,     0,   202,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,    75,    76,    77,     0,   232,   233,    78,    74,     0,
      79,    80,     0,     0,     0,     0,     0,     0,     0,    74,
     183,   184,     0,    75,    76,    77,    81,     0,     0,    78,
      74,   203,    79,    80,    75,    76,    77,     0,   120,   238,
      78,     0,     0,    79,    80,    75,    76,    77,    81,     0,
       0,    78,     0,     0,    79,    80,     0,     0,     0,    81,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      81,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   183,   184
};

static const yytype_int16 yycheck[] =
{
      55,    82,     3,     4,     5,    17,    57,    55,    39,    56,
       4,     4,    10,    48,    55,   110,   111,    52,    30,   114,
     115,   116,    73,     4,     4,   120,     4,    82,   123,    27,
      49,   126,    51,     0,    82,    54,    45,    38,    32,    33,
      41,    82,     4,    30,   139,    32,   141,    40,    95,    35,
      51,    52,    32,    33,    32,    33,   107,     4,   113,     3,
       4,     5,    47,    48,   119,   113,     3,     4,     5,    31,
      32,    33,    52,    49,    52,    51,    51,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
      49,   186,    45,    52,    38,    54,     4,    41,    42,    43,
      52,    38,   226,   227,    41,    53,    54,    51,   232,    51,
       4,     8,     9,    10,    51,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,     4,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    32,    33,
       4,    52,    52,    54,    54,    36,    37,    47,    48,   230,
     231,    49,    46,    51,   235,    53,    54,    36,    37,    45,
       3,    52,     6,     7,     8,     9,    10,    31,    32,    33,
      17,   226,   227,    52,    46,   230,   231,   232,   226,   227,
     235,    47,   230,   231,   232,   226,   227,   235,    50,   230,
     231,   232,     4,    52,   235,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,     4,    48,    31,
      32,    33,     4,     4,    51,    36,    37,    52,    51,    54,
      51,    51,    47,    47,    51,    53,    36,    37,    47,     4,
      46,    52,    52,    46,    31,    32,    33,     4,     4,     4,
      32,    33,    52,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    32,    33,     4,    18,     4,
      46,    54,    51,    36,    37,    47,    47,    51,     4,    52,
      22,    26,    52,    52,    36,    37,    47,    50,    47,    47,
      47,    47,    47,    47,    47,    47,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,     4,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    47,
       5,    53,    19,    20,    21,    47,    36,    37,    25,    19,
      27,    28,    29,    27,    59,    73,    -1,    47,    36,    37,
      -1,   105,    -1,    -1,    95,    -1,     4,    44,    -1,    47,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    19,    20,    21,    -1,    23,    24,    25,     4,    -1,
      28,    29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     4,
      36,    37,    -1,    19,    20,    21,    44,    -1,    -1,    25,
       4,    47,    28,    29,    19,    20,    21,    -1,    34,    24,
      25,    -1,    -1,    28,    29,    19,    20,    21,    44,    -1,
      -1,    25,    -1,    -1,    28,    29,    -1,    -1,    -1,    44,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      44,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    36,    37
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    39,    56,    57,     4,    58,    59,     0,    30,    32,
      64,    84,    45,    40,    59,     4,    31,    32,    33,    65,
      66,    82,    35,    83,     4,    32,    33,    73,    74,    75,
      77,    84,    60,    31,    66,     4,    67,    68,    51,    74,
      84,    45,     4,    76,     4,    32,    33,    61,    62,    63,
      49,    51,    47,    48,    52,    17,    30,    78,    85,    51,
      46,    62,     4,     3,     4,    32,    33,    52,    69,    70,
      71,    72,    68,    45,     4,    19,    20,    21,    25,    28,
      29,    44,    87,    88,    89,    90,    91,    93,    94,    95,
      96,    98,    99,   101,    31,    79,    80,    82,    85,    46,
      52,    69,    47,    50,    52,    48,     4,    78,    85,    49,
      51,    53,    54,    51,    51,    51,    51,    47,    47,    51,
      34,    86,    88,    53,    54,    47,    53,    31,    80,     4,
      81,    46,    52,    71,    85,    46,     3,     4,     5,    38,
      41,    51,    97,    98,    99,   101,    52,    97,   100,    42,
      43,    92,    97,     4,     4,    98,   101,    97,    97,    97,
       4,    98,    97,    18,    97,     4,    97,    47,    48,    46,
      97,    97,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    36,    37,    50,    48,    52,    51,    51,
      47,    47,    52,    52,    52,    52,    52,    52,    52,    52,
      47,    47,    47,    47,     4,    52,    97,    97,    97,    97,
      97,    97,    97,    97,    97,    97,    97,    97,    97,    97,
      52,    52,    47,    47,    47,    47,    22,    26,    47,    47,
      87,    87,    23,    24,    27,    87,    47,    47,    24,    47
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    55,    56,    56,    56,    57,    57,    58,    58,    60,
      59,    61,    61,    62,    63,    63,    63,    64,    64,    65,
      65,    66,    67,    67,    68,    68,    68,    68,    69,    70,
      70,    71,    72,    72,    72,    73,    73,    74,    74,    75,
      75,    76,    77,    77,    77,    78,    78,    79,    79,    80,
      81,    81,    82,    82,    82,    83,    84,    84,    85,    86,
      87,    87,    88,    88,    88,    88,    88,    88,    88,    88,
      88,    89,    89,    89,    90,    91,    91,    91,    91,    92,
      92,    93,    93,    94,    95,    96,    96,    97,    97,    97,
      97,    97,    97,    97,    97,    97,    97,    97,    97,    97,
      97,    97,    97,    97,    97,    97,    97,    97,    97,    98,
      98,    99,    99,   100,   100,   101
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     4,     3,     2,     3,     0,     2,     1,     0,
       5,     2,     1,     3,     1,     1,     1,     3,     2,     2,
       1,     3,     3,     1,     1,     4,     4,     3,     1,     3,
       1,     2,     1,     1,     1,     2,     1,     5,     4,     5,
       4,     1,     1,     1,     1,     3,     2,     2,     1,     3,
       3,     1,     1,     1,     1,     1,     8,     7,     5,     3,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       2,     5,     5,     5,     5,     4,     4,     4,     4,     3,
       3,    10,     8,     8,     2,     5,     5,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     3,     1,     1,     1,     1,     1,     1,     1,     3,
       3,     3,     4,     3,     1,     4
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
#line 36 "task1.y" /* yacc.c:1646  */
    { }
#line 1524 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 37 "task1.y" /* yacc.c:1646  */
    { }
#line 1530 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 38 "task1.y" /* yacc.c:1646  */
    { }
#line 1536 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 42 "task1.y" /* yacc.c:1646  */
    {print_Typetable(); }
#line 1542 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 43 "task1.y" /* yacc.c:1646  */
    {print_Typetable();}
#line 1548 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 45 "task1.y" /* yacc.c:1646  */
    { }
#line 1554 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 46 "task1.y" /* yacc.c:1646  */
    { }
#line 1560 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 49 "task1.y" /* yacc.c:1646  */
    {TInstall((yyvsp[-1].tnode)->varname,0,NULL);}
#line 1566 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 50 "task1.y" /* yacc.c:1646  */
    {
							 
						         Typetable *ttable=TLookup((yyvsp[-4].tnode)->varname);
							 ttable->fields=fieldlist_head;
							 ttable->size=getSize(ttable);
							 reset_fieldlist();
							 }
#line 1578 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 59 "task1.y" /* yacc.c:1646  */
    { }
#line 1584 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 60 "task1.y" /* yacc.c:1646  */
    { }
#line 1590 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 62 "task1.y" /* yacc.c:1646  */
    {FInstall((yyvsp[-1].tnode)->varname,(yyvsp[-2].Typetable)); }
#line 1596 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 64 "task1.y" /* yacc.c:1646  */
    {(yyval.Typetable)=TLookup("int"); }
#line 1602 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 65 "task1.y" /* yacc.c:1646  */
    {(yyval.Typetable)=TLookup("str"); }
#line 1608 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 66 "task1.y" /* yacc.c:1646  */
    {(yyval.Typetable)=TLookup((yyvsp[0].tnode)->varname); }
#line 1614 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 71 "task1.y" /* yacc.c:1646  */
    {
						print_Gsymbol_table();
					 	Gdecl_end_flag=1;
						fp=fopen("task1.xsm","a"); 
						fprintf(fp,"MOV SP, %d\n",sp);
						fprintf(fp,"CALL F0\n");
						fclose(fp);
       						scall("Exit",0,0);
						
					}
#line 1629 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 81 "task1.y" /* yacc.c:1646  */
    {
						print_Gsymbol_table();
					 	Gdecl_end_flag=1;
						fp=fopen("task1.xsm","a"); 
						fprintf(fp,"MOV SP, %d\n",sp);
						fprintf(fp,"CALL F0\n");
						fclose(fp);
       						scall("Exit",0,0);
					}
#line 1643 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 92 "task1.y" /* yacc.c:1646  */
    { }
#line 1649 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 93 "task1.y" /* yacc.c:1646  */
    { }
#line 1655 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 96 "task1.y" /* yacc.c:1646  */
    { }
#line 1661 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 99 "task1.y" /* yacc.c:1646  */
    { }
#line 1667 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 100 "task1.y" /* yacc.c:1646  */
    { }
#line 1673 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 103 "task1.y" /* yacc.c:1646  */
    {
						GInstall((yyvsp[0].tnode)->varname,currtype,1,paramlist_head);
						reset_paramlist();
					}
#line 1682 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 107 "task1.y" /* yacc.c:1646  */
    {
						GInstall((yyvsp[-3].tnode)->varname,currtype,(yyvsp[-1].tnode)->val,paramlist_head);
						reset_paramlist();}
#line 1690 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 110 "task1.y" /* yacc.c:1646  */
    {
						GInstall((yyvsp[-3].tnode)->varname,currtype,-1,paramlist_head); 
						reset_paramlist();
					}
#line 1699 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 114 "task1.y" /* yacc.c:1646  */
    {
						GInstall((yyvsp[-2].tnode)->varname,currtype,-1,paramlist_head);
						reset_paramlist();}
#line 1707 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 119 "task1.y" /* yacc.c:1646  */
    {
						if(Gdecl_end_flag==1)
					 	createLsymbolEntries(paramlist_head);
					}
#line 1716 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 124 "task1.y" /* yacc.c:1646  */
    { }
#line 1722 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 125 "task1.y" /* yacc.c:1646  */
    { }
#line 1728 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 127 "task1.y" /* yacc.c:1646  */
    {
						(yyval.paramstruct)=create_param_node((yyvsp[0].tnode)->varname,(yyvsp[-1].Typetable));
						PInstall((yyval.paramstruct));
					}
#line 1737 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 132 "task1.y" /* yacc.c:1646  */
    {(yyval.Typetable)=TLookup("int"); }
#line 1743 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 133 "task1.y" /* yacc.c:1646  */
    {(yyval.Typetable)=TLookup("str"); }
#line 1749 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 134 "task1.y" /* yacc.c:1646  */
    {(yyval.Typetable)=TLookup((yyvsp[0].tnode)->varname); }
#line 1755 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 143 "task1.y" /* yacc.c:1646  */
    { 
				print_Lsymbol_table(func_name);
				printf("ABSTRACT SYNTAX TREE FOR %s Function\n",func_name);
				//printf("------------GENERATED SUCCESSFULLY---------------------------\n");
				//preorder($4);
				printf("---------CODEGEN------\n");
				generate_code((yyvsp[-1].tnode),func_name);
				reset_Lsymbol_table();
					}
#line 1769 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 152 "task1.y" /* yacc.c:1646  */
    { 
				print_Lsymbol_table(func_name);
				printf("ABSTRACT SYNTAX TREE FOR %s Function\n",func_name);
				//printf("-------------GENERATED SUCCESSFULLY--------------------------\n");
				//preorder($3);
				printf("---------CODEGEN------\n");
				generate_code((yyvsp[-1].tnode),func_name);
				reset_Lsymbol_table();

						}
#line 1784 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 163 "task1.y" /* yacc.c:1646  */
    {
						name_equivalence((yyvsp[-4].Typetable),(yyvsp[-3].tnode)->varname,paramlist_head); 
						reset_paramlist();
					      }
#line 1793 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 167 "task1.y" /* yacc.c:1646  */
    {
						name_equivalence((yyvsp[-3].Typetable),(yyvsp[-2].tnode)->varname,NULL);
						reset_paramlist(); 
					      }
#line 1802 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 172 "task1.y" /* yacc.c:1646  */
    {(yyval.tnode)=(yyvsp[0].tnode);strcpy(func_name,(yyvsp[0].tnode)->varname);}
#line 1808 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 173 "task1.y" /* yacc.c:1646  */
    {(yyval.Typetable)=TLookup("int"); }
#line 1814 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 174 "task1.y" /* yacc.c:1646  */
    {(yyval.Typetable)=TLookup("str"); }
#line 1820 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 175 "task1.y" /* yacc.c:1646  */
    {(yyval.Typetable)=TLookup((yyvsp[0].tnode)->varname); }
#line 1826 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 177 "task1.y" /* yacc.c:1646  */
    { }
#line 1832 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 178 "task1.y" /* yacc.c:1646  */
    { }
#line 1838 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 180 "task1.y" /* yacc.c:1646  */
    { }
#line 1844 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 181 "task1.y" /* yacc.c:1646  */
    { }
#line 1850 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 183 "task1.y" /* yacc.c:1646  */
    { }
#line 1856 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 185 "task1.y" /* yacc.c:1646  */
    {LInstall((yyvsp[0].tnode)->varname,currtype); }
#line 1862 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 186 "task1.y" /* yacc.c:1646  */
    {LInstall((yyvsp[0].tnode)->varname,currtype); }
#line 1868 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 188 "task1.y" /* yacc.c:1646  */
    {
				(yyval.Typetable)=TLookup("int");
				currtype=(yyval.Typetable);
			}
#line 1877 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 192 "task1.y" /* yacc.c:1646  */
    {
				(yyval.Typetable)=TLookup("str");
				currtype=(yyval.Typetable);
			}
#line 1886 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 196 "task1.y" /* yacc.c:1646  */
    { 
				(yyval.Typetable)=TLookup((yyvsp[0].tnode)->varname);
				currtype=(yyval.Typetable);
			}
#line 1895 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 201 "task1.y" /* yacc.c:1646  */
    {strcpy(func_name,"MAIN");}
#line 1901 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 204 "task1.y" /* yacc.c:1646  */
    {
				print_Lsymbol_table("MAIN");
				printf("ABSTRACT SYNTAX TREE FOR MAIN Function\n");
				//printf("---------------GENERATED SUCCESSFULLY------------------------\n");
				//preorder($7);
				printf("---------CODEGEN------\n");
				generate_code((yyvsp[-1].tnode),func_name);
				reset_Lsymbol_table();

		}
#line 1916 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 215 "task1.y" /* yacc.c:1646  */
    {

				print_Lsymbol_table("MAIN");
				printf("ABSTRACT SYNTAX TREE FOR MAIN Function\n");
				//printf("-------------GENERATED SUCCESSFULLY--------------------------\n");
				//preorder($6);
				printf("---------CODEGEN------\n");
				generate_code((yyvsp[-1].tnode),func_name);
				reset_Lsymbol_table();
		}
#line 1931 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 227 "task1.y" /* yacc.c:1646  */
    {	//printf("tree call 1:\n");
				(yyval.tnode)=create_tree(0,TLookup("null"),NULL,conn_node,(yyvsp[-3].tnode),NULL,(yyvsp[-2].tnode));
			 }
#line 1939 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 231 "task1.y" /* yacc.c:1646  */
    {	//printf("tree call 2:\n");
				typecheck((yyvsp[-1].tnode));
				(yyval.tnode)=create_tree(0,(yyvsp[-1].tnode)->type,func_name,ret_node,(yyvsp[-1].tnode),NULL,NULL);
			 }
#line 1948 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 240 "task1.y" /* yacc.c:1646  */
    {	//printf("tree call 3:\n");
				(yyval.tnode)=create_tree(0,TLookup("null"),NULL,conn_node,(yyvsp[-1].tnode),NULL,(yyvsp[0].tnode));
			}
#line 1956 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 243 "task1.y" /* yacc.c:1646  */
    {(yyval.tnode)=(yyvsp[0].tnode); }
#line 1962 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 246 "task1.y" /* yacc.c:1646  */
    {(yyval.tnode)=(yyvsp[0].tnode);}
#line 1968 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 247 "task1.y" /* yacc.c:1646  */
    {(yyval.tnode)=(yyvsp[0].tnode);}
#line 1974 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 248 "task1.y" /* yacc.c:1646  */
    {(yyval.tnode)=(yyvsp[0].tnode);}
#line 1980 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 249 "task1.y" /* yacc.c:1646  */
    {(yyval.tnode)=(yyvsp[0].tnode);}
#line 1986 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 250 "task1.y" /* yacc.c:1646  */
    {(yyval.tnode)=(yyvsp[0].tnode);}
#line 1992 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 251 "task1.y" /* yacc.c:1646  */
    {(yyval.tnode)=(yyvsp[0].tnode);}
#line 1998 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 252 "task1.y" /* yacc.c:1646  */
    {(yyval.tnode)=(yyvsp[0].tnode);}
#line 2004 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 253 "task1.y" /* yacc.c:1646  */
    {	//printf("tree call 4:\n");
				(yyval.tnode)=create_tree(0,TLookup("null"),NULL,continue_node,NULL,NULL,NULL);
			}
#line 2012 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 256 "task1.y" /* yacc.c:1646  */
    {	//printf("tree call 5:\n");
					(yyval.tnode)=create_tree(0,TLookup("null"),NULL,break_node,NULL,NULL,NULL); 
				}
#line 2020 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 261 "task1.y" /* yacc.c:1646  */
    {	//printf("tree call 6:\n");
					typecheck((yyvsp[-2].tnode));
					(yyval.tnode)=create_tree(0,TLookup("null"),NULL,read_node,(yyvsp[-2].tnode),NULL,NULL);
				}
#line 2029 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 265 "task1.y" /* yacc.c:1646  */
    {	//printf("tree call 7:\n");
					typecheck((yyvsp[-2].tnode));
					(yyval.tnode)=create_tree(0,TLookup("null"),NULL,read_node,(yyvsp[-2].tnode),NULL,NULL); 
				}
#line 2038 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 269 "task1.y" /* yacc.c:1646  */
    {	//printf("tree call 8:\n");
					typecheck((yyvsp[-2].tnode));
					(yyval.tnode)=create_tree(0,TLookup("null"),NULL,read_node,(yyvsp[-2].tnode),NULL,NULL); 
				}
#line 2047 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 274 "task1.y" /* yacc.c:1646  */
    {	//printf("tree call 9:\n");
					typecheck((yyvsp[-2].tnode));
					(yyval.tnode)=create_tree(0,TLookup("null"),NULL,write_node,(yyvsp[-2].tnode),NULL,NULL); 
				}
#line 2056 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 279 "task1.y" /* yacc.c:1646  */
    {
					//printf("lex:\n");printf("before:");print_node($1);print_node($3);
					typecheck((yyvsp[-3].tnode));typecheck((yyvsp[-1].tnode));
					//printf("after:");print_node($1);print_node($3);printf("tree call 10:\n");	
					(yyval.tnode)=create_tree(0,TLookup("null"),"=",assg_node,(yyvsp[-3].tnode),NULL,(yyvsp[-1].tnode));
				}
#line 2067 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 285 "task1.y" /* yacc.c:1646  */
    {
					//printf("lex:\n");printf("before:");print_node($1);print_node($3);
					typecheck((yyvsp[-3].tnode));typecheck((yyvsp[-1].tnode));
					//printf("after:");print_node($1);print_node($3);printf("tree call 11:\n");	
					(yyval.tnode)=create_tree(0,TLookup("null"),"=",assg_node,(yyvsp[-3].tnode),NULL,(yyvsp[-1].tnode));
				}
#line 2078 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 291 "task1.y" /* yacc.c:1646  */
    {
					//printf("lex:\n");printf("before:");print_node($1);print_node($3);
					typecheck((yyvsp[-3].tnode));typecheck((yyvsp[-1].tnode));
					//printf("after:");print_node($1);print_node($3);printf("tree call 12:\n");	
					(yyval.tnode)=create_tree(0,TLookup("null"),"=",assg_node,(yyvsp[-3].tnode),NULL,(yyvsp[-1].tnode));
				}
#line 2089 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 297 "task1.y" /* yacc.c:1646  */
    {
					//printf("lex:\n");printf("before:");print_node($1);print_node($3);
					typecheck((yyvsp[-3].tnode));typecheck((yyvsp[-1].tnode));
					//printf("after:");print_node($1);print_node($3);printf("tree call 13:\n");	
					(yyval.tnode)=create_tree(0,TLookup("null"),"=",assg_node,(yyvsp[-3].tnode),NULL,(yyvsp[-1].tnode)); 
				}
#line 2100 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 306 "task1.y" /* yacc.c:1646  */
    {	//printf("tree call 14:\n");
					(yyval.tnode)=create_tree(0,TLookup("null"),NULL,alloc_node,NULL,NULL,NULL);
				}
#line 2108 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 309 "task1.y" /* yacc.c:1646  */
    {	
				//printf("tree call 15:\n");
				(yyval.tnode)=create_tree(0,TLookup("int"),NULL,initialize_node,NULL,NULL,NULL);
			    }
#line 2117 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 315 "task1.y" /* yacc.c:1646  */
    {	//printf("tree call 16:\n");
					(yyval.tnode)=create_tree(0,TLookup("null"),NULL,if_node,(yyvsp[-7].tnode),(yyvsp[-4].tnode),(yyvsp[-2].tnode));
				}
#line 2125 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 319 "task1.y" /* yacc.c:1646  */
    {	//printf("tree call 17:\n");
					(yyval.tnode)=create_tree(0,TLookup("null"),NULL,if_node,(yyvsp[-5].tnode),(yyvsp[-2].tnode),NULL); 
				}
#line 2133 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 324 "task1.y" /* yacc.c:1646  */
    {	//printf("tree call 18:\n");
					(yyval.tnode)=create_tree(0,TLookup("null"),NULL,while_node,(yyvsp[-5].tnode),NULL,(yyvsp[-2].tnode)); 
				}
#line 2141 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 329 "task1.y" /* yacc.c:1646  */
    {(yyval.tnode)=(yyvsp[-1].tnode); }
#line 2147 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 331 "task1.y" /* yacc.c:1646  */
    {
					typecheck((yyvsp[-2].tnode));
					//printf("tree call 19:\n");	
					(yyval.tnode)=create_tree(0,TLookup("int"),NULL,free_node,(yyvsp[-2].tnode),NULL,NULL); 
				}
#line 2157 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 337 "task1.y" /* yacc.c:1646  */
    {
					typecheck((yyvsp[-2].tnode));
				 	//printf("tree call 20:\n");	
					(yyval.tnode)=create_tree(0,TLookup("int"),NULL,free_node,(yyvsp[-2].tnode),NULL,NULL);  
				}
#line 2167 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 346 "task1.y" /* yacc.c:1646  */
    {
					//printf("lex:\n");printf("before:");print_node($1);print_node($3);
					typecheck((yyvsp[-2].tnode));typecheck((yyvsp[0].tnode));
					//printf("after:");print_node($1);print_node($3);printf("tree call 21:\n");	
					(yyval.tnode)=create_tree(0,TLookup("int"),"+",aop_node,(yyvsp[-2].tnode),NULL,(yyvsp[0].tnode)); 
				}
#line 2178 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 352 "task1.y" /* yacc.c:1646  */
    {
					//printf("lex:\n");printf("before:");print_node($1);print_node($3);
					typecheck((yyvsp[-2].tnode));typecheck((yyvsp[0].tnode));
					//printf("after:");print_node($1);print_node($3);printf("tree call 22:\n");	
					(yyval.tnode)=create_tree(0,TLookup("int"),"-",aop_node,(yyvsp[-2].tnode),NULL,(yyvsp[0].tnode)); }
#line 2188 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 357 "task1.y" /* yacc.c:1646  */
    {
					//printf("lex:\n");printf("before:");print_node($1);print_node($3);
					typecheck((yyvsp[-2].tnode));typecheck((yyvsp[0].tnode));
					//printf("after:");print_node($1);print_node($3);printf("tree call 23:\n");	
					(yyval.tnode)=create_tree(0,TLookup("int"),"*",aop_node,(yyvsp[-2].tnode),NULL,(yyvsp[0].tnode));
				}
#line 2199 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 363 "task1.y" /* yacc.c:1646  */
    {
					//printf("lex:\n");printf("before:");print_node($1);print_node($3);
					typecheck((yyvsp[-2].tnode));typecheck((yyvsp[0].tnode));
					//printf("after:");print_node($1);print_node($3);printf("tree call 24:\n");	
					(yyval.tnode)=create_tree(0,TLookup("int"),"/",aop_node,(yyvsp[-2].tnode),NULL,(yyvsp[0].tnode)); 
				}
#line 2210 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 369 "task1.y" /* yacc.c:1646  */
    {
					//printf("lex:\n");printf("before:");print_node($1);print_node($3);
					typecheck((yyvsp[-2].tnode));typecheck((yyvsp[0].tnode));
					//printf("after:");print_node($1);print_node($3);printf("tree call 25:\n");	
					(yyval.tnode)=create_tree(0,TLookup("int"),"%",aop_node,(yyvsp[-2].tnode),NULL,(yyvsp[0].tnode)); 
				}
#line 2221 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 376 "task1.y" /* yacc.c:1646  */
    {
					//printf("lex:\n");printf("before:");print_node($1);print_node($3);
					typecheck((yyvsp[-2].tnode));typecheck((yyvsp[0].tnode));
					//printf("after:");print_node($1);print_node($3);printf("tree call 26:\n");	
					(yyval.tnode)=create_tree(0,TLookup("bool"),"<=",lop_node,(yyvsp[-2].tnode),NULL,(yyvsp[0].tnode)); 
				}
#line 2232 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 382 "task1.y" /* yacc.c:1646  */
    {
					//printf("lex:\n");printf("before:");print_node($1);print_node($3);
					typecheck((yyvsp[-2].tnode));typecheck((yyvsp[0].tnode));
					//printf("after:");print_node($1);print_node($3);printf("tree call 27:\n");	
					(yyval.tnode)=create_tree(0,TLookup("bool"),">=",lop_node,(yyvsp[-2].tnode),NULL,(yyvsp[0].tnode)); 
				}
#line 2243 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 388 "task1.y" /* yacc.c:1646  */
    {
					//printf("lex:\n");printf("before:");print_node($1);print_node($3);
					typecheck((yyvsp[-2].tnode));typecheck((yyvsp[0].tnode));
					//printf("after:");print_node($1);print_node($3);printf("tree call 28:\n");	
					(yyval.tnode)=create_tree(0,TLookup("bool"),"<",lop_node,(yyvsp[-2].tnode),NULL,(yyvsp[0].tnode)); 
				}
#line 2254 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 394 "task1.y" /* yacc.c:1646  */
    {
					//printf("lex:\n");printf("before:");print_node($1);print_node($3);
					typecheck((yyvsp[-2].tnode));typecheck((yyvsp[0].tnode));
					//printf("after:");print_node($1);print_node($3);printf("tree call 29:\n");	
					(yyval.tnode)=create_tree(0,TLookup("bool"),">",lop_node,(yyvsp[-2].tnode),NULL,(yyvsp[0].tnode)); 
				}
#line 2265 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 400 "task1.y" /* yacc.c:1646  */
    {
					//printf("lex:\n");printf("before:");print_node($1);print_node($3);
					typecheck((yyvsp[-2].tnode));typecheck((yyvsp[0].tnode));
					//printf("after:");print_node($1);print_node($3);printf("tree call 30:\n");	
					(yyval.tnode)=create_tree(0,TLookup("bool"),"==",lop_node,(yyvsp[-2].tnode),NULL,(yyvsp[0].tnode)); 
				}
#line 2276 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 406 "task1.y" /* yacc.c:1646  */
    {
					//printf("lex:\n");printf("before:");print_node($1);print_node($3);
					typecheck((yyvsp[-2].tnode));typecheck((yyvsp[0].tnode));
					//printf("after:");print_node($1);print_node($3);printf("tree call 31:\n");	
					(yyval.tnode)=create_tree(0,TLookup("bool"),"!=",lop_node,(yyvsp[-2].tnode),NULL,(yyvsp[0].tnode)); 
				}
#line 2287 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 413 "task1.y" /* yacc.c:1646  */
    {
					//printf("lex:\n");printf("before:");print_node($1);print_node($3);
					typecheck((yyvsp[-2].tnode));typecheck((yyvsp[0].tnode));
					//printf("after:");print_node($1);print_node($3);printf("tree call 32:\n");	
					(yyval.tnode)=create_tree(0,TLookup("bool"),"&&",lop_node,(yyvsp[-2].tnode),NULL,(yyvsp[0].tnode)); 
				}
#line 2298 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 419 "task1.y" /* yacc.c:1646  */
    {
					//printf("lex:\n");printf("before:");print_node($1);print_node($3);
					typecheck((yyvsp[-2].tnode));typecheck((yyvsp[0].tnode));
					//printf("after:");print_node($1);print_node($3);printf("tree call 33:\n");	
					(yyval.tnode)=create_tree(0,TLookup("bool"),"||",lop_node,(yyvsp[-2].tnode),NULL,(yyvsp[0].tnode)); 
				}
#line 2309 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 425 "task1.y" /* yacc.c:1646  */
    {
					//printf("lex:\n");printf("before:");print_node($2);
					typecheck((yyvsp[0].tnode));
					//printf("after:");print_node($2);printf("tree call 34:\n");	
					(yyval.tnode)=create_tree(0,TLookup("bool"),"!",lop_node,(yyvsp[0].tnode),NULL,NULL); 
				}
#line 2320 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 432 "task1.y" /* yacc.c:1646  */
    {(yyval.tnode)=(yyvsp[-1].tnode);}
#line 2326 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 433 "task1.y" /* yacc.c:1646  */
    {(yyval.tnode)=(yyvsp[0].tnode);}
#line 2332 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 434 "task1.y" /* yacc.c:1646  */
    {(yyval.tnode)=(yyvsp[0].tnode);}
#line 2338 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 435 "task1.y" /* yacc.c:1646  */
    {(yyval.tnode)=(yyvsp[0].tnode);}
#line 2344 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 436 "task1.y" /* yacc.c:1646  */
    {(yyval.tnode)=(yyvsp[0].tnode);}
#line 2350 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 437 "task1.y" /* yacc.c:1646  */
    {(yyval.tnode)=(yyvsp[0].tnode);}
#line 2356 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 438 "task1.y" /* yacc.c:1646  */
    {(yyval.tnode)=(yyvsp[0].tnode);}
#line 2362 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 439 "task1.y" /* yacc.c:1646  */
    {(yyval.tnode)=(yyvsp[0].tnode);}
#line 2368 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 441 "task1.y" /* yacc.c:1646  */
    {
				typecheck((yyvsp[-2].tnode));
				struct Fieldlist *f;
				if((yyvsp[-2].tnode)->type==TLookup("int") || (yyvsp[-2].tnode)->type==TLookup("str"))
				{
					printf("invalid field access");
							exit(1);
				}
				f=FLookup((yyvsp[-2].tnode)->type,(yyvsp[0].tnode)->varname);
				if(f==NULL)
				{
			      	 printf("No field :%s in %s type",(yyvsp[0].tnode)->varname,(yyvsp[-2].tnode)->type->name);
				 exit(1);
						
				}
				(yyvsp[-2].tnode)->nodetype=field_node;
				(yyvsp[-2].tnode)->faccess=(yyvsp[0].tnode);
				(yyvsp[0].tnode)->type=f->type;
				(yyvsp[0].tnode)->val=f->fieldIndex;
				(yyvsp[-2].tnode)->type=(yyvsp[0].tnode)->type;
				(yyval.tnode)=(yyvsp[-2].tnode);
			}
#line 2395 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 463 "task1.y" /* yacc.c:1646  */
    {
				struct tnode *temp; 
				struct Fieldlist *f;
				temp=(yyvsp[-2].tnode);
				while(temp->faccess!=NULL)
					temp=temp->faccess;
				f=FLookup(temp->type,(yyvsp[0].tnode)->varname);
				if(f==NULL)
				{
				printf("No field :%s in %s type",(yyvsp[0].tnode)->varname,temp->type->name);
				 exit(1);
				}
				temp->nodetype=field_node;
				temp->faccess=(yyvsp[0].tnode);
				(yyvsp[0].tnode)->type=f->type;
				(yyvsp[0].tnode)->val=f->fieldIndex;
				(yyvsp[-2].tnode)->type=(yyvsp[0].tnode)->type;
				(yyval.tnode)=(yyvsp[-2].tnode);

			}
#line 2420 "y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 485 "task1.y" /* yacc.c:1646  */
    {
					//printf("lex:\n");printf("before:");print_node($1);
					typecheck((yyvsp[-2].tnode));
					//printf("after:");print_node($1);printf("tree call 35:\n");	
					(yyval.tnode)=create_tree(0,TLookup("null"),(yyvsp[-2].tnode)->varname,func_node,NULL,NULL,NULL);
			 }
#line 2431 "y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 491 "task1.y" /* yacc.c:1646  */
    {
					//printf("lex:\n");printf("before:");print_node($1);print_node($3);
					typecheck((yyvsp[-3].tnode));typecheck((yyvsp[-1].tnode));
					//printf("after:");print_node($1);print_node($3);printf("tree call 36:\n");	
					(yyval.tnode)=create_tree(0,TLookup("null"),(yyvsp[-3].tnode)->varname,func_node,(yyvsp[-1].tnode),NULL,NULL); 
			   }
#line 2442 "y.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 500 "task1.y" /* yacc.c:1646  */
    {(yyvsp[0].tnode)->middle=(yyvsp[-2].tnode);
					//printf("lex:\n");printf("before:");print_node($1);print_node($3);
					typecheck((yyvsp[-2].tnode));typecheck((yyvsp[0].tnode));
					//printf("after:");print_node($1);print_node($3);	
					
				  (yyval.tnode)=(yyvsp[0].tnode);
				}
#line 2454 "y.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 507 "task1.y" /* yacc.c:1646  */
    {(yyval.tnode)=(yyvsp[0].tnode);
					//printf("lex:\n");printf("before:");print_node($1);
					typecheck((yyvsp[0].tnode));
					//printf("after:");print_node($1);
				}
#line 2464 "y.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 513 "task1.y" /* yacc.c:1646  */
    {	
					//printf("lex:\n"); printf("before:");print_node($1);print_node($3);
					typecheck((yyvsp[-3].tnode));typecheck((yyvsp[-1].tnode));
					//printf("after:");print_node($1);print_node($3);printf("tree call 37:\n"); 
					(yyval.tnode)=create_tree(0,(yyvsp[-3].tnode)->type,(yyvsp[-3].tnode)->varname,arr_node,(yyvsp[-1].tnode),NULL,NULL); 
				}
#line 2475 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2479 "y.tab.c" /* yacc.c:1646  */
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
#line 520 "task1.y" /* yacc.c:1906  */

int main(int argc, char *argv[])
{
	int i;
	
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
	TypeTableCreate();
	yyparse();	
	
	
	
	return 0;
}

