/*perfect grammar for this stage checked with testcases for all three tasks*/
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
      }

%token NUM VAR MESG  PLUS MINUS MUL DIV MOD  GT LT GE LE EE NE  PBEGIN PEND READ WRITE  IF THEN ELSE ENDIF  WHILE DO ENDWHILE  CONTINUE BREAK  DECL ENDDECL INT STR  RETURN MAINFN ANDTK ORTK NOTTK
%type <tnode> VAR NUM MESG Sarray Fcall expr ArgList FuncStmt
%left GE LE EE NE GT LT ANDTK ORTK NOTTK
%left PLUS MINUS 
%left MUL DIV MOD 


%%

Program	:GdeclBlock FDefBlock MainBlock 	{printf("end of program\n");}
	|GdeclBlock MainBlock			{printf("end of program\n");}
	|MainBlock				{printf("end of program\n");}
	;

GdeclBlock: DECL Gdecllist ENDDECL		{printf("end of global declaration\n");}
	| DECL ENDDECL				
	;

Gdecllist:Gdecllist Gdecl			
	|Gdecl					
	;

Gdecl	:Type Gvarlist ';'			
	;

Gvarlist:Gvarlist ',' Gvar			
	|Gvar
	;					 
	
Gvar	:VAR					
	|VAR '['NUM']' 		
	|VAR '('ParamList')' 					
	;

		

FDefBlock:FDefBlock Fdef		
	|Fdef				
	;
Fdef	:Type VAR '('ParamList')''{'LdeclBlock Body'}' 
	|Type VAR '('ParamList')' '{'Body'}'	{printf("end of function defnition\n");}
	|Type VAR '('')''{'LdeclBlock Body'}' 
	|Type VAR '('')' '{'Body'}'	{printf("end of function defnition\n");}
	;
ParamList:ParamList ',' Param		
	|Param
	;
Param	:Type VAR
	;

LdeclBlock:DECL LDecList ENDDECL		{printf("end of local declaration block\n");}	
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
Type	:INT					
	|STR					
	;
MainBlock:Type MAINFN '(' ')' '{'LdeclBlock Body'}' 	{printf("end of main block\n");}
	|Type MAINFN '(' ')' '{'Body'}'			{printf("end of main block\n");}
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
FuncStmt:Fcall';'		


expr	:expr PLUS expr		
	|expr MINUS expr	
	|expr MUL expr		
	|expr DIV expr		
	|expr MOD expr		
	|expr LE expr		
	|expr GE expr		
	|expr LT expr		
	|expr GT expr		
	|expr EE expr		
	|expr NE expr
	|expr ANDTK expr		
	|expr ORTK expr		
	|expr NOTTK expr	
	|'('expr')'	{$$=$2;}	
	|VAR			
	|NUM			
	|MESG			
	|Sarray			
	|Fcall			
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
	
