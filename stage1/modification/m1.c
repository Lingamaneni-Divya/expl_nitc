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
	
int evaluate(struct tnode *t)
{
	if(t->op == NULL)
	{
	return t->val;
	}
	else
	{
		switch(*(t->op))
		{
		case '+' : return evaluate(t->left) + evaluate(t->right);
		break;
		case '-' : return evaluate(t->left) - evaluate(t->right);
		break;
		case '*' : return evaluate(t->left) * evaluate(t->right);
		break;
		case '/' : return evaluate(t->left) / evaluate(t->right);
		break;
		}
	}
}
int evaluatesquare(struct tnode *t)
{
        int i,j;
	if(t->op == NULL)
	{
	return t->val*t->val;
	}
	else
	{
		switch(*(t->op))
		{
                   
		case '+' : return evaluatesquare(t->left) + evaluatesquare(t->right);
		break;
		case '-' : return evaluatesquare(t->left)- evaluatesquare(t->right);
		break;
		case '*' : return evaluatesquare(t->left) * evaluatesquare(t->right);
		break;
		case '/' : return evaluatesquare(t->left) / evaluatesquare(t->right);
		break;

		}
	}
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

