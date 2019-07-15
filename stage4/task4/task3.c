#include<string.h>
#include<stdlib.h>

int sp=4096;
int yyerror(char const *s);
int c=-1;
int label=-1;
int instcnt;
struct labelstack *label_stack_top=NULL,*label_stack_bottom=NULL;
struct Gsymbol *symbol_table_bottom=NULL,*symbol_table_top=NULL;
struct labeltable *label_table_head=NULL,*label_table_tail=NULL;
void Install(char *name,int type,int size)
{
	struct Gsymbol *temp,*newnode;
	if(Lookup(name)!=NULL)
	{
		printf("variable %s redefined!!\n",name);
		exit(1);
	}

	if (type==nulltype)
	{
		printf("undefined type for variable %s\n",name);
	}

	newnode=(struct Gsymbol *)malloc(sizeof(struct Gsymbol));
	newnode->name=(char *)malloc((strlen(name)+2)*sizeof(char));
	strcpy(newnode->name,name);
	newnode->type=type;
	newnode->size=size;
	newnode->next=NULL;
	newnode->binding=sp;
	if(symbol_table_bottom==NULL)
	{
          symbol_table_bottom=newnode;
	  symbol_table_top=newnode;
	}
	else
	{
	  symbol_table_top->next=newnode;
	  symbol_table_top=newnode;
	}
	sp=sp+size;
}

struct Gsymbol *Lookup(char *name)
{
	struct Gsymbol *temp=symbol_table_bottom;
	while(temp!=NULL)
	{
		if(strcmp(name,temp->name)==0)
		{
			return temp;
		}
		temp=temp->next;
	}
	return NULL;
}


void print_symbol_table()
{
	struct Gsymbol *temp=symbol_table_bottom;
	printf("Name\tType\tSize\tBinding\n");
	printf("-------------------------------\n");
	
	while(temp!=NULL)
	{
		printf("%s\t%d\t%d\t%d\n",temp->name,temp->type,temp->size,temp->binding);
		temp=temp->next;
	}
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
	typecheck(newnode);
	return newnode;
}

void typecheck(struct tnode *t)
{
	struct Gsymbol *temp;
	switch(t->nodetype)
	{
		case read_node:		
			     break;
		case write_node:
			      	if((t->left->type!=inttype)&&(t->left->type!=strtype))
				{
					printf("Type Mismatch:	Invalid argument type to Write() function\n");
					exit(1);
				}
				break;
		case assg_node:
				if(t->left->type!=t->right->type)
				{
					printf("Type Mismatch:	Type of LHS and RHS of an assignment statement does not Match\n");
					exit(1);
				}
				break;
		case conn_node:
				break;
		case iconst_node:
				break;
		case sconst_node:
				break;
		case var_node:
				if(declflag==0)
				{
					temp=Lookup(t->varname);
					if(temp==NULL)
					{
				  	printf("Variable:%s Undeclared\n",t->varname);
				 	 exit(1);
					}
					t->type=temp->type;
					t->Gentry=temp;
				}
				break;
		case aop_node:
			     	if((t->left->type!=inttype)||(t->right->type!=inttype))
				{
				  printf("Type Mismatch:Expected Integer on both sides of arithmetic operator\n");
				exit(1);
				}
				break;
		case lop_node:
				if((t->left->type!=inttype)||(t->right->type!=inttype))
				{
				  printf("Type Mismatch:Expected Integer on both sides of logical operator\n");
				  exit(1);
				}
				break;
		case if_node:
				if(t->left->type!=booltype)
				{
					printf("Invalid expression inside if\n");
					exit(1);
				}
				break;
		case while_node:
				if(t->left->type!=booltype)
				{
					printf("Invalid expression inside while\n");
					exit(1);
				}
				break;
		case continue_node:
				break;
		case break_node:
				break;
	}
}
void print_node(struct tnode *t)
{
	printf("[val:%d type:%d ",t->val,t->type);
	if(t->varname!=NULL)
	printf("varname:%s ",t->varname);
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
	case 11:
	printf("break_node ");
	break;
	case 12:
	printf("continue_node ");
	break;
	case 13:
	printf("sconst_node ");
	}
	if(t->Gentry!=NULL)
	{
		 printf("binding:%d ",t->Gentry->binding);
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
//arr[10] or num or arr[10][10];
int getaddr(tnode *t)
{
  	int i,j,l;
 	FILE *fp;
	j=t->Gentry->binding;
	printf("addr:%d\n",j);
   	if(t->left)
   	{
 		l=codegen(t->left);
		fp=fopen("task3.xsm","a");
		fprintf(fp,"ADD R%d,%d\n",l,t->Gentry->binding);
		fclose(fp);
		return l;
   	}

	else
	{
	   	i=getreg();
		fp=fopen("task3.xsm","a");
		fprintf(fp,"MOV R%d,%d\n",i,t->Gentry->binding);
		fclose(fp);
		return i;
	}


}

int codegen(struct tnode *t)
{
	FILE *fp;
	int l,m,r,i,j,buff,data,v,n;
	struct Gsymbol *temp;
	switch(t->nodetype)
	{
//#
		case read_node:
			//temp=Lookup(t->left->varname);
			//base=temp->binding;
			//buff=4096+*(t->left->varname)-'a';
			//i=scall("Read",-1,buff);
			buff=getaddr(t->left);
			n=0;
			while(n<=c)
			{
			  fp=fopen("task3.xsm","a");
			  fprintf(fp,"PUSH R%d\n",n);
			  fclose(fp);
			  n++;
			  sp=sp+1;
			}
			i=scall("Read",-1,buff);			
			n=c;
			while(n>=0)
			{
			  fp=fopen("task3.xsm","a");
			  fprintf(fp,"POP R%d\n",n);
			  fclose(fp);
			  n--;
			  sp=sp-1;

			}
			return i;
			break;
		case write_node:
			l=codegen(t->left);
			freereg();
			n=0;
			while(n<=c)
			{
			  fp=fopen("task3.xsm","a");
			  fprintf(fp,"PUSH R%d\n",n);
			  fclose(fp);
			  n++;
			  sp=sp+1;
			}
			i=scall("Write",-2,l);
			n=c;
			while(n>=0)
			{
			  fp=fopen("task3.xsm","a");
			  fprintf(fp,"POP R%d\n",n);
			  fclose(fp);
			  n--;
			  sp=sp-1;

			}
			return i;
			break;
//#
		case assg_node:
			r=codegen(t->right);
			v=getaddr(t->left);
			//v=4096+*(t->left->varname)-'a';
			fp=fopen("task3.xsm","a");
			fprintf(fp,"MOV [R%d],R%d\n",v,r);
			fclose(fp);
			freereg();
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
		case iconst_node:
			i=getreg();
			fp=fopen("task3.xsm","a");
			fprintf(fp,"MOV R%d,%d\n",i,t->val);
			fclose(fp);
			return i;
			break;
		case sconst_node:
			i=getreg();
			fp=fopen("task3.xsm","a");
			fprintf(fp,"MOV R%d,%s\n",i,t->varname);
			fclose(fp);
			return i;
			break;
//#
		case var_node:
			//temp=Lookup(t->varname);
			//v=temp->binding;
			
			//v=4096+*(t->varname)-'a';
			v=getaddr(t);
			fp=fopen("task3.xsm","a");
			fprintf(fp,"MOV R%d,[R%d]\n",v,v);
			fclose(fp);
			return v;
			break;
		case aop_node:
			l=codegen(t->left);
			r=codegen(t->right);
			switch(*(t->varname))
			{
				case '+':
					fp=fopen("task3.xsm","a");
					fprintf(fp,"ADD R%d,R%d\n",l,r);
					fclose(fp);
					freereg();
					break;
				case '-':
					fp=fopen("task3.xsm","a");
					fprintf(fp,"SUB R%d,R%d\n",l,r);
					fclose(fp);
					freereg();
					break;
				case '*':
					fp=fopen("task3.xsm","a");
					fprintf(fp,"MUL R%d,R%d\n",l,r);
					fclose(fp);
					freereg();
					break;
				case '/':
					fp=fopen("task3.xsm","a");
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
					fp=fopen("task3.xsm","a");
					fprintf(fp,"GE R%d,R%d\n",l,r);
					fclose(fp);
					freereg();
				}
				else if(strcmp(t->varname,"<=")==0)
				{ 
					fp=fopen("task3.xsm","a");
					fprintf(fp,"LE R%d,R%d\n",l,r);
					fclose(fp);
					freereg();
				}
				else if(strcmp(t->varname,">")==0)
				{ 
					fp=fopen("task3.xsm","a");
					fprintf(fp,"GT R%d,R%d\n",l,r);
					fclose(fp);
					freereg();
				}
				else if(strcmp(t->varname,"<")==0)
				{ 
					fp=fopen("task3.xsm","a");
					fprintf(fp,"LT R%d,R%d\n",l,r);
					fclose(fp);
					freereg();
				}
				else if(strcmp(t->varname,"==")==0)
				{ 
					fp=fopen("task3.xsm","a");
					fprintf(fp,"EQ R%d,R%d\n",l,r);
					fclose(fp);
					freereg();
				}
				else if(strcmp(t->varname,"!=")==0)
				{ 
					fp=fopen("task3.xsm","a");
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
					fp=fopen("task3.xsm","a");
					fprintf(fp,"JZ R%d,L%d\n",l,i);
					fclose(fp);
					m=codegen(t->middle);
					if(t->right!=NULL)
					{
						j=getlabel();
						fp=fopen("task3.xsm","a");
						fprintf(fp,"JMP L%d\n",j);//jump without executing else after executing if 
						fprintf(fp,"L%d:\n",i);//generating code for else part					
						//printf("else start L%d:\n",i);
						fclose(fp);
						r=codegen(t->right);
						fp=fopen("task3.xsm","a");
						fprintf(fp,"L%d:\n",j);//for next code
						//printf("end if L%d:\n",j);
						fclose(fp);
						return l;
						break;
					}
					else
					{
						
						fp=fopen("task3.xsm","a");
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
					fp=fopen("task3.xsm","a");
					fprintf(fp,"L%d:\n",i);
					//printf("while start L%d:\n",i);
					fclose(fp);

					push_label_stack(i);
					l=codegen(t->left);
					freereg();
					j=getlabel();
					fp=fopen("task3.xsm","a");
					fprintf(fp,"JZ R%d,L%d\n",l,j);
					fclose(fp);
					r=codegen(t->right);
					fp=fopen("task3.xsm","a");
					fprintf(fp,"JMP L%d\n",i);
					fprintf(fp,"L%d:\n",j);
					//printf("while end L%d:\n",j);
					fclose(fp);
					pop_label_stack();
					
					return l;
					break;
				}
		case continue_node:
				if(label_stack_top!=NULL)
				{
				 	fp=fopen("task3.xsm","a");
					fprintf(fp,"JMP L%d\n",label_stack_top->val);
					fclose(fp);
				}
				return -1;
				break;
		case break_node:
				if(label_stack_top!=NULL)
				{
					fp=fopen("task3.xsm","a");
					fprintf(fp,"JMP L%d\n",(label_stack_top->val)+1);
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
	
	i=getreg();
	fp=fopen("task3.xsm","a");
	fprintf(fp,"MOV [%d],R%d\n",sp,arg2);
     	fprintf(fp,"MOV R%d,\"%s\"\n",i,fcode);
     	fprintf(fp,"PUSH R%d\n",i);
     
     	fprintf(fp,"MOV R%d,%d\n",i,arg1);
     	fprintf(fp,"PUSH R%d\n",i);
     
     	fprintf(fp,"MOV R%d,[%d]\n",i,sp);
     	fprintf(fp,"PUSH R%d\n",i);
   	fclose(fp);
	j=getreg();
	fp=fopen("task3.xsm","a");
     	fprintf(fp,"PUSH R%d\n",j);
     	fprintf(fp,"PUSH R%d\n",j);
     	fprintf(fp,"CALL 0\n");
	fclose(fp);
	freereg();
    	fp=fopen("task3.xsm","a");
	fprintf(fp,"POP R%d\n",i);
	fclose(fp);
	j=getreg();
	fp=fopen("task3.xsm","a");
     	fprintf(fp,"POP R%d\n",j);
     	fprintf(fp,"POP R%d\n",j);
     	fprintf(fp,"POP R%d\n",j);
     	fprintf(fp,"POP R%d\n",j);
	fclose(fp);
     	freereg();
     
	freereg();
	return i;
    }
   else if(strcmp("Read",fcode)==0)
   {
	
     	i=getreg();
	//printf("i:%d\n",i);
	fp=fopen("task3.xsm","a");
     	fprintf(fp,"MOV R%d,\"%s\"\n",i,fcode);
     	fprintf(fp,"PUSH R%d\n",i);

     	fprintf(fp,"MOV R%d,%d\n",i,arg1);
     	fprintf(fp,"PUSH R%d\n",i);

     	//fprintf(fp,"MOV R%d,%d\n",i,arg2);
     	fprintf(fp,"PUSH R%d\n",arg2);
	fclose(fp);
	j=getreg();
	//printf("j:%d\n",j);
	fp=fopen("task3.xsm","a");
     	fprintf(fp,"PUSH R%d\n",j);
     	fprintf(fp,"PUSH R%d\n",j);
     	fprintf(fp,"CALL 0\n");
	fclose(fp);
	freereg();
	fp=fopen("task3.xsm","a");
     	fprintf(fp,"POP R%d\n",i);
	fclose(fp);
	//printf("i:%d\n",i);
	j=getreg();
	//printf("j:%d\n",j);
	fp=fopen("task3.xsm","a");
     	fprintf(fp,"POP R%d\n",j);
     	fprintf(fp,"POP R%d\n",j);
     	fprintf(fp,"POP R%d\n",j);
     	fprintf(fp,"POP R%d\n",j);
	fclose(fp);
     	freereg();
	freereg();
	return i;
    }
   else if(strcmp("Exit",fcode)==0)
   {
	fp=fopen("task3.xsm","a");    	
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


int getlabel()
{
	label++;	
	return label;
	
}

void insertlabel(int labelnum)
	{
		struct labeltable *temp=(struct labeltable*)malloc(sizeof(struct labeltable));
		temp->val=labelnum;
		temp->address=2048+2*(instcnt);
		temp->next=NULL;
		if(label_table_head==NULL)
		{
			label_table_head=temp;
			label_table_tail=temp;
		}
		else
		{
			label_table_tail->next=temp;
			label_table_tail=temp;
		}

	}

void print_label_table()
{
	struct labeltable *temp=label_table_head;
	printf("Label Num\tAddress\n");
	printf("--------------------\n");
	
		
	while(temp!=NULL)
	{
		printf("%d\t\t%d\n",temp->val,temp->address);
		
		temp=temp->next;
	}
}
int searchlabel(int labelnum)
{
	struct labeltable *temp=label_table_head;
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


void push_label_stack(int num)
{
	struct labelstack *temp=(struct labelstack *)malloc(sizeof(struct labelstack));
	temp->val=num;
	temp->next=NULL;
	if(label_stack_bottom==NULL)
	{
		label_stack_bottom=temp;
		label_stack_top=temp;
	}
	else
	{
		label_stack_top->next=temp;
		label_stack_top=temp;
	}
}

void pop_label_stack()
{
	struct labelstack *temp=label_stack_bottom;
	struct labelstack *prev;
	while(temp!=label_stack_top)
	{
		prev=temp;
		temp=temp->next;
	}
	label_stack_top=prev;
	free(temp);
}
