#include<stdlib.h>
#include<stdio.h>
#include<string.h>
int var[26];
struct tnode* create_tree(int val,int type,char *varname,int nodetype,struct tnode *l,struct tnode *m,struct tnode *r)
{
	struct tnode *temp;
	temp=(struct tnode*)malloc(sizeof(struct tnode));
	temp->val=val;
	temp->type=type;
	if(varname!=NULL)
   	{
    		temp->varname=(char*)malloc(sizeof(char));
    		temp->varname=varname;
    	}
	else
	{
		temp->varname=NULL;
	}
	temp->nodetype=nodetype;
	temp->left=l;
	temp->middle=m;
	temp->right=r;
	if((temp->nodetype==if_node||temp->nodetype==while_node)&&(temp->left->type!=booltype))
	{
		printf("type mismatch if and while should contain boolean expression\n");
		exit(1);
	}
	else if((temp->nodetype==read_node||temp->nodetype==write_node)&&(temp->left->type!=inttype))
	{
		printf("type mistmatch read or write node should contain a arithmetic expression\n");
		exit(1);
	}
	else if((temp->nodetype==assg_node)&&(temp->right->type!=inttype))
	{
		printf("type mismatch right side of an assignment node should be a arithmetic expression\n");
		exit(1); 
	}
	else if((temp->nodetype==aop_node)&& !((temp->right->type==inttype)&&(temp->left->type==inttype)))
	{
		printf("type mismatch at arithmetic operator node\n");
		exit(1);
	}
	else
	{
		return temp;
	}
}
void print_node(struct tnode *t)
{
	printf("[val:%d type:%d ",t->val,t->type);
	if(t->varname!=NULL)
	printf("varname:%c ",*t->varname);
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
	}
	printf("]\n");
}

void preorder(struct tnode *t)
{
	if(t==NULL)
	return;
	print_node(t);
	preorder(t->left);
	preorder(t->middle);
	preorder(t->right);

}

int evaluate(struct tnode *t)
{
	int l,m,r,v,temp;
	switch(t->nodetype)
	{
		case read_node:
				v=*(t->left->varname)-'a';
				scanf("%d",&temp);
				var[v]=temp;
				return -1;
				break;
		case write_node:
				l=evaluate(t->left);
				printf("%d\n",l);
				return -1;
				break;
		case assg_node:
				r=evaluate(t->right);
				v=*(t->left->varname)-'a';
				var[v]=r;
				return -1;
				break;
		case conn_node:
				l=evaluate(t->left);
				r=evaluate(t->right);
				return -1;
				break;
		case const_node:
				return t->val;
				break;
		case var_node:
				v=*(t->varname)-'a';
				return var[v];
				break;
		case aop_node:
				l=evaluate(t->left);
				r=evaluate(t->right);
				switch(*(t->varname))
				{
					case '+':
						 return l+r;
						 break;
					case '-':
						 return l-r;
						 break;
					case '*':
						 return l*r;
						 break;
					case '/':
						 return l/r;
						 break;
					
				}
				break;
	   	case lop_node:
				l=evaluate(t->left);
				r=evaluate(t->right);
				if(strcmp(t->varname,">=")==0)
				{ 
					if(l>=r)
						return 1;
					else
						return 0;
				}
				else if(strcmp(t->varname,"<=")==0)
				{ 
					if(l<=r)
						return 1;
					else
						return 0;
				}
				else if(strcmp(t->varname,">")==0)
				{ 
					if(l>r)
						return 1;
					else
						return 0;
				}
				else if(strcmp(t->varname,"<")==0)
				{ 
					if(l<r)
						return 1;
					else
						return 0;
				}
				else if(strcmp(t->varname,"==")==0)
				{ 
					if(l==r)
						return 1;
					else
						return 0;
				}
				else if(strcmp(t->varname,"!=")==0)
				{ 
					if(l!=r)
						return 1;
					else
						return 0;
				}
				break;
		case if_node:
				l=evaluate(t->left);
				
				
				if(l==1)
				{
					m=evaluate(t->middle);
					//printf("then evaluated:\n");
					return -1;
				}
				else
				{
					r=evaluate(t->right);
					//printf("else evaluated:\n");
					return -1;
				}
				break;
	       case while_node:
				//l=evaluate(t->left);
			        while(evaluate(t->left)!=0)
				{
					r=evaluate(t->right);
					printf("while evaluated:\n");
				}
				return -1;
				break;
				
				
	}
}
