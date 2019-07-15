%{
  #include <stdio.h>
  #include <stdlib.h>
  int yywrap();
  int yylex();
  int yyparse();
  int yyerror();
%}

%token DIGIT

%left '+' '-'
%left '*' 

%%

start : expr '\n' { $$=$1;
                     printf("Expression value = %d",$$); return 0;}
      ;

expr:  expr '+' expr		{$$ = $1 + $3;}
	| expr '-' expr		{$$ = $1 - $3;}
	| expr '*' expr		{$$ = $1 * $3;}
	| '(' expr ')'	 	{$$ = $2;}
	| DIGIT			{$$ = $1;}
	;

%%

int yyerror()
{
	printf("Error\n");
}

int main()
{
  yyparse();
  return 1;
}
