/*taking input from last return point when yylex() is used many times.*/

%option noyywrap
%{
	#include <stdlib.h>
	#include <stdio.h>
        char *file1;
%}
	
number [0-9]+

%%

{number} {return atoi(yytext);}

%%
int main()
{
        
        file1="1.txt";
  	yyin = fopen("1.txt","r");
        int num = yylex();
	printf("Found: %d",num);
        yylex();
        num = yylex();
	printf("Found: %d",num);
       
return 1;
}
