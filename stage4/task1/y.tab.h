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
    PLUS = 260,
    MINUS = 261,
    MUL = 262,
    DIV = 263,
    READ = 264,
    WRITE = 265,
    IF = 266,
    THEN = 267,
    ELSE = 268,
    ENDIF = 269,
    WHILE = 270,
    DO = 271,
    ENDWHILE = 272,
    GT = 273,
    LT = 274,
    GE = 275,
    LE = 276,
    EE = 277,
    NE = 278,
    PBEGIN = 279,
    PEND = 280,
    CONTINUE = 281,
    BREAK = 282,
    INT = 283,
    STR = 284,
    DECL = 285,
    ENDDECL = 286,
    MESG = 287
  };
#endif
/* Tokens.  */
#define NUM 258
#define VAR 259
#define PLUS 260
#define MINUS 261
#define MUL 262
#define DIV 263
#define READ 264
#define WRITE 265
#define IF 266
#define THEN 267
#define ELSE 268
#define ENDIF 269
#define WHILE 270
#define DO 271
#define ENDWHILE 272
#define GT 273
#define LT 274
#define GE 275
#define LE 276
#define EE 277
#define NE 278
#define PBEGIN 279
#define PEND 280
#define CONTINUE 281
#define BREAK 282
#define INT 283
#define STR 284
#define DECL 285
#define ENDDECL 286
#define MESG 287

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 12 "task1.y" /* yacc.c:1909  */

	struct tnode *no;
      

#line 123 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
