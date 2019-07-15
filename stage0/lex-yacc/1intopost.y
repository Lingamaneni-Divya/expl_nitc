%{
      #include <stdio.h>
      #include <stdlib.h>
      int yyerror(char const *s);
      int yyparse();
      int yylex();
%}

%token DIGIT NEWLINE
%left '+' '-'
%left '*' '/'
%%

start : expr NEWLINE  {
                        printf("\nComplete\n");
                        exit(1);
                      }
  ;

expr: expr '+' expr        { printf("+ ");}
    | expr '-' expr     {printf("- ");}
    | '(' expr ')'
    | DIGIT             {printf("%d ",$1);}
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
