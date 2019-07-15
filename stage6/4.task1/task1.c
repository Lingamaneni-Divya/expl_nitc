#include<string.h>
#include<stdlib.h>

int sp=4096;
int flabel=0;
int bodyflag=0;
int declflag=0;
int typedeclflag=0;
struct Gsymbol *Gsymbol_table_head=NULL,*Gsymbol_table_tail=NULL;
struct Lsymbol *Lsymbol_table_head=NULL,*Lsymbol_table_tail=NULL;
struct Paramstruct *paramlist_head=NULL,*paramlist_tail=NULL;
struct Typetable *Typetable_head=NULL,*Typetable_tail=NULL;
struct Fieldlist *fieldlist_head=NULL,*fieldlist_tail=NULL;
int fieldIndex=1;
int local_binding=1;
char func_name[100];

int label=-1;
int instcnt;
struct labelstack *label_stack_top=NULL,*label_stack_bottom=NULL;
struct labeltable *label_table_head=NULL,*label_table_tail=NULL;


int c=-1;
int yyerror(char const *s)
{
	printf("yyerror %s\n",s);
}

void GInstall(char *name,struct Typetable *type,int size,struct Paramstruct *paramlist)
{
	struct Gsymbol *temp ,*newnode;
	if(GLookup(name)!=NULL)
	{
		printf("variable %s redefined!!\n",name);
		exit(1);
	}
	
	if(type==TLookup("null"))
	{
		printf("undefined type for variable %s\n",name);
	}
	newnode=(struct Gsymbol *)malloc(sizeof(struct Gsymbol));
	newnode->name=(char *)malloc((strlen(name)+2)*sizeof(char));
	strcpy(newnode->name,name);	
	newnode->type=type;
	newnode->size=size;
	newnode->paramlist=paramlist;
	if(newnode->size==-1)
	{
		flabel++;	
		newnode->flabel=flabel;
		newnode->binding=-1;
	}
	else
	{
		newnode->binding=sp;
		sp=sp+size;
		newnode->flabel=-1;
	}
	newnode->next=NULL;
	
	if(Gsymbol_table_head==NULL)
	{
		Gsymbol_table_head=newnode;	
		Gsymbol_table_tail=newnode;
	}
	else
	{
		Gsymbol_table_tail->next=newnode;
		Gsymbol_table_tail=newnode;
	}

}

/*DOUBT>>> CAN WE ALLOW int factorial(int n),n in Global declaration??*/
/*May allow Since .....in some program int partition(int low,int high) && int quicksort(int low,int high) are used simultaneously*/
struct Gsymbol *GLookup(char *name)
{
	struct Gsymbol *temp;
	temp=Gsymbol_table_head;

	while(temp!=NULL)
	{
		if(strcmp(name,temp->name)==0)
			return temp;
		temp=temp->next;
	}
	return temp;
} 
struct Paramstruct *create_param_node(char *name,struct Typetable *type)
{
	struct Paramstruct *newnode;
	newnode=(struct Paramstruct *)malloc(sizeof(struct Paramstruct));
	newnode->name=(char *)malloc((strlen(name)+2)*sizeof(char));
	strcpy(newnode->name,name);
	newnode->type=type;
	newnode->next=NULL;
	return newnode;
	
}

void  PInstall(struct Paramstruct *Param)
{
	struct Paramstruct *temp;
	temp=PLookup(Param->name);
	if(temp!=NULL)
	{
	  printf("Parameter:%s redefined in same function defnition",Param->name);
	  exit(1);
	}
	if(paramlist_head==NULL)
	{
		paramlist_head=Param;
		paramlist_tail=Param;
	}
	else
	{
		paramlist_tail->next=Param;
		paramlist_tail=Param;
	}
	
}

struct Paramstruct *PLookup(char *pname)
{
	struct Paramstruct *temp;
	temp=paramlist_head;
	while(temp!=NULL)
	{
		if(strcmp(temp->name,pname)==0)
			break;
		temp=temp->next;
	}
	return temp;
}


void reset_paramlist()
{
	paramlist_head=NULL;
	paramlist_tail=NULL;

}


void print_Gsymbol_table()
{
	struct Gsymbol *temp;
	temp=Gsymbol_table_head;
	printf("GLOBAL SYMBOL TABLE\n");
	printf("-------------------\n");
	printf("Name\t\t\tType\tSize\tBinding\tFlabel\tParamlist\t\n");
	printf("----------------------------------------------------------------\n");
	while(temp!=NULL)
	{
	
		if(temp->paramlist==NULL)
		{
			printf("%s\t\t\t%s\t%d\t%d\t%d\tNULL\t\n",temp->name,temp->type->name,temp->size,temp->binding,temp->flabel);
		}
		else
		{
			printf("%s\t\t\t%s\t%d\t%d\t%d\t\t\t\n",temp->name,temp->type->name,temp->size,temp->binding,temp->flabel);
			printf("\nPARAMLIST FOR %s FUNCTION\n",temp->name);
			printf("-----------------------------------\n");
			print_paramlist(temp->paramlist);
			
		}
		temp=temp->next;
	}
	printf("----------------END OF GLOBAL SYMBOL TABLE-------------------\n");

}	

void print_paramlist(struct Paramstruct *paramlist)
{
	struct Paramstruct *temp;
	temp=paramlist;
	printf("Name\t\t\tType\t\n");
	printf("------------------------------\n");
	
	while(temp!=NULL)
	{
		printf("%s\t\t\t%s\t\n",temp->name,temp->type->name);
		temp=temp->next;
	}
	printf("------------------------------\n\n");
}



struct tnode* create_tree(int val,struct Typetable *type,char *varname,int node_type,struct tnode*l,struct tnode *m,struct tnode *r)
{
	struct tnode *newnode=(struct tnode*)malloc(sizeof(struct tnode));
	
	newnode->val=val;
	newnode->type=type;
	if(varname!=NULL)
	{
		newnode->varname=(char *)malloc((strlen(varname)+2)*sizeof(char));
		strcpy(newnode->varname,varname);
	}
	else
	{
		newnode->varname=NULL;
	}
	newnode->nodetype=node_type;
	newnode->Gentry=NULL;
	newnode->left=l;
	newnode->right=r;
	newnode->middle=m;
	newnode->faccess=NULL;

	//printf("bodyflag:%d\n",bodyflag);
	if(bodyflag!=1||node_type!=var_node)
	{
	
	//printf("before:");
	//print_node(newnode);
	typecheck(newnode);
	//printf("after:");
	//print_node(newnode);
	}
	//print_node(newnode);
	return newnode;
}

void name_equivalence(struct Typetable *function_rettype,char *function_name,struct Paramstruct *paramlist)
{
   	struct Paramstruct *temp,*plist;
   	struct Gsymbol *dummy;
	int arg_count=0;
	dummy=GLookup(function_name);
	if(dummy==NULL)
	{
	 	printf("Function defnition %s without a previous declaration\n",function_name);
		exit(1);
	}
	if(dummy->type!=function_rettype)
	{
		printf("Return type of function \"%s\" does not match in the declaration and defnition\n",function_name);
		exit(1);
	}
	temp=dummy->paramlist;
	plist=paramlist;
	while(plist!=NULL)
	{
		arg_count++;
		if(temp==NULL)
		{
		   printf("Too many arguments for the Function %s\n",function_name);
		   exit(1);
		}
		else if(!((strcmp(plist->name,temp->name)==0) && plist->type==temp->type))
		{

		   printf("Ppname:%s,Gpname:%s\n",plist->name,temp->name);
		   printf("Pptype:%s,Gptype:%s\n",plist->type->name,temp->type->name);
		   printf("Conflict at Parameter %d of Function %s\n",arg_count,function_name);
			exit(1);
		}
		
		else
		{
			plist=plist->next;
			temp=temp->next;
		}
	}
      	if(temp!=NULL)
	{
		printf("Too few arguments for the Function %s\n",function_name);
		exit(1);
	}
}

void createLsymbolEntries(struct Paramstruct *paramlist)
{
	struct Paramstruct *temp;
	temp=paramlist;
	
	int x=0;
	while(temp!=NULL)
	{
		x=x+1;
		local_binding=-(2+x);
		LInstall(temp->name,temp->type);
		temp=temp->next;
		
	}
	local_binding=1;

}


void LInstall(char *name,struct Typetable *type)
{
	struct Lsymbol *temp ,*newnode;
	if(LLookup(name)!=NULL)
	{
		printf("variable %s redefined in Local scope!!\n",name);
		exit(1);
	}
	
	if(type==TLookup("null"))
	{
		printf("undefined type for variable %s\n",name);
	}
	newnode=(struct Lsymbol *)malloc(sizeof(struct Lsymbol));
	newnode->name=(char *)malloc((strlen(name)+2)*sizeof(char));
	strcpy(newnode->name,name);	
	newnode->type=type;
	newnode->binding=local_binding;
	local_binding++;
	newnode->next=NULL;
	
	if(Lsymbol_table_head==NULL)
	{
		Lsymbol_table_head=newnode;	
		Lsymbol_table_tail=newnode;
	}
	else
	{
		Lsymbol_table_tail->next=newnode;
		Lsymbol_table_tail=newnode;
	}

}

struct Lsymbol *LLookup(char *name)
{
	struct Lsymbol *temp;
	temp=Lsymbol_table_head;

	while(temp!=NULL)
	{
		if(strcmp(name,temp->name)==0)
			return temp;
		temp=temp->next;
	}
	return temp;
} 

void reset_Lsymbol_table()
{
	
 	Lsymbol_table_head=NULL;
 	Lsymbol_table_tail=NULL;
	local_binding=1;
}
void print_Lsymbol_table(char *name)
{
								
	struct Lsymbol *temp;
	temp=Lsymbol_table_head;
	printf("\n\nLOCAL SYMBOL TABLE FOR %s FUNCTION\n",name);
	printf("--------------------------------------------\n");
	printf("Name\t\t\tType\tBinding\t\n");
	printf("---------------------------------\n");
	while(temp!=NULL)
	{
		printf("%s\t\t\t%s\t%d\t\n",temp->name,temp->type->name,temp->binding);
		temp=temp->next;
	}
}

void typecheck(struct tnode *t)
{
	struct Lsymbol *local;
	struct Gsymbol *global;
	struct Paramstruct *param;
	//print_node(t);
	switch(t->nodetype)
	{
		case read_node:
			  	break;
		case write_node:
			   if((t->left->type!=TLookup("int"))&&(t->left->type!=TLookup("str")))
				{
				printf("Type Mismatch:	Invalid argument type to Write() function\n");
printf("Write Expects: (an expression which evaluates to integer )OR (a string type constant or variable )\n");
					exit(1);
				}
				break;
		case assg_node:
				if(t->right->nodetype==null_node||t->right->nodetype==alloc_node)
				{
					if(t->left->type==TLookup("int")||t->left->type==TLookup("str"))
					{				
						printf("Invalid assignment to non user defined type variable");
						exit(1);
					}
				}
				else if(t->left->type!=t->right->type)
				{
printf("Type Mismatch:	Type of LHS and RHS of an assignment statement does not Match\n");
					exit(1);
				}
				break;
		case conn_node:
				break;
		case iconst_node:
				break;
		case sconst_node:
				break;
		case var_node:
				if(bodyflag==1)
				{
					//printf("XYZ>>>>>:%s\n",t->varname);
					local=LLookup(t->varname);
					if(local==NULL)
					{
						global=GLookup(t->varname);
						if(global==NULL)
						{
			       printf("Variable:%s Undeclared in Local & Global\n",t->varname);
						exit(1);
						}
						else
						{
							t->type=global->type;
							t->Gentry=global;
						}
					}
					else
					{		
						t->type=local->type;
					}
				}
				break;

		case aop_node:
			     	if((t->left->type!=TLookup("int"))||(t->right->type!=TLookup("int")))
				{
				 printf("Type Mismatch:Expected Integer on both sides of arithmetic operator\n");
				exit(1);
				}
				break;
		case lop_node:
				if(!strcmp(t->varname,"==")||!strcmp(t->varname,"!="))
				{
					if(t->right->type==TLookup("null"))
					{
						if(t->left->type==TLookup("int")||t->left->type==TLookup("str"))
						{
						printf("Invalid comparision b/w NULL and non user defined type");
						exit(1);
						}

					}
					else if(t->left->type!=t->right->type)
					{
						printf("Comparision between 2 args of diff type\n");
						exit(1);

					}


				}
				else if(!strcmp(t->varname,">=")||!strcmp(t->varname,"<=") ||!strcmp(t->varname,">")|| !strcmp(t->varname,"<"))
				{
					if(t->left->type!=TLookup("int")||t->right->type!=TLookup("int"))
					{
						printf("expected int type on both sides of logical operator\n");
						exit(1);
					}
				}
				else if(!strcmp(t->varname,"&&") || !strcmp(t->varname,"||"))
				{
					if((t->left->type!=TLookup("bool"))||(t->right->type!=TLookup("bool")))
					{
				  printf("Type Mismatch:Expected BOOL on both sides of logical operator\n");
				  exit(1);
					}
				}
				else if(!strcmp(t->varname,"!"))
				{
					if(t->left->type!=TLookup("bool"))
					{
				  printf("Type Mismatch:Expected BOOL on with logical operator NOT\n");
				  exit(1);
					}
				}
				break;
		case if_node:
				if(t->left->type!=TLookup("bool"))
				{
					printf("Invalid expression inside if\n");
					exit(1);
				}
				break;
		case while_node:
				if(t->left->type!=TLookup("bool"))
				{
					printf("Invalid expression inside while\n");
					exit(1);
				}
				break;
		case continue_node:
				break;
		case break_node:
				break;
		case arr_node:
				if(declflag==0)
				{
					global=GLookup(t->varname);
					if(global==NULL)
					{
						printf("Array %s Undeclared\n",t->varname);
						exit(1);
					}
					if(t->left->nodetype==iconst_node)
					{
						if(t->left->val >= global->size)
						{
						printf("Array out of bound\n");
						exit(1);
						}
					}
					t->type=global->type;
					t->Gentry=global;
				}
				else if(declflag==1)
				{
					if(t->left->nodetype!=iconst_node)
					{
	printf("Array declaration should be static.....eg:arr[20] but no arr[i]\n");
					exit(1);
					}
				}
				break;
		case func_node:
				argcheck(t->varname,t->left);/*declaration and argument type check is taken care */
				global=GLookup(t->varname);
				t->Gentry=global;
				t->type=global->type;
				break;
		case ret_node:
				printf("Function Name:%s\n",t->varname);
				if(strcmp(t->varname,"MAIN"))
				{
					global=GLookup(t->varname);
					if(global==NULL)
					{
		printf("Function defnition %s without a previous declaration\n",t->varname);
		exit(1);
					}
					if(global->type!=t->left->type)
					{
	printf("Function %s expects type %s but here return type is %s\n",t->varname,global->type->name,t->left->type->name);
				exit(1);

					}
				}
				break;
		case free_node:
			if(t->left->type==TLookup("int")||t->left->type==TLookup("str"))
			{
				printf("free to be called for user defined types only\n");
				exit(1);
			}
			break;
	}
		//print_node(t);
}

void argcheck(char *function_name,struct tnode *t)
{
	struct Gsymbol *dummy;
	struct Paramstruct *temp,*temp1;
	struct tnode *parglist;
	int arg_count=0;
	dummy=GLookup(function_name);
	if(dummy==NULL)
	{
		printf("Usage of Function %s without any previous declaration\n",function_name);
		exit(1);
	}
	temp1=dummy->paramlist;
	//print_paramlist(temp1);
	temp=copylist(temp1);
	//print_paramlist(temp);
	temp=reverse_param(temp);
	//print_paramlist(temp);
	parglist=t;
	while(parglist!=NULL)
	{
		arg_count++;
		if(temp==NULL)
		{
		   printf("hello:Too many arguments int the Function call for %s\n",function_name);
		   exit(1);
		}
		else if(parglist->type!=temp->type)
		{
     printf("Parameter Type Mistmatch at Argument %d of Function %s\n",arg_count,function_name);
			printf("Pptype:%s,Gptype:%s\n",parglist->type->name,temp->type->name);
			exit(1);
		}
		
		else
		{
			parglist=parglist->middle;
			temp=temp->next;
		}
		
	}
	if(temp!=NULL)
	{
		printf("Too few arguments in the Function call for %s\n",function_name);
		exit(1);
	}
}	


void print_node(struct tnode *t)
{
	struct tnode *temp;
	if(t==NULL)
	{
		printf("HEY BOSS IT'S NULL\n");
	}
	printf("[val:%d ",t->val);
	printf("type:%s ",t->type->name);
	if(t->varname!=NULL)
	printf("varname:%s ",t->varname);
	else
	printf("varname:NULL ");
	switch(t->nodetype)
	{
  	case 1:
    	printf("read_node ");
    	break;
    	case 2:
    	printf("write_node ");
   	break;
    	case 3:
    	printf("assg_node ");
    	break;
    	case 4:
    	printf("conn_node ");
   	break;
    	case 5:
  	printf("iconst_node ");
  	break;
    	case 6:
    	printf("var_node ");
   	break;
    	case 7:
    	printf("aop_node ");
    	break;
	case 8:
	printf("lop_node ");
	break;
	case 9:
	printf("if_node ");
	break;
	case 10:
	printf("while_node ");
	break; 
	case 11:
	printf("continue_node ");
	break;
	case 12:
	printf("break_node ");
	break;
	case 13:
	printf("sconst_node ");
	break;
	case 14:
	printf("arr_node ");
	break;
	case 15:
	printf("func_node ");
	break;
	case 16:
	printf("ret_node ");
	break;
	case 17:
	printf("field_node ");
	break;
	case 18:
	printf("alloc_node ");
	break;
	case 19:
	printf("initialize_node ");
	break;
	case 20:
	printf("free_node ");
	break;
	case 21:
	printf("null_node ");
	break;

	}
	if(t->Gentry!=NULL)
	{
		 printf("binding:%d,Gentry_type:%s ",t->Gentry->binding,t->Gentry->type->name);
	}
	if(t->faccess!=NULL)
	{
		printf("fieldname:__ %s",t->varname);
		temp=t->faccess;
		while(temp!=NULL)
		{
			printf(".%s",temp->varname);
			temp=temp->faccess;
		}
		printf(" ");
	}
	printf("]\n");
}
//check this
void preorder(struct tnode *t)
{
	if(t==NULL)
	return;
	else
	{
	printf("node:\n");
	print_node(t);
	if(t->left)
	{
	  printf("left:\n");
	  preorder(t->left);
	}
	if(t->middle)
	{
	printf("middle:\n");
	preorder(t->middle);
	}
	if(t->right)
	{
	printf("right:\n");
	preorder(t->right);
	}
	}

}
void TypeTableCreate()
{
	TInstall("int",1,NULL);
	TInstall("str",1,NULL);
	TInstall("bool",0,NULL);
	TInstall("null",0,NULL);
	TInstall("void",0,NULL);
}

struct Typetable *TLookup(char *name)
{
	Typetable *temp;
	temp=Typetable_head;
	while(temp!=NULL)
	{
		if(strcmp(name,temp->name)==0)
		{
			break;
		}
		temp=temp->next;
	}
	return temp;

}

struct Typetable * TInstall(char *name,int size,struct Fieldlist *fields)
{

	struct Typetable *temp;
	temp=TLookup(name);
	if(temp!=NULL)
	{
		printf("Multiple declarations of type :%s\n",name);		
		exit(1);
	}
	temp=(Typetable *)malloc(sizeof(Typetable));
	temp->name=(char *)malloc(sizeof(char) *6);
	strcpy(temp->name,name);
	temp->size=size;
	temp->fields=fields;
	temp->next=NULL;
	if(Typetable_head==NULL)
	{
		Typetable_head=temp;
		Typetable_tail=temp;
	}
	else
	{
		Typetable_tail->next=temp;
		Typetable_tail=temp;
	}
	return temp;
}


void FInstall(char *name,struct Typetable *type)
{

	struct Fieldlist *temp;
	temp=field_check(name);
	if(temp!=NULL)
	{
		printf("Multiple declarations of field :%s\n",name);		
		exit(1);
	}
	temp=(struct Fieldlist *)malloc(sizeof(struct Fieldlist));
	temp->name=(char *)malloc(sizeof(char) *(strlen(name)+2));
	strcpy(temp->name,name);
	temp->type=type;
	temp->fieldIndex=fieldIndex;
	fieldIndex++;
	temp->next=NULL;
	if(fieldlist_head==NULL)
	{
		fieldlist_head=temp;
		fieldlist_tail=temp;
	}
	else
	{
		fieldlist_tail->next=temp;
		fieldlist_tail=temp;
	}
	
}

struct Fieldlist *field_check(char *name)
{
	struct Fieldlist *temp;
	temp=fieldlist_head;
	while(temp!=NULL)
	{
		if(strcmp(temp->name,name)==0)
			break;
		temp=temp->next;
	}
	return temp;
}

void reset_fieldlist()
{
	fieldlist_head=NULL;
	fieldlist_tail=NULL;
	fieldIndex=1;

}

struct Fieldlist *FLookup(Typetable *struct_type,char *name)
{
	struct Fieldlist *temp=struct_type->fields;
	while(temp!=NULL)
	{
		if(strcmp(name,temp->name)==0)
			break;
		temp=temp->next;
	}
	return temp;

}

int getSize(Typetable *type)
{
	int size=0;
	struct Fieldlist *temp;
	if(strcmp(type->name,"bool")==0||strcmp(type->name,"void")==0)
		return 0;
	if(strcmp(type->name,"int")==0||strcmp(type->name,"str")==0)
		return 1;
	temp=type->fields;
	while(temp!=NULL)
	{	
		size++;
		temp=temp->next;
	}
	return size;
}

void print_Typetable()
{
	struct Typetable *temp=Typetable_head; 
	struct Fieldlist *ftemp;
	printf("-------------------TYPE TABLE--------------------\n");
	printf("NAME		SIZE		FIELDS		\n");
	while(temp!=NULL)
	{
	  ftemp=temp->fields;
	  if(ftemp==NULL)
	  	printf("%s\t\t%d\t\tNULL\t\n",temp->name,temp->size);
	  else
	  {
		printf("%s\t\t%d\t\t--->\t\n",temp->name,temp->size);
		printf("---------FIELDLIST OF %s---------\n",temp->name);
		printf("FIELDINDEX		TYPE		NAME		\n");
		while(ftemp!=NULL)
		{
	  printf("%d\t\t%s\t\t%s\t\n",ftemp->fieldIndex,ftemp->type->name,ftemp->name);
			ftemp=ftemp->next;
		}
		printf("-------------------------------------------------------\n");
		
	  }
	 temp=temp->next;

	}
	printf("-------------------END OF TYPE TABLE--------------------\n");
}	













int getreg()
{
  c=c+1;
  if(c>=20)
    yyerror("registers exhausted!!\n");
  else
     return c;
}

void freereg()
{
 c--;
}


int scall(char *fcode,int arg1, int arg2)
{
	FILE *fp;
 	int r,i,j;
  
  if(strcmp("Write",fcode)==0)
   {
	
	i=getreg();
	fp=fopen("task1.xsm","a");
	fprintf(fp,"MOV [%d],R%d\n",sp,arg2);
     	fprintf(fp,"MOV R%d,\"%s\"\n",i,fcode);
     	fprintf(fp,"PUSH R%d\n",i);
     
     	fprintf(fp,"MOV R%d,%d\n",i,arg1);
     	fprintf(fp,"PUSH R%d\n",i);
     
     	fprintf(fp,"MOV R%d,[%d]\n",i,sp);
     	fprintf(fp,"PUSH R%d\n",i);
   	fclose(fp);
	j=getreg();
	fp=fopen("task1.xsm","a");
     	fprintf(fp,"PUSH R%d\n",j);
     	fprintf(fp,"PUSH R%d\n",j);
     	fprintf(fp,"CALL 0\n");
	fclose(fp);
	freereg();
    	fp=fopen("task1.xsm","a");
	fprintf(fp,"POP R%d\n",i);
	fclose(fp);
	j=getreg();
	fp=fopen("task1.xsm","a");
     	fprintf(fp,"POP R%d\n",j);
     	fprintf(fp,"POP R%d\n",j);
     	fprintf(fp,"POP R%d\n",j);
     	fprintf(fp,"POP R%d\n",j);
	fclose(fp);
     	freereg();
     
	freereg();
	return i;
    }
   else if(strcmp("Read",fcode)==0)
   {
	
     	i=getreg();
	//printf("i:%d\n",i);
	fp=fopen("task1.xsm","a");
     	fprintf(fp,"MOV R%d,\"%s\"\n",i,fcode);
     	fprintf(fp,"PUSH R%d\n",i);

     	fprintf(fp,"MOV R%d,%d\n",i,arg1);
     	fprintf(fp,"PUSH R%d\n",i);

     	//fprintf(fp,"MOV R%d,%d\n",i,arg2);
     	fprintf(fp,"PUSH R%d\n",arg2);
	fclose(fp);
	j=getreg();
	//printf("j:%d\n",j);
	fp=fopen("task1.xsm","a");
     	fprintf(fp,"PUSH R%d\n",j);
     	fprintf(fp,"PUSH R%d\n",j);
     	fprintf(fp,"CALL 0\n");
	fclose(fp);
	freereg();
	fp=fopen("task1.xsm","a");
     	fprintf(fp,"POP R%d\n",i);
	fclose(fp);
	//printf("i:%d\n",i);
	j=getreg();
	//printf("j:%d\n",j);
	fp=fopen("task1.xsm","a");
     	fprintf(fp,"POP R%d\n",j);
     	fprintf(fp,"POP R%d\n",j);
     	fprintf(fp,"POP R%d\n",j);
     	fprintf(fp,"POP R%d\n",j);
	fclose(fp);
     	freereg();
	freereg();
	return i;
    }
   else if(strcmp("Exit",fcode)==0)
   {
		
	i=getreg();
	fp=fopen("task1.xsm","a");    
     	fprintf(fp,"MOV R%d,\"%s\"\n",i,fcode);
	fprintf(fp,"PUSH R%d\n",i);
	fclose(fp);
     	j=getreg();
	fp=fopen("task1.xsm","a"); 
     	fprintf(fp,"PUSH R%d\n",j);
     	fprintf(fp,"PUSH R%d\n",j);
     	fprintf(fp,"PUSH R%d\n",j);
     	fprintf(fp,"PUSH R%d\n",j);
     	fprintf(fp,"CALL 0\n");
	fclose(fp);
     	freereg();
	
	fp=fopen("task1.xsm","a"); 
     	fprintf(fp,"POP R%d\n",i);
	fclose(fp);
     	j=getreg();
	fp=fopen("task1.xsm","a"); 
     	fprintf(fp,"POP R%d\n",j);
     	fprintf(fp,"POP R%d\n",j);
     	fprintf(fp,"POP R%d\n",j);
     	fprintf(fp,"POP R%d\n",j);
	fclose(fp);
     	freereg();
	freereg();
     	
	
     	return i;
    }
   else if(strcmp("Heapset",fcode)==0)
   {
	i=getreg();
	fp=fopen("task1.xsm","a");
     	fprintf(fp,"MOV R%d,\"%s\"\n",i,fcode);
     	fprintf(fp,"PUSH R%d\n",i);
	fclose(fp);
	j=getreg();

	fp=fopen("task1.xsm","a");
	fprintf(fp,"PUSH R%d\n",j);
     	fprintf(fp,"PUSH R%d\n",j);
     	fprintf(fp,"PUSH R%d\n",j);
     	fprintf(fp,"PUSH R%d\n",j);
     	fprintf(fp,"CALL 0\n");
	fclose(fp);
	freereg();

	fp=fopen("task1.xsm","a");
     	fprintf(fp,"POP R%d\n",i);
	fclose(fp);

	j=getreg();
	fp=fopen("task1.xsm","a");
     	fprintf(fp,"POP R%d\n",j);
     	fprintf(fp,"POP R%d\n",j);
     	fprintf(fp,"POP R%d\n",j);
     	fprintf(fp,"POP R%d\n",j);
	fclose(fp);
     	freereg();
	freereg();
	return i;



   }

   else if(strcmp("Alloc",fcode)==0)
   {
	i=getreg();
	fp=fopen("task1.xsm","a");
     	fprintf(fp,"MOV R%d,\"%s\"\n",i,fcode);
     	fprintf(fp,"PUSH R%d\n",i);
	fprintf(fp,"MOV R%d,8\n",i);
	fprintf(fp,"PUSH R%d\n",i);
	fclose(fp);
	j=getreg();

	fp=fopen("task1.xsm","a");
     	fprintf(fp,"PUSH R%d\n",j);
     	fprintf(fp,"PUSH R%d\n",j);
     	fprintf(fp,"PUSH R%d\n",j);
     	fprintf(fp,"CALL 0\n");
	fclose(fp);
	freereg();

	fp=fopen("task1.xsm","a");
     	fprintf(fp,"POP R%d\n",i);
	fclose(fp);

	j=getreg();
	fp=fopen("task1.xsm","a");
     	fprintf(fp,"POP R%d\n",j);
     	fprintf(fp,"POP R%d\n",j);
     	fprintf(fp,"POP R%d\n",j);
     	fprintf(fp,"POP R%d\n",j);
	fclose(fp);
     	freereg();
	freereg();
	return i;


   }
   else if(strcmp("Free",fcode)==0)
   {
	i=getreg();
	fp=fopen("task1.xsm","a");
	fprintf(fp,"MOV [%d],R%d\n",sp,arg1);
	
     	fprintf(fp,"MOV R%d,\"%s\"\n",i,fcode);
     	fprintf(fp,"PUSH R%d\n",i);
     	fprintf(fp,"MOV R%d,[%d]\n",i,sp);
     	fprintf(fp,"PUSH R%d\n",i);
   	fclose(fp);

	j=getreg();
	fp=fopen("task1.xsm","a");
     	fprintf(fp,"PUSH R%d\n",j);
     	fprintf(fp,"PUSH R%d\n",j);
	fprintf(fp,"PUSH R%d\n",j);
     	fprintf(fp,"CALL 0\n");
	fclose(fp);
	freereg();

    	fp=fopen("task1.xsm","a");
	fprintf(fp,"POP R%d\n",i);
	fclose(fp);

	j=getreg();
	fp=fopen("task1.xsm","a");
     	fprintf(fp,"POP R%d\n",j);
     	fprintf(fp,"POP R%d\n",j);
     	fprintf(fp,"POP R%d\n",j);
     	fprintf(fp,"POP R%d\n",j);
	fclose(fp);
     	freereg();
     
	freereg();
	return i;



   }

}

 
void generate_code(struct tnode *t,char *fname)
{
	FILE *fp;
   	int fl;
	int i;
	int x;
	fp=fopen("task1.xsm","a");
	//fprintf(fp,"FUNCTION NAME_____________________________%s\n",fname);
fclose(fp);
   	if(strcmp(fname,"MAIN")==0)
   	{
		fl=0;
   	}
  	else
  	{
		fl=GLookup(fname)->flabel;
	}

	fp=fopen("task1.xsm","a");
	fprintf(fp,"F%d:\n",fl);
	fprintf(fp,"PUSH BP\n");
	fprintf(fp,"MOV BP,SP\n");
	fclose(fp);
	//allocating space ..for local variables...
	for(i=1;i<local_binding;i++)
	{
		fp=fopen("task1.xsm","a");
		fprintf(fp,"PUSH R0\n");
		fclose(fp);
	}
	x=codegen(t);

}

int codegen(struct tnode *t)
{
	FILE *fp;
	int l,m,r,i,j,buff,data,v,n,x;
	struct Gsymbol *global;
	struct Lsymbol *local;
	struct Paramstruct *paramlist;
	struct tnode *arglist;
	printf("codegen:");
	print_node(t);
	switch(t->nodetype)
	{
		
		case read_node:
			printf("read c:%d\n",c);
			buff=getaddr(t->left);
			for(n=0;n<=c;n++)
			{
			  fp=fopen("task1.xsm","a");
			  fprintf(fp,"PUSH R%d\n",n);
			  fclose(fp);
			  sp=sp+1;
			}
			i=scall("Read",-1,buff);			
			for(n=c;n>=0;n--)
			{
			  fp=fopen("task1.xsm","a");
			  fprintf(fp,"POP R%d\n",n);
			  fclose(fp);
			  sp=sp-1;
			}
			freereg();
			printf("read c:%d\n",c);
			return i;
			break;

		case write_node:
			printf("read c:%d\n",c);
			l=codegen(t->left);
			freereg();
			for(n=0;n<=c;n++)
			{
			  fp=fopen("task1.xsm","a");
			  fprintf(fp,"PUSH R%d\n",n);
			  fclose(fp);
			  sp=sp+1;
			}
			i=scall("Write",-2,l);
			for(n=c;n>=0;n--)
			{
			  fp=fopen("task1.xsm","a");
			  fprintf(fp,"POP R%d\n",n);
			  fclose(fp);
			  sp=sp-1;
			}
			printf("write c:%d\n",c);
			return i;
			break;

		case assg_node:
			v=getaddr(t->left);
			r=codegen(t->right);
			
			fp=fopen("task1.xsm","a");
			fprintf(fp,"MOV [R%d],R%d\n",v,r);
			fclose(fp);
			freereg();
			if(t->right->nodetype!=initialize_node&&t->right->nodetype!=alloc_node)
			{
			freereg();
			}
			printf("assg c:%d\n",c);
			return v;
			break;

		case conn_node:
			
			l=codegen(t->left);
			l=codegen(t->right);
			printf("conn c:%d\n",c);
			return l;
			break;

		case iconst_node:
			
			i=getreg();
			fp=fopen("task1.xsm","a");
			fprintf(fp,"MOV R%d,%d\n",i,t->val);
			fclose(fp);
			printf("iconst c:%d\n",c);
			return i;
			break;
//##CHECK>>CHANGED TO ...ARRAY AND VAR

		case var_node:
			
			v=getaddr(t);
			fp=fopen("task1.xsm","a");
			fprintf(fp,"MOV R%d,[R%d]\n",v,v);
			fclose(fp);
			printf("var c:%d\n",c);
			return v;
			break;
			
		case aop_node:
			
			l=codegen(t->left);
			r=codegen(t->right);
			switch(*(t->varname))
			{
				case '+':
					fp=fopen("task1.xsm","a");
					fprintf(fp,"ADD R%d,R%d\n",l,r);
					fclose(fp);
					freereg();
					break;
				case '-':
					fp=fopen("task1.xsm","a");
					fprintf(fp,"SUB R%d,R%d\n",l,r);
					fclose(fp);
					freereg();
					break;
				case '*':
					fp=fopen("task1.xsm","a");
					fprintf(fp,"MUL R%d,R%d\n",l,r);
					fclose(fp);
					freereg();
					break;
				case '/':
					fp=fopen("task1.xsm","a");
					fprintf(fp,"DIV R%d,R%d\n",l,r);
					fclose(fp);
					freereg();
					break;
				case '%':
					fp=fopen("task1.xsm","a");
					fprintf(fp,"MOD R%d,R%d\n",l,r);
					fclose(fp);
					freereg();
					break;
			}
			printf("aop c:%d\n",c);
			return l;
			break;

		case lop_node:
			
			if(strcmp(t->varname,">=")==0)
			{ 
				l=codegen(t->left);
				r=codegen(t->right);
				fp=fopen("task1.xsm","a");
				fprintf(fp,"GE R%d,R%d\n",l,r);
				fclose(fp);
				freereg();
				printf(">= c:%d\n",c);
				return l;
			}
			else if(strcmp(t->varname,"<=")==0)
			{ 
				l=codegen(t->left);
				r=codegen(t->right);
				fp=fopen("task1.xsm","a");
				fprintf(fp,"LE R%d,R%d\n",l,r);
				fclose(fp);
				freereg();
				printf("<= c:%d\n",c);
				return l;
			}
			else if(strcmp(t->varname,">")==0)
			{ 
				l=codegen(t->left);
				r=codegen(t->right);
				fp=fopen("task1.xsm","a");
				fprintf(fp,"GT R%d,R%d\n",l,r);
				fclose(fp);
				freereg();
				printf("> c:%d\n",c);
				return l;
			}
			else if(strcmp(t->varname,"<")==0)
			{ 
				l=codegen(t->left);
				r=codegen(t->right);
				fp=fopen("task1.xsm","a");
				fprintf(fp,"LT R%d,R%d\n",l,r);
				fclose(fp);
				freereg();
				printf("< c:%d\n",c);
				return l;
			}
			else if(strcmp(t->varname,"==")==0)
			{ 
				l=codegen(t->left);
				r=codegen(t->right);
				fp=fopen("task1.xsm","a");
				fprintf(fp,"EQ R%d,R%d\n",l,r);
				fclose(fp);
				freereg();
				printf("== c:%d\n",c);
				return l;
			}
			else if(strcmp(t->varname,"!=")==0)
			{ 
				l=codegen(t->left);
				r=codegen(t->right);
				fp=fopen("task1.xsm","a");
				fprintf(fp,"NE R%d,R%d\n",l,r);
				fclose(fp);
				freereg();
				printf("!= c:%d\n",c);
				return l;
			}
			else if(strcmp(t->varname,"&&")==0)
			{ 
				l=codegen(t->left);
				r=codegen(t->right);
				i=getlabel();
				j=getlabel();
				fp=fopen("task1.xsm","a");
				fprintf(fp,"JZ R%d,L%d\n",l,i);
				fprintf(fp,"JZ R%d,L%d\n",r,i);
				fprintf(fp,"MOV R%d,1\n",l);
				fprintf(fp,"JMP L%d\n",j);
				fprintf(fp,"L%d:\n",i);
				fprintf(fp,"MOV R%d,0\n",l);
				fprintf(fp,"L%d:\n",j);
				fclose(fp);
				freereg();
				printf("&& c:%d\n",c);
				return l;
			}
			else if(strcmp(t->varname,"||")==0)
			{ 
				l=codegen(t->left);
				r=codegen(t->right);
				i=getlabel();
				j=getlabel();
				fp=fopen("task1.xsm","a");
				fprintf(fp,"JNZ R%d,L%d\n",l,i);
				fprintf(fp,"JNZ R%d,L%d\n",r,i);
				fprintf(fp,"MOV R%d,0\n",l);
				fprintf(fp,"JMP L%d\n",j);
				fprintf(fp,"L%d:\n",i);
				fprintf(fp,"MOV R%d,1\n",l);
				fprintf(fp,"L%d:\n",j);
				fclose(fp);
				freereg();
				printf("|| c:%d\n",c);
				return l;
			}
			else if(strcmp(t->varname,"!")==0)
			{ 
				l=codegen(t->left);
				i=getlabel();
				j=getlabel();
				fp=fopen("task1.xsm","a");
				fprintf(fp,"JZ R%d,L%d\n",l,i);
				fprintf(fp,"MOV R%d,0\n",l);
				fprintf(fp,"JMP L%d\n",j);
				fprintf(fp,"L%d:\n",i);
				fprintf(fp,"MOV R%d,1\n",l);
				fprintf(fp,"L%d:\n",j);
				fclose(fp);
				printf("! c:%d\n",c);
				return l;
			}
			break;

		case if_node:
			{	
				l=codegen(t->left);
				freereg();
					
				i=getlabel();
				fp=fopen("task1.xsm","a");
				fprintf(fp,"JZ R%d,L%d\n",l,i);
				fclose(fp);
				m=codegen(t->middle);
				if(t->right!=NULL)
				{
					j=getlabel();
					fp=fopen("task1.xsm","a");
					fprintf(fp,"JMP L%d\n",j);
					fprintf(fp,"L%d:\n",i);
					fclose(fp);
					r=codegen(t->right);
					fp=fopen("task1.xsm","a");
					fprintf(fp,"L%d:\n",j);
					fclose(fp);
					printf("if c:%d\n",c);
					return l;
					break;
				}
				else
				{
					fp=fopen("task1.xsm","a");
					fprintf(fp,"L%d:\n",i);
					fclose(fp);
					printf("if c:%d\n",c);
					return l;
					break;	
				}
			}

		case while_node:
			{
				
				
				i=getlabel();
				fp=fopen("task1.xsm","a");
				fprintf(fp,"L%d:\n",i);
				fclose(fp);
				push_label_stack(i);
				l=codegen(t->left);
				freereg();
				j=getlabel();
				fp=fopen("task1.xsm","a");
				fprintf(fp,"JZ R%d,L%d\n",l,j);
				fclose(fp);
				r=codegen(t->right);
				fp=fopen("task1.xsm","a");
				fprintf(fp,"JMP L%d\n",i);
				fprintf(fp,"L%d:\n",j);
				fclose(fp);
				pop_label_stack();
				printf("while c:%d\n",c);
				return l;
				break;
			}

		case continue_node:
			
			if(label_stack_top!=NULL)
			{
			 	fp=fopen("task1.xsm","a");
				fprintf(fp,"JMP L%d\n",label_stack_top->val);
				fclose(fp);
			}
			printf("continue c:%d\n",c);
			return -1;
			break;

		case break_node:
			
			if(label_stack_top!=NULL)
			{
				fp=fopen("task1.xsm","a");
				fprintf(fp,"JMP L%d\n",(label_stack_top->val)+1);
				fclose(fp);
			}
			printf("break c:%d\n",c);
			return -1;
			break;

		case sconst_node:
				
				i=getreg();
				fp=fopen("task1.xsm","a");
				fprintf(fp,"MOV R%d,%s\n",i,t->varname);
				fclose(fp);
				printf("sconst c:%d\n",c);
				return i;
				break;

		case arr_node:
				if(t->Gentry==NULL)
				{
					printf("HEY ITS NULL HERE ALSO___________\n");
				//exit(1);
				}
				v=getaddr(t);
				fp=fopen("task1.xsm","a");
				fprintf(fp,"MOV R%d,[R%d]\n",v,v);
				fclose(fp);
				printf("arr_node c:%d\n",c);
				return v;
				break;

		case func_node:
			
//SAVING MACHINE STATE by pushing all the registers before function call....
				for(n=0;n<=c;n++)
				{				
					fp=fopen("task1.xsm","a");
					fprintf(fp,"PUSH R%d\n",n);
					fclose(fp);
					sp=sp+1;
				}
//evaluate arguments and push.......
				arglist=t->left;
				while(arglist!=NULL)
				{
					x=codegen(arglist);
					fp=fopen("task1.xsm","a");
					fprintf(fp,"PUSH R%d\n",x);
					fclose(fp);
					freereg();
					arglist=arglist->middle;
				}
//space for return value....
				fp=fopen("task1.xsm","a");
				fprintf(fp,"PUSH R0\n");
				fclose(fp);
//function call.....
				global=t->Gentry;
				fp=fopen("task1.xsm","a");
				fprintf(fp,"CALL F%d\n",global->flabel);
				fclose(fp);
//poping and saving...return value....after call
				i=getreg();
				fp=fopen("task1.xsm","a");
				fprintf(fp,"POP R%d\n",i);
				fclose(fp);
//saving..arguments....
				arglist=t->left;
				j=getreg();
				while(arglist!=NULL)
				{
					fp=fopen("task1.xsm","a");
					fprintf(fp,"POP R%d\n",j);
					fclose(fp);
					arglist=arglist->middle;
				}
				freereg();
//poping MACHINE STATE......
				for(n=i-1;n>=0;n--)
				{				
					fp=fopen("task1.xsm","a");
					fprintf(fp,"POP R%d\n",n);
					fclose(fp);
					sp=sp-1;
				}
				printf("func c:%d\n",c);
				return i;
				break;

		case ret_node:
				
//evaluating return value and saving it space allocated....
				l=codegen(t->left);
				i=getreg();
				fp=fopen("task1.xsm","a");
				fprintf(fp,"MOV R%d,BP\n",i);
				fprintf(fp,"SUB R%d,2\n",i);
				fprintf(fp,"MOV [R%d],R%d\n",i,l);
				fclose(fp);
				
//pop all the local variables.....
				for(n=1;n<local_binding;n++)
				{
					fp=fopen("task1.xsm","a");
					fprintf(fp,"POP R%d\n",i);
					fclose(fp);
				}
				freereg();
				freereg();
//pop old BP value...
				fp=fopen("task1.xsm","a");
				fprintf(fp,"POP BP\n");
				fclose(fp);
//return stmt
				fp=fopen("task1.xsm","a");
				fprintf(fp,"RET\n");
				fclose(fp);
				printf("ret c:%d\n",c);
				return l;
				break;
		case field_node:
			
			v=getaddr(t);
			fp=fopen("task1.xsm","a");
			fprintf(fp,"MOV R%d,[R%d]\n",v,v);
			fclose(fp);
			printf("field c:%d\n",c);
			return v;
			break;
		case initialize_node:
			printf("init c:%d\n",c);
			for(n=0;n<=c;n++)
			{
			  fp=fopen("task1.xsm","a");
			  fprintf(fp,"PUSH R%d\n",n);
			  fclose(fp);
			  sp=sp+1;
			}
			i=scall("Heapset",0,0);
			for(n=c;n>=0;n--)
			{
			  fp=fopen("task1.xsm","a");
			  fprintf(fp,"POP R%d\n",n);
			  fclose(fp);
			  sp=sp-1;
			}
			//freereg();
			printf("init c:%d\n",c);
			return i;
			break;
		case alloc_node:
			for(n=0;n<=c;n++)
			{
			  fp=fopen("task1.xsm","a");
			  fprintf(fp,"PUSH R%d\n",n);
			  fclose(fp);
			  sp=sp+1;
			}
			i=scall("Alloc",8,0);
			for(n=c;n>=0;n--)
			{
			  fp=fopen("task1.xsm","a");
			  fprintf(fp,"POP R%d\n",n);
			  fclose(fp);
			  sp=sp-1;
			}
			//freereg();
			printf("alloc c:%d\n",c);
			return i;
			break;
		case free_node:
			l=codegen(t->left);
			for(n=0;n<=c;n++)
			{
			  fp=fopen("task1.xsm","a");
			  fprintf(fp,"PUSH R%d\n",n);
			  fclose(fp);
			  sp=sp+1;
			}
			i=scall("Free",l,0);
			for(n=c;n>=0;n--)
			{
			  fp=fopen("task1.xsm","a");
			  fprintf(fp,"POP R%d\n",n);
			  fclose(fp);
			  sp=sp-1;
			}
			//freereg();
			printf("free c:%d\n",c);
			return i;
			break;
		case null_node:
			i=getreg();
			fp=fopen("task1.xsm","a");
			fprintf(fp,"MOV R%d, 0\n",i);
			fclose(fp);
			printf("null c:%d\n",c);
			return i;
			break;
	}
	

}




int getaddr(tnode *t)
{
  	int i,j,l,base;
 	FILE *fp;
	struct Lsymbol *local;
	struct Gsymbol *global;
	printf("get addr:");
	print_node(t);
   	if(t->nodetype==arr_node)
   	{
		if(t->Gentry==NULL)
		{
			printf("HEY ITS NULL___________\n");
			exit(1);
		}
		base=t->Gentry->binding;
		printf("addr of base:%d\n",base);
 		l=codegen(t->left);
		//freereg();
		fp=fopen("task1.xsm","a");
		fprintf(fp,"ADD R%d,%d\n",l,t->Gentry->binding);
		fclose(fp);
		printf("get addr--nodetype:%d c:%d\n",t->nodetype,c);
		return l;
   	}

	if(t->nodetype==var_node)
	{
		local=LLookup(t->varname);
		if(local==NULL)
		{
	   		i=getreg();
			fp=fopen("task1.xsm","a");
			fprintf(fp,"MOV R%d,%d\n",i,t->Gentry->binding);
			fclose(fp);
			printf("addr of global variable:%d\n",t->Gentry->binding);
			//freereg();
			printf("get addr--nodetype:%d c:%d\n",t->nodetype,c);
			return i;
		}
		else
		{
			i=getreg();
			fp=fopen("task1.xsm","a");
			fprintf(fp,"MOV R%d,BP\n",i);
			fprintf(fp,"ADD R%d,%d\n",i,local->binding);
			fclose(fp);
			printf("relative addr of local variable:%d\n",local->binding);
			printf("get addr--nodetype:%d c:%d\n",t->nodetype,c);
			return i;
		}
	}
	if(t->nodetype==field_node)
	{
		int addr;
		struct tnode *temp;
		
		local=LLookup(t->varname);
		if(local==NULL)
		{
	   		i=getreg();
			fp=fopen("task1.xsm","a");
			fprintf(fp,"MOV R%d,%d\n",i,t->Gentry->binding);
			fclose(fp);
			//printf("addr of global variable:%d\n",t->Gentry->binding);
			//freereg();
			//return i;
		}
		else
		{
			i=getreg();
			fp=fopen("task1.xsm","a");
			fprintf(fp,"MOV R%d,BP\n",i);
			fprintf(fp,"ADD R%d,%d\n",i,local->binding);
			fclose(fp);
			//printf("relative addr of local variable:%d\n",local->binding);
			//return i;
		}
		fp=fopen("task1.xsm","a");
		fprintf(fp,"MOV R%d, [R%d]\n",i,i);
		fclose(fp);
		temp=t->faccess;
		while(temp!=NULL)
		{
			fp=fopen("task1.xsm","a");
			fprintf(fp,"ADD R%d, %d\n",i,temp->val);
			fclose(fp);
			if(temp->faccess!=NULL)
			{
				fp=fopen("task1.xsm","a");
				fprintf(fp,"MOV R%d, [R%d]\n",i,i);
				fclose(fp);
			}
			temp=temp->faccess;
		}
		printf("get addr--nodetype:%d c:%d\n",t->nodetype,c);
		return i;
	}
}



int getlabel()
{
	label++;	
	return label;
	
}

void insertlabel(char *labelname)
	{
		struct labeltable *temp=(struct labeltable*)malloc(sizeof(struct labeltable));
		
 		temp->name=malloc((strlen(labelname)+2)*sizeof(char));
		strcpy(temp->name,labelname);
		//temp->val=labelnum;
		temp->address=2048+2*(instcnt);
		temp->next=NULL;
		if(label_table_head==NULL)
		{
			label_table_head=temp;
			label_table_tail=temp;
		}
		else
		{
			label_table_tail->next=temp;
			label_table_tail=temp;
		}

	}

void print_label_table()
{
	struct labeltable *temp=label_table_head;
	printf("Label Num\tAddress\n");
	printf("--------------------\n");
	
		
	while(temp!=NULL)
	{
		printf("%s\t\t%d\n",temp->name,temp->address);
		
		temp=temp->next;
	}
}
int searchlabel(char *labelname)
{
	struct labeltable *temp=label_table_head;
	while(temp!=NULL)
	{
		if(strcmp(temp->name,labelname)==0)
		{
			return temp->address;
		}
		else
		{
			temp=temp->next;
		}
	}
}


void push_label_stack(int num)
{
	struct labelstack *temp=(struct labelstack *)malloc(sizeof(struct labelstack));
	temp->val=num;
	temp->next=NULL;
	if(label_stack_bottom==NULL)
	{
		label_stack_bottom=temp;
		label_stack_top=temp;
	}
	else
	{
		label_stack_top->next=temp;
		label_stack_top=temp;
	}
}

void pop_label_stack()
{
	struct labelstack *temp=label_stack_bottom;
	struct labelstack *prev;
	if(temp->next==NULL)
	{
		label_stack_bottom=NULL;
		label_stack_top=NULL;
	}
	else
	{
		while(temp->next!=NULL)
		{
			prev=temp;
			temp=temp->next;
		}
		label_stack_top=prev;
		label_stack_top->next=NULL;
		free(temp);
	}
}

struct Paramstruct *reverse_param(struct Paramstruct *plist)
{
	struct Paramstruct *curr=plist,*prev=NULL,*next=NULL;
	while(curr!=NULL)
	{
		next=curr->next;
		curr->next=prev;
		prev=curr;
		curr=next;
	}
	plist=prev;
	return plist;
}
int count(struct Paramstruct *plist)
{
	struct Paramstruct *temp;
	temp=plist;
	int l=0;
	while(temp!=NULL)
	{
		l++;
		temp=temp->next;
	}
	return l;
}

struct Paramstruct *copylist(struct Paramstruct *plist)
{
	struct Paramstruct *temp_head=NULL,*temp_tail=NULL;
	struct Paramstruct *dummy,*x;
	dummy=plist;
	while(dummy!=NULL)
	{
		x=create_param_node(dummy->name,dummy->type);
		if(temp_head==NULL)
		{
			temp_head=x;
			temp_tail=x;
		}
		else
		{
			temp_tail->next=x;
			temp_tail=x;
		}
		dummy=dummy->next;

	}
	return temp_head;


}
