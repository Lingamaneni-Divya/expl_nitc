#include<stdio.h>
struct tnode* makeLeafNode(int n)
{
	struct tnode *temp;
	temp = (struct tnode*)malloc(sizeof(struct tnode));
	temp->op = NULL;
	temp->val = n;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}
	
struct tnode* makeOperatorNode(char c,struct tnode *l,struct tnode *r)
{
	struct tnode *temp;
	temp = (struct tnode*)malloc(sizeof(struct tnode));
	temp->op = malloc(sizeof(char));
	*(temp->op) = c;
	temp->left = l;
	temp->right = r;
	return temp;
}
	
void postfix(struct tnode *t)
{
	if(t->left!=NULL)
		postfix(t->left);
	if(t->right!=NULL)
		postfix(t->right);
        if(t->op==NULL)
		printf("%d ",t->val);
	else
		printf("%c ",*(t->op));
}

void prefix(struct tnode *t)
{
	if(t->op==NULL)
		printf("%d ",t->val);
	else
		printf("%c ",*(t->op));
	if(t->left!=NULL)
		prefix(t->left);
	if(t->right!=NULL)
		prefix(t->right);
}


