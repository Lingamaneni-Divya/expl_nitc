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
	int Gdecl_end_flag=0,Classdecl_end_flag=0;
	
%}

%union{
	struct tnode *tnode;
	struct Gsymbol *Gsymbol;
	struct Paramstruct *paramstruct;
	struct Typetable *Typetable;
	struct Classtable *classtable;
      }


%token NUM VAR MESG  PLUS MINUS MUL DIV MOD  GT LT GE LE EE NE  PBEGIN PEND READ WRITE  IF THEN ELSE ENDIF  WHILE DO ENDWHILE  CONTINUE BREAK  DECL ENDDECL RETURN MAINFN ANDTK ORTK NOTTK TYPE ENDTYPE NULLTK ALLOC INITIALIZE FREE CLASS ENDCLASS DELETE NEW EXTENDS SELF
%type <tnode> VAR NUM MESG NULLTK Fcall Sarray Field expr ArgList FreeStmt FuncStmt WhileStmt IfStmt AssgStmt OutputStmt InputStmt Stmt Slist RetStmt Body FuncName dexpr DeleteStmt FieldFunction ndexpr 
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


TypeDefBlock: TYPE TypeDefList ENDTYPE			{print_Typetable(); }
	    |						{print_Typetable(); }
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
FieldDecl :VAR VAR ';'				       {FInstall($2->varname,TLookup($1->varname)); }
	;

ClassDefBlock	:CLASS ClassDefList ENDCLASS		{print_classtable(); }
		|					{print_classtable(); }
		;
ClassDefList	:ClassDefList ClassDef			{ }
		|ClassDef				{ }
		;
ClassDef	:Cname '{'{Classdecl_end_flag=0;} DECL Fieldlists MethodDecl ENDDECL{Classdecl_end_flag=1;} MethodDefns '}'	{createVfuncTableEntries();currclass=NULL;}
		;
Cname		:VAR			{
						$$=CInstall($1->varname,NULL);
						currclass=$$;
					}
		|VAR EXTENDS VAR	{
						$$=CInstall($1->varname,$3->varname);
						currclass=$$;
					}
		;
Fieldlists	:Fieldlists Fld				{ }
		|					{/*NO ACTION*/}
		;
Fld		:VAR VAR ';'			{	
							Class_FInstall(currclass,$1->varname,$2->varname); 
						}
		;
MethodDecl	:MethodDecl MDecl			{ }
		|MDecl					{ }
		;
MDecl		:VAR VAR '('ParamList')'';'	{ 
								Class_MInstall(currclass,$2->varname,TLookup($1->varname),paramlist_head);
								reset_paramlist();
							}
		|VAR VAR '(' ')'';'		{ 
								Class_MInstall(currclass,$2->varname,TLookup($1->varname),paramlist_head);
								reset_paramlist();
							}
		;
MethodDefns	:MethodDefns Fdef			{}
		|Fdef					{ }
		;

GdeclBlock:DECL Gdecllist ENDDECL	{
						print_Gsymbol_table();
					 	Gdecl_end_flag=1;
						sp=sp+1;//next instruction address
						fp=fopen("start.xsm","a"); 
						fprintf(fp,"MOV SP, %d\n",sp);
						fprintf(fp,"CALL F0\n");
						fclose(fp);
       						scall("Exit",0,0);	
						
					}	
	| DECL ENDDECL			{
						print_Gsymbol_table();
					 	Gdecl_end_flag=1;
						sp=sp+1;//next address
						fp=fopen("start.xsm","a"); 
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
Type	:VAR		{ 
				currtype=TLookup($1->varname);
				curr_declclass=CLookup($1->varname);
			}			
	;

Gvarlist:Gvarlist ',' Gvar		{ }	
	|Gvar				{ }
	;					 
	
Gvar	:VAR				{	
						if(curr_declclass==NULL)
						{GInstall($1->varname,currtype,curr_declclass,1,paramlist_head);}
						else
						{GInstall($1->varname,currtype,curr_declclass,2,paramlist_head);}
						reset_paramlist();
					}	
	|VAR '['NUM']' 			{
						GInstall($1->varname,currtype,curr_declclass,$3->val,paramlist_head);
						reset_paramlist();
					}
	|VAR '('ParamList')' 		{
						GInstall($1->varname,currtype,curr_declclass,-1,paramlist_head); 
						reset_paramlist();
					}
	|VAR '(' ')'			{
						GInstall($1->varname,currtype,curr_declclass,-1,paramlist_head);
						reset_paramlist();
					}
	;

ParamList:PL				{
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
ParamTypeName:VAR			{$$=TLookup($1->varname);}
	;



FDefBlock:FDefBlock Fdef		{}
	|Fdef				{}
	;
Fdef	:NameParam '{'LdeclBlock Body'}'
		 			{ 
					print_Lsymbol_table(func_name);	
				printf("ABSTRACT SYNTAX TREE FOR %s Function\n",func_name);
				//preorder($4);
				printf("------------GENERATED SUCCESSFULLY---------------------------\n");
				printf("---------CODEGEN------\n");
				generate_code($4,func_name);
					reset_Lsymbol_table();	
					}
	|NameParam '{' Body'}' { 
					print_Lsymbol_table(func_name);	
				printf("ABSTRACT SYNTAX TREE FOR %s Function\n",func_name);
				//preorder($3);
				printf("-------------GENERATED SUCCESSFULLY--------------------------\n");
				printf("---------CODEGEN------\n");
				generate_code($3,func_name);
					reset_Lsymbol_table();	

			       }
	;
NameParam:RetTypeName FuncName '('ParamList')'{
						createLsymbolEntries(paramlist_head);
						name_equivalence($1,$2->varname,paramlist_head);
						reset_paramlist();	
					      }
	 |RetTypeName FuncName '('')' 	      {
						createLsymbolEntries(paramlist_head);
						name_equivalence($1,$2->varname,NULL);
						reset_paramlist();	
					      }
	 ;
FuncName:VAR 			{$$=$1;strcpy(func_name,$1->varname); }
	;
RetTypeName:VAR			{$$=TLookup($1->varname); }
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
	|VAR				{LInstall($1->varname,currtype); }
	;

Main: MAINFN 	{strcpy(func_name,"MAIN"); }
	;
MainBlock:VAR Main '(' ')' '{'LdeclBlock Body'}'
		{
			print_Lsymbol_table("MAIN");
				printf("ABSTRACT SYNTAX TREE FOR MAIN Function\n");
				//preorder($7);
				printf("---------------GENERATED SUCCESSFULLY------------------------\n");
				
				printf("---------CODEGEN------\n");
				generate_code($7,func_name);
			reset_Lsymbol_table();
		}
	|VAR Main '(' ')' '{' Body '}'
		{
			print_Lsymbol_table("MAIN");
				printf("ABSTRACT SYNTAX TREE FOR MAIN Function\n");
				//preorder($6);
				printf("-------------GENERATED SUCCESSFULLY--------------------------\n");
				printf("---------CODEGEN------\n");
				generate_code($6,func_name);
			reset_Lsymbol_table();
			
		}
	;
Body	:PBEGIN Slist RetStmt PEND';' 
			 {
			$$=create_tree(0,TLookup("null"),NULL,conn_node,$2,NULL,$3);	
			 }
	|PBEGIN RetStmt PEND';'		{
						$$=$2;
					}
	;	
RetStmt	:RETURN expr ';' {	
				typecheck($2);
				$$=create_tree(0,$2->type,func_name,ret_node,$2,NULL,NULL);
			 }
	;




Slist	:Slist Stmt	{
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
	|DeleteStmt		{$$=$1;}
	|CONTINUE';'	{
				$$=create_tree(0,TLookup("null"),NULL,continue_node,NULL,NULL,NULL);
			}
	|BREAK';'	{
				$$=create_tree(0,TLookup("null"),NULL,break_node,NULL,NULL,NULL);
			}
	;

InputStmt:READ '('VAR')'';'	{	
					typecheck($3);
					$$=create_tree(0,TLookup("null"),NULL,read_node,$3,NULL,NULL);	
				}
	 |READ '('Sarray')'';'	{
					typecheck($3);
					$$=create_tree(0,TLookup("null"),NULL,read_node,$3,NULL,NULL);

				}
	 |READ '('Field')'';'	{
					typecheck($3);
					$$=create_tree(0,TLookup("null"),NULL,read_node,$3,NULL,NULL); 
				}
	;
OutputStmt:WRITE '('expr')' ';'	{	
					typecheck($3);
					$$=create_tree(0,TLookup("null"),NULL,write_node,$3,NULL,NULL);
				}
	  ;
AssgStmt:VAR '=' expr ';'	{
					typecheck($1);typecheck($3);
					$$=create_tree(0,TLookup("null"),"=",assg_node,$1,NULL,$3);
				}
	|Sarray'='expr';'	{
					typecheck($1);typecheck($3);
					$$=create_tree(0,TLookup("null"),"=",assg_node,$1,NULL,$3);
				}
	|Field'='expr';'	{
					typecheck($1);typecheck($3);
					$$=create_tree(0,TLookup("null"),"=",assg_node,$1,NULL,$3);
				}
	|VAR '=' dexpr ';'	{
					typecheck($1);typecheck($3);
					$$=create_tree(0,TLookup("null"),"=",assg_node,$1,NULL,$3);
				}
	|VAR '=' ndexpr';'{
				typecheck($1);typecheck($3);
				$$=create_tree(0,TLookup("null"),"=",assg_node,$1,NULL,$3);
			  }
	|Field'=' ndexpr';'{
				typecheck($1);typecheck($3);
				$$=create_tree(0,TLookup("null"),"=",assg_node,$1,NULL,$3);
			   }
	;
DeleteStmt:DELETE '('Field')'';'{ 
				typecheck($3);
				$$=create_tree(0,TLookup("int"),NULL,free_node,$3,NULL,NULL);
				}
	;
dexpr	:ALLOC '(' ')'	{			
				$$=create_tree(0,TLookup("null"),NULL,alloc_node,NULL,NULL,NULL);
			}
	|INITIALIZE '(' ')' {	
				$$=create_tree(0,TLookup("int"),NULL,initialize_node,NULL,NULL,NULL);
			    }
	;
ndexpr:NEW '('VAR')'		{
					
					$$=create_tree(0,NULL,NULL,new_node,NULL,NULL,NULL);
					//$$->ctype=$3->ctype;
					$$->ctype=CLookup($3->varname);
				}
	;
IfStmt	:IF '('expr')' THEN Slist ELSE Slist ENDIF ';'
			     	{	
					$$=create_tree(0,TLookup("null"),NULL,if_node,$3,$6,$8);
				}
	|IF '('expr')' THEN Slist ENDIF ';'
				{	
					$$=create_tree(0,TLookup("null"),NULL,if_node,$3,$6,NULL); 
				}
	;
WhileStmt:WHILE '('expr')' DO Slist ENDWHILE';'
				{	
					$$=create_tree(0,TLookup("null"),NULL,while_node,$3,NULL,$6);
				}

	;
FuncStmt:Fcall';'		{$$=$1; }
	;
FreeStmt:FREE '('Field')'';'	{
					typecheck($3);
					$$=create_tree(0,TLookup("int"),NULL,free_node,$3,NULL,NULL);	
				}
				
	|FREE '('VAR')' ';'	{
					typecheck($3);
					$$=create_tree(0,TLookup("int"),NULL,free_node,$3,NULL,NULL);
				}

	;
expr	:expr PLUS expr		{
					typecheck($1);typecheck($3);
					$$=create_tree(0,TLookup("int"),"+",aop_node,$1,NULL,$3);
				}	
	|expr MINUS expr	{
					typecheck($1);typecheck($3);
					$$=create_tree(0,TLookup("int"),"-",aop_node,$1,NULL,$3); 
				}
	|expr MUL expr		{
					typecheck($1);typecheck($3);
					$$=create_tree(0,TLookup("int"),"*",aop_node,$1,NULL,$3);
				}
	|expr DIV expr		{
					typecheck($1);typecheck($3);
					$$=create_tree(0,TLookup("int"),"/",aop_node,$1,NULL,$3);
				}
	|expr MOD expr		{
					typecheck($1);typecheck($3);
					$$=create_tree(0,TLookup("int"),"%",aop_node,$1,NULL,$3);
				}
		
	|expr LE expr		{
					typecheck($1);typecheck($3);
					$$=create_tree(0,TLookup("bool"),"<=",lop_node,$1,NULL,$3); 
				}
	|expr GE expr		{
					typecheck($1);typecheck($3);
					$$=create_tree(0,TLookup("bool"),">=",lop_node,$1,NULL,$3);
				}
	|expr LT expr		{
					typecheck($1);typecheck($3);
					$$=create_tree(0,TLookup("bool"),"<",lop_node,$1,NULL,$3);
				}
	|expr GT expr		{
					typecheck($1);typecheck($3);
					$$=create_tree(0,TLookup("bool"),">",lop_node,$1,NULL,$3);
				}
	|expr EE expr		{
					typecheck($1);typecheck($3);
					$$=create_tree(0,TLookup("bool"),"==",lop_node,$1,NULL,$3);
				}
	|expr NE expr		{
					typecheck($1);typecheck($3);
					$$=create_tree(0,TLookup("bool"),"!=",lop_node,$1,NULL,$3);
				}

	|expr ANDTK expr        {
					typecheck($1);typecheck($3);
					$$=create_tree(0,TLookup("bool"),"&&",lop_node,$1,NULL,$3);
				}
	|expr ORTK expr		{
					typecheck($1);typecheck($3);
					$$=create_tree(0,TLookup("bool"),"||",lop_node,$1,NULL,$3);
				}
	|    NOTTK expr		{
				 	typecheck($2);
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
	|FieldFunction		{$$=$1;}
	;
Field	:SELF'.'VAR	{
				struct Fieldlist *f;
				if(currclass==NULL)
				{
				printf("self can only be used inside a class definition\n");
				exit(1);
				}
				f=Class_FLookup(currclass,$3->varname);
				if(f==NULL)
				{
				printf("Undeclared variable %s inside the class %s\n",$3->varname,currclass->name);
				exit(1);
				}
				$$=create_tree(0,NULL,"self",field_node,NULL,NULL,NULL);
				$$->faccess=$3;
				$3->val=f->fieldIndex;
				$3->type=f->type;
				$3->ctype=f->ctype;
				$$->type=f->type;
				$$->ctype=f->ctype;
			}
	|VAR '.' VAR	{
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
				if($1->ctype!=NULL)
				{
					printf("Cannot access private variable from outside a  class\n");
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
				if(temp->ctype!=NULL)
				{
				printf("Cannot access private variables of a class\n");
				exit(1);
				}
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
FieldFunction	:SELF '.'VAR '('')'	{
						struct Memberfunclist *mfunc;
						struct Paramstruct *plist;
						if(currclass==NULL)
						{
						printf("self can only be used inside a class definition\n");
						exit(1);
						}
						mfunc=Class_MLookup(currclass,$3->varname);
						if(mfunc==NULL)
						{
						printf("Undefined method %s of Class %s\n",$3->varname,currclass->name);
						exit(1);
						}
						if(hasSameSignatureArg(mfunc->paramlist,NULL)!=1)
						{
						printf("ARGUMENTS TYPE MISMATCH FOR FUNCTION CALL self.%s of class %s\n",$3->varname,currclass->name);
						exit(1);
						}
						$$=create_tree(0,NULL,"self",fieldfunction_node,NULL,NULL,NULL);
						$3->type=mfunc->type;
						$$->type=$3->type;
					  	$$->ctype=currclass;
					  	$$->faccess=$3;
					  	$3->left=NULL;
						
					}
		|SELF '.'VAR '('ArgList')'{
						struct Memberfunclist *mfunc;
						struct Paramstruct *plist;
						if(currclass==NULL)
						{
						printf("self can only be used inside a class definition\n");
						exit(1);
						}
						mfunc=Class_MLookup(currclass,$3->varname);
						if(mfunc==NULL)
						{
						printf("Undefined method %s of Class %s\n",$3->varname,currclass->name);
						exit(1);
						}
						if(hasSameSignatureArg(mfunc->paramlist,$5)!=1)
						{
						printf("ARGUMENTS TYPE MISMATCH FOR FUNCTION CALL self.%s of class %s\n",$3->varname,currclass->name);
						exit(1);
						}
						$$=create_tree(0,NULL,"self",fieldfunction_node,NULL,NULL,NULL);
						$3->type=mfunc->type;
						$$->type=$3->type;
					  	$$->ctype=currclass;
					  	$$->faccess=$3;
					  	$3->left=$5;
					}
		|VAR'.'VAR'('')'	{	typecheck($1);
						struct Memberfunclist *mfunc;
						struct Paramstruct *plist;
						mfunc=Class_MLookup($1->ctype,$3->varname);
						if(hasSameSignatureArg(mfunc->paramlist,NULL)!=1)
						{
						printf("ARGUMENTS TYPE MISMATCH FOR FUNCTION CALL %s.%s of class %s\n",$1->varname,$3->varname,$1->ctype->name);
						exit(1);
						}
						$$=create_tree(0,NULL,$1->varname,fieldfunction_node,NULL,NULL,NULL);
						$3->type=mfunc->type;
						$$->type=$3->type;
						$$->ctype=$1->ctype;
						$$->faccess=$3;
						$$->Gentry=$1->Gentry;
						$3->left=NULL;
						
					}
		|VAR'.'VAR'('ArgList')'	{	typecheck($1);
						struct Memberfunclist *mfunc;
						struct Paramstruct *plist;
						mfunc=Class_MLookup($1->ctype,$3->varname);
						if(hasSameSignatureArg(mfunc->paramlist,$5)!=1)
						{
						printf("ARGUMENTS TYPE MISMATCH FOR FUNCTION CALL %s.%s of class %s\n",$1->varname,$3->varname,$1->ctype->name);
						exit(1);
						}
						$$=create_tree(0,NULL,$1->varname,fieldfunction_node,NULL,NULL,NULL);
						$3->type=mfunc->type;
						$$->type=$3->type;
						$$->ctype=$1->ctype;
						$$->faccess=$3;
						$$->Gentry=$1->Gentry;
						$3->left=$5;

					}
		|Field '.'VAR'('')'	{
						struct tnode *temp;		
						struct Memberfunclist *mfunc;
						temp=$1;
						temp=temp->faccess;
						if(temp->faccess!=NULL)
						{
							printf("Illegal member function access\n");
							exit(1);
						}
						mfunc=Class_MLookup(temp->ctype,$3->varname);
						if(hasSameSignatureArg(mfunc->paramlist,NULL)!=1)
						{
		     	printf("ARGUMENTS TYPE MISMATCH FOR FUNCTION CALL %s of class %s\n",$3->varname,temp->ctype->name);
						exit(1);
						}
						$1->nodetype=fieldfunction_node;
						$$=$1;
						$3->type=mfunc->type;
						$$->type=$3->type;
						temp->faccess=$3;
						$3->left=NULL;
					}
		|Field '.'VAR'('ArgList')'{
						struct tnode *temp;		
						struct Memberfunclist *mfunc;
						temp=$1;
						temp=temp->faccess;
						if(temp->faccess!=NULL)
						{
							printf("Illegal member function access\n");
							exit(1);
						}
						mfunc=Class_MLookup(temp->ctype,$3->varname);
						if(hasSameSignatureArg(mfunc->paramlist,$5)!=1)
						{
		     	printf("ARGUMENTS TYPE MISMATCH FOR FUNCTION CALL %s of class %s\n",$3->varname,temp->ctype->name);
						exit(1);
						}
						$1->nodetype=fieldfunction_node;
						$$=$1;
						$3->type=mfunc->type;
						$$->type=$3->type;
						temp->faccess=$3;
						$3->left=$5;

					}
		;
Fcall	:VAR '(' ')'	{
				typecheck($1);
				$$=create_tree(0,TLookup("null"),$1->varname,func_node,NULL,NULL,NULL);		
			}
  	|VAR '(' ArgList ')'	{
					typecheck($1);typecheck($3);
					$$=create_tree(0,TLookup("null"),$1->varname,func_node,$3,NULL,NULL);	
			  	}
	;
//Arglist,expr because function call may be as factorial(n-1);
//may be like f(1,f(0)); in recursion etc
ArgList	: ArgList','expr	{
					$3->middle=$1;
					typecheck($1);typecheck($3);
					$$=$3;
				}
	|expr			{
					$$=$1;
					typecheck($$);
				}
	;
Sarray	:VAR '[' expr ']'	{	
					typecheck($1);typecheck($3);
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
	fp=fopen("start.xsm","w");
	
	fprintf(fp,"%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n",0,2056,0,0,0,0,0,0);
	fprintf(fp,"MOV SP, %d\n",sp);
	fclose(fp);
	
	fp=fopen("temp.xsm","w");
	fclose(fp);
	TypeTableCreate();
	yyparse();	
	FILE *fp1,*fp2,*fp3;
	fp1=fopen("start.xsm","r");
	fp2=fopen("temp.xsm","r");
	fp3=fopen("task1.xsm","w");
	char c;
	while((c=fgetc(fp1))!=EOF)
		fputc(c,fp3);
	while((c=fgetc(fp2))!=EOF)
		fputc(c,fp3);
	fclose(fp1);
	fclose(fp2);
	fclose(fp3);
	
	
	return 0;
}

