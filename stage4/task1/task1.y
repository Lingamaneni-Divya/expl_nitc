%{
	#include<stdio.h>
	#include"task1.h"
	#include"task1.c"
	int yylex(void);
	int yyerror(char const*);
	int yywrap();
	FILE *fp,*yyin;
	int currtype;
%}

%union{
	struct tnode *no;
      }

%token NUM VAR PLUS MINUS MUL DIV READ WRITE IF THEN ELSE ENDIF WHILE DO ENDWHILE GT LT GE LE EE NE PBEGIN PEND CONTINUE BREAK INT STR DECL ENDDECL MESG

%type <no> VAR NUM MESG expr WhileStmt IfStmt AssgStmt OutputStmt InputStmt Stmt Slist program
%left GE LE EE NE GT LT
%left PLUS MINUS 
%left MUL DIV


%%
program	:PBEGIN Declarations Slist PEND ';' 	{	$$=$3;
							printf("Abstract Syntax Tree Created Successfully\n");
				 		 	preorder($$);
						 	return 0;
						}

	|PBEGIN Declarations PEND ';' 			{$$=NULL;}
	;

Declarations: DECL Decllist ENDDECL		{print_symbol_table();}
	    | DECL ENDDECL			{print_symbol_table();}
	    ;

Decllist:Decllist Decl				{ }
	|Decl					{ }
	;

Decl	:Type Varlist ';'			{ }
	;
Type	:INT					{currtype=inttype;}
	|STR					{currtype=strtype;}
	;
Varlist :Varlist ',' VAR			{printf("currtype:%d\n",currtype);
						 Install($3->varname,currtype,1);}	
	|VAR					{printf("currtype:%d\n",currtype);
						  Install($1->varname,currtype,1);}
	;
		




Slist	:Slist Stmt		{$$=create_tree(0,nulltype,NULL,conn_node,$1,NULL,$2);}
	|Stmt			{$$=$1;}
	;

Stmt	:InputStmt		{$$=$1;}
	|OutputStmt		{$$=$1;}
	|AssgStmt		{$$=$1;}
	|IfStmt			{$$=$1;}
	|WhileStmt		{$$=$1;}
	|CONTINUE';'		{$$=create_tree(0,nulltype,NULL,continue_node,NULL,NULL,NULL);}
	|BREAK';'		{$$=create_tree(0,nulltype,NULL,break_node,NULL,NULL,NULL);}
	;

InputStmt:READ '('VAR')'';'	{$$=create_tree(0,nulltype,NULL,read_node,$3,NULL,NULL);}
	;
OutputStmt:WRITE '('expr')' ';'	{$$=create_tree(0,nulltype,NULL,write_node,$3,NULL,NULL);}
	  ;
AssgStmt:VAR '=' expr ';'	{$$=create_tree(0,nulltype,"=",assg_node,$1,NULL,$3);}
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
	|VAR			{$$=$1;}
	|NUM			{$$=$1;}
	|MESG			{$$=$1;}
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
	
