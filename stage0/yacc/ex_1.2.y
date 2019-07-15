%{
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int yyerror(char const *);
int yyparse();
int yylex();

%}

%token ALPHABET NUM

%%
start:var '\n' {printf("valid variable\n");
                 return 0;}
     ;
var :ALPHABET rest;
rest :ALPHABET rest
      |NUM rest
      |ALPHABET
      |NUM
     ;

%%
int yyerror(char const* s)
{
  printf("yyerror %s",s);
}
yylex(){
   char c;
   c=getchar(); 
   if(isdigit(c))
     return NUM;
   else if(isalpha(c))
     return ALPHABET;
   else
    return c;
}

int main()
{
 yyparse();
  return 1;
}


