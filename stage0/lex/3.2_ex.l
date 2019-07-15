/*yytext usage*/

%option noyywrap
%{
	#include <stdlib.h>
	#include <stdio.h>
%}
	
number_sequence [0-9]*
 
%%
 
{number_sequence}[0|2|4|6|8] {printf("Found : %d AN EVEN NUMBER\n",atoi(yytext));}
{number_sequence}[1|3|5|7|9] {printf("Found : %d AN ODD NUMBER\n",atoi(yytext));}
 
%%
 
int main()
{
	yylex();
	return 1;
}
