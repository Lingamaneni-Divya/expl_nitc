#include<string.h>
#include<stdlib.h>
int sp=4096;

struct Gsymbol *symbol_table_bottom=NULL,*symbol_table_top=NULL;
void Install(char *name,int type,int size)
{
	struct Gsymbol *temp,*newnode;
	if(Lookup(name)!=NULL)
	{
		printf("variable %s redefined!!\n",name);
		exit(1);
	}

	if (type==nulltype)
	{
		printf("undefined type for variable %s\n",name);
	}

	newnode=(struct Gsymbol *)malloc(sizeof(struct Gsymbol));
	newnode->name=(char *)malloc((strlen(name)+2)*sizeof(char));
	strcpy(newnode->name,name);
	newnode->type=type;
	newnode->size=size;
	newnode->next=NULL;
	newnode->binding=sp;
	if(symbol_table_bottom==NULL)
	{
          symbol_table_bottom=newnode;
	  symbol_table_top=newnode;
	}
	else
	{
	  symbol_table_top->next=newnode;
	  symbol_table_top=newnode;
	}
	sp=sp+size;
}

struct Gsymbol *Lookup(char *name)
{
	struct Gsymbol *temp=symbol_table_bottom;
	while(temp!=NULL)
	{
		if(strcmp(name,temp->name)==0)
		{
			return temp;
		}
		temp=temp->next;
	}
	return NULL;
}


void print_symbol_table()
{
	struct Gsymbol *temp=symbol_table_bottom;
	printf("Name\tType\tSize\tBinding\n");
	printf("-------------------------------\n");
	
	while(temp!=NULL)
	{
		printf("%s\t%d\t%d\t%d\n",temp->name,temp->type,temp->size,temp->binding);
		temp=temp->next;
	}
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

void typecheck(struct tnode *t)
{
	struct Gsymbol *temp;
	switch(t->nodetype)
	{
		case read_node:		
			     break;
		case write_node:
			      	if((t->left->type!=inttype)&&(t->left->type!=strtype))
				{
					printf("Type Mismatch:	Invalid argument type to Write() function\n");
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
				if(declflag==0)
				{
					temp=Lookup(t->varname);
					if(temp==NULL)
					{
				  	printf("Variable:%s Undeclared\n",t->varname);
				 	 exit(1);
					}
					t->type=temp->type;
					t->Gentry=temp;
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
	}
}
void print_node(struct tnode *t)
{
	printf("[val:%d type:%d ",t->val,t->type);
	if(t->varname!=NULL)
	printf("varname:%s ",t->varname);
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
  	printf("const_node ");
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
	printf("break_node ");
	break;
	case 12:
	printf("continue_node ");
	break;
	case 13:
	printf("sconst_node ");
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
	print_node(t);
	preorder(t->left);
	preorder(t->middle);
	preorder(t->right);

}
