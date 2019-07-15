#include<string.h>
#include<stdlib.h>

int sp=4096;
int flabel=-1;
int yyerror(char const *s);
struct Gsymbol *Gsymbol_table_head=NULL,*Gsymbol_table_tail=NULL;
struct Lsymbol *Lsymbol_table_head=NULL,*Lsymbol_table_tail=NULL;
int local_binding=0;
char func_name[100];

void GInstall(char *name,int type,int size,struct Paramstruct *paramlist)
{
	struct Gsymbol *temp ,*newnode;
	if(GLookup(name)!=NULL)
	{
		printf("variable %s redefined!!\n",name);
		exit(1);
	}
	
	if(type==nulltype)
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
struct Paramstruct *create_param_node(char *name,int type)
{
	struct Paramstruct *newnode;
	newnode=(struct Paramstruct *)malloc(sizeof(struct Paramstruct));
	newnode->name=(char *)malloc((strlen(name)+2)*sizeof(char));
	strcpy(newnode->name,name);
	newnode->type=type;
	newnode->next=NULL;
	return newnode;
	
}

struct Paramstruct *PInstall(struct Paramstruct *Paramlist,struct Paramstruct *Param)
{
	struct Paramstruct *temp;
	if(Paramlist==NULL)
	{
		Paramlist=Param;
	}
	else
	{	
		if(PLookup(Paramlist,Param->name)!=NULL)
		{
			printf("parameter %s redefined is same function defnition!!\n",Param->name);
			exit(1);
		}
		else
		{
		temp=Paramlist;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=Param;
		}
		
	}

	return Paramlist;
}

struct Paramstruct *PLookup(struct Paramstruct *Paramlist,char *pname)
{
	struct Paramstruct *temp;
	temp=Paramlist;
	while(temp!=NULL)
	{
		if(temp->name==pname)
			return temp;
		temp=temp->next;
	}
	return NULL;
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
			printf("%s\t\t\t%d\t%d\t%d\t%d\tNULL\t\n",temp->name,temp->type,temp->size,temp->binding,temp->flabel);
		}
		else
		{
			printf("%s\t\t\t%d\t%d\t%d\t%d\t\t\t\n",temp->name,temp->type,temp->size,temp->binding,temp->flabel);
			printf("\nPARAMLIST FOR %s FUNCTION\n",temp->name);
			printf("-----------------------------------\n");
			print_paramlist(temp->paramlist);
			
		}
		temp=temp->next;
	}


}	

void print_paramlist(struct Paramstruct *paramlist)
{
	struct Paramstruct *temp;
	temp=paramlist;
	printf("Name\t\t\tType\t\n");
	printf("------------------------------\n");
	
	while(temp!=NULL)
	{
		printf("%s\t\t\t%d\t\n",temp->name,temp->type);
		temp=temp->next;
	}
	printf("------------------------------\n\n");
}



struct tnode* create_tree(int val,int type,char *varname,int node_type,struct tnode*l,struct tnode *m,struct tnode *r)
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
	typecheck(newnode);
	return newnode;
}

struct Typenode *create_typenode(int type)
{
   struct Typenode *newnode=(struct Typenode *) malloc(sizeof(struct Typenode));
   newnode->type=type;
   return newnode;
}

void name_equivalence(int function_rettype,char *function_name,struct Paramstruct *paramlist)
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
		   printf("Pptype:%d,Gptype:%d\n",plist->type,temp->type);
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
	while(temp!=NULL)
	{
		local_binding--;
		temp=temp->next;
	}
	temp=paramlist;
	while(temp!=NULL)
	{
	 LInstall(temp->name,temp->type);
	 temp=temp->next;
	}

}


void LInstall(char *name,int type)
{
	struct Lsymbol *temp ,*newnode;
	if(LLookup(name)!=NULL)
	{
		printf("variable %s redefined in Local scope!!\n",name);
		exit(1);
	}
	
	if(type==nulltype)
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
	local_binding=0;
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
		printf("%s\t\t\t%d\t%d\t\n",temp->name,temp->type,temp->binding);
		temp=temp->next;
	}
}

void typecheck(struct tnode *t)
{
	struct Lsymbol *local;
	struct Gsymbol *global;
	struct Paramstruct *param;

	switch(t->nodetype)
	{
		case read_node:
			  	break;
		case write_node:
			      	if((t->left->type!=inttype)&&(t->left->type!=strtype))
				{
				printf("Type Mismatch:	Invalid argument type to Write() function\n");
printf("Write Expects: (an expression which evaluates to integer )OR (a string type constant or variable )\n");
					exit(1);
				}
				break;
		case assg_node:
				if(t->left->type!=t->right->type)
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
			     	if((t->left->type!=inttype)||(t->right->type!=inttype))
				{
				  printf("Type Mismatch:Expected Integer on both sides of arithmetic operator\n");
				exit(1);
				}
				break;
		case lop_node:
				if(strcmp(t->varname,"&&")&&strcmp(t->varname,"||")&&strcmp(t->varname,"!"))
				if((t->left->type!=inttype)||(t->right->type!=inttype))
				{
				  printf("Type Mismatch:Expected Integer on both sides of logical operator\n");
				  exit(1);
				}
				break;
		case if_node:
				if(t->left->type!=booltype)
				{
					printf("Invalid expression inside if\n");
					exit(1);
				}
				break;
		case while_node:
				if(t->left->type!=booltype)
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
	printf("Function %s expects type %d but here return type is %d\n",t->varname,global->type,t->left->type);
				exit(1);

					}
				}
				break;
	}
}

void argcheck(char *function_name,struct tnode *t)
{
	struct Gsymbol *dummy;
	struct Paramstruct *temp;
	struct tnode *parglist;
	int arg_count=0;
	dummy=GLookup(function_name);
	if(temp==NULL)
	{
		printf("Usage of Function %s without any previous declaration\n",function_name);
		exit(1);
	}
	temp=dummy->paramlist;
	parglist=t;
	while(parglist!=NULL)
	{
		arg_count++;
		if(temp==NULL)
		{
		   printf("Too many arguments int the Function call for %s\n",function_name);
		   exit(1);
		}
		else if(parglist->type!=temp->type)
		{
     printf("Parameter Type Mistmatch at Argument %d of Function %s\n",arg_count,function_name);
			printf("Pptype:%d,Gptype:%d",parglist->type,temp->type);
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
	printf("[val:%d type:%d ",t->val,t->type);
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
	case 14:
	printf("arr_node ");
	case 15:
	printf("func_node ");
	case 16:
	printf("ret_node ");
	}
	if(t->Gentry!=NULL)
	{
		 printf("binding:%d ",t->Gentry->binding);
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

