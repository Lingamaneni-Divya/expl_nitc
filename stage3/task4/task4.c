#include<stdlib.h>
#include<stdio.h>
#include<string.h>
int var[26];
int yyerror(char const *s);
int c=-1;
int label=-1;
struct labelstack *top=NULL,*bottom=NULL;
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
//check this
void print_node(struct tnode *t)
{
	printf("[val:%d type:%d ",t->val,t->type);
	if(t->varname!=NULL)
	printf("varname:%c ",*(t->varname));
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
//check this
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
					//printf("while evaluated:\n");
				}
				return -1;
				break;
				
				
	}
}
int getreg()
{
  c=c+1;
  if(c>=20)
    yyerror("registers exhausted!!\n");
  else
     return c;
}

void freereg()
{
 c--;
}

int getlabel()
{
	label++;	
	return label;
	
}
int codegen(struct tnode *t)
{
	FILE *fp;
	int l,m,r,i,j,buff,data,v;
	switch(t->nodetype)
	{
		case read_node:
			buff=4096+*(t->left->varname)-'a';
			i=scall("Read",-1,buff);
			return i;
			break;
			return -1;
		case write_node:
			l=codegen(t->left);
			freereg();
			i=scall("Write",-2,4121);
			return i;
			break;
			return -1;
		case assg_node:
			r=codegen(t->right);
			v=4096+*(t->left->varname)-'a';
			fp=fopen("task4.xsm","a");
			fprintf(fp,"MOV [%d],R%d\n",v,r);
			fclose(fp);
			freereg();
			printf("%d\n",c);
			return r;
			break;
		case conn_node:

			l=codegen(t->left);
			//freereg();
			l=codegen(t->right);
			//freereg();
			//fclose(fp);
			return l;
			break;
// #
		case const_node:
			i=getreg();
			fp=fopen("task4.xsm","a");
			fprintf(fp,"MOV R%d,%d\n",i,t->val);
			fclose(fp);
			return i;
			break;
//#
		case var_node:
			v=4096+*(t->varname)-'a';
			i=getreg();
			fp=fopen("task4.xsm","a");
			fprintf(fp,"MOV R%d,[%d]\n",i,v);
			fclose(fp);
			return i;
			break;

//#
		case aop_node:
			l=codegen(t->left);
			r=codegen(t->right);
			switch(*(t->varname))
			{
				case '+':
					fp=fopen("task4.xsm","a");
					fprintf(fp,"ADD R%d,R%d\n",l,r);
					fclose(fp);
					freereg();
					break;
				case '-':
					fp=fopen("task4.xsm","a");
					fprintf(fp,"SUB R%d,R%d\n",l,r);
					fclose(fp);
					freereg();
					break;
				case '*':
					fp=fopen("task4.xsm","a");
					fprintf(fp,"MUL R%d,R%d\n",l,r);
					fclose(fp);
					freereg();
					break;
				case '/':
					fp=fopen("task4.xsm","a");
					fprintf(fp,"DIV R%d,R%d\n",l,r);
					fclose(fp);
					freereg();
					break;
			}
			return l;
			break;
		case lop_node:
				l=codegen(t->left);
				r=codegen(t->right);
				if(strcmp(t->varname,">=")==0)
				{ 
					fp=fopen("task4.xsm","a");
					fprintf(fp,"GE R%d,R%d\n",l,r);
					fclose(fp);
					freereg();
				}
				else if(strcmp(t->varname,"<=")==0)
				{ 
					fp=fopen("task4.xsm","a");
					fprintf(fp,"LE R%d,R%d\n",l,r);
					fclose(fp);
					freereg();
				}
				else if(strcmp(t->varname,">")==0)
				{ 
					fp=fopen("task4.xsm","a");
					fprintf(fp,"GT R%d,R%d\n",l,r);
					fclose(fp);
					freereg();
				}
				else if(strcmp(t->varname,"<")==0)
				{ 
					fp=fopen("task4.xsm","a");
					fprintf(fp,"LT R%d,R%d\n",l,r);
					fclose(fp);
					freereg();
				}
				else if(strcmp(t->varname,"==")==0)
				{ 
					fp=fopen("task4.xsm","a");
					fprintf(fp,"EQ R%d,R%d\n",l,r);
					fclose(fp);
					freereg();
				}
				else if(strcmp(t->varname,"!=")==0)
				{ 
					fp=fopen("task4.xsm","a");
					fprintf(fp,"NE R%d,R%d\n",l,r);
					fclose(fp);
					freereg();
				}
				return l;
				break;
		
		case if_node:
				{	
					l=codegen(t->left);
					freereg();
					
					i=getlabel();
					fp=fopen("task4.xsm","a");
					fprintf(fp,"JZ R%d,L%d\n",l,i);
					fclose(fp);
					m=codegen(t->middle);
					if(t->right!=NULL)
					{
						j=getlabel();
						fp=fopen("task4.xsm","a");
						fprintf(fp,"JMP L%d\n",j);//jump without executing else after executing if 
						fprintf(fp,"L%d:\n",i);//generating code for else part					
						//printf("else start L%d:\n",i);
						fclose(fp);
						r=codegen(t->right);
						fp=fopen("task4.xsm","a");
						fprintf(fp,"L%d:\n",j);//for next code
						//printf("end if L%d:\n",j);
						fclose(fp);
						return l;
						break;
					}
					else
					{
						
						fp=fopen("task4.xsm","a");
						fprintf(fp,"L%d:\n",i);//for next code
						//printf("end if L%d:\n",i);
						fclose(fp);
						return l;
						break;	

					}
					
					

				}
		case while_node:
				{
					i=getlabel();
					fp=fopen("task4.xsm","a");
					fprintf(fp,"L%d:\n",i);
					//printf("while start L%d:\n",i);
					fclose(fp);

					pushstack(i);
					l=codegen(t->left);
					freereg();
					j=getlabel();
					fp=fopen("task4.xsm","a");
					fprintf(fp,"JZ R%d,L%d\n",l,j);
					fclose(fp);
					r=codegen(t->right);
					fp=fopen("task4.xsm","a");
					fprintf(fp,"JMP L%d\n",i);
					fprintf(fp,"L%d:\n",j);
					//printf("while end L%d:\n",j);
					fclose(fp);
					popstack();
					
					return l;
					break;
				}
		case continue_node:
				if(top!=NULL)
				{
				 	fp=fopen("task4.xsm","a");
					fprintf(fp,"JMP L%d\n",top->val);
					fclose(fp);
				}
				return -1;
				break;
		case break_node:
				if(top!=NULL)
				{
					fp=fopen("task4.xsm","a");
					fprintf(fp,"JMP L%d\n",(top->val)+1);
					fclose(fp);

				}

	}

}
int scall(char *fcode,int arg1, int arg2)
{
	FILE *fp;
 	int r,i,j;
  
  if(strcmp("Write",fcode)==0)
   {
	fp=fopen("task4.xsm","a");
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
	fp=fopen("task4.xsm","a");
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
	fp=fopen("task4.xsm","a");    	
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


void insertlabel(int labelnum)
	{
		struct labeltable *temp=(struct labeltable*)malloc(sizeof(struct labeltable));
		temp->val=labelnum;
		temp->address=2048+2*(instcnt);
		temp->next=NULL;
		if(head==NULL)
		{
			head=temp;
			tail=temp;
		}
		else
		{
			tail->next=temp;
			tail=temp;
		}

	}
	void printtable()
	{
		struct labeltable *temp=head;
		while(temp!=NULL)
		{
			printf("%d:%d\n",temp->val,temp->address);
			temp=temp->next;
		}
	}
	int searchlabel(int labelnum)
	{
		struct labeltable *temp=head;
		while(temp!=NULL)
		{
			if(temp->val==labelnum)
			{
				return temp->address;
			}
			else
			{
				temp=temp->next;
			}
		}
	}


void pushstack(int num)
{
	struct labelstack *temp=(struct labelstack *)malloc(sizeof(struct labelstack));
	temp->val=num;
	temp->next=NULL;
	if(bottom==NULL)
	{
		bottom=temp;
		top=temp;
	}
	else
	{
		top->next=temp;
		top=temp;
	}
}

void popstack()
{
	struct labelstack *temp=bottom;
	struct labelstack *prev;
	while(temp!=top)
	{
		prev=temp;
		temp=temp->next;
	}
	top=prev;
	free(temp);
}
