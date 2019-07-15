%{
	#include<stdio.h>
	#include<stdlib.h>
	#include"y.tab.h"
	#include"task1.h"
	int yyerror(char const*);
	int number;
%}

%%
[0-9]+	{	number=atoi(yytext);
		//printf("%d ",number);
		yylval.no=create_tree(number,inttype,NULL,const_node,NULL,NULL,NULL);
		return NUM;
	}
[a-z]	{	//printf("ID ");
		yylval.no=create_tree(0,inttype,yytext,var_node,NULL,NULL,NULL);
		return ID;
	}
"begin" {	//printf("begin ");
		return PBEGIN;}
"end"	{//printf("end ");
	return PEND;}
"write"	{//printf("write ");
	return WRITE;}
"read"	{//printf("read ");
	return READ;}

"+"	{//printf("plus");
	return PLUS;}
"-"	{//printf("minus ");
	return MINUS;}
"*"	{//printf("mul ");
	return MUL;}
"/"	{//printf("div ");
	return DIV;}

";"	{//printf("; ");
	return *yytext;}
"="	{//printf("= ");
	return *yytext;}

">="	{//printf(">= ");
	return GE;}
"<="	{//printf("<= ");
	return LE;}
"=="	{//printf("== ");
	return EE;}
"!="	{//printf("!= ");
	return NE;}
">"	{//printf("> ");
	return GT;}
"<"	{//printf("< ");
	return LT;}

"if"	{//printf("if ");
	return IF;}
"then"	{//printf("then ");
	return THEN;}
"else"	{//printf("else ");
	return ELSE;}
"endif"	{//printf("endif ");
	return ENDIF;}

"while"	{//printf("while ");
	return WHILE;}
"do"	{//printf("do ");
	return DO;}
"endwhile" {return ENDWHILE;}


[ \t\n]+ {//printf("space ");
		}
[()]	{//printf("%s ",yytext);
	return *yytext;}

.	{	yyerror("unknown character\n");
		exit(1);
	}
%%

int yywrap(void)
{
	return 1;
}
