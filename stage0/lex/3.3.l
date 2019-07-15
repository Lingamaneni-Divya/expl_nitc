%option noyywrap
%{
	#include <stdlib.h>
	#include <stdio.h>
%}
	
number [0-9]+
 
%%
 
{number} printf("Number of digits = %d",yyleng);

 
%%
 
int main()
{
	yylex();
	return 1;
}
