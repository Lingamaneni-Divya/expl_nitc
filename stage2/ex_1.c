#include<stdio.h>
int var[26];

struct tnode* create_tree(int val,int type,char* varname,int nodetype,struct tnode *l,struct tnode *r)
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
	temp->right=r;
	return temp;
}
void print_node(struct tnode *t)
{
	printf("[val:%d type:%d ",t->val,t->type);
	if(t->varname!=NULL)
	printf("varname:%c ",*t->varname);
	switch(t->nodetype)
	{
  	case 1:
    	printf("op_node ");
    	break;
    	case 2:
    	printf("assg_node ");
   	break;
    	case 3:
    	printf("conn_node ");
    	break;
    	case 4:
    	printf("const_node ");
   	break;
    	case 5:
  	printf("read_node ");
  	break;
    	case 6:
    	printf("var_node ");
   	break;
    	case 7:
    	printf("write_node ");
    	break; 
	}
	printf("]\n");
}

void inorder(struct tnode *t)
{
	if(t==NULL)
	return;
	inorder(t->left);
	print_node(t);
	inorder(t->right);

}

int evaluate(struct tnode *t)
{
	int v,l,r,ret;	
	switch(t->nodetype)
	{

		case conn_node:

			l=evaluate(t->left);
			l=evaluate(t->right);
			return l;
			break;
		case read_node:
			v=*(t->left->varname)-'a';
			ret=scanf("%d",&var[v]);
			return ret;
			break;
		case assg_node:
			r=evaluate(t->right);
			v=*(t->left->varname)-'a';
			var[v]=r;
			return var[v];
			break;
//#
		case var_node:
			v=*(t->varname)-'a';
			return var[v];
			break;
// #
		case const_node:
			return t->val;
			break;
		case write_node:
			r=evaluate(t->left);
			printf("%d\n",r);
			return r;
			break;
//#
		case op_node:
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
	}

}
