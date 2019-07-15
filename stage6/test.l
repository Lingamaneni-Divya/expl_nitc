%{
	#include<stdio.h>
	#include<stdlib.h>
	
	int number;
	int declflag;
%}

%%
[0-9]+	{ 
		number=atoi(yytext);
		printf("\ninteger type constant:%d\n",number);
		
	}
	  

"+"	{printf("\nPLUS\n");}
"-"	{printf("\nMINUS\n");}
"*"	{printf("\nMUL\n");}
"/"	{printf("\nDIV\n");}
"%"	{printf("\nMOD\n");}

";"	{printf("\n%s\n",yytext);}
"="	{printf("\n%s\n",yytext);}
[()]	{printf("\n%s\n",yytext);}
","	{printf("\n%s\n",yytext);}
"."	{printf("\n%s\n",yytext);}

">="	{printf("\nGE\n");}
"<="	{printf("\nLE\n");}
"=="	{printf("\nEE\n");}
"!="	{printf("\nNE\n");}
">"	{printf("\nGT\n");}
"<"	{printf("\nLT\n");}


"begin" {printf("\nPBEGIN\n");}
"end"	{printf("\nPEND\n");}
"write"	{printf("\nWRITE\n");}
"read"	{printf("\nREAD\n");}

"and"	{printf("\nANDTK\n");}
"or"	{printf("\nORTK\n");}
"not"	{printf("\nNOTTK\n");}




"if"	{printf("\nIF\n");}
"then"	{printf("\nTHEN\n");}
"else"	{printf("\nELSE\n");}
"endif"	{printf("\nENDIF\n");}

"while"	{printf("\nWHILE\n");}
"do"	{printf("\nDO\n");}
"endwhile" {printf("\nENDWHILE\n");}

"continue" {return printf("\nCONTINUE\n");}
"break"    {return printf("\nBREAK\n");}

"decl"  {declflag=1; printf("\nDECL\n");}
"enddecl" {declflag=0;printf("\nENDDECL\n");}
"int" 	{printf("\nINT\n");}
"str"	{printf("\nSTR\n");}
[\[\]]	{printf("\n%s\n",yytext);}

"main"	{printf("\nMAINFN\n");}
"return" {printf("\nRETURN\n");}
[{}]	{printf("\n%s\n",yytext);}
"type"	{printf("\nTYPE\n");}
"endtype" {printf("\nENDTYPE\n");}
"NULL"	{printf("\nNULLTK\n");}
"alloc" {printf("\nALLOC\n");}
"free"	{printf("\nFREE\n");}
"initialize"	{printf("\nINITIALIZE\n");}
[ \t\n]+ { }

[a-zA-Z][a-zA-Z0-9]*	{
			
			/*yylval.tnode=create_tree(0,nulltype,yytext,var_node,NULL,NULL,NULL);
				return VAR;*/
			printf("\nVARIABLE:%s\n",yytext);
			}
["][^"\n]*["]  {
			printf("\nSTR TYPE CONSTANT:%s\n",yytext);
		}

. {printf("unknown character\n");
   exit(1);
   }
%%

int yywrap(void)
{
	 return 1;
}
int main() {
	yyin = fopen("task1/testcases/10.binary_search_tree.txt","r");
	yylex();
	return 0;
}
