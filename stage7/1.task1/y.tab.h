/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
#line 15 "task1.y" /* yacc.c:1909  */

	struct tnode *tnode;
	struct Gsymbol *Gsymbol;
	struct Paramstruct *paramstruct;
	struct Typetable *Typetable;
	struct Classtable *classtable;
      

#line 159 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
