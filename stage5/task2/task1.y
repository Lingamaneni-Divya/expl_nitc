%{
	#include<stdio.h>
	#include"task1.h"
	#include"task1.c"
	int yylex(void);
	int yyerror(char const*);
	int yywrap();
	FILE *fp,*yyin;
	int currtype=nulltype;
	int Gdecl_end_flag=0;
	int rettype;
	struct Paramstruct *p;
%}
/*NOTE.......HERE CURRTYPE IS BEING CORRUPTED DUE TO VARIOUS REFERENCES.....THAT IS WHY WE USED Type Rettype and Paramtype*/
%union{
	struct tnode *tnode;
	struct Gsymbol *Gsymbol;
	struct Paramstruct *paramstruct;
	struct Typenode *typenode;
      }

%token NUM VAR MESG  PLUS MINUS MUL DIV MOD  GT LT GE LE EE NE  PBEGIN PEND READ WRITE  IF THEN ELSE ENDIF  WHILE DO ENDWHILE  CONTINUE BREAK  DECL ENDDECL INT STR  RETURN MAINFN ANDTK ORTK NOTTK
%type <tnode> VAR NUM MESG Fcall Sarray expr ArgList FuncStmt WhileStmt IfStmt AssgStmt OutputStmt InputStmt Stmt Slist RetStmt Body FuncName
%type <paramstruct> Param ParamList PL
%type <typenode> Type Rettype Paramtype

%left GE LE EE NE GT LT ANDTK ORTK NOTTK
%left PLUS MINUS 
%left MUL DIV MOD 


%%

Program	:GdeclBlock FDefBlock MainBlock 	{ }	
	|GdeclBlock MainBlock			{ }
	|MainBlock				{ }
	;

GdeclBlock:DECL Gdecllist ENDDECL	{
						print_Gsymbol_table();
					 	Gdecl_end_flag=1;
					}	
	| DECL ENDDECL			{
						print_Gsymbol_table();
						Gdecl_end_flag=1;
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
	
Gvar	:VAR				{GInstall($1->varname,currtype,1,NULL);}	
	|VAR '['NUM']' 			{GInstall($1->varname,currtype,$3->val,NULL);}
	|VAR '('ParamList')' 		{GInstall($1->varname,currtype,-1,$3);}
	|VAR '(' ')'			{GInstall($1->varname,currtype,-1,NULL);}
	;

		

FDefBlock:FDefBlock Fdef		
	|Fdef				
	;
Fdef	:NameParam '{'LdeclBlock Body'}'
		 	{ 
				
				
				print_Lsymbol_table(func_name);
				printf("ABSTRACT SYNTAX TREE FOR %s Function\n",func_name);
				printf("---------------------------------------\n");
				preorder($4);
				reset_Lsymbol_table();
			}
	|NameParam '{' Body'}'
		 	{ 
				
				
				print_Lsymbol_table(func_name);
				printf("ABSTRACT SYNTAX TREE FOR %s Function\n",func_name);
				printf("---------------------------------------\n");
				preorder($3);
				reset_Lsymbol_table();
			}		
	;
NameParam:Rettype FuncName '('ParamList')'{name_equivalence($1->type,$2->varname,$4); }
	 |Rettype FuncName '('')' 	  {name_equivalence($1->type,$2->varname,NULL); }
	 ;
ParamList:PL		{	$$=$1;
				if(Gdecl_end_flag==1)
				createLsymbolEntries($$);

			}
	 ;
PL:PL ',' Param	     	{ //printf("This is formation of paramlist\n");
				$$=PInstall($1,$3);
			/*DOUBT!!!!!! WHY EVEN PRINT STATEMENT IS WORKING HERE*/
					
			}
	|Param		{$$=$1;}
	;
Param	:Paramtype VAR		{
					$$=create_param_node($2->varname,$1->type);
				}
	;


LdeclBlock:DECL LDecList ENDDECL	{ }		
	|DECL ENDDECL			{ }	
	;
LDecList:LDecList LDecl 		{ }
	|LDecl				{ }
	;
LDecl	:Type Lvarlist	';'		{ }
	;
Lvarlist:Lvarlist ','VAR 		{LInstall($3->varname,currtype);}
	|VAR				{LInstall($1->varname,currtype);}
	;
Type	:INT		{
				$$=create_typenode(inttype);
				currtype=$$->type;
			}				
	|STR		{
				$$=create_typenode(strtype);
				currtype=$$->type;
			}			
	;
Paramtype:INT	{$$=create_typenode(inttype);
		  			
		}
	 |STR	{$$=create_typenode(strtype);
						
			}			
	;
Rettype:INT	{$$=create_typenode(inttype);
			rettype=inttype;}
	 |STR	{$$=create_typenode(strtype);
		rettype=strtype;}			
	;
FuncName:VAR 	{$$=$1;strcpy(func_name,$1->varname);}
	;
Main: MAINFN 	{strcpy(func_name,"MAIN");}
MainBlock:Rettype Main '(' ')' '{'LdeclBlock Body'}' 
		{ 
				if($1->type!=inttype)
				{
				printf("Function main expects integer return type");
				exit(1);
				}
				
				print_Lsymbol_table("MAIN");
				printf("ABSTRACT SYNTAX TREE FOR MAIN Function\n");
				printf("---------------------------------------\n");
				preorder($7);
				reset_Lsymbol_table();
				
		}	
	|Rettype Main '(' ')' '{'Body'}'	
		{ 
				if($1->type!=inttype)
				{
				printf("Function main expects integer return type");
				exit(1);
				}

				print_Lsymbol_table("MAIN");
				printf("ABSTRACT SYNTAX TREE FOR MAIN Function\n");
				printf("---------------------------------------\n");
				preorder($6);
				reset_Lsymbol_table();
				
		}		
	;


Body	:PBEGIN Slist RetStmt PEND';' {$$=create_tree(0,nulltype,NULL,conn_node,$2,NULL,$3);}
	;
RetStmt	:RETURN expr ';' {$$=create_tree(0,$2->type,func_name,ret_node,$2,NULL,NULL);
			}
	;




Slist	:Slist Stmt	{$$=create_tree(0,nulltype,NULL,conn_node,$1,NULL,$2);}	
	|Stmt		{$$=$1;}	
	;

Stmt	:InputStmt		{$$=$1;}
	|OutputStmt		{$$=$1;}
	|AssgStmt		{$$=$1;}
	|IfStmt			{$$=$1;}
	|WhileStmt		{$$=$1;}
	|FuncStmt		{$$=$1;}
	|CONTINUE';'		{$$=create_tree(0,nulltype,NULL,continue_node,NULL,NULL,NULL);}
	|BREAK';'		{$$=create_tree(0,nulltype,NULL,break_node,NULL,NULL,NULL);}
	;

InputStmt:READ '('VAR')'';'	{$$=create_tree(0,nulltype,NULL,read_node,$3,NULL,NULL);}
	 |READ '('Sarray')'';'	{$$=create_tree(0,nulltype,NULL,read_node,$3,NULL,NULL);}
	;
OutputStmt:WRITE '('expr')' ';'	{$$=create_tree(0,nulltype,NULL,write_node,$3,NULL,NULL);}
	  ;
AssgStmt:VAR '=' expr ';'	{$$=create_tree(0,nulltype,"=",assg_node,$1,NULL,$3);}
	|Sarray'='expr';'	{$$=create_tree(0,nulltype,"=",assg_node,$1,NULL,$3);}
	;
IfStmt	:IF '('expr')' THEN Slist ELSE Slist ENDIF ';'
			     	{$$=create_tree(0,nulltype,NULL,if_node,$3,$6,$8);}
	|IF '('expr')' THEN Slist ENDIF ';'
				{$$=create_tree(0,nulltype,NULL,if_node,$3,$6,NULL);}
	;
WhileStmt:WHILE '('expr')' DO Slist ENDWHILE';'
				{$$=create_tree(0,nulltype,NULL,while_node,$3,NULL,$6);}

	;
FuncStmt:Fcall';'		{$$=$1;}


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
Fcall	:VAR '(' ')'	     {$$=create_tree(0,nulltype,$1->varname,func_node,NULL,NULL,NULL);}
  	|VAR '(' ArgList ')' {$$=create_tree(0,nulltype,$1->varname,func_node,$3,NULL,NULL);}
	;
//Arglist,expr because function call may be as factorial(n-1);
//may be like f(1,f(0)); in recursion etc
ArgList	:expr ',' ArgList	{$1->middle=$3;
				  $$=$1;
				 	}
	|expr			{$$=$1;}
	;
Sarray	:VAR '[' expr ']'	{$$=create_tree(0,$1->type,$1->varname,arr_node,$3,NULL,NULL);}
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
	
