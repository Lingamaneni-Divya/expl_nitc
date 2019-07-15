%{
	#include<stdio.h>
	#include<stdlib.h>
	
	#include"y.tab.h"
	#include"task1.h"
	int yyerror(char const*);
	
	int number;
%}
/*struct tnode* create_tree(int val,int type,char* varname,int nodetype,struct tnode *l,struct tnode *r);*/
%%
[0-9]+	{	number=atoi(yytext);
		yylval.no=create_tree(number,0,NULL,const_node,NULL,NULL);
		return NUM;
	}
[a-z]	{
		yylval.no=create_tree(0,0,yytext,var_node,NULL,NULL);
		return ID;
	}
"begin"	{return PBEGIN;}
"read"	{return READ;}
"write"	{return WRITE;}
"end"	{return PEND;}
"+"	{return PLUS;}
"-"	{return MINUS;}
"*"	{return MUL;}
"/"	{return DIV;}
";"	{return *yytext;}
"="	{return *yytext;}
[ \t]	{}
[\n]	{}
[()]	{return *yytext;}
.	{	yyerror("unknown character\n");
		exit(1);
	}
%%
int yywrap(void)
{
	return 1;
} 
