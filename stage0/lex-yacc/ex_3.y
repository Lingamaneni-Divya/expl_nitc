%{
	#include<stdio.h>
	#include<stdlib.h>
	#include<string.h>
	int yyerror(char const *s);
     	int yyparse();
     	int yylex(void);
	char buf[10];
%}
%union {
	 char *str;
	}

%token STRI NEWLINE
%left '+' '-'
%left '*' '/'
%type <str> expr STRI NEWLINE start
%%
start: expr NEWLINE {printf("%s\nComplete\n",$1);
			return 0;
		    }
	;
expr	:expr '*' expr	{buf[0]='\0';strcpy($$,strcat(strcpy(buf,"* "),strcat($1,$3)));}
	|expr '/' expr	{buf[0]='\0';strcpy($$,strcat(strcpy(buf,"/ "),strcat($1,$3)));}
	|expr '+' expr	{buf[0]='\0';strcpy($$,strcat(strcpy(buf,"+ "),strcat($1,$3)));}
	|expr '-' expr	{buf[0]='\0';strcpy($$,strcat(strcpy(buf,"- "),strcat($1,$3)));}	
	| '(' expr ')'	{buf[0]='\0';strcpy($$,strcat($2,(strcpy(buf," ")))); }
	|STRI		{buf[0]='\0';strcpy($$,strcat($1,(strcpy(buf," ")))); }
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

