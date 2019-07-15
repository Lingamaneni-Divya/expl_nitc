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
	
void infix(struct tnode *t)
{
	if(t->left!=NULL)
		infix(t->left);
        if(t->op==NULL)
		printf("%d",t->val);
	else
		printf("%c",*(t->op));
	if(t->right!=NULL)
		infix(t->right);
        
}

void infixsquare(struct tnode *t)
{
        if(t->left!=NULL)
		infixsquare(t->left);
	if(t->op==NULL)
		printf("%d*%d",t->val,t->val);
	else
		printf("%c",*(t->op));
	
	if(t->right!=NULL)
		infixsquare(t->right);
}


