%{
	#include<stdio.h>
	#include"task1.h"
	#include"task1.c"
	int yylex(void);
	int yyerror(char const *s);
	int yywrap();
	FILE *fp,*yyin;
	int size;
	struct Typetable *currtype;
	int Gdecl_end_flag=0;
%}

%union{
	struct tnode *tnode;
	struct Gsymbol *Gsymbol;
	struct Paramstruct *paramstruct;
	struct Typetable *Typetable;
	struct Classtable *classtable;
      }


%token NUM VAR MESG  PLUS MINUS MUL DIV MOD  GT LT GE LE EE NE  PBEGIN PEND READ WRITE  IF THEN ELSE ENDIF  WHILE DO ENDWHILE  CONTINUE BREAK  DECL ENDDECL RETURN MAINFN ANDTK ORTK NOTTK TYPE ENDTYPE NULLTK ALLOC INITIALIZE FREE CLASS ENDCLASS DELETE NEW EXTENDS SELF
%type <tnode> VAR NUM MESG NULLTK Fcall Sarray Field expr ArgList FreeStmt FuncStmt WhileStmt IfStmt AssgStmt OutputStmt InputStmt Stmt Slist RetStmt Body FuncName dexpr DeleteStmt FieldFunction 		DELETE SELF
%type <paramstruct> Param ParamList PL
%type <Typetable> ParamTypeName RetTypeName Type
%type <classtable> Cname

%left GE LE EE NE GT LT ANDTK ORTK NOTTK
%left PLUS MINUS 
%left MUL DIV MOD 


%%


Program:TypeDefBlock ClassDefBlock GdeclBlock FDefBlock MainBlock	{ }
	|TypeDefBlock ClassDefBlock GdeclBlock MainBlock 		{ }
	|TypeDefBlock ClassDefBlock MainBlock				{ }
	;


TypeDefBlock: TYPE TypeDefList ENDTYPE			{ }
	    |						{ }
	    ;
TypeDefList :TypeDefList TypeDef			{ }
	|TypeDef					{ }
	;

TypeDef	:VAR '{'  {TInstall($1->varname,0,NULL);}  FieldDeclList '}'			
							{
							
						      
							 }
	;

FieldDeclList:FieldDeclList FieldDecl			{ }
	|FieldDecl					{ }
	;
FieldDecl :VAR VAR ';'				       { }
	;

ClassDefBlock	:CLASS ClassDefList ENDCLASS		{ }
		|					{ }
		;
ClassDefList	:ClassDefList ClassDef			{ }
		|ClassDef				{ }
		;
ClassDef	:Cname '{' DECL Fieldlists MethodDecl ENDDECL MethodDefns '}'	{ }
		;
Cname		:VAR			{
						
					}
		|VAR EXTENDS VAR	{
						
					}
		;
Fieldlists	:Fieldlists Fld				{ }
		|					{/*NO ACTION*/}
		;
Fld		:VAR VAR ';'			{	
						
						}
		;
MethodDecl	:MethodDecl MDecl			{ }
		|MDecl					{ }
		;
MDecl		:VAR VAR '('ParamList')'';'	{ 
								
							}
		|VAR VAR '(' ')'';'		{ 
								
							}
		;
MethodDefns	:MethodDefns Fdef			{}
		|Fdef					{ }
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
	
Gvar	:VAR				{
				
					}	
	|VAR '['NUM']' 			{
					}
	|VAR '('ParamList')' 		{
					}
	|VAR '(' ')'			{
					}
	;

ParamList:PL				{
					}
	;
PL:PL ',' Param 			{ }
	|Param				{ }
	;
Param	:ParamTypeName VAR		{
						
					}
	;
ParamTypeName:VAR			{}
	;



FDefBlock:FDefBlock Fdef		{}
	|Fdef				{}
	;
Fdef	:NameParam '{'LdeclBlock Body'}'
		 			{ 
						
					}
	|NameParam '{' Body'}' { 
						

						}
	;
NameParam:RetTypeName FuncName '('ParamList')'{
							
					      }
	 |RetTypeName FuncName '('')' 	      {
							
					      }
	 ;
FuncName:VAR 			{ }
	;
RetTypeName:VAR			{ }
	;
LdeclBlock:DECL LDecList ENDDECL	{ }		
	|DECL ENDDECL			{ }	
	;
LDecList:LDecList LDecl 		{ }
	|LDecl				{ }
	;
LDecl	:Type Lvarlist	';'		{ }
	;
Lvarlist:Lvarlist ','VAR 		{}
	|VAR				{ }
	;
Type	:VAR		{ 
				
			}			
	;
Main: MAINFN 	{ }
	;
MainBlock:VAR Main '(' ')' '{'LdeclBlock Body'}'
		{
			

		}
	|VAR Main '(' ')' '{' Body '}'
		{
			
		}
	;
Body	:PBEGIN Slist RetStmt PEND';' 
			 {
				
			 }
	|PBEGIN RetStmt PEND';'		{ }
	;	
RetStmt	:RETURN expr ';' {	
				
			 }
	;




Slist	:Slist Stmt	{	
			}	
	|Stmt		{$$=$1; }	
	;

Stmt	:InputStmt		{$$=$1;}
	|OutputStmt		{$$=$1;}
	|AssgStmt		{$$=$1;}
	|IfStmt			{$$=$1;}
	|WhileStmt		{$$=$1;}
	|FuncStmt		{$$=$1;}
	|FreeStmt		{$$=$1;}
	|DeleteStmt		{$$=$1;}
	|CONTINUE';'	{				}
	|BREAK';'		{	}
	;

InputStmt:READ '('VAR')'';'	{	}
	 |READ '('Sarray')'';'	{	}
	 |READ '('Field')'';'	{	}
	;
OutputStmt:WRITE '('expr')' ';'	{	}
	  ;
AssgStmt:VAR '=' expr ';'	{}
	|Sarray'='expr';'	{}
	|Field'='expr';'	{}
	|VAR '=' dexpr ';'	{}
	|VAR '=' NEW '('VAR')'';'	{}
	|Field'=' NEW '('VAR')'';'
	;
DeleteStmt:DELETE '('Field')'';'	{ }
	;
dexpr	:ALLOC '(' ')'		{				}
	|INITIALIZE '(' ')' {	
				
			    }
	;
IfStmt	:IF '('expr')' THEN Slist ELSE Slist ENDIF ';'
			     	{	
				}
	|IF '('expr')' THEN Slist ENDIF ';'
				{	}
	;
WhileStmt:WHILE '('expr')' DO Slist ENDWHILE';'
				{	}

	;
FuncStmt:Fcall';'		{$$=$1; }
	;
FreeStmt:FREE '('Field')'';'	{
					}
				
	|FREE '('VAR')' ';'	{
					}

	;
expr	:expr PLUS expr		{
					
				}	
	|expr MINUS expr	{
					 }
	|expr MUL expr		{
					
				}
	|expr DIV expr		{
					
				}
	|expr MOD expr		{
					
				}
		
	|expr LE expr		{
					
				}
	|expr GE expr		{
					
				}
	|expr LT expr		{
					
				}
	|expr GT expr		{
					
				}
	|expr EE expr		{
					
				}
	|expr NE expr		{
					
				}

	|expr ANDTK expr        {
					
				}
	|expr ORTK expr		{
					
				}
	|    NOTTK expr		{
				 
				}
	
	|'('expr')'		{$$=$2;}	
	|VAR			{$$=$1;}	
	|NUM	       		{$$=$1;}		
	|MESG			{$$=$1;}		
	|Sarray			{$$=$1;}	
	|Fcall			{$$=$1;}
	|NULLTK			{$$=$1;}
	|Field			{$$=$1;}
	|FieldFunction		{$$=$1;}
	;
Field	:SELF'.'VAR

	|VAR '.' VAR	{
				
			}
	|Field '.' VAR	{
				

			}
		
	;
FieldFunction	:SELF '.'VAR '('')'
		|SELF '.'VAR '('ArgList')'
		|VAR'.'VAR'('')'
		|VAR'.'VAR'('ArgList')'
		|Field '.'VAR'('')'
		|Field '.'VAR'('ArgList')'
		;
Fcall	:VAR '(' ')'	  {
					
			 }
  	|VAR '(' ArgList ')'{
					
			   }
	;
//Arglist,expr because function call may be as factorial(n-1);
//may be like f(1,f(0)); in recursion etc
ArgList	: ArgList','expr	{
				}
	|expr			{
				}
	;
Sarray	:VAR '[' expr ']'	{	
					
				}
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
	TypeTableCreate();
	yyparse();	
	
	
	
	return 0;
}

