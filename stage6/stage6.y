/*perfect grammar for stage 6*/

%{
	#include<stdio.h>
	#include"task1.h"
	#include"task1.c"
	int yylex(void);
	int yyerror(char const *s);
	int yywrap();
	FILE *fp,*yyin;
%}

%union{
	struct tnode *tnode;
	struct Gsymbol *Gsymbol;
	struct Paramstruct *paramstruct;
//check if this is needed
	struct Typenode *typenode;
      }


%token NUM VAR MESG  PLUS MINUS MUL DIV MOD  GT LT GE LE EE NE  PBEGIN PEND READ WRITE  IF THEN ELSE ENDIF  WHILE DO ENDWHILE  CONTINUE BREAK  DECL ENDDECL INT STR  RETURN MAINFN ANDTK ORTK NOTTK TYPE ENDTYPE NULLTK ALLOC INITIALIZE FREE
%type <tnode> VAR NUM MESG NULLTK Fcall Sarray Feild expr ArgList FreeStmt FuncStmt WhileStmt IfStmt AssgStmt OutputStmt InputStmt Stmt Slist RetStmt Body
%type <paramstruct> Param ParamList


%left GE LE EE NE GT LT ANDTK ORTK NOTTK
%left PLUS MINUS 
%left MUL DIV MOD 


%%


Program:TypeDefBlock GdeclBlock FDefBlock MainBlock	{ }
	|TypeDefBlock GdeclBlock MainBlock 		{ }
	|TypeDefBlock MainBlock				{ }
	|GdeclBlock FDefBlock MainBlock			{ }
	|GdeclBlock MainBlock 				{ }
	|MainBlock					{ }
	;



TypeDefBlock: TYPE TypeDefList ENDTYPE			{ }
	    ;
TypeDefList :TypeDefList TypeDef			{ }
	|TypeDef					{ }
	;

TypeDef	:VAR '{' FeildDeclList '}'			{ }
	;

FeildDeclList:FeildDeclList FeildDecl			{ }
	|FeildDecl					{ }
	;
FeildDecl :TypeName VAR ';'				{ }
	;
TypeName : INT 						{ }
	|STR						{ }
	|VAR						{ }
	;



GdeclBlock:DECL Gdecllist ENDDECL	{
						
					}	
	| DECL ENDDECL			{
						
					}	
	;

Gdecllist:Gdecllist Gdecl		{ }		
	|Gdecl				{ }	
	;

Gdecl	:Type Gvarlist ';'		{ }	
	;

Gvarlist:Gvarlist ',' Gvar		{ }	
	|Gvar				{ }
	;					 
	
Gvar	:VAR				{ }	
	|VAR '['NUM']' 			{ }
	|VAR '('ParamList')' 		{ }
	|VAR '(' ')'			{ }
	;

ParamList:ParamList ',' Param 		{ }
	|Param
	;
Param	:ParamTypeName VAR		{
				
					}
	;
ParamTypeName:INT
	|STR
	|VAR
	;



FDefBlock:FDefBlock Fdef		
	|Fdef				
	;
Fdef	:RetTypeName VAR '('ParamList ')' '{'LdeclBlock Body'}'
		 	{ 
				
				
				
			}
	|RetTypeName VAR '(' ')' '{'LdeclBlock Body'}' { }
	|RetTypeName VAR '('ParamList ')' '{' Body'}'
		 	{ 
				
			}	
	|RetTypeName VAR '(' ')' '{' Body'}'	
	;
RetTypeName:INT
	|STR
	|VAR
	;
LdeclBlock:DECL LDecList ENDDECL	{ }		
	|DECL ENDDECL			{ }	
	;
LDecList:LDecList LDecl 		{ }
	|LDecl				{ }
	;
LDecl	:Type Lvarlist	';'		{ }
	;
Lvarlist:Lvarlist ','VAR 		{ }
	|VAR				{ }
	;
Type	:INT		{
				
			}				
	|STR		{
				
			}
	|VAR		{ }			
	;
MainBlock:INT MAINFN '(' ')' '{'LdeclBlock Body'}'
		{

		}
	|INT MAINFN '(' ')' '{' Body '}'
		{

		}
	;
Body	:PBEGIN Slist RetStmt PEND';' { }
	;
RetStmt	:RETURN expr ';' { }
	;




Slist	:Slist Stmt	{ }	
	|Stmt		{ }	
	;

Stmt	:InputStmt		{$$=$1;}
	|OutputStmt		{$$=$1;}
	|AssgStmt		{$$=$1;}
	|IfStmt			{$$=$1;}
	|WhileStmt		{$$=$1;}
	|FuncStmt		{$$=$1;}
	|FreeStmt		{$$=$1;}
	|CONTINUE';'		{ }
	|BREAK';'		{ }
	;

InputStmt:READ '('VAR')'';'	{ }
	 |READ '('Sarray')'';'	{ }
	 |READ '('Feild')'';'	{ }
	;
OutputStmt:WRITE '('expr')' ';'	{ }
	  ;
AssgStmt:VAR '=' expr ';'	{ }
	|Sarray'='expr';'	{ }
	|Feild'='expr';'	{ }
	|VAR '=' dexpr ';'	{ }
//check if this is needed
	|Sarray'='dexpr';'	{ }
	|Feild'='dexpr';'	{ }
	;
dexpr	:ALLOC '(' ')'
	|INITIALIZE '(' ')'
	;
IfStmt	:IF '('expr')' THEN Slist ELSE Slist ENDIF ';'
			     	{ }
	|IF '('expr')' THEN Slist ENDIF ';'
				{ }
	;
WhileStmt:WHILE '('expr')' DO Slist ENDWHILE';'
				{ }

	;
FuncStmt:Fcall';'		{ }
	;
FreeStmt:FREE '('Feild')'';'	{ }
	|FREE '('VAR')' ';'	{ }
//check if this is needed 
	|FREE '('Sarray')'';'	{ }
	;

expr	:expr PLUS expr		{ }	
	|expr MINUS expr	{ }
	|expr MUL expr		{ }
	|expr DIV expr		{ }
	|expr MOD expr		{ }
		
	|expr LE expr		{ }
	|expr GE expr		{ }
	|expr LT expr		{ }
	|expr GT expr		{ }
	|expr EE expr		{ }
	|expr NE expr		{ }

	|expr ANDTK expr        { }
	|expr ORTK expr		{ }
	|NOTTK expr		{ }
	
	|'('expr')'		{$$=$2;}	
	|VAR			{$$=$1;}	
	|NUM	       		{$$=$1;}		
	|MESG			{$$=$1;}		
	|Sarray			{$$=$1;}	
	|Fcall			{$$=$1;}
	|NULLTK			{$$=$1;}
	|Feild			{$$=$1;}
	;
Feild	:VAR '.' VAR
	|Feild '.' VAR
	;
Fcall	:VAR '(' ')'	     { }
  	|VAR '(' ArgList ')' { }
	;
//Arglist,expr because function call may be as factorial(n-1);
//may be like f(1,f(0)); in recursion etc
ArgList	: ArgList','expr	{
					}
	|expr			{$$=$1;}
	;
Sarray	:VAR '[' expr ']'	{ }
	;
%%
int main(int argc, char *argv[])
{
	int i;
	
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

