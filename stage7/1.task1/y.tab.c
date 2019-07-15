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
	struct Classtable *currclass;

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
    RETURN = 287,
    MAINFN = 288,
    ANDTK = 289,
    ORTK = 290,
    NOTTK = 291,
    TYPE = 292,
    ENDTYPE = 293,
    NULLTK = 294,
    ALLOC = 295,
    INITIALIZE = 296,
    FREE = 297,
    CLASS = 298,
    ENDCLASS = 299,
    DELETE = 300,
    NEW = 301,
    EXTENDS = 302,
    SELF = 303
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
#define RETURN 287
#define MAINFN 288
#define ANDTK 289
#define ORTK 290
#define NOTTK 291
#define TYPE 292
#define ENDTYPE 293
#define NULLTK 294
#define ALLOC 295
#define INITIALIZE 296
#define FREE 297
#define CLASS 298
#define ENDCLASS 299
#define DELETE 300
#define NEW 301
#define EXTENDS 302
#define SELF 303

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 15 "task1.y" /* yacc.c:355  */

	struct tnode *tnode;
	struct Gsymbol *Gsymbol;
	struct Paramstruct *paramstruct;
	struct Typetable *Typetable;
	struct Classtable *classtable;
      

#line 225 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 242 "y.tab.c" /* yacc.c:358  */

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
#define YYLAST   563

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  59
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  57
/* YYNRULES -- Number of rules.  */
#define YYNRULES  135
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  308

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   303

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
      52,    53,     2,     2,    54,     2,    58,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    51,
       2,    57,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    55,     2,    56,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    49,     2,    50,     2,     2,     2,     2,
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
static const yytype_uint16 yyrline[] =
{
       0,    38,    38,    39,    40,    44,    45,    47,    48,    51,
      51,    61,    62,    64,    67,    68,    70,    71,    73,    75,
      79,    84,    85,    87,    91,    92,    94,    98,   103,   104,
     107,   111,   116,   117,   120,   123,   124,   127,   130,   133,
     136,   141,   144,   145,   147,   152,   157,   158,   160,   164,
     169,   172,   176,   178,   180,   181,   183,   184,   186,   188,
     189,   191,   195,   197,   202,   207,   211,   213,   221,   223,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     238,   239,   240,   242,   244,   245,   246,   247,   248,   249,
     251,   253,   254,   258,   261,   264,   268,   270,   273,   277,
     280,   282,   285,   288,   292,   295,   298,   301,   304,   307,
     311,   314,   317,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   331,   333,   336,   342,   343,   344,   345,   346,
     347,   349,   352,   358,   360,   363
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
  "ENDWHILE", "CONTINUE", "BREAK", "DECL", "ENDDECL", "RETURN", "MAINFN",
  "ANDTK", "ORTK", "NOTTK", "TYPE", "ENDTYPE", "NULLTK", "ALLOC",
  "INITIALIZE", "FREE", "CLASS", "ENDCLASS", "DELETE", "NEW", "EXTENDS",
  "SELF", "'{'", "'}'", "';'", "'('", "')'", "','", "'['", "']'", "'='",
  "'.'", "$accept", "Program", "TypeDefBlock", "TypeDefList", "TypeDef",
  "$@1", "FieldDeclList", "FieldDecl", "ClassDefBlock", "ClassDefList",
  "ClassDef", "Cname", "Fieldlists", "Fld", "MethodDecl", "MDecl",
  "MethodDefns", "GdeclBlock", "Gdecllist", "Gdecl", "Gvarlist", "Gvar",
  "ParamList", "PL", "Param", "ParamTypeName", "FDefBlock", "Fdef",
  "NameParam", "FuncName", "RetTypeName", "LdeclBlock", "LDecList",
  "LDecl", "Lvarlist", "Type", "Main", "MainBlock", "Body", "RetStmt",
  "Slist", "Stmt", "InputStmt", "OutputStmt", "AssgStmt", "DeleteStmt",
  "dexpr", "IfStmt", "WhileStmt", "FuncStmt", "FreeStmt", "expr", "Field",
  "FieldFunction", "Fcall", "ArgList", "Sarray", YY_NULLPTR
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   123,
     125,    59,    40,    41,    44,    91,    93,    61,    46
};
# endif

#define YYPACT_NINF -133

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-133)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -7,    45,    53,    48,    49,    33,  -133,  -133,   101,    96,
    -133,  -133,  -133,    74,    10,  -133,    80,   105,    32,   141,
    -133,   143,   145,  -133,  -133,   159,  -133,   146,  -133,  -133,
      34,  -133,   192,   105,   141,  -133,   161,   204,  -133,   227,
      11,  -133,  -133,  -133,   184,  -133,  -133,    75,   103,  -133,
    -133,  -133,    73,  -133,   188,   191,  -133,  -133,   245,   210,
       5,   260,  -133,   192,   142,    68,   248,   222,     6,  -133,
     263,  -133,    92,  -133,    73,  -133,  -133,   221,   246,  -133,
     271,   220,  -133,   121,   249,   250,   251,   252,   254,   257,
     225,   258,   259,   255,   291,   142,  -133,  -133,  -133,  -133,
    -133,  -133,  -133,  -133,  -133,   -15,   261,   262,  -133,    93,
    -133,   310,   265,  -133,  -133,   267,   104,   312,   317,  -133,
     248,   273,  -133,   318,  -133,  -133,    83,   225,   214,   320,
       2,   225,   225,   225,  -133,  -133,  -133,   114,  -133,   225,
    -133,   268,   225,   342,   269,  -133,  -133,  -133,     8,     9,
     324,   278,   313,  -133,   155,   326,  -133,   225,  -133,  -133,
    -133,   134,  -133,  -133,  -133,     7,   280,  -133,    14,  -133,
     284,  -133,  -133,  -133,   528,   167,    13,   281,   307,   308,
     311,   388,  -133,   180,   -19,   282,    67,   272,   283,   357,
     238,   359,   331,   225,   225,   225,   225,   225,   225,   225,
     225,   225,   225,   225,   225,   225,  -133,   360,    95,   122,
     309,   144,  -133,  -133,   319,   316,   399,  -133,   445,  -133,
     365,   321,   322,  -133,  -133,  -133,  -133,   225,  -133,   325,
     327,   367,  -133,  -133,   323,   328,   330,   332,   351,   356,
     333,   334,  -133,   196,   196,  -133,  -133,  -133,   238,   238,
     238,   238,   238,   238,   238,   238,   335,   337,   338,   339,
    -133,   387,  -133,  -133,  -133,  -133,   341,   528,  -133,  -133,
     363,  -133,  -133,  -133,  -133,   503,   503,    89,   129,   147,
    -133,  -133,  -133,   364,  -133,   368,   443,   473,  -133,   198,
    -133,   215,  -133,   217,   369,  -133,   503,   370,   373,  -133,
    -133,  -133,  -133,   485,  -133,  -133,   374,  -133
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       6,     0,     0,    15,     0,     0,     8,     1,     0,     0,
       9,     5,     7,    19,     0,    17,     0,     0,     0,     0,
       4,     0,     0,    14,    16,     0,    62,     0,    61,    31,
       0,    33,     0,    53,     0,    47,     0,     0,     3,     0,
       0,    12,    20,    22,     0,    30,    32,    37,     0,    36,
      46,     2,     0,    52,     0,     0,    10,    11,     0,     0,
       0,     0,    34,     0,     0,     0,     0,     0,     0,    13,
       0,    21,     0,    25,     0,    45,    40,     0,    41,    43,
       0,     0,    35,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    69,    70,    71,    72,
      77,    73,    74,    75,    76,     0,     0,     0,    55,     0,
      57,     0,     0,    49,    51,     0,     0,     0,     0,    24,
       0,     0,    39,     0,    44,    38,     0,     0,     0,     0,
       0,     0,     0,     0,    78,    79,   115,   114,   116,     0,
     119,     0,     0,     0,   120,   121,   118,   117,     0,     0,
       0,     0,     0,    68,     0,     0,    96,     0,    54,    56,
      60,     0,    48,    50,    23,     0,     0,    53,     0,    29,
       0,    64,    42,   131,   134,     0,     0,     0,     0,     0,
       0,     0,   123,     0,     0,     0,     0,     0,     0,     0,
     112,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    67,     0,     0,     0,
       0,     0,   122,    66,     0,     0,     0,   124,     0,    58,
       0,     0,     0,    18,    28,    63,   132,     0,   135,     0,
       0,     0,    87,    84,     0,     0,     0,     0,     0,     0,
     123,   122,   113,    99,   100,   101,   102,   103,   107,   106,
     105,   104,   108,   109,   110,   111,   124,     0,     0,     0,
      65,     0,    86,    85,    59,    27,     0,   133,    91,    92,
       0,    80,    82,    81,    83,     0,     0,     0,     0,     0,
      98,    97,    90,     0,    26,     0,     0,     0,   127,     0,
     125,     0,   129,     0,     0,    88,     0,     0,     0,   128,
     126,   130,    89,     0,    94,    95,     0,    93
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -133,  -133,  -133,  -133,   413,  -133,  -133,   386,  -133,  -133,
     414,  -133,  -133,  -133,  -133,   355,  -133,  -133,  -133,   400,
    -133,   366,   -61,  -133,   314,  -133,  -133,   -29,  -133,  -133,
    -133,   358,  -133,   329,  -133,   -14,  -133,    -2,   -58,   336,
    -132,   -94,  -133,  -133,  -133,  -133,  -133,  -133,  -133,  -133,
    -133,   -87,   -64,  -133,   -60,   -21,   -62
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     5,     6,    21,    40,    41,     9,    14,
      15,    16,    58,    71,    72,    73,   168,    19,    30,    31,
      48,    49,    77,    78,    79,    80,    34,    35,    36,    54,
      37,    66,   109,   110,   161,    32,    27,    20,    67,    94,
      95,    96,    97,    98,    99,   100,   180,   101,   102,   103,
     104,   174,   144,   145,   146,   175,   147
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
     105,   153,   107,   143,   106,    50,   183,   115,   112,    75,
      75,    75,   208,   210,    13,    39,   121,    38,   167,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
       1,   105,    51,   107,   235,   106,    28,     4,    28,   155,
     176,   181,   154,   155,   186,   187,   188,   204,   205,     4,
      93,   111,   190,     7,    23,   192,    93,    93,    76,   114,
     221,    56,   170,    29,   223,    45,   184,   216,   185,   228,
     218,    11,    28,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   209,   211,   136,   137,   138,   169,
      64,     8,   136,   137,   138,   111,   117,    28,    10,   108,
      17,   204,   205,    65,   222,    13,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   139,
     237,    22,   140,   118,   158,   139,    18,    60,   140,    25,
      61,   141,   136,   137,   138,   142,   173,   141,    26,   224,
     267,   142,   288,   286,   287,    33,    83,    39,   257,    42,
     136,   137,   138,   129,    62,   164,   165,    63,   136,   137,
     138,    84,    85,    86,   303,   139,   126,    87,   140,   127,
      88,    89,   189,   126,    90,   258,   127,   141,   128,   129,
     155,   142,   290,   139,    91,   219,   140,    92,   220,    43,
      93,   139,   153,   153,   140,   141,    47,   259,    44,   142,
     292,   215,   155,   141,   195,   196,   197,   142,    53,   153,
      52,   105,   105,   107,   107,   106,   106,   136,   137,   138,
     226,   227,   105,   105,   107,   107,   106,   106,   136,   137,
     138,    55,   105,   234,   107,   127,   106,    59,   129,   105,
      68,   107,    69,   106,   193,   194,   195,   196,   197,    70,
     139,   299,   227,   140,   177,   178,   289,   291,   293,    74,
     179,   139,   141,    81,   140,    64,   142,   116,   300,   227,
     301,   227,   113,   141,   122,   124,   125,   142,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     123,   130,   131,   132,   133,   134,   204,   205,   135,   151,
     148,   149,   156,   150,   160,   162,   166,   204,   205,   157,
     163,   167,    75,   171,   182,   238,   191,   207,   212,   213,
     217,   214,   165,   229,   225,   236,   239,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   230,
     231,   240,   232,   241,   256,   204,   205,   129,   261,   264,
     260,   270,   265,   275,   271,   266,   204,   205,   268,   272,
     269,   273,   276,   274,   242,   277,   278,   279,   280,   281,
     282,   283,   284,   206,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   285,   294,    12,   295,
     302,   304,   204,   205,   305,   307,    57,   119,    24,    82,
      46,   152,   120,   204,   205,     0,     0,   172,   159,   233,
       0,     0,     0,     0,     0,     0,     0,    83,     0,     0,
     262,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,    84,    85,    86,     0,   296,   297,    87,     0,
       0,    88,    89,     0,     0,     0,     0,    83,     0,   204,
     205,     0,     0,     0,     0,    91,     0,     0,    92,    83,
       0,    93,    84,    85,    86,     0,   263,     0,    87,     0,
     298,    88,    89,     0,    84,    85,    86,    83,     0,   306,
      87,     0,     0,    88,    89,    91,     0,     0,    92,     0,
       0,    93,    84,    85,    86,     0,     0,    91,    87,     0,
      92,    88,    89,    93,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,    91,     0,     0,    92,     0,
       0,    93,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   204,   205
};

static const yytype_int16 yycheck[] =
{
      64,    95,    64,    90,    64,    34,     4,    68,    66,     4,
       4,     4,     4,     4,     4,     4,    74,    19,     4,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      37,    95,    34,    95,    53,    95,     4,     4,     4,    58,
     127,   128,    57,    58,   131,   132,   133,    34,    35,     4,
      48,    65,   139,     0,    44,   142,    48,    48,    53,    53,
      53,    50,   120,    31,    50,    31,   130,   154,   130,    56,
     157,    38,     4,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,   148,   149,     3,     4,     5,   118,
      17,    43,     3,     4,     5,   109,     4,     4,    49,    31,
       4,    34,    35,    30,   165,     4,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,    36,
      53,    47,    39,    31,    31,    36,    30,    52,    39,    49,
      55,    48,     3,     4,     5,    52,    53,    48,    33,   168,
     227,    52,    53,   275,   276,     4,     4,     4,    53,     4,
       3,     4,     5,    58,    51,    51,    52,    54,     3,     4,
       5,    19,    20,    21,   296,    36,    52,    25,    39,    55,
      28,    29,    58,    52,    32,    53,    55,    48,    57,    58,
      58,    52,    53,    36,    42,    51,    39,    45,    54,    30,
      48,    36,   286,   287,    39,    48,     4,    53,    52,    52,
      53,    46,    58,    48,     8,     9,    10,    52,     4,   303,
      49,   275,   276,   275,   276,   275,   276,     3,     4,     5,
      53,    54,   286,   287,   286,   287,   286,   287,     3,     4,
       5,     4,   296,    53,   296,    55,   296,    53,    58,   303,
      52,   303,    51,   303,     6,     7,     8,     9,    10,     4,
      36,    53,    54,    39,    40,    41,   277,   278,   279,    49,
      46,    36,    48,     3,    39,    17,    52,     4,    53,    54,
      53,    54,    50,    48,    53,     4,    56,    52,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      54,    52,    52,    52,    52,    51,    34,    35,    51,    18,
      52,    52,    51,    58,     4,    50,     4,    34,    35,    57,
      53,     4,     4,    50,     4,    53,    58,    58,     4,    51,
       4,    18,    52,    52,    50,    53,    53,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    52,
      52,     4,    51,     4,     4,    34,    35,    58,    52,     4,
      51,     4,    51,    22,    51,    53,    34,    35,    53,    51,
      53,    51,    26,    51,    53,    52,    52,    52,    51,    51,
      51,     4,    51,    51,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    53,    53,     5,    51,
      51,    51,    34,    35,    51,    51,    40,    72,    14,    63,
      30,    95,    74,    34,    35,    -1,    -1,   123,   109,    51,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     4,    -1,    -1,
      51,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    19,    20,    21,    -1,    23,    24,    25,    -1,
      -1,    28,    29,    -1,    -1,    -1,    -1,     4,    -1,    34,
      35,    -1,    -1,    -1,    -1,    42,    -1,    -1,    45,     4,
      -1,    48,    19,    20,    21,    -1,    51,    -1,    25,    -1,
      27,    28,    29,    -1,    19,    20,    21,     4,    -1,    24,
      25,    -1,    -1,    28,    29,    42,    -1,    -1,    45,    -1,
      -1,    48,    19,    20,    21,    -1,    -1,    42,    25,    -1,
      45,    28,    29,    48,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    42,    -1,    -1,    45,    -1,
      -1,    48,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    34,    35
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    37,    60,    61,     4,    62,    63,     0,    43,    67,
      49,    38,    63,     4,    68,    69,    70,     4,    30,    76,
      96,    64,    47,    44,    69,    49,    33,    95,     4,    31,
      77,    78,    94,     4,    85,    86,    87,    89,    96,     4,
      65,    66,     4,    30,    52,    31,    78,     4,    79,    80,
      86,    96,    49,     4,    88,     4,    50,    66,    71,    53,
      52,    55,    51,    54,    17,    30,    90,    97,    52,    51,
       4,    72,    73,    74,    49,     4,    53,    81,    82,    83,
      84,     3,    80,     4,    19,    20,    21,    25,    28,    29,
      32,    42,    45,    48,    98,    99,   100,   101,   102,   103,
     104,   106,   107,   108,   109,   111,   113,   115,    31,    91,
      92,    94,    97,    50,    53,    81,     4,     4,    31,    74,
      90,    97,    53,    54,     4,    56,    52,    55,    57,    58,
      52,    52,    52,    52,    51,    51,     3,     4,     5,    36,
      39,    48,    52,   110,   111,   112,   113,   115,    52,    52,
      58,    18,    98,   100,    57,    58,    51,    57,    31,    92,
       4,    93,    50,    53,    51,    52,     4,     4,    75,    86,
      97,    50,    83,    53,   110,   114,   110,    40,    41,    46,
     105,   110,     4,     4,   111,   115,   110,   110,   110,    58,
     110,    58,   110,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    34,    35,    51,    58,     4,   111,
       4,   111,     4,    51,    18,    46,   110,     4,   110,    51,
      54,    53,    81,    50,    86,    50,    53,    54,    56,    52,
      52,    52,    51,    51,    53,    53,    53,    53,    53,    53,
       4,     4,    53,   110,   110,   110,   110,   110,   110,   110,
     110,   110,   110,   110,   110,   110,     4,    53,    53,    53,
      51,    52,    51,    51,     4,    51,    53,   110,    53,    53,
       4,    51,    51,    51,    51,    22,    26,    52,    52,    52,
      51,    51,    51,     4,    51,    53,    99,    99,    53,   114,
      53,   114,    53,   114,    53,    51,    23,    24,    27,    53,
      53,    53,    51,    99,    51,    51,    24,    51
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    59,    60,    60,    60,    61,    61,    62,    62,    64,
      63,    65,    65,    66,    67,    67,    68,    68,    69,    70,
      70,    71,    71,    72,    73,    73,    74,    74,    75,    75,
      76,    76,    77,    77,    78,    79,    79,    80,    80,    80,
      80,    81,    82,    82,    83,    84,    85,    85,    86,    86,
      87,    87,    88,    89,    90,    90,    91,    91,    92,    93,
      93,    94,    95,    96,    96,    97,    97,    98,    99,    99,
     100,   100,   100,   100,   100,   100,   100,   100,   100,   100,
     101,   101,   101,   102,   103,   103,   103,   103,   103,   103,
     104,   105,   105,   106,   106,   107,   108,   109,   109,   110,
     110,   110,   110,   110,   110,   110,   110,   110,   110,   110,
     110,   110,   110,   110,   110,   110,   110,   110,   110,   110,
     110,   110,   111,   111,   111,   112,   112,   112,   112,   112,
     112,   113,   113,   114,   114,   115
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     4,     3,     3,     0,     2,     1,     0,
       5,     2,     1,     3,     3,     0,     2,     1,     8,     1,
       3,     2,     0,     3,     2,     1,     6,     5,     2,     1,
       3,     2,     2,     1,     3,     3,     1,     1,     4,     4,
       3,     1,     3,     1,     2,     1,     2,     1,     5,     4,
       5,     4,     1,     1,     3,     2,     2,     1,     3,     3,
       1,     1,     1,     8,     7,     5,     4,     3,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     2,
       5,     5,     5,     5,     4,     4,     4,     4,     7,     7,
       5,     3,     3,    10,     8,     8,     2,     5,     5,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     3,     3,     5,     6,     5,     6,     5,
       6,     3,     4,     3,     1,     4
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
#line 38 "task1.y" /* yacc.c:1646  */
    { }
#line 1583 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 39 "task1.y" /* yacc.c:1646  */
    { }
#line 1589 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 40 "task1.y" /* yacc.c:1646  */
    { }
#line 1595 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 44 "task1.y" /* yacc.c:1646  */
    {print_Typetable(); }
#line 1601 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 45 "task1.y" /* yacc.c:1646  */
    {print_Typetable(); }
#line 1607 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 47 "task1.y" /* yacc.c:1646  */
    { }
#line 1613 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 48 "task1.y" /* yacc.c:1646  */
    { }
#line 1619 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 51 "task1.y" /* yacc.c:1646  */
    {TInstall((yyvsp[-1].tnode)->varname,0,NULL);}
#line 1625 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 52 "task1.y" /* yacc.c:1646  */
    {
							Typetable *ttable=TLookup((yyvsp[-4].tnode)->varname);
							 ttable->fields=fieldlist_head;
							 ttable->size=getSize(ttable);
							 reset_fieldlist();	
						      
							 }
#line 1637 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 61 "task1.y" /* yacc.c:1646  */
    { }
#line 1643 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 62 "task1.y" /* yacc.c:1646  */
    { }
#line 1649 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 64 "task1.y" /* yacc.c:1646  */
    {FInstall((yyvsp[-1].tnode)->varname,TLookup((yyvsp[-2].tnode)->varname)); }
#line 1655 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 67 "task1.y" /* yacc.c:1646  */
    {print_classtable(); }
#line 1661 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 68 "task1.y" /* yacc.c:1646  */
    {print_classtable(); }
#line 1667 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 70 "task1.y" /* yacc.c:1646  */
    { }
#line 1673 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 71 "task1.y" /* yacc.c:1646  */
    { }
#line 1679 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 73 "task1.y" /* yacc.c:1646  */
    { }
#line 1685 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 75 "task1.y" /* yacc.c:1646  */
    {
						(yyval.classtable)=CInstall((yyvsp[0].tnode)->varname,NULL);
						currclass=(yyval.classtable);
					}
#line 1694 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 79 "task1.y" /* yacc.c:1646  */
    {
						(yyval.classtable)=CInstall((yyvsp[-2].tnode)->varname,(yyvsp[0].tnode)->varname);
						currclass=(yyval.classtable);
					}
#line 1703 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 84 "task1.y" /* yacc.c:1646  */
    { }
#line 1709 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 85 "task1.y" /* yacc.c:1646  */
    {/*NO ACTION*/}
#line 1715 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 87 "task1.y" /* yacc.c:1646  */
    {	
							Class_FInstall(currclass,(yyvsp[-2].tnode)->varname,(yyvsp[-1].tnode)->varname); 
						}
#line 1723 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 91 "task1.y" /* yacc.c:1646  */
    { }
#line 1729 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 92 "task1.y" /* yacc.c:1646  */
    { }
#line 1735 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 94 "task1.y" /* yacc.c:1646  */
    { 
								Class_MInstall(currclass,(yyvsp[-4].tnode)->varname,TLookup((yyvsp[-5].tnode)->varname),paramlist_head);
								reset_paramlist();
							}
#line 1744 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 98 "task1.y" /* yacc.c:1646  */
    { 
								Class_MInstall(currclass,(yyvsp[-3].tnode)->varname,TLookup((yyvsp[-4].tnode)->varname),paramlist_head);
								reset_paramlist();
							}
#line 1753 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 103 "task1.y" /* yacc.c:1646  */
    {}
#line 1759 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 104 "task1.y" /* yacc.c:1646  */
    { }
#line 1765 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 107 "task1.y" /* yacc.c:1646  */
    {
						
						
					}
#line 1774 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 111 "task1.y" /* yacc.c:1646  */
    {
						
					}
#line 1782 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 116 "task1.y" /* yacc.c:1646  */
    { }
#line 1788 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 117 "task1.y" /* yacc.c:1646  */
    { }
#line 1794 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 120 "task1.y" /* yacc.c:1646  */
    { }
#line 1800 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 123 "task1.y" /* yacc.c:1646  */
    { }
#line 1806 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 124 "task1.y" /* yacc.c:1646  */
    { }
#line 1812 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 127 "task1.y" /* yacc.c:1646  */
    {
						reset_paramlist();
					}
#line 1820 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 130 "task1.y" /* yacc.c:1646  */
    {
						reset_paramlist();
					}
#line 1828 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 133 "task1.y" /* yacc.c:1646  */
    {
						reset_paramlist();
					}
#line 1836 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 136 "task1.y" /* yacc.c:1646  */
    {
						reset_paramlist();
					}
#line 1844 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 141 "task1.y" /* yacc.c:1646  */
    {
					}
#line 1851 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 144 "task1.y" /* yacc.c:1646  */
    { }
#line 1857 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 145 "task1.y" /* yacc.c:1646  */
    { }
#line 1863 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 147 "task1.y" /* yacc.c:1646  */
    {
						(yyval.paramstruct)=create_param_node((yyvsp[0].tnode)->varname,(yyvsp[-1].Typetable));
						PInstall((yyval.paramstruct));
					}
#line 1872 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 152 "task1.y" /* yacc.c:1646  */
    {(yyval.Typetable)=TLookup((yyvsp[0].tnode)->varname);}
#line 1878 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 157 "task1.y" /* yacc.c:1646  */
    {}
#line 1884 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 158 "task1.y" /* yacc.c:1646  */
    {}
#line 1890 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 161 "task1.y" /* yacc.c:1646  */
    { 
						
					}
#line 1898 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 164 "task1.y" /* yacc.c:1646  */
    { 
						

						}
#line 1907 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 169 "task1.y" /* yacc.c:1646  */
    {
						reset_paramlist();	
					      }
#line 1915 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 172 "task1.y" /* yacc.c:1646  */
    {
						reset_paramlist();	
					      }
#line 1923 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 176 "task1.y" /* yacc.c:1646  */
    { }
#line 1929 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 178 "task1.y" /* yacc.c:1646  */
    { }
#line 1935 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 180 "task1.y" /* yacc.c:1646  */
    { }
#line 1941 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 181 "task1.y" /* yacc.c:1646  */
    { }
#line 1947 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 183 "task1.y" /* yacc.c:1646  */
    { }
#line 1953 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 184 "task1.y" /* yacc.c:1646  */
    { }
#line 1959 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 186 "task1.y" /* yacc.c:1646  */
    { }
#line 1965 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 188 "task1.y" /* yacc.c:1646  */
    {}
#line 1971 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 189 "task1.y" /* yacc.c:1646  */
    { }
#line 1977 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 191 "task1.y" /* yacc.c:1646  */
    { 
				
			}
#line 1985 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 195 "task1.y" /* yacc.c:1646  */
    { }
#line 1991 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 198 "task1.y" /* yacc.c:1646  */
    {
			

		}
#line 2000 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 203 "task1.y" /* yacc.c:1646  */
    {
			
		}
#line 2008 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 208 "task1.y" /* yacc.c:1646  */
    {
				
			 }
#line 2016 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 211 "task1.y" /* yacc.c:1646  */
    { }
#line 2022 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 213 "task1.y" /* yacc.c:1646  */
    {	
				
			 }
#line 2030 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 221 "task1.y" /* yacc.c:1646  */
    {	
			}
#line 2037 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 223 "task1.y" /* yacc.c:1646  */
    {(yyval.tnode)=(yyvsp[0].tnode); }
#line 2043 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 226 "task1.y" /* yacc.c:1646  */
    {(yyval.tnode)=(yyvsp[0].tnode);}
#line 2049 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 227 "task1.y" /* yacc.c:1646  */
    {(yyval.tnode)=(yyvsp[0].tnode);}
#line 2055 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 228 "task1.y" /* yacc.c:1646  */
    {(yyval.tnode)=(yyvsp[0].tnode);}
#line 2061 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 229 "task1.y" /* yacc.c:1646  */
    {(yyval.tnode)=(yyvsp[0].tnode);}
#line 2067 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 230 "task1.y" /* yacc.c:1646  */
    {(yyval.tnode)=(yyvsp[0].tnode);}
#line 2073 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 231 "task1.y" /* yacc.c:1646  */
    {(yyval.tnode)=(yyvsp[0].tnode);}
#line 2079 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 232 "task1.y" /* yacc.c:1646  */
    {(yyval.tnode)=(yyvsp[0].tnode);}
#line 2085 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 233 "task1.y" /* yacc.c:1646  */
    {(yyval.tnode)=(yyvsp[0].tnode);}
#line 2091 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 234 "task1.y" /* yacc.c:1646  */
    {				}
#line 2097 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 235 "task1.y" /* yacc.c:1646  */
    {	}
#line 2103 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 238 "task1.y" /* yacc.c:1646  */
    {	}
#line 2109 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 239 "task1.y" /* yacc.c:1646  */
    {	}
#line 2115 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 240 "task1.y" /* yacc.c:1646  */
    {	}
#line 2121 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 242 "task1.y" /* yacc.c:1646  */
    {	}
#line 2127 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 244 "task1.y" /* yacc.c:1646  */
    {}
#line 2133 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 245 "task1.y" /* yacc.c:1646  */
    {}
#line 2139 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 246 "task1.y" /* yacc.c:1646  */
    {}
#line 2145 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 247 "task1.y" /* yacc.c:1646  */
    {}
#line 2151 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 248 "task1.y" /* yacc.c:1646  */
    {}
#line 2157 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 251 "task1.y" /* yacc.c:1646  */
    { }
#line 2163 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 253 "task1.y" /* yacc.c:1646  */
    {				}
#line 2169 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 254 "task1.y" /* yacc.c:1646  */
    {	
				
			    }
#line 2177 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 259 "task1.y" /* yacc.c:1646  */
    {	
				}
#line 2184 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 262 "task1.y" /* yacc.c:1646  */
    {	}
#line 2190 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 265 "task1.y" /* yacc.c:1646  */
    {	}
#line 2196 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 268 "task1.y" /* yacc.c:1646  */
    {(yyval.tnode)=(yyvsp[-1].tnode); }
#line 2202 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 270 "task1.y" /* yacc.c:1646  */
    {
					}
#line 2209 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 273 "task1.y" /* yacc.c:1646  */
    {
					}
#line 2216 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 277 "task1.y" /* yacc.c:1646  */
    {
					
				}
#line 2224 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 280 "task1.y" /* yacc.c:1646  */
    {
					 }
#line 2231 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 282 "task1.y" /* yacc.c:1646  */
    {
					
				}
#line 2239 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 285 "task1.y" /* yacc.c:1646  */
    {
					
				}
#line 2247 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 288 "task1.y" /* yacc.c:1646  */
    {
					
				}
#line 2255 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 292 "task1.y" /* yacc.c:1646  */
    {
					
				}
#line 2263 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 295 "task1.y" /* yacc.c:1646  */
    {
					
				}
#line 2271 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 298 "task1.y" /* yacc.c:1646  */
    {
					
				}
#line 2279 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 301 "task1.y" /* yacc.c:1646  */
    {
					
				}
#line 2287 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 304 "task1.y" /* yacc.c:1646  */
    {
					
				}
#line 2295 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 307 "task1.y" /* yacc.c:1646  */
    {
					
				}
#line 2303 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 311 "task1.y" /* yacc.c:1646  */
    {
					
				}
#line 2311 "y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 314 "task1.y" /* yacc.c:1646  */
    {
					
				}
#line 2319 "y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 317 "task1.y" /* yacc.c:1646  */
    {
				 
				}
#line 2327 "y.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 321 "task1.y" /* yacc.c:1646  */
    {(yyval.tnode)=(yyvsp[-1].tnode);}
#line 2333 "y.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 322 "task1.y" /* yacc.c:1646  */
    {(yyval.tnode)=(yyvsp[0].tnode);}
#line 2339 "y.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 323 "task1.y" /* yacc.c:1646  */
    {(yyval.tnode)=(yyvsp[0].tnode);}
#line 2345 "y.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 324 "task1.y" /* yacc.c:1646  */
    {(yyval.tnode)=(yyvsp[0].tnode);}
#line 2351 "y.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 325 "task1.y" /* yacc.c:1646  */
    {(yyval.tnode)=(yyvsp[0].tnode);}
#line 2357 "y.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 326 "task1.y" /* yacc.c:1646  */
    {(yyval.tnode)=(yyvsp[0].tnode);}
#line 2363 "y.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 327 "task1.y" /* yacc.c:1646  */
    {(yyval.tnode)=(yyvsp[0].tnode);}
#line 2369 "y.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 328 "task1.y" /* yacc.c:1646  */
    {(yyval.tnode)=(yyvsp[0].tnode);}
#line 2375 "y.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 329 "task1.y" /* yacc.c:1646  */
    {(yyval.tnode)=(yyvsp[0].tnode);}
#line 2381 "y.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 333 "task1.y" /* yacc.c:1646  */
    {
				
			}
#line 2389 "y.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 336 "task1.y" /* yacc.c:1646  */
    {
				

			}
#line 2398 "y.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 349 "task1.y" /* yacc.c:1646  */
    {
					
			 }
#line 2406 "y.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 352 "task1.y" /* yacc.c:1646  */
    {
					
			   }
#line 2414 "y.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 358 "task1.y" /* yacc.c:1646  */
    {
				}
#line 2421 "y.tab.c" /* yacc.c:1646  */
    break;

  case 134:
#line 360 "task1.y" /* yacc.c:1646  */
    {
				}
#line 2428 "y.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 363 "task1.y" /* yacc.c:1646  */
    {	
					
				}
#line 2436 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2440 "y.tab.c" /* yacc.c:1646  */
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
#line 367 "task1.y" /* yacc.c:1906  */

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

