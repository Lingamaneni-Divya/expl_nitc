#include<stdio.h>
#include<string.h>
int yyerror(char const *s);
int c=-1;
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

int getreg()
{
  c++;
  if(c>20)
    yyerror("registers exhausted!!\n");
  else
     return c;
}

void freereg()
{
 c--;
}

int codegen(struct tnode*t)
{
  FILE *fp =fopen("ex_2.xsm","a");
  int r,i,j;
  if(t->op==NULL)
   {
	r=getreg();
	fprintf(fp,"MOV R%d,%d\n",r,t->val);
	fclose(fp);
	return r;
    }
  else
    {
      i=codegen(t->left);
      j=codegen(t->right);
      switch(*(t->op))
      {
       	case '+':
		 { fprintf(fp,"ADD R%d,R%d\n",i,j);
      		  
  		   break;}
	case '-':
		  {fprintf(fp,"SUB R%d,R%d\n",i,j);
      		  
  		   break;}
        case '*':
		  {fprintf(fp,"MUL R%d,R%d\n",i,j);
      		  
  		   break;}
       case '/':
		  {fprintf(fp,"DIV R%d,R%d\n",i,j);
      		  
  		   break;}
      }
     		  freereg();
       		  fclose(fp);
      		  return i;
      }

}


void scall(char *fcode,int arg1,int arg2)
{
  FILE *fp=fopen("ex_2.xsm","a");
  int r,i,j;
  
  if(strcmp("Write",fcode)==0)
   {
     r=getreg();
     fprintf(fp,"MOV [%d],R%d\n",arg2,r);
     fprintf(fp,"MOV R%d,\"%s\"\n",r,fcode);
     fprintf(fp,"PUSH R%d\n",r);
     fprintf(fp,"MOV R%d,%d\n",r,arg1);
     fprintf(fp,"PUSH R%d\n",r);
     i=getreg();
     fprintf(fp,"MOV R%d,[%d]\n",i,arg2);
     fprintf(fp,"PUSH R%d\n",i);
     freereg();
     fprintf(fp,"PUSH R%d\n",r);
     fprintf(fp,"PUSH R%d\n",r);
     fprintf(fp,"CALL 0\n");
     i=getreg();
     fprintf(fp,"POP R%d\n",i);
     fprintf(fp,"POP R%d\n",r);
     fprintf(fp,"POP R%d\n",r);
     fprintf(fp,"POP R%d\n",r);
     fprintf(fp,"POP R%d\n",r);
     freereg();
     freereg();
     fclose(fp);
    }
   else if(strcmp("Read",fcode)==0)
   {
     r=getreg();
     fprintf(fp,"MOV R%d,\"%s\"\n",r,fcode);
     fprintf(fp,"PUSH R%d\n",r);
     fprintf(fp,"MOV R%d,%d\n",r,arg1);
     fprintf(fp,"PUSH R%d\n",r);
     i=getreg();
     fprintf(fp,"MOV R%d,%d\n",i,arg2);
     fprintf(fp,"PUSH R%d\n",i);
     freereg();
     fprintf(fp,"PUSH R%d\n",r);
     fprintf(fp,"PUSH R%d\n",r);
     fprintf(fp,"CALL 0\n");
     i=getreg();
     fprintf(fp,"POP R%d\n",i);
     fprintf(fp,"POP R%d\n",r);
     fprintf(fp,"POP R%d\n",r);
     fprintf(fp,"POP R%d\n",r);
     fprintf(fp,"POP R%d\n",r);
     freereg();
     freereg();
     fclose(fp);
    }
   else if(strcmp("Exit",fcode)==0)
   {
     r=getreg();
     fprintf(fp,"MOV R%d,\"%s\"\n",r,fcode);
     fprintf(fp,"PUSH R%d\n",r);
     fprintf(fp,"PUSH R%d\n",r);
     fprintf(fp,"PUSH R%d\n",r);
     fprintf(fp,"PUSH R%d\n",r);
     fprintf(fp,"PUSH R%d\n",r);
     fprintf(fp,"CALL 0\n");
     i=getreg();
     fprintf(fp,"POP R%d\n",i);
     fprintf(fp,"POP R%d\n",r);
     fprintf(fp,"POP R%d\n",r);
     fprintf(fp,"POP R%d\n",r);
     fprintf(fp,"POP R%d\n",r);
     freereg();
     freereg();
     fclose(fp);
    }
 }
