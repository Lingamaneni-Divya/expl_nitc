%{
	#include<stdio.h>
	#include"task2.h"
	#include"task2.c"
	int yylex(void);
	int yyerror(char const*);
	int yywrap();
	FILE *fp,*yyin;
%}

%union{
	struct tnode *no;
      }

%token NUM ID PLUS MINUS MUL DIV READ WRITE IF THEN ELSE ENDIF WHILE DO ENDWHILE GT LT GE LE EE NE PBEGIN PEND

%type <no> ID NUM expr WhileStmt IfStmt AssgStmt OutputStmt InputStmt Stmt Slist program
%left GE LE EE NE GT LT
%left PLUS MINUS 
%left MUL DIV


%%
program	:PBEGIN Slist PEND ';'	{$$=$2;
				 printf("Abstract syntax tree created succesfully\n");
				 preorder($$);
				 //evaluate($$);
				codegen($$);
				scall("Exit",0,0);
				}
	|PBEGIN PEND ';' 	{$$=NULL;}
	;

Slist	:Slist Stmt		{$$=create_tree(0,nulltype,NULL,conn_node,$1,NULL,$2);}
	|Stmt			{$$=$1;}
	;

Stmt	:InputStmt		{$$=$1;}
	|OutputStmt		{$$=$1;}
	|AssgStmt		{$$=$1;}
	|IfStmt			{$$=$1;}
	|WhileStmt		{$$=$1;}
	;

InputStmt:READ '('ID')'';'	{$$=create_tree(0,nulltype,NULL,read_node,$3,NULL,NULL);}
	;
OutputStmt:WRITE '('expr')' ';'	{$$=create_tree(0,nulltype,NULL,write_node,$3,NULL,NULL);}
	;
AssgStmt:ID '=' expr ';'	{$$=create_tree(0,nulltype,"=",assg_node,$1,NULL,$3);}
	;
IfStmt	:IF '('expr')' THEN Slist ELSE Slist ENDIF ';'
			     	{$$=create_tree(0,nulltype,NULL,if_node,$3,$6,$8);}
	|IF '('expr')' THEN Slist ENDIF ';'
				{$$=create_tree(0,nulltype,NULL,if_node,$3,$6,NULL);}
	;
WhileStmt:WHILE '('expr')' DO Slist ENDWHILE';'
				{$$=create_tree(0,nulltype,NULL,while_node,$3,NULL,$6);}
	;



expr	:expr PLUS expr		{$$=create_tree(0,inttype,"+",aop_node,$1,NULL,$3);}
	|expr MINUS expr	{$$=create_tree(0,inttype,"-",aop_node,$1,NULL,$3);}
	|expr MUL expr		{$$=create_tree(0,inttype,"*",aop_node,$1,NULL,$3);}
	|expr DIV expr		{$$=create_tree(0,inttype,"/",aop_node,$1,NULL,$3);}
	
	|expr LE expr		{$$=create_tree(0,booltype,"<=",lop_node,$1,NULL,$3);}
	|expr GE expr		{$$=create_tree(0,booltype,">=",lop_node,$1,NULL,$3);}
	|expr LT expr		{$$=create_tree(0,booltype,"<",lop_node,$1,NULL,$3);}
	|expr GT expr		{$$=create_tree(0,booltype,">",lop_node,$1,NULL,$3);}
	|expr EE expr		{$$=create_tree(0,booltype,"==",lop_node,$1,NULL,$3);}
	|expr NE expr		{$$=create_tree(0,booltype,"!=",lop_node,$1,NULL,$3);}
	|'('expr')'		{$$=$2;}
	|ID			{$$=$1;}
	|NUM			{$$=$1;}
	;
%%
int yyerror(char const *s)
{
	printf("yyerror %s",s);
}
int main()
{
	yyin=fopen("task2.txt","r");
	fp=fopen("task2.xsm","w");
	fprintf(fp, "%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n",0,2056,0,0,0,0,0,0); 
	fprintf(fp, "BRKP\n");
	fprintf(fp, "MOV SP,4121\n");
	fclose(fp);
	yyparse();
	return 0;
}
	
