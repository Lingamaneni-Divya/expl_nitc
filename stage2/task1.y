%{
	#include<stdio.h>
	#include<stdlib.h>
	
	#include"task1.h"
	#include"task1.c"
	int yylex(void);
	int yyerror(char const*);
	int yywrap();
	FILE *fp,*yyin;
%}
%union
{
	struct tnode *no;
}
%type <no> NUM ID expr AssgStmt OutputStmt InputStmt Stmt Slist program
%token NUM ID PLUS MINUS MUL DIV READ WRITE PBEGIN PEND
%left PLUS MINUS
%left MUL DIV

%%
program : PBEGIN Slist PEND';'	{$$=$2;
				 printf("Abstract syntax tree created succesfully\n");
				inorder($2);}
	|PBEGIN PEND';'		{$$=NULL;}
	;
Slist	: Slist Stmt		{$$=create_tree(0,0,NULL,conn_node,$1,$2);}	
	|Stmt			{$$=$1;}
	;
Stmt	: InputStmt		{$$=$1;}
	|OutputStmt		{$$=$1;}
	|AssgStmt		{$$=$1;}
	;
InputStmt:READ'('ID')'';'	{$$=create_tree(0,0,NULL,read_node,$3,NULL);}
	 ;
OutputStmt:WRITE'('expr')'';'	{$$=create_tree(0,0,NULL,write_node,$3,NULL);}
	  ;
AssgStmt	:ID'='expr';'	{$$=create_tree(0,0,"=",assg_node,$1,$3);}
	;
expr	:expr PLUS expr		{$$=create_tree(0,0,"+",op_node,$1,$3);}
	|expr MINUS expr	{$$=create_tree(0,0,"-",op_node,$1,$3);}
	|expr MUL expr		{$$=create_tree(0,0,"*",op_node,$1,$3);}
	|expr DIV expr		{$$=create_tree(0,0,"/",op_node,$1,$3);}
	|'('expr')'		{$$=$2;}
	|NUM			{$$=$1;}
	|ID			{$$=$1;}
	;
%%
int yyerror(char const *s)
{
	printf("yyerror %s",s);
}		
int main()
{
	yyin=fopen("task1.txt","r");
	yyparse();
	return 0;
}
