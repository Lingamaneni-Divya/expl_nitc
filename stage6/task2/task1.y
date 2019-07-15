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
	//struct Typenode *typenode;
      }


%token NUM VAR MESG  PLUS MINUS MUL DIV MOD  GT LT GE LE EE NE  PBEGIN PEND READ WRITE  IF THEN ELSE ENDIF  WHILE DO ENDWHILE  CONTINUE BREAK  DECL ENDDECL INT STR  RETURN MAINFN ANDTK ORTK NOTTK TYPE ENDTYPE NULLTK ALLOC INITIALIZE FREE
%type <tnode> VAR NUM MESG NULLTK Fcall Sarray Field expr ArgList FreeStmt FuncStmt WhileStmt IfStmt AssgStmt OutputStmt InputStmt Stmt Slist RetStmt Body FuncName dexpr
%type <paramstruct> Param ParamList PL
%type <Typetable> TypeName ParamTypeName RetTypeName Type

%left GE LE EE NE GT LT ANDTK ORTK NOTTK
%left PLUS MINUS 
%left MUL DIV MOD 


%%


Program:TypeDefBlock GdeclBlock FDefBlock MainBlock	{ }
	|TypeDefBlock GdeclBlock MainBlock 		{ }
	|TypeDefBlock MainBlock				{ }
	;


TypeDefBlock: TYPE TypeDefList ENDTYPE			{print_Typetable(); }
	    |	{print_Typetable();}
	    ;
TypeDefList :TypeDefList TypeDef			{ }
	|TypeDef					{ }
	;

TypeDef	:VAR '{'  {TInstall($1->varname,0,NULL);}  FieldDeclList '}'			
							{
							 
						         Typetable *ttable=TLookup($1->varname);
							 ttable->fields=fieldlist_head;
							 ttable->size=getSize(ttable);
							 reset_fieldlist();
							 }
	;

FieldDeclList:FieldDeclList FieldDecl			{ }
	|FieldDecl					{ }
	;
FieldDecl :TypeName VAR ';'				{FInstall($2->varname,$1); }
	;
TypeName : INT 						{$$=TLookup("int"); }
	|STR						{$$=TLookup("str"); }
	|VAR						{$$=TLookup($1->varname); }
	;



GdeclBlock:DECL Gdecllist ENDDECL	{
						print_Gsymbol_table();
					 	Gdecl_end_flag=1;
						fp=fopen("task1.xsm","a"); 
						fprintf(fp,"MOV SP, %d\n",sp);
						fprintf(fp,"CALL F0\n");
						fclose(fp);
       						scall("Exit",0,0);
						
					}	
	| DECL ENDDECL			{
						print_Gsymbol_table();
					 	Gdecl_end_flag=1;
						fp=fopen("task1.xsm","a"); 
						fprintf(fp,"MOV SP, %d\n",sp);
						fprintf(fp,"CALL F0\n");
						fclose(fp);
       						scall("Exit",0,0);
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
						GInstall($1->varname,currtype,1,paramlist_head);
						reset_paramlist();
					}	
	|VAR '['NUM']' 			{
						GInstall($1->varname,currtype,$3->val,paramlist_head);
						reset_paramlist();}
	|VAR '('ParamList')' 		{
						GInstall($1->varname,currtype,-1,paramlist_head); 
						reset_paramlist();
					}
	|VAR '(' ')'			{
						GInstall($1->varname,currtype,-1,paramlist_head);
						reset_paramlist();}
	;

ParamList:PL				{
						if(Gdecl_end_flag==1)
					 	createLsymbolEntries(paramlist_head);
					}
	;
PL:PL ',' Param 			{ }
	|Param				{ }
	;
Param	:ParamTypeName VAR		{
						$$=create_param_node($2->varname,$1);
						PInstall($$);
					}
	;
ParamTypeName:INT		{$$=TLookup("int"); }
	|STR			{$$=TLookup("str"); }
	|VAR			{$$=TLookup($1->varname); }
	;



FDefBlock:FDefBlock Fdef		
	|Fdef				
	;
Fdef	:NameParam '{'LdeclBlock Body'}'
		 			{ 
				print_Lsymbol_table(func_name);
				printf("ABSTRACT SYNTAX TREE FOR %s Function\n",func_name);
				//printf("------------GENERATED SUCCESSFULLY---------------------------\n");
				//preorder($4);
				printf("---------CODEGEN------\n");
				generate_code($4,func_name);
				reset_Lsymbol_table();
					}
	|NameParam '{' Body'}' { 
				print_Lsymbol_table(func_name);
				printf("ABSTRACT SYNTAX TREE FOR %s Function\n",func_name);
				//printf("-------------GENERATED SUCCESSFULLY--------------------------\n");
				//preorder($3);
				printf("---------CODEGEN------\n");
				generate_code($3,func_name);
				reset_Lsymbol_table();

						}
	;
NameParam:RetTypeName FuncName '('ParamList')'{
						name_equivalence($1,$2->varname,paramlist_head); 
						reset_paramlist();
					      }
	 |RetTypeName FuncName '('')' 	      {
						name_equivalence($1,$2->varname,NULL);
						reset_paramlist(); 
					      }
	 ;
FuncName:VAR 			{$$=$1;strcpy(func_name,$1->varname);}
	;
RetTypeName:INT			{$$=TLookup("int"); }
	|STR			{$$=TLookup("str"); }
	|VAR			{$$=TLookup($1->varname); }
	;
LdeclBlock:DECL LDecList ENDDECL	{ }		
	|DECL ENDDECL			{ }	
	;
LDecList:LDecList LDecl 		{ }
	|LDecl				{ }
	;
LDecl	:Type Lvarlist	';'		{ }
	;
Lvarlist:Lvarlist ','VAR 		{LInstall($3->varname,currtype); }
	|VAR				{LInstall($1->varname,currtype); }
	;
Type	:INT		{
				$$=TLookup("int");
				currtype=$$;
			}				
	|STR		{
				$$=TLookup("str");
				currtype=$$;
			}
	|VAR		{ 
				$$=TLookup($1->varname);
				currtype=$$;
			}			
	;
Main: MAINFN 	{strcpy(func_name,"MAIN");}
	;
MainBlock:INT Main '(' ')' '{'LdeclBlock Body'}'
		{
				print_Lsymbol_table("MAIN");
				printf("ABSTRACT SYNTAX TREE FOR MAIN Function\n");
				//printf("---------------GENERATED SUCCESSFULLY------------------------\n");
				//preorder($7);
				printf("---------CODEGEN------\n");
				generate_code($7,func_name);
				reset_Lsymbol_table();

		}
	|INT Main '(' ')' '{' Body '}'
		{

				print_Lsymbol_table("MAIN");
				printf("ABSTRACT SYNTAX TREE FOR MAIN Function\n");
				//printf("-------------GENERATED SUCCESSFULLY--------------------------\n");
				//preorder($6);
				printf("---------CODEGEN------\n");
				generate_code($6,func_name);
				reset_Lsymbol_table();
		}
	;
Body	:PBEGIN Slist RetStmt PEND';' 
			 {	//printf("tree call 1:\n");
				$$=create_tree(0,TLookup("null"),NULL,conn_node,$2,NULL,$3);
			 }
	;
RetStmt	:RETURN expr ';' {	//printf("tree call 2:\n");
				typecheck($2);
				$$=create_tree(0,$2->type,func_name,ret_node,$2,NULL,NULL);
			 }
	;




Slist	:Slist Stmt	{	//printf("tree call 3:\n");
				$$=create_tree(0,TLookup("null"),NULL,conn_node,$1,NULL,$2);
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
	|CONTINUE';'	{	//printf("tree call 4:\n");
				$$=create_tree(0,TLookup("null"),NULL,continue_node,NULL,NULL,NULL);
			}
	|BREAK';'		{	//printf("tree call 5:\n");
					$$=create_tree(0,TLookup("null"),NULL,break_node,NULL,NULL,NULL); 
				}
	;

InputStmt:READ '('VAR')'';'	{	//printf("tree call 6:\n");
					typecheck($3);
					$$=create_tree(0,TLookup("null"),NULL,read_node,$3,NULL,NULL);
				}
	 |READ '('Sarray')'';'	{	//printf("tree call 7:\n");
					typecheck($3);
					$$=create_tree(0,TLookup("null"),NULL,read_node,$3,NULL,NULL); 
				}
	 |READ '('Field')'';'	{	//printf("tree call 8:\n");
					typecheck($3);
					$$=create_tree(0,TLookup("null"),NULL,read_node,$3,NULL,NULL); 
				}
	;
OutputStmt:WRITE '('expr')' ';'	{	//printf("tree call 9:\n");
					typecheck($3);
					$$=create_tree(0,TLookup("null"),NULL,write_node,$3,NULL,NULL); 
				}
	  ;
AssgStmt:VAR '=' expr ';'	{
					//printf("lex:\n");printf("before:");print_node($1);print_node($3);
					typecheck($1);typecheck($3);
					//printf("after:");print_node($1);print_node($3);printf("tree call 10:\n");	
					$$=create_tree(0,TLookup("null"),"=",assg_node,$1,NULL,$3);
				}
	|Sarray'='expr';'	{
					//printf("lex:\n");printf("before:");print_node($1);print_node($3);
					typecheck($1);typecheck($3);
					//printf("after:");print_node($1);print_node($3);printf("tree call 11:\n");	
					$$=create_tree(0,TLookup("null"),"=",assg_node,$1,NULL,$3);
				}
	|Field'='expr';'	{
					//printf("lex:\n");printf("before:");print_node($1);print_node($3);
					typecheck($1);typecheck($3);
					//printf("after:");print_node($1);print_node($3);printf("tree call 12:\n");	
					$$=create_tree(0,TLookup("null"),"=",assg_node,$1,NULL,$3);
				}
	|VAR '=' dexpr ';'	{
					//printf("lex:\n");printf("before:");print_node($1);print_node($3);
					typecheck($1);typecheck($3);
					//printf("after:");print_node($1);print_node($3);printf("tree call 13:\n");	
					$$=create_tree(0,TLookup("null"),"=",assg_node,$1,NULL,$3); 
				}
/*	|Sarray'='dexpr';'	{$$=create_tree(0,NULL,"=",assg_node,$1,NULL,$3); }
	|Field'='dexpr';'	{$$=create_tree(0,NULL,"=",assg_node,$1,NULL,$3); }*/
	;
dexpr	:ALLOC '(' ')'		{	//printf("tree call 14:\n");
					$$=create_tree(0,TLookup("null"),NULL,alloc_node,NULL,NULL,NULL);
				}
	|INITIALIZE '(' ')' {	
				//printf("tree call 15:\n");
				$$=create_tree(0,TLookup("int"),NULL,initialize_node,NULL,NULL,NULL);
			    }
	;
IfStmt	:IF '('expr')' THEN Slist ELSE Slist ENDIF ';'
			     	{	//printf("tree call 16:\n");
					$$=create_tree(0,TLookup("null"),NULL,if_node,$3,$6,$8);
				}
	|IF '('expr')' THEN Slist ENDIF ';'
				{	//printf("tree call 17:\n");
					$$=create_tree(0,TLookup("null"),NULL,if_node,$3,$6,NULL); 
				}
	;
WhileStmt:WHILE '('expr')' DO Slist ENDWHILE';'
				{	//printf("tree call 18:\n");
					$$=create_tree(0,TLookup("null"),NULL,while_node,$3,NULL,$6); 
				}

	;
FuncStmt:Fcall';'		{$$=$1; }
	;
FreeStmt:FREE '('Field')'';'	{
					typecheck($3);
					//printf("tree call 19:\n");	
					$$=create_tree(0,TLookup("int"),NULL,free_node,$3,NULL,NULL); 
				}
				
	|FREE '('VAR')' ';'	{
					typecheck($3);
				 	//printf("tree call 20:\n");	
				        $$=create_tree(0,TLookup("int"),NULL,free_node,$3,NULL,NULL);  
				}
//check if this is needed  since array not allocated dynamically
/*	|FREE '('Sarray')'';'	{$$=create_tree(0,NULL,NULL,free_node,$3,NULL,NULL); }*/
	;

expr	:expr PLUS expr		{
					//printf("lex:\n");printf("before:");print_node($1);print_node($3);
					typecheck($1);typecheck($3);
					//printf("after:");print_node($1);print_node($3);printf("tree call 21:\n");	
					$$=create_tree(0,TLookup("int"),"+",aop_node,$1,NULL,$3); 
				}	
	|expr MINUS expr	{
					//printf("lex:\n");printf("before:");print_node($1);print_node($3);
					typecheck($1);typecheck($3);
					//printf("after:");print_node($1);print_node($3);printf("tree call 22:\n");	
					$$=create_tree(0,TLookup("int"),"-",aop_node,$1,NULL,$3); }
	|expr MUL expr		{
					//printf("lex:\n");printf("before:");print_node($1);print_node($3);
					typecheck($1);typecheck($3);
					//printf("after:");print_node($1);print_node($3);printf("tree call 23:\n");	
					$$=create_tree(0,TLookup("int"),"*",aop_node,$1,NULL,$3);
				}
	|expr DIV expr		{
					//printf("lex:\n");printf("before:");print_node($1);print_node($3);
					typecheck($1);typecheck($3);
					//printf("after:");print_node($1);print_node($3);printf("tree call 24:\n");	
					$$=create_tree(0,TLookup("int"),"/",aop_node,$1,NULL,$3); 
				}
	|expr MOD expr		{
					//printf("lex:\n");printf("before:");print_node($1);print_node($3);
					typecheck($1);typecheck($3);
					//printf("after:");print_node($1);print_node($3);printf("tree call 25:\n");	
					$$=create_tree(0,TLookup("int"),"%",aop_node,$1,NULL,$3); 
				}
		
	|expr LE expr		{
					//printf("lex:\n");printf("before:");print_node($1);print_node($3);
					typecheck($1);typecheck($3);
					//printf("after:");print_node($1);print_node($3);printf("tree call 26:\n");	
					$$=create_tree(0,TLookup("bool"),"<=",lop_node,$1,NULL,$3); 
				}
	|expr GE expr		{
					//printf("lex:\n");printf("before:");print_node($1);print_node($3);
					typecheck($1);typecheck($3);
					//printf("after:");print_node($1);print_node($3);printf("tree call 27:\n");	
					$$=create_tree(0,TLookup("bool"),">=",lop_node,$1,NULL,$3); 
				}
	|expr LT expr		{
					//printf("lex:\n");printf("before:");print_node($1);print_node($3);
					typecheck($1);typecheck($3);
					//printf("after:");print_node($1);print_node($3);printf("tree call 28:\n");	
					$$=create_tree(0,TLookup("bool"),"<",lop_node,$1,NULL,$3); 
				}
	|expr GT expr		{
					//printf("lex:\n");printf("before:");print_node($1);print_node($3);
					typecheck($1);typecheck($3);
					//printf("after:");print_node($1);print_node($3);printf("tree call 29:\n");	
					$$=create_tree(0,TLookup("bool"),">",lop_node,$1,NULL,$3); 
				}
	|expr EE expr		{
					//printf("lex:\n");printf("before:");print_node($1);print_node($3);
					typecheck($1);typecheck($3);
					//printf("after:");print_node($1);print_node($3);printf("tree call 30:\n");	
					$$=create_tree(0,TLookup("bool"),"==",lop_node,$1,NULL,$3); 
				}
	|expr NE expr		{
					//printf("lex:\n");printf("before:");print_node($1);print_node($3);
					typecheck($1);typecheck($3);
					//printf("after:");print_node($1);print_node($3);printf("tree call 31:\n");	
					$$=create_tree(0,TLookup("bool"),"!=",lop_node,$1,NULL,$3); 
				}

	|expr ANDTK expr        {
					//printf("lex:\n");printf("before:");print_node($1);print_node($3);
					typecheck($1);typecheck($3);
					//printf("after:");print_node($1);print_node($3);printf("tree call 32:\n");	
					$$=create_tree(0,TLookup("bool"),"&&",lop_node,$1,NULL,$3); 
				}
	|expr ORTK expr		{
					//printf("lex:\n");printf("before:");print_node($1);print_node($3);
					typecheck($1);typecheck($3);
					//printf("after:");print_node($1);print_node($3);printf("tree call 33:\n");	
					$$=create_tree(0,TLookup("bool"),"||",lop_node,$1,NULL,$3); 
				}
	|    NOTTK expr		{
					//printf("lex:\n");printf("before:");print_node($2);
					typecheck($2);
					//printf("after:");print_node($2);printf("tree call 34:\n");	
					$$=create_tree(0,TLookup("bool"),"!",lop_node,$2,NULL,NULL); 
				}
	
	|'('expr')'		{$$=$2;}	
	|VAR			{$$=$1;}	
	|NUM	       		{$$=$1;}		
	|MESG			{$$=$1;}		
	|Sarray			{$$=$1;}	
	|Fcall			{$$=$1;}
	|NULLTK			{$$=$1;}
	|Field			{$$=$1;}
	;
Field	:VAR '.' VAR	{
				typecheck($1);
				struct Fieldlist *f;
				if($1->type==TLookup("int") || $1->type==TLookup("str"))
				{
					printf("invalid field access");
							exit(1);
				}
				f=FLookup($1->type,$3->varname);
				if(f==NULL)
				{
			      	 printf("No field :%s in %s type",$3->varname,$1->type->name);
				 exit(1);
						
				}
				$1->nodetype=field_node;
				$1->faccess=$3;
				$3->type=f->type;
				$3->val=f->fieldIndex;
				$1->type=$3->type;
				$$=$1;
			}
	|Field '.' VAR	{
				struct tnode *temp; 
				struct Fieldlist *f;
				temp=$1;
				while(temp->faccess!=NULL)
					temp=temp->faccess;
				f=FLookup(temp->type,$3->varname);
				if(f==NULL)
				{
				printf("No field :%s in %s type",$3->varname,temp->type->name);
				 exit(1);
				}
				temp->nodetype=field_node;
				temp->faccess=$3;
				$3->type=f->type;
				$3->val=f->fieldIndex;
				$1->type=$3->type;
				$$=$1;

			}
		
	;
Fcall	:VAR '(' ')'	  {
					//printf("lex:\n");printf("before:");print_node($1);
					typecheck($1);
					//printf("after:");print_node($1);printf("tree call 35:\n");	
					$$=create_tree(0,TLookup("null"),$1->varname,func_node,NULL,NULL,NULL);
			 }
  	|VAR '(' ArgList ')'{
					//printf("lex:\n");printf("before:");print_node($1);print_node($3);
					typecheck($1);typecheck($3);
					//printf("after:");print_node($1);print_node($3);printf("tree call 36:\n");	
					$$=create_tree(0,TLookup("null"),$1->varname,func_node,$3,NULL,NULL); 
			   }
	;
//Arglist,expr because function call may be as factorial(n-1);
//may be like f(1,f(0)); in recursion etc
ArgList	: ArgList','expr	{$3->middle=$1;
					//printf("lex:\n");printf("before:");print_node($1);print_node($3);
					typecheck($1);typecheck($3);
					//printf("after:");print_node($1);print_node($3);	
					
				  $$=$3;
				}
	|expr			{$$=$1;
					//printf("lex:\n");printf("before:");print_node($1);
					typecheck($1);
					//printf("after:");print_node($1);
				}
	;
Sarray	:VAR '[' expr ']'	{	
					//printf("lex:\n"); printf("before:");print_node($1);print_node($3);
					typecheck($1);typecheck($3);
					//printf("after:");print_node($1);print_node($3);printf("tree call 37:\n"); 
					$$=create_tree(0,$1->type,$1->varname,arr_node,$3,NULL,NULL); 
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

