%{

#include <stdio.h>
#include <stdlib.h>

int commentStart = 0;

/*
[ \t\r\n]      ;
*/

%}

singleCom \/\/(.)*
multiComStart \/\*(.)*
multiComEnd (.)*\*\/
multiCom \/\*(.)*\*\/
nonCom (.)+

%%

{singleCom} {printf("SINGLE LINE: \t%s\n\n",yytext);}

{multiCom} {printf("MULTI LINE: \t%s\n\n",yytext);}

{multiComEnd} {	printf("\t\t%s\n\n",yytext);
				yywrap();}
				
{multiComStart} {
				commentStart = 1;
				printf("MULTI LINE: \t%s\n\n",yytext);
				}

{nonCom} {
			if(commentStart)
				printf("\t\t%s\n\n",yytext);
		}

[ \t\r\n]      ;

%%

int yywrap() {
	if(commentStart) {
		commentStart = 0;
		return 0;
	}
	return 1;
}

int main() {
	yyin = fopen("input_file_ex_1.4.l","r");
	yylex();
	return 0;
}

