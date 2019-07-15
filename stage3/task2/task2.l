%{
	#include<stdio.h>
	#include<stdlib.h>
	#include"y.tab.h"
	#include"task2.h"
	int yyerror(char const*);
	int number;
%}

%%
[0-9]+	{	number=atoi(yytext);
		yylval.no=create_tree(number,inttype,NULL,const_node,NULL,NULL,NULL);
		return NUM;
	}
[a-z]	{
		yylval.no=create_tree(0,inttype,yytext,var_node,NULL,NULL,NULL);
		return ID;
	}
"begin" {return PBEGIN;}
"end"	{return PEND;}
"write"	{return WRITE;}
"read"	{return READ;}

"+"	{return PLUS;}
"-"	{return MINUS;}
"*"	{return MUL;}
"/"	{return DIV;}

";"	{return *yytext;}
"="	{return *yytext;}

">="	{return GE;}
"<="	{return LE;}
"=="	{return EE;}
"!="	{return NE;}
">"	{return GT;}
"<"	{return LT;}

"if"	{return IF;}
"then"	{return THEN;}
"else"	{return ELSE;}
"endif"	{return ENDIF;}

"while"	{return WHILE;}
"do"	{return DO;}
"endwhile" {return ENDWHILE;}


[ \t\n]+ {}
[()]	{return *yytext;}

.	{	yyerror("unknown character\n");
		exit(1);
	}
%%

int yywrap(void)
{
	return 1;
}
