%{
/*** Auxiliary declarations section ***/

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
int yyerror();
int yyparse();
int yylex();
%}

 /*** YACC Declarations section ***/
%token DIGIT
%left '+'
%left '*'
%%

/*** Rules Section ***/
start : expr '\n' {printf("complete\n");exit(1);}
      ;

expr: expr'+'expr   {printf("+ ");}
    | expr'*'expr   {printf("* ");}
    | '('expr')'
    | DIGIT          {printf("%d ",$1);}
    ;

%%



int yyerror()
{
    printf("error");
}

int yylex(){
    char c;
    c = getchar();
    if(isdigit(c)){
        yylval= c-'0';
        return DIGIT;
    }
    
        return c;
    
}

int main()
{
	yyparse();
	return 1;
}
