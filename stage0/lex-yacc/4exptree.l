%{
	#include <stdio.h>
	
	#include "4exptree.h"
	#include <stdlib.h>
	#include "y.tab.h"
        int yylex(void);
        int yyerror(char const *s);
	int number;
	
%}
	
%%
	
[0-9]+ {number = atoi(yytext);
	yylval.no = makeLeafNode(number); 
       
	return DIGIT;
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
