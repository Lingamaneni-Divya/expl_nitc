/*Declarations section start here*/

/* Auxiliary declarations start here*/
%option noyywrap
%{
	#include <stdio.h>
	int global_variable;
%}

/*Auxiliary declarations end & Regular definitions start here*/

number [0-9]+
op     [-|+|*|/|^|=]

/*Declarations section ends here*/
/*rules*/
%%

{number} {printf(" number ");}
{op} {printf(" operator ");}

%%
/*auxiliary functions*/
int main()
{
    yylex();
    return 1;
}

