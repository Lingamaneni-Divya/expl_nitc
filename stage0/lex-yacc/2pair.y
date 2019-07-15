%{
  #include <stdio.h>
  #include<stdlib.h>
  int yyerror();
  int yylex();
  int yyparse();
  int yywrap();
%}

%token DIGIT NEWLINE
/*%left '+' '-'
%left '*' '/'
*/
%%

start : pair NEWLINE {printf("\nComplete\n"); return 0;}
      ;

pair  : num ',' num	{ printf("pair(%d,%d)",$1,$3); }
      ;
num   : DIGIT		{$$=$1;}
      ;

%%

int yyerror()
{
	printf("Error");
}

int main()
{
	yyparse();
	return 1;
}
