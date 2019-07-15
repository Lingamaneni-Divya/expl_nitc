%{
	#include <stdio.h>
	#include <stdlib.h>
	#include "m2.h"
 	#include "m2.c"
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
			printf("postfix notation\n");
			postfix($$);printf("\n");
			printf("prefix notation\n");
			prefix($$);printf("\n");
			printf("infix notation\n");
                        infix($$);printf("\n");
			printf("infix of sqaures\n");
			infixsquare($$);printf("\n");
			int r;
   			r =codegen($$);
			freereg();
			printf("Expression value:\n");
			scall("Write",-2,4096);
			r =codegen_sos($$);
			freereg();
			printf("Expression of squares value:\n");
			scall("Write",-2,4097);
			scall("Exit",0,0);
			return 0;
		    }
	;
	
expr    : expr PLUS expr 	{$$ = makeOperatorNode('+',$1,$3);}
        | expr MINUS expr 	{$$ = makeOperatorNode('-',$1,$3);}
        | expr MUL expr 	{$$ = makeOperatorNode('*',$1,$3);}
        | expr DIV expr 	{$$ = makeOperatorNode('/',$1,$3);}
	| '(' expr ')' 		{$$ = $2;}
	| NUM		        {$$ = $1;}
	;
	
%%
	
int yyerror(char const *s)
{
	printf("yyerror %s",s);
}
	
int main() {
	yyin =fopen("m2.txt","r");
	fp = fopen("m2.xsm","w");
	fprintf(fp,"%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n",0,2056,0,0,0,0,0,0);
	fprintf(fp,"MOV SP,4097\n");
	fclose(fp);
	yyparse();
	return 0;
}
