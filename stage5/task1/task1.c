#include<string.h>
#include<stdlib.h>

int sp=4096;
int flabel=-1;
int yyerror(char const *s);
struct Gsymbol *Gsymbol_table_head=NULL,*Gsymbol_table_tail=NULL;

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
	//typecheck(newnode);
	return newnode;
}
