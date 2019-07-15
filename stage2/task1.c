/*smile please🤗😁😁*/

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
