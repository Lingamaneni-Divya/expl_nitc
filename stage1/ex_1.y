%{
	#include <stdio.h>
	#include <stdlib.h>
	#include "ex_1.h"
 	#include "ex_1.c"

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
			postfix($$);printf("\n");
			prefix($$);printf("\n");
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
  yyparse();
  return 0;
}
