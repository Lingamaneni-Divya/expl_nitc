%{
	#include<stdio.h>
	#include"task3.h"
	#include"task3.c"
	int yylex(void);
	int yyerror(char const*);
	int yywrap();
	FILE *fp,*yyin;
	int currtype;
%}

%union{
	struct tnode *no;
      }

%token NUM VAR PLUS MINUS MUL DIV READ WRITE IF THEN ELSE ENDIF WHILE DO ENDWHILE GT LT GE LE EE NE PBEGIN PEND CONTINUE BREAK INT STR DECL ENDDECL MESG MOD

%type <no> VAR NUM MESG expr WhileStmt IfStmt AssgStmt OutputStmt InputStmt Stmt Slist program Sarray
%left GE LE EE NE GT LT
%left PLUS MINUS 
%left MUL DIV MOD


%%
program	:PBEGIN Declarations Slist PEND ';' 	{	$$=$3;
							printf("Abstract Syntax Tree Created Successfully\n");
				 		 	preorder($$);
							fp=fopen("task3.xsm","a");
							fprintf(fp,"MOV SP,%d\n",sp);
							fclose(fp);
							codegen($$);
							scall("Exit",0,0);
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
	|Varlist ',' VAR '['NUM']' 		{printf("currtype:%d\n",currtype);
						 Install($3->varname,currtype,$5->val);
						
						}
	|VAR '['NUM']' 				{printf("currtype:%d\n",currtype);
						 Install($1->varname,currtype,$3->val);
						
						}			
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
	 |READ '('Sarray')'';'	{$$=create_tree(0,nulltype,NULL,read_node,$3,NULL,NULL);}
	;
OutputStmt:WRITE '('expr')' ';'	{$$=create_tree(0,nulltype,NULL,write_node,$3,NULL,NULL);}
	  ;
AssgStmt:VAR '=' expr ';'	{$$=create_tree(0,nulltype,"=",assg_node,$1,NULL,$3);}
	|Sarray '=' expr ';'	{$$=create_tree(0,nulltype,NULL,assg_node,$1,NULL,$3);}
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
	|expr MOD expr		{$$=create_tree(0,inttype,"%",aop_node,$1,NULL,$3);}
	
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
	|Sarray			{$$=$1;}
	;
Sarray	:VAR '[' NUM ']'	{$$=create_tree(0,$1->type,$1->varname,$1->nodetype,$3,NULL,NULL);
		free($1);
	}
	|VAR '[' VAR ']'	{$$=create_tree(0,$1->type,$1->varname,$1->nodetype,$3,NULL,NULL);
		free($1);
	}
	;
%%
int yyerror(char const *s)
{
	printf("yyerror %s",s);
}
int main()
{
	yyin=fopen("task3.txt","r");
	fp=fopen("task3.xsm","w");
	fprintf(fp, "%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n",0,2056,0,0,0,0,0,0); 
	//fprintf(fp, "BRKP\n");
	//fprintf(fp, "MOV SP,4121\n");
	fclose(fp);
	yyparse();
	return 0;
}
	
