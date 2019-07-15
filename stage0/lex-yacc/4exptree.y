%{
	#include <stdio.h>
	#include <stdlib.h>
	#include "4exptree.h"
 	#include "4exptree.c"

	int yyerror(char const *s);
	int yylex(void);
	
%}
%union{
	 struct tnode *no;
	}

%type <no> expr DIGIT program END	
%token DIGIT PLUS MINUS MUL DIV END
%left PLUS MINUS
%left MUL DIV
	
%%
	
program : expr END {    $$ = $2;
			printf("Answer : %d\n",evaluate($1));
			exit(1);
		    }
	;
	
expr    : expr PLUS expr 	{$$ = makeOperatorNode('+',$1,$3);}
	| expr MINUS expr 	{$$ = makeOperatorNode('-',$1,$3);}
	| expr MUL expr 	{$$ = makeOperatorNode('*',$1,$3);}
	| expr DIV expr	        {$$ = makeOperatorNode('/',$1,$3);}
	| '(' expr ')' 		{$$ = $2;}
	| DIGIT 		{$$ = $1;}
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
