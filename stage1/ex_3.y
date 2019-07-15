%{
	#include <stdio.h>
	#include <stdlib.h>
	#include "ex_3.h"
 	#include "ex_3.c"
	FILE *fp,*yyin;
	int yyerror(char const *s);
	int yylex(void);
	
%}
%union{
	 struct tnode *no;
	}
%token NUM PLUS MINUS MUL DIV END
%type <no> expr NUM program END	

%left PLUS MINUS
%left MUL DIV
	
%%
	
program : expr END {    printf("tree generated!!!\n");
			printf("infix notation\n");
                        infix($$);printf("\n");
			printf("postfix notation\n");
			postfix($$);printf("\n");
			printf("prefix notation\n");
			prefix($$);printf("\n");
   			int r=codegen($$);
			freereg();
			scall("Write",-2,4096);
			scall("Exit",0,0);
			return 0;
		    }
	;
	
expr    : PLUS expr expr 	{$$ = makeOperatorNode('+',$2,$3);}
        | MINUS expr expr 	{$$ = makeOperatorNode('-',$2,$3);}
        | MUL expr expr 	{$$ = makeOperatorNode('*',$2,$3);}
        | DIV expr expr 	{$$ = makeOperatorNode('/',$2,$3);}
	| '(' expr ')' 		{$$ = $2;}
	| NUM		        {$$ = $1;}
	;
	
%%
	
int yyerror(char const *s)
{
	printf("yyerror %s",s);
}
	
int main() {
	yyin =fopen("ex_3.txt","r");
	fp = fopen("ex_3.xsm","w");
	fprintf(fp,"%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n",0,2056,0,0,0,0,0,0);
	fprintf(fp,"MOV SP,4096\n");
	fclose(fp);
	yyparse();
	return 0;
}
