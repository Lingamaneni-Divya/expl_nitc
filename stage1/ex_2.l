%{
	#include <stdio.h>
	#include "ex_2.h"
	#include <stdlib.h>
	#include "y.tab.h"
        int yylex(void);
        int yyerror(char const *s);
	int number;
	
%}	
%%
	
[0-9]+ {number = atoi(yytext);
	yylval.no = makeLeafNode(number); 
        return NUM;
	}
"+" {return PLUS;}
"-" {return MINUS;}
"*" {return MUL;}
"/" {return DIV;}
[ \t] {}
[()] {return *yytext;}
[\n] {return END;}
(.) {yyerror("unknown character\n");
	exit(1);}

%%
	
int yywrap(void) 
{
   return 1;
}
