#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int yyerror(char const *s);
int c=-1;

struct tnode* create_tree(int val,int type,char*varname,int nodetype,struct tnode *l,struct tnode *r)
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
void preorder(struct tnode *t)
{
	if(t==NULL)
	return;
	print_node(t);
	preorder(t->left);
	
	preorder(t->right);

}
int getreg()
{
  c=c+1;
  if(c>20)
    yyerror("registers exhausted!!\n");
  else
     return c;
}

void freereg()
{
 c--;
}

int codegen(struct tnode *t)
{
	FILE *fp;
	fp=fopen("task2.xsm","a");
	int l,r,i,j,buff,data,v;
	switch(t->nodetype)
	{

		case conn_node:

			l=codegen(t->left);
			//freereg();
			l=codegen(t->right);
			//freereg();
			fclose(fp);
			return l;
			break;
		case read_node:
			buff=4096+*(t->left->varname)-'a';
			i=scall("Read",-1,buff);
			fclose(fp);
			return i;
			break;
		case assg_node:
			r=codegen(t->right);
			v=4096+*(t->left->varname)-'a';
			fprintf(fp,"MOV [%d],R%d\n",v,r);
			fclose(fp);
			freereg();
			printf("%d\n",c);
			return r;
			break;
//#
		case var_node:
			v=4096+*(t->varname)-'a';
			i=getreg();
			fprintf(fp,"MOV R%d,[%d]\n",i,v);
			fclose(fp);
			return i;
			break;
// #
		case const_node:
			i=getreg();
			fprintf(fp,"MOV R%d,%d\n",i,t->val);
			fclose(fp);
			return i;
			break;
		case write_node:
			r=codegen(t->left);
			freereg();
			i=scall("Write",-2,4121);
			fclose(fp);
			return i;
			break;
//#
		case op_node:
			l=codegen(t->left);
			r=codegen(t->right);
			switch(*(t->varname))
			{
				case '+':
					fprintf(fp,"ADD R%d,R%d\n",l,r);
					fclose(fp);
					freereg();
					break;
				case '-':
					fprintf(fp,"SUB R%d,R%d\n",l,r);
					fclose(fp);
					freereg();
					break;
				case '*':
					fprintf(fp,"MUL R%d,R%d\n",l,r);
					fclose(fp);
					freereg();
					break;
				case '/':
					fprintf(fp,"DIV R%d,R%d\n",l,r);
					fclose(fp);
					freereg();
					break;
			}
			return l;
			break;
	}

}
int scall(char *fcode,int arg1, int arg2)
{
	FILE *fp=fopen("task2.xsm","a");
 	int r,i,j;
  
  if(strcmp("Write",fcode)==0)
   {
	i=getreg();
	fprintf(fp,"MOV [%d],R%d\n",arg2,i);
     	fprintf(fp,"MOV R%d,\"%s\"\n",i,fcode);
     	fprintf(fp,"PUSH R%d\n",i);
     
     	fprintf(fp,"MOV R%d,%d\n",i,arg1);
     	fprintf(fp,"PUSH R%d\n",i);
     
     	fprintf(fp,"MOV R%d,[%d]\n",i,arg2);
     	fprintf(fp,"PUSH R%d\n",i);
   
	j=getreg();
     	fprintf(fp,"PUSH R%d\n",j);
     	fprintf(fp,"PUSH R%d\n",j);
     	fprintf(fp,"CALL 0\n");
	freereg();
    	
	fprintf(fp,"POP R%d\n",i);

	j=getreg();
     	fprintf(fp,"POP R%d\n",j);
     	fprintf(fp,"POP R%d\n",j);
     	fprintf(fp,"POP R%d\n",j);
     	fprintf(fp,"POP R%d\n",j);
     	freereg();
     
	freereg();
	fclose(fp);
	return i;
    }
   else if(strcmp("Read",fcode)==0)
   {
     	i=getreg();
     	fprintf(fp,"MOV R%d,\"%s\"\n",i,fcode);
     	fprintf(fp,"PUSH R%d\n",i);

     	fprintf(fp,"MOV R%d,%d\n",i,arg1);
     	fprintf(fp,"PUSH R%d\n",i);

     	fprintf(fp,"MOV R%d,%d\n",i,arg2);
     	fprintf(fp,"PUSH R%d\n",i);
	
	j=getreg();
     	fprintf(fp,"PUSH R%d\n",j);
     	fprintf(fp,"PUSH R%d\n",j);
     	fprintf(fp,"CALL 0\n");
	freereg();
	
     	fprintf(fp,"POP R%d\n",i);

	j=getreg();
     	fprintf(fp,"POP R%d\n",j);
     	fprintf(fp,"POP R%d\n",j);
     	fprintf(fp,"POP R%d\n",j);
     	fprintf(fp,"POP R%d\n",j);
     	freereg();

     	freereg();
     	fclose(fp);
	return i;
    }
   else if(strcmp("Exit",fcode)==0)
   {
     	i=getreg();
     	fprintf(fp,"MOV R%d,\"%s\"\n",i,fcode);
	fprintf(fp,"PUSH R%d\n",i);
     	j=getreg();
     	fprintf(fp,"PUSH R%d\n",j);
     	fprintf(fp,"PUSH R%d\n",j);
     	fprintf(fp,"PUSH R%d\n",j);
     	fprintf(fp,"PUSH R%d\n",j);
     	fprintf(fp,"CALL 0\n");
     	freereg();

     	fprintf(fp,"POP R%d\n",i);
     	j=getreg();
     	fprintf(fp,"POP R%d\n",j);
     	fprintf(fp,"POP R%d\n",j);
     	fprintf(fp,"POP R%d\n",j);
     	fprintf(fp,"POP R%d\n",j);
     	freereg();

     	freereg();
     	fclose(fp);
     	return i;
    }
	

}

