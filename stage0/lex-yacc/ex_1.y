%{
      #include <stdio.h>
      #include <stdlib.h>
      #define YYSTYPE char
      int yyerror(char const *s);
      int yyparse();
      int yylex();
%}

%token CHARACTER NEWLINE
%left '+' '-'
%left '*' '/'
%%

start : expr NEWLINE  {
                        printf("\nComplete\n");
                        exit(1);
                      }
  ;

expr: expr '+' expr     { printf("+ ");}
    | expr '-' expr     {printf("- ");}
    | expr '*' expr     {printf("* ");}
    | expr '/' expr     {printf("/ ");}
    | '(' expr ')'
    | CHARACTER         {printf("%c ",yylval);}
    ;

%%

int yyerror(char const *s)
{
    printf("yyerror  %s\n",s);
  
}
int main()
{
  yyparse();
  return 1;
}
