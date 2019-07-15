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
	struct tnode *tnode;
	struct Gsymbol *Gsymbol;
	struct Paramstruct *paramstruct;
      }

%token NUM VAR MESG  PLUS MINUS MUL DIV MOD  GT LT GE LE EE NE  PBEGIN PEND READ WRITE  IF THEN ELSE ENDIF  WHILE DO ENDWHILE  CONTINUE BREAK  DECL ENDDECL INT STR  RETURN MAINFN ANDTK ORTK NOTTK
%type <tnode> VAR NUM MESG expr ArgList Fcall Sarray FuncStmt
%type <paramstruct> Param ParamList 
%left GE LE EE NE GT LT ANDTK ORTK NOTTK
%left PLUS MINUS 
%left MUL DIV MOD 


%%

Program	:GdeclBlock FDefBlock MainBlock 	
	|GdeclBlock MainBlock			
	|MainBlock				
	;

GdeclBlock:DECL Gdecllist ENDDECL	{print_Gsymbol_table();
					}	
	| DECL ENDDECL			{print_Gsymbol_table();
					}	
	;

Gdecllist:Gdecllist Gdecl		{ }		
	|Gdecl				{ }	
	;

Gdecl	:Type Gvarlist ';'		{/*currtype=nulltype;*/ }	
	;

Gvarlist:Gvarlist ',' Gvar		{ }	
	|Gvar				{ }
	;					 
	
Gvar	:VAR				{GInstall($1->varname,currtype,1,NULL);}	
	|VAR '['NUM']' 			{GInstall($1->varname,currtype,$3->val,NULL);}
	|VAR '('ParamList')' 		{GInstall($1->varname,currtype,-1,$3);}
	|VAR '(' ')'			{GInstall($1->varname,currtype,-1,NULL);}
	;

		

FDefBlock:FDefBlock Fdef		
	|Fdef				
	;
Fdef	:Type VAR '('ParamList')''{'LdeclBlock Body'}' 
	|Type VAR '('ParamList')' '{'Body'}'		
	|Type VAR '('')''{'LdeclBlock Body'}' 		
	|Type VAR '('')' '{'Body'}'			
	;
ParamList:ParamList ',' Param	      {$$=PInstall($1,$3);}
	|Param			      {$$=$1;}
	;
Param	:Type VAR		      {//printf("type:%d\n",currtype);
					$$=create_param_node($2->varname,currtype);
					
					}
	;

LdeclBlock:DECL LDecList ENDDECL			
	|DECL ENDDECL				
	;
LDecList:LDecList LDecl 	
	|LDecl			
	;
LDecl	:Type Lvarlist	';'		
	;
Lvarlist:Lvarlist ','VAR 
	|VAR
	;
Type	:INT		{currtype=inttype;}				
	|STR		{currtype=inttype;}			
	;
MainBlock:Type MAINFN '(' ')' '{'LdeclBlock Body'}' 	
	|Type MAINFN '(' ')' '{'Body'}'			
	;


Body	:PBEGIN Slist RetStmt PEND';'
	;
RetStmt	:RETURN expr ';'		
	;




Slist	:Slist Stmt		
	|Stmt			
	;

Stmt	:InputStmt		
	|OutputStmt		
	|AssgStmt		
	|IfStmt			
	|WhileStmt		
	|FuncStmt		
	|CONTINUE';'		
	|BREAK';'		
	;

InputStmt:READ '('VAR')'';'	
	 |READ '('Sarray')'';'	
	;
OutputStmt:WRITE '('expr')' ';'	
	  ;
AssgStmt:VAR '=' expr ';'	
	|Sarray'='expr';'	
	;
IfStmt	:IF '('expr')' THEN Slist ELSE Slist ENDIF ';'
			     	
	|IF '('expr')' THEN Slist ENDIF ';'
				
	;
WhileStmt:WHILE '('expr')' DO Slist ENDWHILE';'
				

	;
FuncStmt:Fcall';'				//{$$=$1;}


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

	|expr ANDTK expr        {$$=create_tree(0,booltype,"&&",lop_node,$1,NULL,$3);}
	|expr ORTK expr		{$$=create_tree(0,booltype,"||",lop_node,$1,NULL,$3);}
	|expr NOTTK expr	{$$=create_tree(0,booltype,"!",lop_node,$1,NULL,$3);}
	
	|'('expr')'		{$$=$2;}	
	|VAR			{$$=$1;}	
	|NUM	       		{$$=$1;}		
	|MESG			{$$=$1;}		
	|Sarray			{$$=$1;}	
	|Fcall			{$$=$1;}	
	;
Fcall	:VAR '(' ')'		
	|VAR '(' ArgList ')'	
	;
//Arglist,expr because function call may be as factorial(n-1);
//may be like f(1,f(0)); in recursion etc
ArgList	:ArgList ',' expr
	|expr
	;
Sarray	:VAR '[' expr ']'	
	;
%%
int yyerror(char const *s)
{
	printf("yyerror %s",s);
}
int main(int argc, char *argv[])
{
	if(argc==2)
	{
		char *filename;
		int n=strlen(argv[1]);
		filename=(char *) malloc(n *sizeof(char));
		strcpy(filename,argv[1]);
		printf("filename:%s\n",filename);
		yyin=fopen(filename,"r");
			
	}
	else
	{	
		yyin=fopen("task1.txt","r");
	}	
	fp=fopen("task1.xsm","w");
	
	fprintf(fp,"%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n",0,2056,0,0,0,0,0,0); 
	fclose(fp);
	yyparse();
	return 0;
}
	
