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
	int Gdecl_end_flag=0,Classdecl_end_flag=0;
	

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
#define YYLAST   585

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  59
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  60
/* YYNRULES -- Number of rules.  */
#define YYNRULES  138
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
      51,    61,    62,    64,    67,    68,    70,    71,    73,    73,
      73,    75,    79,    84,    85,    87,    91,    92,    94,    98,
     103,   104,   107,   118,   130,   131,   134,   136,   142,   143,
     146,   153,   157,   161,   167,   170,   171,   173,   178,   183,
     184,   186,   196,   207,   212,   218,   220,   222,   223,   225,
     226,   228,   230,   231,   234,   236,   247,   259,   263,   267,
     276,   279,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   293,   298,   302,   307,   312,   317,   321,   325,   329,
     333,   337,   342,   347,   350,   354,   361,   365,   370,   376,
     378,   383,   389,   393,   397,   401,   405,   410,   414,   418,
     422,   426,   430,   435,   439,   443,   448,   449,   450,   451,
     452,   453,   454,   455,   456,   458,   479,   506,   533,   560,
     586,   604,   622,   645,   670,   674,   681,   686,   691
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
  "ClassDef", "$@2", "$@3", "Cname", "Fieldlists", "Fld", "MethodDecl",
  "MDecl", "MethodDefns", "GdeclBlock", "Gdecllist", "Gdecl", "Type",
  "Gvarlist", "Gvar", "ParamList", "PL", "Param", "ParamTypeName",
  "FDefBlock", "Fdef", "NameParam", "FuncName", "RetTypeName",
  "LdeclBlock", "LDecList", "LDecl", "Lvarlist", "Main", "MainBlock",
  "Body", "RetStmt", "Slist", "Stmt", "InputStmt", "OutputStmt",
  "AssgStmt", "DeleteStmt", "dexpr", "ndexpr", "IfStmt", "WhileStmt",
  "FuncStmt", "FreeStmt", "expr", "Field", "FieldFunction", "Fcall",
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   123,
     125,    59,    40,    41,    44,    91,    93,    61,    46
};
# endif

#define YYPACT_NINF -177

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-177)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -6,    35,    50,    43,    41,    36,  -177,  -177,   150,    71,
    -177,  -177,  -177,   114,    33,  -177,   115,    63,    37,   184,
    -177,   186,   194,  -177,  -177,  -177,  -177,   148,  -177,  -177,
      45,  -177,   200,    63,   184,  -177,   161,   217,  -177,   219,
       5,  -177,  -177,   201,   177,  -177,  -177,    92,   101,  -177,
    -177,  -177,    68,  -177,   182,   185,  -177,  -177,  -177,   189,
       6,   237,  -177,   200,   453,    47,   225,   220,     7,  -177,
     263,    68,  -177,  -177,   216,   221,  -177,   270,   222,  -177,
      70,   224,   227,   228,   229,   226,   231,   170,   233,   234,
     230,   269,   453,  -177,  -177,  -177,  -177,  -177,  -177,  -177,
    -177,  -177,    73,   239,   232,  -177,   288,    49,  -177,   243,
    -177,  -177,   241,   291,  -177,    60,  -177,   225,   246,  -177,
     293,  -177,  -177,    31,   170,   145,   294,     4,   170,   170,
     170,  -177,  -177,  -177,   107,  -177,   170,  -177,   242,   170,
     356,   267,  -177,  -177,  -177,    23,    25,   295,   250,   309,
    -177,   153,   322,  -177,   170,  -177,   109,  -177,  -177,  -177,
    -177,   116,   324,  -177,  -177,   279,  -177,  -177,  -177,   550,
     123,    10,   278,   281,   282,   284,   285,   367,  -177,   213,
     -20,   286,   238,   249,   297,   333,    96,   334,   308,   170,
     170,   170,   170,   170,   170,   170,   170,   170,   170,   170,
     170,   170,  -177,   336,    39,    87,   283,    93,  -177,  -177,
     296,   298,   413,  -177,   424,  -177,   340,  -177,     9,   299,
     341,  -177,  -177,   170,  -177,   300,   301,   342,  -177,  -177,
    -177,   304,   305,   306,   307,   326,   358,   335,   337,  -177,
     162,   162,  -177,  -177,  -177,    96,    96,    96,    96,    96,
      96,    96,    96,   343,   345,   346,   347,  -177,  -177,  -177,
    -177,  -177,   348,   332,  -177,    11,  -177,   550,  -177,  -177,
     339,  -177,  -177,  -177,  -177,   526,   526,    84,    90,   130,
    -177,  -177,  -177,  -177,   349,  -177,  -177,  -177,   442,   484,
    -177,   126,  -177,   154,  -177,   166,  -177,   526,   352,   353,
    -177,  -177,  -177,   495,  -177,  -177,   354,  -177
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       6,     0,     0,    15,     0,     0,     8,     1,     0,     0,
       9,     5,     7,    21,     0,    17,     0,     0,     0,     0,
       4,     0,     0,    14,    16,    18,    64,     0,    37,    33,
       0,    35,     0,    56,     0,    50,     0,     0,     3,     0,
       0,    12,    22,     0,     0,    32,    34,    40,     0,    39,
      49,     2,     0,    55,     0,     0,    10,    11,    24,     0,
       0,     0,    36,     0,     0,     0,     0,     0,     0,    13,
       0,     0,    48,    43,     0,    44,    46,     0,     0,    38,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    71,    72,    73,    74,    79,    75,    76,
      77,    78,     0,     0,     0,    58,     0,     0,    60,     0,
      52,    54,     0,     0,    23,     0,    27,     0,     0,    42,
       0,    47,    41,     0,     0,     0,     0,     0,     0,     0,
       0,    80,    81,   118,   117,   119,     0,   122,     0,     0,
       0,   123,   124,   121,   120,     0,     0,     0,     0,     0,
      70,     0,     0,    99,     0,    63,     0,    57,    59,    51,
      53,     0,     0,    19,    26,     0,    66,    45,   134,   137,
       0,     0,     0,     0,     0,     0,     0,     0,   126,     0,
       0,     0,     0,     0,     0,     0,   115,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    69,     0,     0,     0,     0,     0,   125,    68,
       0,     0,     0,   127,     0,    61,     0,    25,     0,     0,
       0,    65,   135,     0,   138,     0,     0,     0,    89,    90,
      86,     0,     0,     0,     0,     0,     0,   126,   125,   116,
     102,   103,   104,   105,   106,   110,   109,   108,   107,   111,
     112,   113,   114,   127,     0,     0,     0,    67,    91,    88,
      87,    62,     0,     0,    56,     0,    31,   136,    93,    94,
       0,    82,    84,    83,    85,     0,     0,     0,     0,     0,
     101,   100,    92,    29,     0,    20,    30,    95,     0,     0,
     130,     0,   128,     0,   132,     0,    28,     0,     0,     0,
     131,   129,   133,     0,    97,    98,     0,    96
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -177,  -177,  -177,  -177,   355,  -177,  -177,   312,  -177,  -177,
     372,  -177,  -177,  -177,  -177,  -177,  -177,   244,  -177,  -177,
    -177,   363,   -51,  -177,   325,   -65,  -177,   274,  -177,  -177,
     -33,  -177,  -177,  -177,   338,  -177,   303,  -177,  -177,   105,
     -59,   314,  -176,   -86,  -177,  -177,  -177,  -177,  -177,   257,
    -177,  -177,  -177,  -177,   -82,   -64,  -177,   -60,   -83,   -62
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     5,     6,    21,    40,    41,     9,    14,
      15,    43,   220,    16,    70,   114,   115,   116,   265,    19,
      30,    31,    32,    48,    49,    74,    75,    76,    77,    34,
      35,    36,    54,    37,    66,   107,   108,   156,    27,    20,
      67,    91,    92,    93,    94,    95,    96,    97,   175,   176,
      98,    99,   100,   101,   169,   141,   142,   143,   170,   144
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
     102,    50,   104,   112,   103,   140,   150,   109,   179,    39,
      72,    72,   118,    72,   106,   264,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   204,   102,   206,
     104,     1,   103,   232,   133,   134,   135,    13,   152,     4,
       4,    28,   171,   177,   200,   201,   182,   183,   184,    28,
       7,    28,    90,    28,   186,    56,   106,   188,   165,    73,
     111,   285,   262,   180,   162,   181,   224,   136,    29,   212,
     137,    90,   214,    90,    11,    17,    45,    23,   105,   138,
     157,   205,   207,   139,   168,    64,     8,   133,   134,   135,
      10,   163,   254,   133,   134,   135,    26,   126,    65,   288,
     289,    18,   189,   190,   191,   192,   193,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     136,   303,   123,   137,    38,   124,   136,   125,   126,   137,
     151,   152,   138,   133,   134,   135,   139,   290,   138,    51,
     255,   267,   139,   292,    60,   152,   256,    61,   133,   134,
     135,   152,    62,   263,    13,    63,   133,   134,   135,   123,
     215,    22,   124,   216,    25,   185,   136,   217,   218,   137,
     191,   192,   193,   133,   134,   135,   222,   223,   138,   300,
     223,   136,   139,   294,   137,   172,   173,   266,    33,   136,
      39,   174,   137,   138,   291,   293,   295,   139,    42,   174,
      44,   138,   150,   150,    47,   139,   136,   301,   223,   137,
      52,   102,   102,   104,   104,   103,   103,   150,   138,   302,
     223,    53,   139,    55,   102,   102,   104,   104,   103,   103,
      59,    58,   286,   102,    68,   104,    69,   103,    71,   102,
      78,   104,    64,   103,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   231,   113,   124,   119,
     110,   126,   200,   201,   121,   120,   127,   131,   122,   128,
     129,   130,   132,   200,   201,   145,   146,   148,   147,   154,
     153,   234,   155,   159,   160,   161,   166,    72,   178,   208,
     187,   209,   235,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   203,   213,   210,   219,   221,
     225,   200,   201,   226,   227,   228,   229,   237,   238,   233,
     253,   126,   200,   201,   261,   264,   270,   257,   275,   258,
     236,   218,    57,   268,   269,   271,   272,   273,   274,   164,
      12,   239,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   276,   284,    24,   277,    79,   278,
     200,   201,   287,    46,   167,   279,   280,   281,   282,   283,
     296,   200,   201,   304,   305,   307,   149,   202,   211,   117,
     158,     0,     0,     0,     0,     0,     0,     0,   230,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,     0,     0,     0,     0,     0,    80,   200,   201,     0,
       0,     0,     0,     0,     0,     0,     0,    80,   200,   201,
       0,    81,    82,    83,   259,   297,   298,    84,     0,     0,
      85,    86,    81,    82,    83,   260,     0,     0,    84,     0,
       0,    85,    86,     0,    88,    87,     0,    89,    80,     0,
      90,     0,     0,     0,     0,    88,     0,     0,    89,    80,
       0,    90,     0,    81,    82,    83,     0,     0,     0,    84,
       0,   299,    85,    86,    81,    82,    83,     0,     0,   306,
      84,     0,     0,    85,    86,     0,    88,     0,     0,    89,
      80,     0,    90,     0,     0,     0,     0,    88,     0,     0,
      89,     0,     0,    90,     0,    81,    82,    83,     0,     0,
       0,    84,     0,     0,    85,    86,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,     0,    88,     0,
       0,    89,     0,     0,    90,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   200,   201
};

static const yytype_int16 yycheck[] =
{
      64,    34,    64,    68,    64,    87,    92,    66,     4,     4,
       4,     4,    71,     4,    65,     4,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,     4,    92,     4,
      92,    37,    92,    53,     3,     4,     5,     4,    58,     4,
       4,     4,   124,   125,    34,    35,   128,   129,   130,     4,
       0,     4,    48,     4,   136,    50,   107,   139,   117,    53,
      53,    50,    53,   127,     4,   127,    56,    36,    31,   151,
      39,    48,   154,    48,    38,     4,    31,    44,    31,    48,
      31,   145,   146,    52,    53,    17,    43,     3,     4,     5,
      49,    31,    53,     3,     4,     5,    33,    58,    30,   275,
     276,    30,     6,     7,     8,     9,    10,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
      36,   297,    52,    39,    19,    55,    36,    57,    58,    39,
      57,    58,    48,     3,     4,     5,    52,    53,    48,    34,
      53,   223,    52,    53,    52,    58,    53,    55,     3,     4,
       5,    58,    51,   218,     4,    54,     3,     4,     5,    52,
      51,    47,    55,    54,    49,    58,    36,    51,    52,    39,
       8,     9,    10,     3,     4,     5,    53,    54,    48,    53,
      54,    36,    52,    53,    39,    40,    41,   220,     4,    36,
       4,    46,    39,    48,   277,   278,   279,    52,     4,    46,
      52,    48,   288,   289,     4,    52,    36,    53,    54,    39,
      49,   275,   276,   275,   276,   275,   276,   303,    48,    53,
      54,     4,    52,     4,   288,   289,   288,   289,   288,   289,
      53,    30,   265,   297,    52,   297,    51,   297,    49,   303,
       3,   303,    17,   303,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    53,     4,    55,    53,
      50,    58,    34,    35,     4,    54,    52,    51,    56,    52,
      52,    52,    51,    34,    35,    52,    52,    18,    58,    57,
      51,    53,     4,    50,    53,     4,    50,     4,     4,     4,
      58,    51,    53,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    58,     4,    18,     4,    50,
      52,    34,    35,    52,    52,    51,    51,     4,     4,    53,
       4,    58,    34,    35,     4,     4,     4,    51,    22,    51,
      53,    52,    40,    53,    53,    51,    51,    51,    51,   115,
       5,    53,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    26,    53,    14,    52,    63,    52,
      34,    35,    53,    30,   120,    52,    51,    51,    51,    51,
      51,    34,    35,    51,    51,    51,    92,    51,   151,    71,
     107,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    -1,    -1,    -1,    -1,    -1,     4,    34,    35,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     4,    34,    35,
      -1,    19,    20,    21,    51,    23,    24,    25,    -1,    -1,
      28,    29,    19,    20,    21,    51,    -1,    -1,    25,    -1,
      -1,    28,    29,    -1,    42,    32,    -1,    45,     4,    -1,
      48,    -1,    -1,    -1,    -1,    42,    -1,    -1,    45,     4,
      -1,    48,    -1,    19,    20,    21,    -1,    -1,    -1,    25,
      -1,    27,    28,    29,    19,    20,    21,    -1,    -1,    24,
      25,    -1,    -1,    28,    29,    -1,    42,    -1,    -1,    45,
       4,    -1,    48,    -1,    -1,    -1,    -1,    42,    -1,    -1,
      45,    -1,    -1,    48,    -1,    19,    20,    21,    -1,    -1,
      -1,    25,    -1,    -1,    28,    29,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    -1,    42,    -1,
      -1,    45,    -1,    -1,    48,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    34,    35
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    37,    60,    61,     4,    62,    63,     0,    43,    67,
      49,    38,    63,     4,    68,    69,    72,     4,    30,    78,
      98,    64,    47,    44,    69,    49,    33,    97,     4,    31,
      79,    80,    81,     4,    88,    89,    90,    92,    98,     4,
      65,    66,     4,    70,    52,    31,    80,     4,    82,    83,
      89,    98,    49,     4,    91,     4,    50,    66,    30,    53,
      52,    55,    51,    54,    17,    30,    93,    99,    52,    51,
      73,    49,     4,    53,    84,    85,    86,    87,     3,    83,
       4,    19,    20,    21,    25,    28,    29,    32,    42,    45,
      48,   100,   101,   102,   103,   104,   105,   106,   109,   110,
     111,   112,   114,   116,   118,    31,    81,    94,    95,    99,
      50,    53,    84,     4,    74,    75,    76,    93,    99,    53,
      54,     4,    56,    52,    55,    57,    58,    52,    52,    52,
      52,    51,    51,     3,     4,     5,    36,    39,    48,    52,
     113,   114,   115,   116,   118,    52,    52,    58,    18,   100,
     102,    57,    58,    51,    57,     4,    96,    31,    95,    50,
      53,     4,     4,    31,    76,    99,    50,    86,    53,   113,
     117,   113,    40,    41,    46,   107,   108,   113,     4,     4,
     114,   118,   113,   113,   113,    58,   113,    58,   113,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      34,    35,    51,    58,     4,   114,     4,   114,     4,    51,
      18,   108,   113,     4,   113,    51,    54,    51,    52,     4,
      71,    50,    53,    54,    56,    52,    52,    52,    51,    51,
      51,    53,    53,    53,    53,    53,    53,     4,     4,    53,
     113,   113,   113,   113,   113,   113,   113,   113,   113,   113,
     113,   113,   113,     4,    53,    53,    53,    51,    51,    51,
      51,     4,    53,    84,     4,    77,    89,   113,    53,    53,
       4,    51,    51,    51,    51,    22,    26,    52,    52,    52,
      51,    51,    51,    51,    53,    50,    89,    53,   101,   101,
      53,   117,    53,   117,    53,   117,    51,    23,    24,    27,
      53,    53,    53,   101,    51,    51,    24,    51
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    59,    60,    60,    60,    61,    61,    62,    62,    64,
      63,    65,    65,    66,    67,    67,    68,    68,    70,    71,
      69,    72,    72,    73,    73,    74,    75,    75,    76,    76,
      77,    77,    78,    78,    79,    79,    80,    81,    82,    82,
      83,    83,    83,    83,    84,    85,    85,    86,    87,    88,
      88,    89,    89,    90,    90,    91,    92,    93,    93,    94,
      94,    95,    96,    96,    97,    98,    98,    99,    99,   100,
     101,   101,   102,   102,   102,   102,   102,   102,   102,   102,
     102,   102,   103,   103,   103,   104,   105,   105,   105,   105,
     105,   105,   106,   107,   107,   108,   109,   109,   110,   111,
     112,   112,   113,   113,   113,   113,   113,   113,   113,   113,
     113,   113,   113,   113,   113,   113,   113,   113,   113,   113,
     113,   113,   113,   113,   113,   114,   114,   114,   115,   115,
     115,   115,   115,   115,   116,   116,   117,   117,   118
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     4,     3,     3,     0,     2,     1,     0,
       5,     2,     1,     3,     3,     0,     2,     1,     0,     0,
      10,     1,     3,     2,     0,     3,     2,     1,     6,     5,
       2,     1,     3,     2,     2,     1,     3,     1,     3,     1,
       1,     4,     4,     3,     1,     3,     1,     2,     1,     2,
       1,     5,     4,     5,     4,     1,     1,     3,     2,     2,
       1,     3,     3,     1,     1,     8,     7,     5,     4,     3,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     2,     5,     5,     5,     5,     4,     4,     4,     4,
       4,     4,     5,     3,     3,     4,    10,     8,     8,     2,
       5,     5,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     3,     3,     5,     6,
       5,     6,     5,     6,     3,     4,     3,     1,     4
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
#line 1588 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 39 "task1.y" /* yacc.c:1646  */
    { }
#line 1594 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 40 "task1.y" /* yacc.c:1646  */
    { }
#line 1600 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 44 "task1.y" /* yacc.c:1646  */
    {print_Typetable(); }
#line 1606 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 45 "task1.y" /* yacc.c:1646  */
    {print_Typetable(); }
#line 1612 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 47 "task1.y" /* yacc.c:1646  */
    { }
#line 1618 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 48 "task1.y" /* yacc.c:1646  */
    { }
#line 1624 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 51 "task1.y" /* yacc.c:1646  */
    {TInstall((yyvsp[-1].tnode)->varname,0,NULL);}
#line 1630 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 52 "task1.y" /* yacc.c:1646  */
    {
							Typetable *ttable=TLookup((yyvsp[-4].tnode)->varname);
							 ttable->fields=fieldlist_head;
							 ttable->size=getSize(ttable);
							 reset_fieldlist();	
						      
							 }
#line 1642 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 61 "task1.y" /* yacc.c:1646  */
    { }
#line 1648 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 62 "task1.y" /* yacc.c:1646  */
    { }
#line 1654 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 64 "task1.y" /* yacc.c:1646  */
    {FInstall((yyvsp[-1].tnode)->varname,TLookup((yyvsp[-2].tnode)->varname)); }
#line 1660 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 67 "task1.y" /* yacc.c:1646  */
    {print_classtable(); }
#line 1666 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 68 "task1.y" /* yacc.c:1646  */
    {print_classtable(); }
#line 1672 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 70 "task1.y" /* yacc.c:1646  */
    { }
#line 1678 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 71 "task1.y" /* yacc.c:1646  */
    { }
#line 1684 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 73 "task1.y" /* yacc.c:1646  */
    {Classdecl_end_flag=0;}
#line 1690 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 73 "task1.y" /* yacc.c:1646  */
    {Classdecl_end_flag=1;}
#line 1696 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 73 "task1.y" /* yacc.c:1646  */
    {createVfuncTableEntries();currclass=NULL;}
#line 1702 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 75 "task1.y" /* yacc.c:1646  */
    {
						(yyval.classtable)=CInstall((yyvsp[0].tnode)->varname,NULL);
						currclass=(yyval.classtable);
					}
#line 1711 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 79 "task1.y" /* yacc.c:1646  */
    {
						(yyval.classtable)=CInstall((yyvsp[-2].tnode)->varname,(yyvsp[0].tnode)->varname);
						currclass=(yyval.classtable);
					}
#line 1720 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 84 "task1.y" /* yacc.c:1646  */
    { }
#line 1726 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 85 "task1.y" /* yacc.c:1646  */
    {/*NO ACTION*/}
#line 1732 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 87 "task1.y" /* yacc.c:1646  */
    {	
							Class_FInstall(currclass,(yyvsp[-2].tnode)->varname,(yyvsp[-1].tnode)->varname); 
						}
#line 1740 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 91 "task1.y" /* yacc.c:1646  */
    { }
#line 1746 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 92 "task1.y" /* yacc.c:1646  */
    { }
#line 1752 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 94 "task1.y" /* yacc.c:1646  */
    { 
								Class_MInstall(currclass,(yyvsp[-4].tnode)->varname,TLookup((yyvsp[-5].tnode)->varname),paramlist_head);
								reset_paramlist();
							}
#line 1761 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 98 "task1.y" /* yacc.c:1646  */
    { 
								Class_MInstall(currclass,(yyvsp[-3].tnode)->varname,TLookup((yyvsp[-4].tnode)->varname),paramlist_head);
								reset_paramlist();
							}
#line 1770 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 103 "task1.y" /* yacc.c:1646  */
    {}
#line 1776 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 104 "task1.y" /* yacc.c:1646  */
    { }
#line 1782 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 107 "task1.y" /* yacc.c:1646  */
    {
						print_Gsymbol_table();
					 	Gdecl_end_flag=1;
						sp=sp+1;//next instruction address
						fp=fopen("start.xsm","a"); 
						fprintf(fp,"MOV SP, %d\n",sp);
						fprintf(fp,"CALL F0\n");
						fclose(fp);
       						scall("Exit",0,0);	
						
					}
#line 1798 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 118 "task1.y" /* yacc.c:1646  */
    {
						print_Gsymbol_table();
					 	Gdecl_end_flag=1;
						sp=sp+1;//next address
						fp=fopen("start.xsm","a"); 
						fprintf(fp,"MOV SP, %d\n",sp);
						fprintf(fp,"CALL F0\n");
						fclose(fp);
       						scall("Exit",0,0);
					}
#line 1813 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 130 "task1.y" /* yacc.c:1646  */
    { }
#line 1819 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 131 "task1.y" /* yacc.c:1646  */
    { }
#line 1825 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 134 "task1.y" /* yacc.c:1646  */
    { }
#line 1831 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 136 "task1.y" /* yacc.c:1646  */
    { 
				currtype=TLookup((yyvsp[0].tnode)->varname);
				curr_declclass=CLookup((yyvsp[0].tnode)->varname);
			}
#line 1840 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 142 "task1.y" /* yacc.c:1646  */
    { }
#line 1846 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 143 "task1.y" /* yacc.c:1646  */
    { }
#line 1852 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 146 "task1.y" /* yacc.c:1646  */
    {	
						if(curr_declclass==NULL)
						{GInstall((yyvsp[0].tnode)->varname,currtype,curr_declclass,1,paramlist_head);}
						else
						{GInstall((yyvsp[0].tnode)->varname,currtype,curr_declclass,2,paramlist_head);}
						reset_paramlist();
					}
#line 1864 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 153 "task1.y" /* yacc.c:1646  */
    {
						GInstall((yyvsp[-3].tnode)->varname,currtype,curr_declclass,(yyvsp[-1].tnode)->val,paramlist_head);
						reset_paramlist();
					}
#line 1873 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 157 "task1.y" /* yacc.c:1646  */
    {
						GInstall((yyvsp[-3].tnode)->varname,currtype,curr_declclass,-1,paramlist_head); 
						reset_paramlist();
					}
#line 1882 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 161 "task1.y" /* yacc.c:1646  */
    {
						GInstall((yyvsp[-2].tnode)->varname,currtype,curr_declclass,-1,paramlist_head);
						reset_paramlist();
					}
#line 1891 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 167 "task1.y" /* yacc.c:1646  */
    {
					}
#line 1898 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 170 "task1.y" /* yacc.c:1646  */
    { }
#line 1904 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 171 "task1.y" /* yacc.c:1646  */
    { }
#line 1910 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 173 "task1.y" /* yacc.c:1646  */
    {
						(yyval.paramstruct)=create_param_node((yyvsp[0].tnode)->varname,(yyvsp[-1].Typetable));
						PInstall((yyval.paramstruct));
					}
#line 1919 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 178 "task1.y" /* yacc.c:1646  */
    {(yyval.Typetable)=TLookup((yyvsp[0].tnode)->varname);}
#line 1925 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 183 "task1.y" /* yacc.c:1646  */
    {}
#line 1931 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 184 "task1.y" /* yacc.c:1646  */
    {}
#line 1937 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 187 "task1.y" /* yacc.c:1646  */
    { 
					print_Lsymbol_table(func_name);	
				printf("ABSTRACT SYNTAX TREE FOR %s Function\n",func_name);
				//preorder($4);
				printf("------------GENERATED SUCCESSFULLY---------------------------\n");
				printf("---------CODEGEN------\n");
				generate_code((yyvsp[-1].tnode),func_name);
					reset_Lsymbol_table();	
					}
#line 1951 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 196 "task1.y" /* yacc.c:1646  */
    { 
					print_Lsymbol_table(func_name);	
				printf("ABSTRACT SYNTAX TREE FOR %s Function\n",func_name);
				//preorder($3);
				printf("-------------GENERATED SUCCESSFULLY--------------------------\n");
				printf("---------CODEGEN------\n");
				generate_code((yyvsp[-1].tnode),func_name);
					reset_Lsymbol_table();	

			       }
#line 1966 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 207 "task1.y" /* yacc.c:1646  */
    {
						createLsymbolEntries(paramlist_head);
						name_equivalence((yyvsp[-4].Typetable),(yyvsp[-3].tnode)->varname,paramlist_head);
						reset_paramlist();	
					      }
#line 1976 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 212 "task1.y" /* yacc.c:1646  */
    {
						createLsymbolEntries(paramlist_head);
						name_equivalence((yyvsp[-3].Typetable),(yyvsp[-2].tnode)->varname,NULL);
						reset_paramlist();	
					      }
#line 1986 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 218 "task1.y" /* yacc.c:1646  */
    {(yyval.tnode)=(yyvsp[0].tnode);strcpy(func_name,(yyvsp[0].tnode)->varname); }
#line 1992 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 220 "task1.y" /* yacc.c:1646  */
    {(yyval.Typetable)=TLookup((yyvsp[0].tnode)->varname); }
#line 1998 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 222 "task1.y" /* yacc.c:1646  */
    { }
#line 2004 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 223 "task1.y" /* yacc.c:1646  */
    { }
#line 2010 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 225 "task1.y" /* yacc.c:1646  */
    { }
#line 2016 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 226 "task1.y" /* yacc.c:1646  */
    { }
#line 2022 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 228 "task1.y" /* yacc.c:1646  */
    { }
#line 2028 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 230 "task1.y" /* yacc.c:1646  */
    {LInstall((yyvsp[0].tnode)->varname,currtype);}
#line 2034 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 231 "task1.y" /* yacc.c:1646  */
    {LInstall((yyvsp[0].tnode)->varname,currtype); }
#line 2040 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 234 "task1.y" /* yacc.c:1646  */
    {strcpy(func_name,"MAIN"); }
#line 2046 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 237 "task1.y" /* yacc.c:1646  */
    {
			print_Lsymbol_table("MAIN");
				printf("ABSTRACT SYNTAX TREE FOR MAIN Function\n");
				//preorder($7);
				printf("---------------GENERATED SUCCESSFULLY------------------------\n");
				
				printf("---------CODEGEN------\n");
				generate_code((yyvsp[-1].tnode),func_name);
			reset_Lsymbol_table();
		}
#line 2061 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 248 "task1.y" /* yacc.c:1646  */
    {
			print_Lsymbol_table("MAIN");
				printf("ABSTRACT SYNTAX TREE FOR MAIN Function\n");
				//preorder($6);
				printf("-------------GENERATED SUCCESSFULLY--------------------------\n");
				printf("---------CODEGEN------\n");
				generate_code((yyvsp[-1].tnode),func_name);
			reset_Lsymbol_table();
			
		}
#line 2076 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 260 "task1.y" /* yacc.c:1646  */
    {
			(yyval.tnode)=create_tree(0,TLookup("null"),NULL,conn_node,(yyvsp[-3].tnode),NULL,(yyvsp[-2].tnode));	
			 }
#line 2084 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 263 "task1.y" /* yacc.c:1646  */
    {
						(yyval.tnode)=(yyvsp[-2].tnode);
					}
#line 2092 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 267 "task1.y" /* yacc.c:1646  */
    {	
				typecheck((yyvsp[-1].tnode));
				(yyval.tnode)=create_tree(0,(yyvsp[-1].tnode)->type,func_name,ret_node,(yyvsp[-1].tnode),NULL,NULL);
			 }
#line 2101 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 276 "task1.y" /* yacc.c:1646  */
    {
				(yyval.tnode)=create_tree(0,TLookup("null"),NULL,conn_node,(yyvsp[-1].tnode),NULL,(yyvsp[0].tnode));	
			}
#line 2109 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 279 "task1.y" /* yacc.c:1646  */
    {(yyval.tnode)=(yyvsp[0].tnode); }
#line 2115 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 282 "task1.y" /* yacc.c:1646  */
    {(yyval.tnode)=(yyvsp[0].tnode);}
#line 2121 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 283 "task1.y" /* yacc.c:1646  */
    {(yyval.tnode)=(yyvsp[0].tnode);}
#line 2127 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 284 "task1.y" /* yacc.c:1646  */
    {(yyval.tnode)=(yyvsp[0].tnode);}
#line 2133 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 285 "task1.y" /* yacc.c:1646  */
    {(yyval.tnode)=(yyvsp[0].tnode);}
#line 2139 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 286 "task1.y" /* yacc.c:1646  */
    {(yyval.tnode)=(yyvsp[0].tnode);}
#line 2145 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 287 "task1.y" /* yacc.c:1646  */
    {(yyval.tnode)=(yyvsp[0].tnode);}
#line 2151 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 288 "task1.y" /* yacc.c:1646  */
    {(yyval.tnode)=(yyvsp[0].tnode);}
#line 2157 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 289 "task1.y" /* yacc.c:1646  */
    {(yyval.tnode)=(yyvsp[0].tnode);}
#line 2163 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 290 "task1.y" /* yacc.c:1646  */
    {
				(yyval.tnode)=create_tree(0,TLookup("null"),NULL,continue_node,NULL,NULL,NULL);
			}
#line 2171 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 293 "task1.y" /* yacc.c:1646  */
    {
				(yyval.tnode)=create_tree(0,TLookup("null"),NULL,break_node,NULL,NULL,NULL);
			}
#line 2179 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 298 "task1.y" /* yacc.c:1646  */
    {	
					typecheck((yyvsp[-2].tnode));
					(yyval.tnode)=create_tree(0,TLookup("null"),NULL,read_node,(yyvsp[-2].tnode),NULL,NULL);	
				}
#line 2188 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 302 "task1.y" /* yacc.c:1646  */
    {
					typecheck((yyvsp[-2].tnode));
					(yyval.tnode)=create_tree(0,TLookup("null"),NULL,read_node,(yyvsp[-2].tnode),NULL,NULL);

				}
#line 2198 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 307 "task1.y" /* yacc.c:1646  */
    {
					typecheck((yyvsp[-2].tnode));
					(yyval.tnode)=create_tree(0,TLookup("null"),NULL,read_node,(yyvsp[-2].tnode),NULL,NULL); 
				}
#line 2207 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 312 "task1.y" /* yacc.c:1646  */
    {	
					typecheck((yyvsp[-2].tnode));
					(yyval.tnode)=create_tree(0,TLookup("null"),NULL,write_node,(yyvsp[-2].tnode),NULL,NULL);
				}
#line 2216 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 317 "task1.y" /* yacc.c:1646  */
    {
					typecheck((yyvsp[-3].tnode));typecheck((yyvsp[-1].tnode));
					(yyval.tnode)=create_tree(0,TLookup("null"),"=",assg_node,(yyvsp[-3].tnode),NULL,(yyvsp[-1].tnode));
				}
#line 2225 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 321 "task1.y" /* yacc.c:1646  */
    {
					typecheck((yyvsp[-3].tnode));typecheck((yyvsp[-1].tnode));
					(yyval.tnode)=create_tree(0,TLookup("null"),"=",assg_node,(yyvsp[-3].tnode),NULL,(yyvsp[-1].tnode));
				}
#line 2234 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 325 "task1.y" /* yacc.c:1646  */
    {
					typecheck((yyvsp[-3].tnode));typecheck((yyvsp[-1].tnode));
					(yyval.tnode)=create_tree(0,TLookup("null"),"=",assg_node,(yyvsp[-3].tnode),NULL,(yyvsp[-1].tnode));
				}
#line 2243 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 329 "task1.y" /* yacc.c:1646  */
    {
					typecheck((yyvsp[-3].tnode));typecheck((yyvsp[-1].tnode));
					(yyval.tnode)=create_tree(0,TLookup("null"),"=",assg_node,(yyvsp[-3].tnode),NULL,(yyvsp[-1].tnode));
				}
#line 2252 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 333 "task1.y" /* yacc.c:1646  */
    {
				typecheck((yyvsp[-3].tnode));typecheck((yyvsp[-1].tnode));
				(yyval.tnode)=create_tree(0,TLookup("null"),"=",assg_node,(yyvsp[-3].tnode),NULL,(yyvsp[-1].tnode));
			  }
#line 2261 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 337 "task1.y" /* yacc.c:1646  */
    {
				typecheck((yyvsp[-3].tnode));typecheck((yyvsp[-1].tnode));
				(yyval.tnode)=create_tree(0,TLookup("null"),"=",assg_node,(yyvsp[-3].tnode),NULL,(yyvsp[-1].tnode));
			   }
#line 2270 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 342 "task1.y" /* yacc.c:1646  */
    { 
				typecheck((yyvsp[-2].tnode));
				(yyval.tnode)=create_tree(0,TLookup("int"),NULL,free_node,(yyvsp[-2].tnode),NULL,NULL);
				}
#line 2279 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 347 "task1.y" /* yacc.c:1646  */
    {			
				(yyval.tnode)=create_tree(0,TLookup("null"),NULL,alloc_node,NULL,NULL,NULL);
			}
#line 2287 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 350 "task1.y" /* yacc.c:1646  */
    {	
				(yyval.tnode)=create_tree(0,TLookup("int"),NULL,initialize_node,NULL,NULL,NULL);
			    }
#line 2295 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 354 "task1.y" /* yacc.c:1646  */
    {
					
					(yyval.tnode)=create_tree(0,NULL,NULL,new_node,NULL,NULL,NULL);
					//$$->ctype=$3->ctype;
					(yyval.tnode)->ctype=CLookup((yyvsp[-1].tnode)->varname);
				}
#line 2306 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 362 "task1.y" /* yacc.c:1646  */
    {	
					(yyval.tnode)=create_tree(0,TLookup("null"),NULL,if_node,(yyvsp[-7].tnode),(yyvsp[-4].tnode),(yyvsp[-2].tnode));
				}
#line 2314 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 366 "task1.y" /* yacc.c:1646  */
    {	
					(yyval.tnode)=create_tree(0,TLookup("null"),NULL,if_node,(yyvsp[-5].tnode),(yyvsp[-2].tnode),NULL); 
				}
#line 2322 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 371 "task1.y" /* yacc.c:1646  */
    {	
					(yyval.tnode)=create_tree(0,TLookup("null"),NULL,while_node,(yyvsp[-5].tnode),NULL,(yyvsp[-2].tnode));
				}
#line 2330 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 376 "task1.y" /* yacc.c:1646  */
    {(yyval.tnode)=(yyvsp[-1].tnode); }
#line 2336 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 378 "task1.y" /* yacc.c:1646  */
    {
					typecheck((yyvsp[-2].tnode));
					(yyval.tnode)=create_tree(0,TLookup("int"),NULL,free_node,(yyvsp[-2].tnode),NULL,NULL);	
				}
#line 2345 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 383 "task1.y" /* yacc.c:1646  */
    {
					typecheck((yyvsp[-2].tnode));
					(yyval.tnode)=create_tree(0,TLookup("int"),NULL,free_node,(yyvsp[-2].tnode),NULL,NULL);
				}
#line 2354 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 389 "task1.y" /* yacc.c:1646  */
    {
					typecheck((yyvsp[-2].tnode));typecheck((yyvsp[0].tnode));
					(yyval.tnode)=create_tree(0,TLookup("int"),"+",aop_node,(yyvsp[-2].tnode),NULL,(yyvsp[0].tnode));
				}
#line 2363 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 393 "task1.y" /* yacc.c:1646  */
    {
					typecheck((yyvsp[-2].tnode));typecheck((yyvsp[0].tnode));
					(yyval.tnode)=create_tree(0,TLookup("int"),"-",aop_node,(yyvsp[-2].tnode),NULL,(yyvsp[0].tnode)); 
				}
#line 2372 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 397 "task1.y" /* yacc.c:1646  */
    {
					typecheck((yyvsp[-2].tnode));typecheck((yyvsp[0].tnode));
					(yyval.tnode)=create_tree(0,TLookup("int"),"*",aop_node,(yyvsp[-2].tnode),NULL,(yyvsp[0].tnode));
				}
#line 2381 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 401 "task1.y" /* yacc.c:1646  */
    {
					typecheck((yyvsp[-2].tnode));typecheck((yyvsp[0].tnode));
					(yyval.tnode)=create_tree(0,TLookup("int"),"/",aop_node,(yyvsp[-2].tnode),NULL,(yyvsp[0].tnode));
				}
#line 2390 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 405 "task1.y" /* yacc.c:1646  */
    {
					typecheck((yyvsp[-2].tnode));typecheck((yyvsp[0].tnode));
					(yyval.tnode)=create_tree(0,TLookup("int"),"%",aop_node,(yyvsp[-2].tnode),NULL,(yyvsp[0].tnode));
				}
#line 2399 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 410 "task1.y" /* yacc.c:1646  */
    {
					typecheck((yyvsp[-2].tnode));typecheck((yyvsp[0].tnode));
					(yyval.tnode)=create_tree(0,TLookup("bool"),"<=",lop_node,(yyvsp[-2].tnode),NULL,(yyvsp[0].tnode)); 
				}
#line 2408 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 414 "task1.y" /* yacc.c:1646  */
    {
					typecheck((yyvsp[-2].tnode));typecheck((yyvsp[0].tnode));
					(yyval.tnode)=create_tree(0,TLookup("bool"),">=",lop_node,(yyvsp[-2].tnode),NULL,(yyvsp[0].tnode));
				}
#line 2417 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 418 "task1.y" /* yacc.c:1646  */
    {
					typecheck((yyvsp[-2].tnode));typecheck((yyvsp[0].tnode));
					(yyval.tnode)=create_tree(0,TLookup("bool"),"<",lop_node,(yyvsp[-2].tnode),NULL,(yyvsp[0].tnode));
				}
#line 2426 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 422 "task1.y" /* yacc.c:1646  */
    {
					typecheck((yyvsp[-2].tnode));typecheck((yyvsp[0].tnode));
					(yyval.tnode)=create_tree(0,TLookup("bool"),">",lop_node,(yyvsp[-2].tnode),NULL,(yyvsp[0].tnode));
				}
#line 2435 "y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 426 "task1.y" /* yacc.c:1646  */
    {
					typecheck((yyvsp[-2].tnode));typecheck((yyvsp[0].tnode));
					(yyval.tnode)=create_tree(0,TLookup("bool"),"==",lop_node,(yyvsp[-2].tnode),NULL,(yyvsp[0].tnode));
				}
#line 2444 "y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 430 "task1.y" /* yacc.c:1646  */
    {
					typecheck((yyvsp[-2].tnode));typecheck((yyvsp[0].tnode));
					(yyval.tnode)=create_tree(0,TLookup("bool"),"!=",lop_node,(yyvsp[-2].tnode),NULL,(yyvsp[0].tnode));
				}
#line 2453 "y.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 435 "task1.y" /* yacc.c:1646  */
    {
					typecheck((yyvsp[-2].tnode));typecheck((yyvsp[0].tnode));
					(yyval.tnode)=create_tree(0,TLookup("bool"),"&&",lop_node,(yyvsp[-2].tnode),NULL,(yyvsp[0].tnode));
				}
#line 2462 "y.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 439 "task1.y" /* yacc.c:1646  */
    {
					typecheck((yyvsp[-2].tnode));typecheck((yyvsp[0].tnode));
					(yyval.tnode)=create_tree(0,TLookup("bool"),"||",lop_node,(yyvsp[-2].tnode),NULL,(yyvsp[0].tnode));
				}
#line 2471 "y.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 443 "task1.y" /* yacc.c:1646  */
    {
				 	typecheck((yyvsp[0].tnode));
					(yyval.tnode)=create_tree(0,TLookup("bool"),"!",lop_node,(yyvsp[0].tnode),NULL,NULL);
				}
#line 2480 "y.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 448 "task1.y" /* yacc.c:1646  */
    {(yyval.tnode)=(yyvsp[-1].tnode);}
#line 2486 "y.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 449 "task1.y" /* yacc.c:1646  */
    {(yyval.tnode)=(yyvsp[0].tnode);}
#line 2492 "y.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 450 "task1.y" /* yacc.c:1646  */
    {(yyval.tnode)=(yyvsp[0].tnode);}
#line 2498 "y.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 451 "task1.y" /* yacc.c:1646  */
    {(yyval.tnode)=(yyvsp[0].tnode);}
#line 2504 "y.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 452 "task1.y" /* yacc.c:1646  */
    {(yyval.tnode)=(yyvsp[0].tnode);}
#line 2510 "y.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 453 "task1.y" /* yacc.c:1646  */
    {(yyval.tnode)=(yyvsp[0].tnode);}
#line 2516 "y.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 454 "task1.y" /* yacc.c:1646  */
    {(yyval.tnode)=(yyvsp[0].tnode);}
#line 2522 "y.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 455 "task1.y" /* yacc.c:1646  */
    {(yyval.tnode)=(yyvsp[0].tnode);}
#line 2528 "y.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 456 "task1.y" /* yacc.c:1646  */
    {(yyval.tnode)=(yyvsp[0].tnode);}
#line 2534 "y.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 458 "task1.y" /* yacc.c:1646  */
    {
				struct Fieldlist *f;
				if(currclass==NULL)
				{
				printf("self can only be used inside a class definition\n");
				exit(1);
				}
				f=Class_FLookup(currclass,(yyvsp[0].tnode)->varname);
				if(f==NULL)
				{
				printf("Undeclared variable %s inside the class %s\n",(yyvsp[0].tnode)->varname,currclass->name);
				exit(1);
				}
				(yyval.tnode)=create_tree(0,NULL,"self",field_node,NULL,NULL,NULL);
				(yyval.tnode)->faccess=(yyvsp[0].tnode);
				(yyvsp[0].tnode)->val=f->fieldIndex;
				(yyvsp[0].tnode)->type=f->type;
				(yyvsp[0].tnode)->ctype=f->ctype;
				(yyval.tnode)->type=f->type;
				(yyval.tnode)->ctype=f->ctype;
			}
#line 2560 "y.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 479 "task1.y" /* yacc.c:1646  */
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
				if((yyvsp[-2].tnode)->ctype!=NULL)
				{
					printf("Cannot access private variable from outside a  class\n");
					exit(1);
				}
				(yyvsp[-2].tnode)->nodetype=field_node;
				(yyvsp[-2].tnode)->faccess=(yyvsp[0].tnode);
				(yyvsp[0].tnode)->type=f->type;
				(yyvsp[0].tnode)->val=f->fieldIndex;
				(yyvsp[-2].tnode)->type=(yyvsp[0].tnode)->type;
				(yyval.tnode)=(yyvsp[-2].tnode);	
			}
#line 2592 "y.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 506 "task1.y" /* yacc.c:1646  */
    {
				struct tnode *temp; 
				struct Fieldlist *f;
				temp=(yyvsp[-2].tnode);
				while(temp->faccess!=NULL)
					temp=temp->faccess;
				if(temp->ctype!=NULL)
				{
				printf("Cannot access private variables of a class\n");
				exit(1);
				}
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
#line 2622 "y.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 533 "task1.y" /* yacc.c:1646  */
    {
						struct Memberfunclist *mfunc;
						struct Paramstruct *plist;
						if(currclass==NULL)
						{
						printf("self can only be used inside a class definition\n");
						exit(1);
						}
						mfunc=Class_MLookup(currclass,(yyvsp[-2].tnode)->varname);
						if(mfunc==NULL)
						{
						printf("Undefined method %s of Class %s\n",(yyvsp[-2].tnode)->varname,currclass->name);
						exit(1);
						}
						if(hasSameSignatureArg(mfunc->paramlist,NULL)!=1)
						{
						printf("ARGUMENTS TYPE MISMATCH FOR FUNCTION CALL self.%s of class %s\n",(yyvsp[-2].tnode)->varname,currclass->name);
						exit(1);
						}
						(yyval.tnode)=create_tree(0,NULL,"self",fieldfunction_node,NULL,NULL,NULL);
						(yyvsp[-2].tnode)->type=mfunc->type;
						(yyval.tnode)->type=(yyvsp[-2].tnode)->type;
					  	(yyval.tnode)->ctype=currclass;
					  	(yyval.tnode)->faccess=(yyvsp[-2].tnode);
					  	(yyvsp[-2].tnode)->left=NULL;
						
					}
#line 2654 "y.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 560 "task1.y" /* yacc.c:1646  */
    {
						struct Memberfunclist *mfunc;
						struct Paramstruct *plist;
						if(currclass==NULL)
						{
						printf("self can only be used inside a class definition\n");
						exit(1);
						}
						mfunc=Class_MLookup(currclass,(yyvsp[-3].tnode)->varname);
						if(mfunc==NULL)
						{
						printf("Undefined method %s of Class %s\n",(yyvsp[-3].tnode)->varname,currclass->name);
						exit(1);
						}
						if(hasSameSignatureArg(mfunc->paramlist,(yyvsp[-1].tnode))!=1)
						{
						printf("ARGUMENTS TYPE MISMATCH FOR FUNCTION CALL self.%s of class %s\n",(yyvsp[-3].tnode)->varname,currclass->name);
						exit(1);
						}
						(yyval.tnode)=create_tree(0,NULL,"self",fieldfunction_node,NULL,NULL,NULL);
						(yyvsp[-3].tnode)->type=mfunc->type;
						(yyval.tnode)->type=(yyvsp[-3].tnode)->type;
					  	(yyval.tnode)->ctype=currclass;
					  	(yyval.tnode)->faccess=(yyvsp[-3].tnode);
					  	(yyvsp[-3].tnode)->left=(yyvsp[-1].tnode);
					}
#line 2685 "y.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 586 "task1.y" /* yacc.c:1646  */
    {	typecheck((yyvsp[-4].tnode));
						struct Memberfunclist *mfunc;
						struct Paramstruct *plist;
						mfunc=Class_MLookup((yyvsp[-4].tnode)->ctype,(yyvsp[-2].tnode)->varname);
						if(hasSameSignatureArg(mfunc->paramlist,NULL)!=1)
						{
						printf("ARGUMENTS TYPE MISMATCH FOR FUNCTION CALL %s.%s of class %s\n",(yyvsp[-4].tnode)->varname,(yyvsp[-2].tnode)->varname,(yyvsp[-4].tnode)->ctype->name);
						exit(1);
						}
						(yyval.tnode)=create_tree(0,NULL,(yyvsp[-4].tnode)->varname,fieldfunction_node,NULL,NULL,NULL);
						(yyvsp[-2].tnode)->type=mfunc->type;
						(yyval.tnode)->type=(yyvsp[-2].tnode)->type;
						(yyval.tnode)->ctype=(yyvsp[-4].tnode)->ctype;
						(yyval.tnode)->faccess=(yyvsp[-2].tnode);
						(yyval.tnode)->Gentry=(yyvsp[-4].tnode)->Gentry;
						(yyvsp[-2].tnode)->left=NULL;
						
					}
#line 2708 "y.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 604 "task1.y" /* yacc.c:1646  */
    {	typecheck((yyvsp[-5].tnode));
						struct Memberfunclist *mfunc;
						struct Paramstruct *plist;
						mfunc=Class_MLookup((yyvsp[-5].tnode)->ctype,(yyvsp[-3].tnode)->varname);
						if(hasSameSignatureArg(mfunc->paramlist,(yyvsp[-1].tnode))!=1)
						{
						printf("ARGUMENTS TYPE MISMATCH FOR FUNCTION CALL %s.%s of class %s\n",(yyvsp[-5].tnode)->varname,(yyvsp[-3].tnode)->varname,(yyvsp[-5].tnode)->ctype->name);
						exit(1);
						}
						(yyval.tnode)=create_tree(0,NULL,(yyvsp[-5].tnode)->varname,fieldfunction_node,NULL,NULL,NULL);
						(yyvsp[-3].tnode)->type=mfunc->type;
						(yyval.tnode)->type=(yyvsp[-3].tnode)->type;
						(yyval.tnode)->ctype=(yyvsp[-5].tnode)->ctype;
						(yyval.tnode)->faccess=(yyvsp[-3].tnode);
						(yyval.tnode)->Gentry=(yyvsp[-5].tnode)->Gentry;
						(yyvsp[-3].tnode)->left=(yyvsp[-1].tnode);

					}
#line 2731 "y.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 622 "task1.y" /* yacc.c:1646  */
    {
						struct tnode *temp;		
						struct Memberfunclist *mfunc;
						temp=(yyvsp[-4].tnode);
						temp=temp->faccess;
						if(temp->faccess!=NULL)
						{
							printf("Illegal member function access\n");
							exit(1);
						}
						mfunc=Class_MLookup(temp->ctype,(yyvsp[-2].tnode)->varname);
						if(hasSameSignatureArg(mfunc->paramlist,NULL)!=1)
						{
		     	printf("ARGUMENTS TYPE MISMATCH FOR FUNCTION CALL %s of class %s\n",(yyvsp[-2].tnode)->varname,temp->ctype->name);
						exit(1);
						}
						(yyvsp[-4].tnode)->nodetype=fieldfunction_node;
						(yyval.tnode)=(yyvsp[-4].tnode);
						(yyvsp[-2].tnode)->type=mfunc->type;
						(yyval.tnode)->type=(yyvsp[-2].tnode)->type;
						temp->faccess=(yyvsp[-2].tnode);
						(yyvsp[-2].tnode)->left=NULL;
					}
#line 2759 "y.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 645 "task1.y" /* yacc.c:1646  */
    {
						struct tnode *temp;		
						struct Memberfunclist *mfunc;
						temp=(yyvsp[-5].tnode);
						temp=temp->faccess;
						if(temp->faccess!=NULL)
						{
							printf("Illegal member function access\n");
							exit(1);
						}
						mfunc=Class_MLookup(temp->ctype,(yyvsp[-3].tnode)->varname);
						if(hasSameSignatureArg(mfunc->paramlist,(yyvsp[-1].tnode))!=1)
						{
		     	printf("ARGUMENTS TYPE MISMATCH FOR FUNCTION CALL %s of class %s\n",(yyvsp[-3].tnode)->varname,temp->ctype->name);
						exit(1);
						}
						(yyvsp[-5].tnode)->nodetype=fieldfunction_node;
						(yyval.tnode)=(yyvsp[-5].tnode);
						(yyvsp[-3].tnode)->type=mfunc->type;
						(yyval.tnode)->type=(yyvsp[-3].tnode)->type;
						temp->faccess=(yyvsp[-3].tnode);
						(yyvsp[-3].tnode)->left=(yyvsp[-1].tnode);

					}
#line 2788 "y.tab.c" /* yacc.c:1646  */
    break;

  case 134:
#line 670 "task1.y" /* yacc.c:1646  */
    {
				typecheck((yyvsp[-2].tnode));
				(yyval.tnode)=create_tree(0,TLookup("null"),(yyvsp[-2].tnode)->varname,func_node,NULL,NULL,NULL);		
			}
#line 2797 "y.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 674 "task1.y" /* yacc.c:1646  */
    {
					typecheck((yyvsp[-3].tnode));typecheck((yyvsp[-1].tnode));
					(yyval.tnode)=create_tree(0,TLookup("null"),(yyvsp[-3].tnode)->varname,func_node,(yyvsp[-1].tnode),NULL,NULL);	
			  	}
#line 2806 "y.tab.c" /* yacc.c:1646  */
    break;

  case 136:
#line 681 "task1.y" /* yacc.c:1646  */
    {
					(yyvsp[0].tnode)->middle=(yyvsp[-2].tnode);
					typecheck((yyvsp[-2].tnode));typecheck((yyvsp[0].tnode));
					(yyval.tnode)=(yyvsp[0].tnode);
				}
#line 2816 "y.tab.c" /* yacc.c:1646  */
    break;

  case 137:
#line 686 "task1.y" /* yacc.c:1646  */
    {
					(yyval.tnode)=(yyvsp[0].tnode);
					typecheck((yyval.tnode));
				}
#line 2825 "y.tab.c" /* yacc.c:1646  */
    break;

  case 138:
#line 691 "task1.y" /* yacc.c:1646  */
    {	
					typecheck((yyvsp[-3].tnode));typecheck((yyvsp[-1].tnode));
					(yyval.tnode)=create_tree(0,(yyvsp[-3].tnode)->type,(yyvsp[-3].tnode)->varname,arr_node,(yyvsp[-1].tnode),NULL,NULL);	
				}
#line 2834 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2838 "y.tab.c" /* yacc.c:1646  */
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
#line 696 "task1.y" /* yacc.c:1906  */

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
	fp=fopen("start.xsm","w");
	
	fprintf(fp,"%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n",0,2056,0,0,0,0,0,0);
	fprintf(fp,"MOV SP, %d\n",sp);
	fclose(fp);
	
	fp=fopen("temp.xsm","w");
	fclose(fp);
	TypeTableCreate();
	yyparse();	
	FILE *fp1,*fp2,*fp3;
	fp1=fopen("start.xsm","r");
	fp2=fopen("temp.xsm","r");
	fp3=fopen("task1.xsm","w");
	char c;
	while((c=fgetc(fp1))!=EOF)
		fputc(c,fp3);
	while((c=fgetc(fp2))!=EOF)
		fputc(c,fp3);
	fclose(fp1);
	fclose(fp2);
	fclose(fp3);
	
	
	return 0;
}

