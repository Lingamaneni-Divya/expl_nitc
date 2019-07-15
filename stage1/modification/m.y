%{
	#include <stdio.h>
	#include <stdlib.h>
	#include "m.h"
 	#include "m.c"
        FILE *yyin;
	int yyerror(char const *s);
	int yylex(void);
	
%}
%union{
	 struct tnode *no;
	}
%token NUM PLUS END
%type <no> expr NUM program END	

%left PLUS
	
%%
	
program : expr END {   printf("tree generated!!!\n");
			infix($$);printf("\n");
			infixsquare($$);printf("\n");
			return 0;
		    }
	;
	
expr    : expr PLUS expr 	{$$ = makeOperatorNode('+',$1,$3);}
	| '(' expr ')' 		{$$ = $2;}
	| NUM		{$$ = $1;}
	;
	
%%
	
int yyerror(char const *s)
{
	printf("yyerror %s",s);
}
	
	
int main(void) 
{
  yyin = fopen("input.txt","r");
  
  yyparse();
  return 0;
}
