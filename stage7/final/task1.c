#include<string.h>
#include<stdlib.h>

int sp=4095;
int sp1=4095;
int flabel=0;
int bodyflag=0;
int declflag=0;
int typedeclflag=0;

struct Gsymbol *Gsymbol_table_head=NULL,*Gsymbol_table_tail=NULL;
struct Lsymbol *Lsymbol_table_head=NULL,*Lsymbol_table_tail=NULL;
struct Paramstruct *paramlist_head=NULL,*paramlist_tail=NULL;
struct Typetable *Typetable_head=NULL,*Typetable_tail=NULL;
struct Fieldlist *fieldlist_head=NULL,*fieldlist_tail=NULL;
struct Classtable *classtable_head=NULL,*classtable_tail=NULL;
struct Classtable *currclass=NULL;
struct Classtable *curr_declclass=NULL;
int class_index=0;

int fieldIndex=1;
int local_binding=1;
char func_name[100];

int label=-1;
int instcnt;
struct labelstack *label_stack_top=NULL,*label_stack_bottom=NULL;
struct labeltable *label_table_head=NULL,*label_table_tail=NULL;


int c=-1;
int yyerror(char const *s)
{
	printf("yyerror %s\n",s);
}

void GInstall(char *name,struct Typetable *type,struct Classtable *ctype,int size,struct Paramstruct *paramlist)
{
	struct Gsymbol *temp ,*newnode;
	if(GLookup(name)!=NULL||CLookup(name)!=NULL)
	{
		printf("variable %s redefined!!\n",name);
		exit(1);
	}
	
	if((type==TLookup("null")||type==NULL)&&ctype==NULL)
	{
		printf("undefined type for variable %s\n",name);
	}
	newnode=(struct Gsymbol *)malloc(sizeof(struct Gsymbol));
	newnode->name=(char *)malloc((strlen(name)+2)*sizeof(char));
	strcpy(newnode->name,name);	
	newnode->type=type;
	newnode->ctype=ctype;
	newnode->size=size;
	newnode->paramlist=paramlist;
	if(newnode->size==-1)
	{
		flabel++;	
		newnode->flabel=flabel;
		newnode->binding=-1;
	}
	else
	{
		newnode->binding=sp+1;
		sp=sp+size;
		sp1=sp1+size;
		newnode->flabel=-1;
	}
	newnode->next=NULL;
	
	if(Gsymbol_table_head==NULL)
	{
		Gsymbol_table_head=newnode;	
		Gsymbol_table_tail=newnode;
	}
	else
	{
		Gsymbol_table_tail->next=newnode;
		Gsymbol_table_tail=newnode;
	}

}
/*DOUBT>>> CAN WE ALLOW int factorial(int n),n in Global declaration??*/
/*May allow Since .....in some program int partition(int low,int high) && int quicksort(int low,int high) are used simultaneously*/
struct Gsymbol *GLookup(char *name)
{
	struct Gsymbol *temp;
	temp=Gsymbol_table_head;

	while(temp!=NULL)
	{
		if(strcmp(name,temp->name)==0)
			return temp;
		temp=temp->next;
	}
	return temp;
} 
struct Paramstruct *create_param_node(char *name,struct Typetable *type)
{
	struct Paramstruct *newnode;
	newnode=(struct Paramstruct *)malloc(sizeof(struct Paramstruct));
	newnode->name=(char *)malloc((strlen(name)+2)*sizeof(char));
	strcpy(newnode->name,name);
	newnode->type=type;
	newnode->next=NULL;
	return newnode;
	
}

void  PInstall(struct Paramstruct *Param)
{
	struct Paramstruct *temp;
	temp=PLookup(Param->name);
	if(temp!=NULL)
	{
	  printf("Parameter:%s redefined in same function defnition",Param->name);
	  exit(1);
	}
	if(paramlist_head==NULL)
	{
		paramlist_head=Param;
		paramlist_tail=Param;
	}
	else
	{
		paramlist_tail->next=Param;
		paramlist_tail=Param;
	}
	
}

struct Paramstruct *PLookup(char *pname)
{
	struct Paramstruct *temp;
	temp=paramlist_head;
	while(temp!=NULL)
	{
		if(strcmp(temp->name,pname)==0)
			break;
		temp=temp->next;
	}
	return temp;
}


void reset_paramlist()
{
	paramlist_head=NULL;
	paramlist_tail=NULL;

}


void print_Gsymbol_table()
{
	struct Gsymbol *temp;
	temp=Gsymbol_table_head;
	
	printf("______________________________________GLOBAL SYMBOL TABLE________________________________________\n");
	printf("NAME\t\t\t|TYPE\t|CTYPE\t|SIZE\t|BINDING\t|PARAMLIST\t|FLABEL\t|\n");
	printf("_________________________________________________________________________________________________\n");
	while(temp!=NULL)
	{
	  	printf("%s\t\t\t|",temp->name);
		if(temp->type==NULL)
		{
			printf("NULL\t|");
		}
		else
		{
			printf("-->%s\t|",temp->type->name);
		}
		if(temp->ctype==NULL)
		{
			printf("NULL\t|");
		}
		else
		{
			printf("-->%s\t|",temp->ctype->name);
		}
		printf("%d\t|",temp->size);
		printf("%d\t|",temp->binding);
		if(temp->paramlist==NULL)
		{
			printf("NULL\t|");
		}	
		else
		{
			printf("--->\t|");
		}
		printf("%d\t|\n",temp->flabel);
		if(temp->paramlist!=NULL)
		{
			printf("__________PARAMLIST FOR FUNCTION %s__________",temp->name);
			print_paramlist(temp->paramlist);
		}
			
		temp=temp->next;
	}
	

}



void print_paramlist(struct Paramstruct *paramlist)
{
	struct Paramstruct *temp;
	temp=paramlist;
	printf("------------PARAMLIST------------------\n");
	printf("Name\t\t\tType\t\n");
	printf("------------------------------\n");
	
	while(temp!=NULL)
	{
		printf("%s\t\t\t",temp->name);
		if(temp->type!=NULL)
		{
		printf("%s\t\n",temp->type->name);
		}
		else
		{
		printf("NULL\t\n");
		}
		temp=temp->next;
	}
	printf("------------END OF PARAMLIST------------------\n\n");
}





void name_equivalence(struct Typetable *function_rettype,char *function_name,struct Paramstruct *paramlist)
{
	if(currclass!=NULL)
	{
		struct Memberfunclist *mfunc;
		mfunc=Class_MLookup(currclass,function_name);
		if(mfunc==NULL)
		{
			printf("NO SUCH METHOD WITH NAME %s IN CLASS %s\n",function_name,currclass->name);
			exit(1);
		}
		struct Paramstruct *plist,*temp;
		plist=mfunc->paramlist;
		temp=paramlist;
		if(function_rettype!=mfunc->type)
		{
			printf("RETURN TYPE MISMATCH FOR METHOD %s OF CLASS %s\n",function_name,currclass->name);
			exit(1);
		}

		if(hasSameSignature(plist,temp)==0)
		{
	printf("SIGNATURE MISMATCH BTW DECLARATION AND DEFNITION OF METHOD %s OF CLASS %s\n",function_name,currclass->name);
			exit(1);
		}
	}
	else
	{
		struct Gsymbol *global;
		global=GLookup(function_name);
		if(global==NULL)
		{
			printf("NO SUCH FUNCTION WITH NAME %s DECLARED BEFORE\n",function_name);
			exit(1);
		}
		struct Paramstruct *plist,*temp;
		plist=global->paramlist;
		temp=paramlist;
		if(function_rettype!=global->type)
		{
			printf("RETURN TYPE MISMATCH FOR FUNCTION %s\n",function_name);
			exit(1);
		}
		if(hasSameSignature(plist,temp)==0)
		{
	printf("SIGNATURE MISMATCH BTW DECLARATION AND DEFNITION OF FUNCTION %s\n",function_name);
			exit(1);
		}

	}

}

void createLsymbolEntries(struct Paramstruct *paramlist)
{
	struct Paramstruct *temp;
	temp=paramlist;
	
	int x=0;
	while(temp!=NULL)
	{
		x=x+1;
		local_binding=-(2+x);
		LInstall(temp->name,temp->type);
		temp=temp->next;
		
	}
	if(currclass!=NULL)
	{
		x=x+2;
		local_binding=-(2+x);
		LInstall("self",NULL);
	}	
	local_binding=1;

}


void LInstall(char *name,struct Typetable *type)
{
	struct Lsymbol *temp ,*newnode;
	if(LLookup(name)!=NULL)
	{
		printf("variable %s redefined in Local scope!!\n",name);
		exit(1);
	}
	
	if(type==TLookup("null"))
	{
		printf("undefined type for variable %s\n",name);
	}
	newnode=(struct Lsymbol *)malloc(sizeof(struct Lsymbol));
	newnode->name=(char *)malloc((strlen(name)+2)*sizeof(char));
	strcpy(newnode->name,name);	
	newnode->type=type;
	newnode->binding=local_binding;
	local_binding++;
	newnode->next=NULL;
	
	if(Lsymbol_table_head==NULL)
	{
		Lsymbol_table_head=newnode;	
		Lsymbol_table_tail=newnode;
	}
	else
	{
		Lsymbol_table_tail->next=newnode;
		Lsymbol_table_tail=newnode;
	}

}

struct Lsymbol *LLookup(char *name)
{
	struct Lsymbol *temp;
	temp=Lsymbol_table_head;

	while(temp!=NULL)
	{
		if(strcmp(name,temp->name)==0)
			return temp;
		temp=temp->next;
	}
	return temp;
} 

void reset_Lsymbol_table()
{
	
 	Lsymbol_table_head=NULL;
 	Lsymbol_table_tail=NULL;
	local_binding=1;
}
void print_Lsymbol_table(char *name)
{
								
	struct Lsymbol *temp;
	temp=Lsymbol_table_head;
	printf("\n\nLOCAL SYMBOL TABLE FOR %s FUNCTION\n",name);
	printf("--------------------------------------------\n");
	printf("Name\t\t\tType\tBinding\t\n");
	printf("---------------------------------\n");
	while(temp!=NULL)
	{
		printf("%s\t\t\t",temp->name);
		if(temp->type!=NULL)
		{	
			printf("%s\t",temp->type->name);
		}
		else
		{
			printf("NULL\t");
		}
		printf("%d\t\n",temp->binding);
		
		temp=temp->next;
	}
}


void TypeTableCreate()
{
	TInstall("int",1,NULL);
	TInstall("str",1,NULL);
	TInstall("bool",0,NULL);
	TInstall("null",0,NULL);
	TInstall("void",0,NULL);
}

struct Typetable *TLookup(char *name)
{
	Typetable *temp;
	temp=Typetable_head;
	while(temp!=NULL)
	{
		if(strcmp(name,temp->name)==0)
		{
			break;
		}
		temp=temp->next;
	}
	return temp;

}

struct Typetable * TInstall(char *name,int size,struct Fieldlist *fields)
{

	struct Typetable *temp;
	temp=TLookup(name);
	if(temp!=NULL)
	{
		printf("Multiple declarations of type :%s\n",name);		
		exit(1);
	}
	temp=(Typetable *)malloc(sizeof(Typetable));
	temp->name=(char *)malloc(sizeof(char) *6);
	strcpy(temp->name,name);
	temp->size=size;
	temp->fields=fields;
	temp->next=NULL;
	if(Typetable_head==NULL)
	{
		Typetable_head=temp;
		Typetable_tail=temp;
	}
	else
	{
		Typetable_tail->next=temp;
		Typetable_tail=temp;
	}
	return temp;
}


void FInstall(char *name,struct Typetable *type)
{

	struct Fieldlist *temp;
	temp=field_check(name);
	if(temp!=NULL)
	{
		printf("Multiple declarations of field :%s\n",name);		
		exit(1);
	}
	temp=(struct Fieldlist *)malloc(sizeof(struct Fieldlist));
	temp->name=(char *)malloc(sizeof(char) *(strlen(name)+2));
	strcpy(temp->name,name);
	temp->type=type;
	temp->fieldIndex=fieldIndex;
	fieldIndex++;
	temp->next=NULL;
	if(fieldlist_head==NULL)
	{
		fieldlist_head=temp;
		fieldlist_tail=temp;
	}
	else
	{
		fieldlist_tail->next=temp;
		fieldlist_tail=temp;
	}
	
}

struct Fieldlist *field_check(char *name)
{
	struct Fieldlist *temp;
	temp=fieldlist_head;
	while(temp!=NULL)
	{
		if(strcmp(temp->name,name)==0)
			break;
		temp=temp->next;
	}
	return temp;
}

void reset_fieldlist()
{
	fieldlist_head=NULL;
	fieldlist_tail=NULL;
	fieldIndex=1;

}

struct Fieldlist *FLookup(Typetable *struct_type,char *name)
{
	struct Fieldlist *temp=struct_type->fields;
	while(temp!=NULL)
	{
		if(strcmp(name,temp->name)==0)
			break;
		temp=temp->next;
	}
	return temp;

}

int getSize(Typetable *type)
{
	int size=0;
	struct Fieldlist *temp;
	if(strcmp(type->name,"bool")==0||strcmp(type->name,"void")==0)
		return 0;
	if(strcmp(type->name,"int")==0||strcmp(type->name,"str")==0)
		return 1;
	temp=type->fields;
	while(temp!=NULL)
	{	
		size++;
		temp=temp->next;
	}
	return size;
}

void print_Typetable()
{
	struct Typetable *temp=Typetable_head; 
	struct Fieldlist *ftemp;
	printf("-------------------TYPE TABLE--------------------\n");
	printf("NAME		SIZE		FIELDS		\n");
	while(temp!=NULL)
	{
	  ftemp=temp->fields;
	  if(ftemp==NULL)
	  	printf("%s\t\t%d\t\tNULL\t\n",temp->name,temp->size);
	  else
	  {
		printf("%s\t\t%d\t\t--->\t\n",temp->name,temp->size);
		printf("---------FIELDLIST OF %s---------\n",temp->name);
		printf("FIELDINDEX		TYPE		NAME		\n");
		while(ftemp!=NULL)
		{
	  printf("%d\t\t%s\t\t%s\t\n",ftemp->fieldIndex,ftemp->type->name,ftemp->name);
			ftemp=ftemp->next;
		}
		printf("-------------------------------------------------------\n");
		
	  }
	 temp=temp->next;

	}
	printf("-------------------END OF TYPE TABLE--------------------\n");
}	














struct Paramstruct *reverse_param(struct Paramstruct *plist)
{
	struct Paramstruct *curr=plist,*prev=NULL,*next=NULL;
	while(curr!=NULL)
	{
		next=curr->next;
		curr->next=prev;
		prev=curr;
		curr=next;
	}
	plist=prev;
	return plist;
}
int count(struct Paramstruct *plist)
{
	struct Paramstruct *temp;
	temp=plist;
	int l=0;
	while(temp!=NULL)
	{
		l++;
		temp=temp->next;
	}
	return l;
}

struct Paramstruct *copylist(struct Paramstruct *plist)
{
	struct Paramstruct *temp_head=NULL,*temp_tail=NULL;
	struct Paramstruct *dummy,*x;
	dummy=plist;
	while(dummy!=NULL)
	{
		x=create_param_node(dummy->name,dummy->type);
		if(temp_head==NULL)
		{
			temp_head=x;
			temp_tail=x;
		}
		else
		{
			temp_tail->next=x;
			temp_tail=x;
		}
		dummy=dummy->next;

	}
	return temp_head;


}

struct Classtable *CInstall(char *name,char *parent_name)
{
	struct Classtable *temp,*new;
	new=(struct Classtable*)malloc(sizeof(struct Classtable));
	new->name=name;
	new->memberfield=NULL;
	new->vfuncptr=NULL;
	new->parentptr=CLookup(parent_name);
	new->class_index=++class_index;
	new->fieldcount=0;
	new->methodcount=0;
	if(classtable_head==NULL)
	{
	 classtable_head=new;
	 classtable_tail=new;
	}
	else
	{
	 classtable_tail->next=new;
	 classtable_tail=new;
	}

	if(new->parentptr!=NULL)
	{
	new->fieldcount=new->parentptr->fieldcount;
	new->methodcount=new->parentptr->methodcount;
  	new->memberfield =inherit_fields(new->memberfield,new->parentptr->memberfield);
   	new->vfuncptr	 =inherit_methods(new->vfuncptr,new->parentptr->vfuncptr);
	}
	return new;
}

struct Classtable *CLookup(char *name)
{
	struct Classtable *temp;
	temp=classtable_head;
	if(name==NULL)
	{
		return NULL;
	}
	while(temp!=NULL)
	{	
		if(strcmp(name,temp->name)==0)
			return temp;
		temp=temp->next;
	}
	return temp;

}

struct Fieldlist *inherit_fields(struct Fieldlist *flist,struct Fieldlist *parent_flist)
{
	struct Fieldlist *new,*temp,*head=NULL,*tail=NULL;
	temp=parent_flist;
	while(temp!=NULL)
	{
		new=malloc(sizeof(struct Fieldlist));
		new->name=temp->name;
		new->fieldIndex=temp->fieldIndex;
		new->type=temp->type;
		new->ctype=temp->ctype;
		new->next=NULL;
		if(head==NULL)
		{
		 head=new;
		 tail=new;
		}
		else
		{
			tail->next=new;
			tail=new;
		}
		temp=temp->next;
	}
	if(flist==NULL)
	{
		flist=head;
	}
	else
	{
		temp=flist;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=head;
	}
	return flist;
}
struct Memberfunclist *inherit_methods(struct Memberfunclist *mlist,struct Memberfunclist *parent_mlist)
{
	struct Memberfunclist *new,*temp,*head=NULL,*tail=NULL;
	temp=parent_mlist;
	while(temp!=NULL)
	{
		new=malloc(sizeof(struct Memberfunclist));
		new->name=temp->name;
		new->type=temp->type;
		new->paramlist=temp->paramlist;
		new->funcposition=temp->funcposition;
		new->flabel=temp->flabel;
		new->next=NULL;
		if(head==NULL)
		{
		 head=new;
		 tail=new;
		}
		else
		{
			tail->next=new;
			tail=new;
		}
		temp=temp->next;
	}
	if(mlist==NULL)
	{
		mlist=head;
	}
	else
	{
		temp=mlist;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=head;
	}
	return mlist;
}

void Class_FInstall(struct Classtable *Cptr,char *typename,char *name)
{
	struct Typetable *type;
	struct Classtable *ctype;
	struct Fieldlist *new,*temp;
	type=TLookup(typename);
	ctype=CLookup(typename);
	if(type==NULL &&ctype==NULL)
	{
		printf("Undefined type %s for %s in Class %s\n",typename,name,Cptr->name);
		exit(1);
	}
	if(Class_FLookup(Cptr,name)!=NULL)
	{
		printf("Cannot overwrite/redefine field %s in Class %s\n",name,Cptr->name);
		exit(1);
	}
	new=(struct Fieldlist*)malloc(sizeof(struct Fieldlist));
	new->name=name;
	new->fieldIndex=++Cptr->fieldcount;
	if(ctype!=NULL)
	{
	  Cptr->fieldcount++;	//two words for class type
	}
	new->type=type;
	new->ctype=ctype;
	new->next=NULL;
	if(Cptr->memberfield==NULL)
	{
		Cptr->memberfield=new;
	}
	else
	{
		temp=Cptr->memberfield;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=new;
	}
}

struct Fieldlist *Class_FLookup(struct Classtable *Cptr,char *name)
{
	struct Fieldlist *temp;
	temp=Cptr->memberfield;
	while(temp!=NULL)
	{
		if(strcmp(temp->name,name)==0)
			return temp;
		temp=temp->next;
	}
	return temp;
}

/*rettype of a function cannot be a class*/
void Class_MInstall(struct Classtable *Cptr,char *name,struct Typetable *rettype,struct Paramstruct *paramlist)
{
	struct Memberfunclist *new,*temp;
	if(rettype==NULL||rettype==TLookup("null"))	
	{
		printf("no such type as rettype \"NULL or null\" of method %s of class %s\n",name,Cptr->name);
		exit(1);
	}

	if((Class_MLookup(Cptr,name)!=NULL)&&(Class_MLookup(Cptr->parentptr,name)==NULL))
	{
		printf("method %s redeclared in same class %s\n",name,Cptr->name);
		exit(1);
	}
	else if((Class_MLookup(Cptr,name)!=NULL)&& (Class_MLookup(Cptr->parentptr,name)!=NULL))
	{
		temp=Class_MLookup(Cptr,name);
		if((rettype!=temp->type)||(hasSameSignature(paramlist,temp->paramlist)==0))
		{
			printf("Heyyy....Overloading not permitted!!!!\n");
			printf("Name and Signature of Method %s does not match in Class %s and it Parent's Class %s",name,Cptr->name,Cptr->parentptr->name);
			exit(1);
			
		}
		else
		{
		/*Overriding parents methods(say F1:m1,F2:m2,F3:m3) child methods(say F4:m4,F5:m5,F6:m6	
		if(m5 eq m2) then vfuncptr F1->F5->F3->F4->F6; since name signature doesn't change and funcposition also does not change
		*/
		 temp->flabel=++flabel;
		 temp->paramlist=paramlist;
		 return;
		}		
	
	}
	else if(Class_MLookup(Cptr,name)==NULL)
	{
		new=(struct Memberfunclist *)malloc(sizeof(struct Memberfunclist));			
		new->name=name;
		new->type=rettype;
		new->paramlist=paramlist;
		new->funcposition=++Cptr->methodcount;
		new->flabel=++flabel;
		new->next=NULL;
		
		if(Cptr->vfuncptr==NULL)
		{
		 Cptr->vfuncptr=new;
		}
		else
		{
			temp=Cptr->vfuncptr;
			while(temp->next!=NULL)
			{
				temp=temp->next;
			}
			temp->next=new;
		}
	}

}

int  hasSameSignature(struct Paramstruct *p1,struct Paramstruct *p2)
{
	while(p1!=NULL&&p2!=NULL)
	{
		if(p1->type!=p2->type||!(strcmp(p1->name,p2->name)==0))
		{
			return 0;
		}
		p1=p1->next;
		p2=p2->next;
	}
	if(p1==NULL&&p2==NULL)
	{
		return 1;
	}
	else if(p1==NULL||p2==NULL)
	{
		return 0;
	}	

}
struct Memberfunclist *Class_MLookup(struct Classtable *Cptr,char *name)
{
	struct Memberfunclist *temp;
	temp=Cptr->vfuncptr;
	while(temp!=NULL)
	{
		if(strcmp(temp->name,name)==0)
			return temp;
		temp=temp->next;
	}
	return temp;
}



void print_classtable()
{
	struct Classtable *temp;
	temp=classtable_head;
printf("_________________________________________________CLASS TABLE____________________________________________________\n");
printf("NAME\t\t|MEMBERFIELD\t|VFUNCPTR\t|PARENTPTR\t|CLASSINDEX\t|FIELDCOUNT\t|METHODCOUNT\t|\n");	
	while(temp!=NULL)
	{
printf("_________________________________________________________________________________________________________________\n");
	 	printf("%s\t|",temp->name);
	 	if(temp->memberfield==NULL)
	 	{
	 	 printf("NULL\t\t|");
	 	}	
	 	else
	 	{
	 	 printf("--->\t\t|");
	 	}
	 	if(temp->vfuncptr==NULL)
		{
	 	 printf("NULL\t\t|");
	 	}	
	 	else
	 	{
	 	 printf("--->\t\t|");
	 	 
	 	}
		if(temp->parentptr==NULL)
		{
	 	 printf("NULL\t\t|");
	 	}	
	 	else
	 	{
	 	 printf("---->%s\t|",temp->parentptr->name);
	 	}
		printf("%d\t\t|",temp->class_index);
		printf("%d\t\t|",temp->fieldcount);
		printf("%d\t\t|\n",temp->methodcount);
		if(temp->memberfield!=NULL)
	 	{
		print_memberlist(temp->memberfield);
		}
		if(temp->vfuncptr!=NULL)
		{
		print_memberfunclist(temp->vfuncptr);
		}

		temp=temp->next;
	}
printf("_______________________________________________END OFCLASS TABLE________________________________________________\n");
}


void print_memberlist(struct Fieldlist *f)
{
	struct Fieldlist *temp;
	temp=f;
	printf("--------------------------FIELDLIST---------------------------------------\n");
	printf("NAME\t\t|FIELDINDEX\t|TYPE\t\t|CTYPE\t\t|\n");
	while(temp!=NULL)
	{
		//printf("-----------------------------------------------------------------\n");
		printf("%s\t\t|",temp->name);
		printf("%d\t\t|",temp->fieldIndex);
		if(temp->type==NULL)
		{
			printf("NULL\t\t|");
		}
		else
		{
			printf("--->%s\t|",temp->type->name);
		}
		if(temp->ctype==NULL)
		{
			printf("NULL\t\t|\n");
		}
		else
		{
			printf("--->%s\t|\n",temp->ctype->name);
		}
		temp=temp->next;
	}
	printf("--------------------------END OF FIELDLIST---------------------------------------\n");

}
void print_memberfunclist(struct Memberfunclist *m)
{
	struct Memberfunclist *temp;
	temp=m;
	printf("_______________________________MEMBER FUNCLIST_____________________________________\n");
	printf("NAME\t\t|TYPE\t\t|PARAMLIST\t|FUNCPOSITION\t|FLABEL\t|\n"); 
	while(temp!=NULL)
	{
		printf("%s\t\t|",temp->name);
		if(temp->type==NULL)
		{
			printf("NULL\t\t|");
		}
		else
		{
			printf("--->%s\t|",temp->type->name);
		}
		if(temp->paramlist==NULL)
		{
			printf("NULL\t\t|");
		}
		else
		{
			printf("---->\t\t|");
		}
		printf("%d\t\t|",temp->funcposition);
		printf("%d\t|\n",temp->flabel);
	
		if(temp->paramlist!=NULL)
		{
		print_paramlist(temp->paramlist);
		}
		temp=temp->next;
	}
	printf("_________________________________END OF MEMBER FUNCLIST____________________________________\n");


}

void createVfuncTableEntries()
{
	int i, a[8]={-1}, index;
	FILE *fp;
	struct Memberfunclist *mfunc;
	mfunc=currclass->vfuncptr;
	index=currclass->class_index;
	while(mfunc!=NULL){
		if(mfunc->funcposition <= 8)
			a[mfunc->funcposition-1]=mfunc->flabel;
		mfunc=mfunc->next;
	}
	for (i=0;i<8;i++)
	{
		if(a[i]>0)
		{
			fp=fopen("start.xsm","a");
			fprintf(fp,"MOV R0, F%d\n",a[i]);
			fclose(fp);
		}
		fp=fopen("start.xsm","a");
		fprintf(fp,"PUSH R0\n");
		fclose(fp);
	}
	sp=sp+8;
	sp1=sp1+8;	
	
}







struct tnode* create_tree(int val,struct Typetable *type,char *varname,int node_type,struct tnode*l,struct tnode *m,struct tnode *r)
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
	newnode->ctype=NULL;
	newnode->nodetype=node_type;
	newnode->Gentry=NULL;
	newnode->left=l;
	newnode->right=r;
	newnode->middle=m;
	newnode->faccess=NULL;
	//bodyflag!=1||
	if(node_type!=var_node)
	{
	typecheck(newnode);
	}
	return newnode;
}

void typecheck(struct tnode *t)
{
	struct Lsymbol *local;
	struct Gsymbol *global;
	struct Paramstruct *param;
	struct Classtable *Cptr;
	struct Fieldlist *f;
	struct Memberfunclist *mfunc;
	//print_node(t);
	switch(t->nodetype)
	{
		case read_node:
			  	break;
		case write_node:
			   if((t->left->type!=TLookup("int"))&&(t->left->type!=TLookup("str")))
				{
				printf("Type Mismatch:	Invalid argument type to Write() function\n");
printf("Write Expects: (an expression which evaluates to integer )OR (a string type constant or variable )\n");
					exit(1);
				}
				break;
		case assg_node:
			 if(t->left->ctype==NULL)
			 {	if(t->right->nodetype==null_node||t->right->nodetype==alloc_node)
				{
					if(t->left->type==TLookup("int")||t->left->type==TLookup("str"))
					{				
						printf("Invalid assignment to non user defined type variable");
						exit(1);
					}
				}
				else if(t->left->type!=t->right->type)
				{
printf("Type Mismatch:	Type of LHS and RHS of an assignment statement does not Match\n");
					exit(1);
				}
			}
			else
			{
				if(t->right->ctype==NULL||t->left->ctype==NULL)
				{
					printf("INVALID ASSIGNMENT FOR CLASS TYPE OBJECTS");
					exit(1);
				}
				Cptr=t->right->ctype;
				while(Cptr!=NULL)
				{
					if(t->left->ctype==Cptr)
						break;
					Cptr=Cptr->parentptr;
				}
				if(Cptr==NULL)
				{
				printf("A class variable can be assigned to objects of it's descendent classes only");
				exit(1);
				}
			}
				break;
		case conn_node:
				break;
		case iconst_node:
				break;
		case sconst_node:
				break;
		case var_node:
				if(bodyflag==1)
				{
					//printf("XYZ>>>>>:%s\n",t->varname);
					local=LLookup(t->varname);
					if(local==NULL)
					{
						global=GLookup(t->varname);
						if(global==NULL)
						{
			       printf("Variable:%s Undeclared in Local & Global\n",t->varname);
						exit(1);
						}
						else
						{
							t->type=global->type;
							t->ctype=global->ctype;
							t->Gentry=global;
						}
					}
					else
					{		
						t->type=local->type;
						//t->ctype=NULL;
					}
				}
				break;

		case aop_node:
			     	if((t->left->type!=TLookup("int"))||(t->right->type!=TLookup("int")))
				{
				 printf("Type Mismatch:Expected Integer on both sides of arithmetic operator\n");
				exit(1);
				}
				break;
		case lop_node:
				if(!strcmp(t->varname,"==")||!strcmp(t->varname,"!="))
				{
					if(t->right->type==TLookup("null"))
					{
						if(t->left->type==TLookup("int")||t->left->type==TLookup("str"))
						{
						printf("Invalid comparision b/w NULL and non user defined type");
						exit(1);
						}

					}
					else if(t->left->type!=t->right->type)
					{
						printf("Comparision between 2 args of diff type\n");
						exit(1);

					}


				}
				else if(!strcmp(t->varname,">=")||!strcmp(t->varname,"<=") ||!strcmp(t->varname,">")|| !strcmp(t->varname,"<"))
				{
					if(t->left->type!=TLookup("int")||t->right->type!=TLookup("int"))
					{
						printf("expected int type on both sides of logical operator\n");
						exit(1);
					}
				}
				else if(!strcmp(t->varname,"&&") || !strcmp(t->varname,"||"))
				{
					if((t->left->type!=TLookup("bool"))||(t->right->type!=TLookup("bool")))
					{
				  printf("Type Mismatch:Expected BOOL on both sides of logical operator\n");
				  exit(1);
					}
				}
				else if(!strcmp(t->varname,"!"))
				{
					if(t->left->type!=TLookup("bool"))
					{
				  printf("Type Mismatch:Expected BOOL on with logical operator NOT\n");
				  exit(1);
					}
				}
				break;
		case if_node:
				if(t->left->type!=TLookup("bool"))
				{
					printf("Invalid expression inside if\n");
					exit(1);
				}
				break;
		case while_node:
				if(t->left->type!=TLookup("bool"))
				{
					printf("Invalid expression inside while\n");
					exit(1);
				}
				break;
		case continue_node:
				break;
		case break_node:
				break;
		case arr_node:
				if(declflag==0)
				{
					global=GLookup(t->varname);
					if(global==NULL)
					{
						printf("Array %s Undeclared\n",t->varname);
						exit(1);
					}
					if(t->left->nodetype==iconst_node)
					{
						if(t->left->val >= global->size)
						{
						printf("Array out of bound\n");
						exit(1);
						}
					}
					t->type=global->type;
					t->ctype=global->ctype;
					t->Gentry=global;
				}
				else if(declflag==1)
				{
					if(t->left->nodetype!=iconst_node)
					{
	printf("Array declaration should be static.....eg:arr[20] but no arr[i]\n");
					exit(1);
					}
				}
				break;
		case func_node:
			//this node is only for functions which are declared in global declarations
				argcheck(t->varname,t->left);/*declaration and argument type check is taken care */
				global=GLookup(t->varname);
				t->Gentry=global;
				t->type=global->type;
				t->ctype=global->ctype;
				break;
		case ret_node:
				printf("Function Name:%s\n",t->varname);
				if(strcmp(t->varname,"MAIN"))
				{
					if(currclass==NULL)
					{
					global=GLookup(t->varname);
					if(global==NULL)
					{
		printf("Function defnition %s without a previous declaration\n",t->varname);
		exit(1);
					}
					if(global->type!=t->left->type)
					{
	printf("Function %s expects type %s but here return type is %s\n",t->varname,global->type->name,t->left->type->name);
				exit(1);

					}
					}
					else
					{
						mfunc=Class_MLookup(currclass,t->varname);
						if(mfunc->type!=t->left->type)
						{
					printf("RETURN TYPE MISMATCH IN METHOD %s OF CLASS %s\n",t->varname,currclass->name);
						exit(1);
						}
					}
				
				}
				break;
		case free_node:
			if(t->left->type==TLookup("int")||t->left->type==TLookup("str"))
			{
				printf("free to be called for user defined types only\n");
				exit(1);
			}
			break;
	}
		//print_node(t);
}

void argcheck(char *function_name,struct tnode *t)
{
//this is only for functions declared in global declarations
	struct Gsymbol *dummy;
	struct Paramstruct *temp,*temp1;
	struct tnode *parglist;
	int arg_count=0;
	dummy=GLookup(function_name);
	if(dummy==NULL)
	{
		printf("Usage of Function %s without any previous declaration\n",function_name);
		exit(1);
	}
	temp1=dummy->paramlist;
	temp=copylist(temp1);
	temp=reverse_param(temp);
	parglist=t;
	while(parglist!=NULL)
	{
		arg_count++;
		if(temp==NULL)
		{
		   printf("hello:Too many arguments int the Function call for %s\n",function_name);
		   exit(1);
		}
		else if(parglist->type!=temp->type)
		{
     printf("Parameter Type Mistmatch at Argument %d of Function %s\n",arg_count,function_name);
			printf("Pptype:%s,Gptype:%s\n",parglist->type->name,temp->type->name);
			exit(1);
		}
		
		else
		{
			parglist=parglist->middle;
			temp=temp->next;
		}
		
	}
	if(temp!=NULL)
	{
		printf("Too few arguments in the Function call for %s\n",function_name);
		exit(1);
	}
}	


void print_node(struct tnode *t)
{
	struct tnode *temp;
	if(t==NULL)
	{
		printf("HEY BOSS IT'S NULL\n");
	}
	printf("[val:%d ",t->val);
	if(t->type!=NULL)
	{
	printf("type:%s ",t->type->name);
	}
	else
	{
	printf("type:NULL ");
	}
	if(t->ctype!=NULL)
	{
	printf("ctype:%s ",t->ctype->name);
	}
	else
	{
	printf("ctype:NULL ");
	}
	if(t->varname!=NULL)
	{printf("varname:%s ",t->varname);}
	else
	{printf("varname:NULL ");}
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
  	printf("iconst_node ");
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
	printf("continue_node ");
	break;
	case 12:
	printf("break_node ");
	break;
	case 13:
	printf("sconst_node ");
	break;
	case 14:
	printf("arr_node ");
	break;
	case 15:
	printf("func_node ");
	break;
	case 16:
	printf("ret_node ");
	break;
	case 17:
	printf("field_node ");
	break;
	case 18:
	printf("alloc_node ");
	break;
	case 19:
	printf("initialize_node ");
	break;
	case 20:
	printf("free_node ");
	break;
	case 21:
	printf("null_node ");
	break;
	case 22:
	printf("new_node ");
	break;
	case 23:
	printf("fieldfunction_node ");
	break;
	}
	if(t->Gentry!=NULL)
	{
		 printf("binding:%d,",t->Gentry->binding);
		 if(t->Gentry->type!=NULL)
		 {
			printf("Gentry_type:%s,",t->Gentry->type->name);
		 }
		 if(t->Gentry->ctype!=NULL)
		 {
			printf("Gentry_ctype:%s ",t->Gentry->ctype->name);
		 }
	}
	if(t->faccess!=NULL)
	{
		printf("fieldname:__ %s",t->varname);
		temp=t->faccess;
		while(temp!=NULL)
		{
			printf(".%s",temp->varname);
			temp=temp->faccess;
		}
		printf(" ");
	}
	printf("]\n");
}
//check this
void preorder(struct tnode *t)
{
	if(t==NULL)
	return;
	else
	{
	printf("node:\n");
	print_node(t);
	if(t->left)
	{
	  printf("left:\n");
	  preorder(t->left);
	}
	if(t->middle)
	{
	printf("middle:\n");
	preorder(t->middle);
	}
	if(t->right)
	{
	printf("right:\n");
	preorder(t->right);
	}
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


int scall(char *fcode,int arg1, int arg2)
{
	FILE *fp;
 	int r,i,j,x;
  
  if(strcmp("Write",fcode)==0)
   {
	
	i=getreg();
	x=getreg();
	fp=fopen("temp.xsm","a");
	fprintf(fp,"MOV R%d,R%d\n",x,arg2);
     	fprintf(fp,"MOV R%d,\"%s\"\n",i,fcode);
     	fprintf(fp,"PUSH R%d\n",i);
     
     	fprintf(fp,"MOV R%d,%d\n",i,arg1);
     	fprintf(fp,"PUSH R%d\n",i);
     
     	fprintf(fp,"MOV R%d,R%d\n",i,x);
     	fprintf(fp,"PUSH R%d\n",i);
   	fclose(fp);
	freereg();
	j=getreg();
	fp=fopen("temp.xsm","a");
     	fprintf(fp,"PUSH R%d\n",j);
     	fprintf(fp,"PUSH R%d\n",j);
	sp1=sp1+5;
     	fprintf(fp,"CALL 0\n");
	fclose(fp);
	freereg();
    	fp=fopen("temp.xsm","a");
	fprintf(fp,"POP R%d\n",i);
	fclose(fp);
	j=getreg();
	fp=fopen("temp.xsm","a");
     	fprintf(fp,"POP R%d\n",j);
     	fprintf(fp,"POP R%d\n",j);
     	fprintf(fp,"POP R%d\n",j);
     	fprintf(fp,"POP R%d\n",j);
	fclose(fp);
	sp1=sp1-5;
     	freereg();
     
	freereg();
	return i;
    }
   else if(strcmp("Read",fcode)==0)
   {
	
     	i=getreg();
	//printf("i:%d\n",i);
	fp=fopen("temp.xsm","a");
     	fprintf(fp,"MOV R%d,\"%s\"\n",i,fcode);
     	fprintf(fp,"PUSH R%d\n",i);

     	fprintf(fp,"MOV R%d,%d\n",i,arg1);
     	fprintf(fp,"PUSH R%d\n",i);

     	//fprintf(fp,"MOV R%d,%d\n",i,arg2);
     	fprintf(fp,"PUSH R%d\n",arg2);
	fclose(fp);
	j=getreg();
	//printf("j:%d\n",j);
	fp=fopen("temp.xsm","a");
     	fprintf(fp,"PUSH R%d\n",j);
     	fprintf(fp,"PUSH R%d\n",j);
	sp1=sp1+5;
     	fprintf(fp,"CALL 0\n");
	fclose(fp);
	freereg();
	fp=fopen("temp.xsm","a");
     	fprintf(fp,"POP R%d\n",i);
	fclose(fp);
	//printf("i:%d\n",i);
	j=getreg();
	//printf("j:%d\n",j);
	fp=fopen("temp.xsm","a");
     	fprintf(fp,"POP R%d\n",j);
     	fprintf(fp,"POP R%d\n",j);
     	fprintf(fp,"POP R%d\n",j);
     	fprintf(fp,"POP R%d\n",j);
	sp1=sp1-5;
	fclose(fp);
     	freereg();
	freereg();
	return i;
    }
   else if(strcmp("Exit",fcode)==0)
   {
		
	i=getreg();
	fp=fopen("start.xsm","a");    
     	fprintf(fp,"MOV R%d,\"%s\"\n",i,fcode);
	fprintf(fp,"PUSH R%d\n",i);
	fclose(fp);
     	j=getreg();
	fp=fopen("start.xsm","a"); 
     	fprintf(fp,"PUSH R%d\n",j);
     	fprintf(fp,"PUSH R%d\n",j);
     	fprintf(fp,"PUSH R%d\n",j);
     	fprintf(fp,"PUSH R%d\n",j);
	sp1=sp1+5;
     	fprintf(fp,"CALL 0\n");
	fclose(fp);
     	freereg();
	
	fp=fopen("start.xsm","a"); 
     	fprintf(fp,"POP R%d\n",i);
	fclose(fp);
     	j=getreg();
	fp=fopen("start.xsm","a"); 
     	fprintf(fp,"POP R%d\n",j);
     	fprintf(fp,"POP R%d\n",j);
     	fprintf(fp,"POP R%d\n",j);
     	fprintf(fp,"POP R%d\n",j);
	sp1=sp1-5;
	fclose(fp);
     	freereg();
	freereg();
     	
	
     	return i;
    }
   else if(strcmp("Heapset",fcode)==0)
   {
	i=getreg();
	fp=fopen("temp.xsm","a");
     	fprintf(fp,"MOV R%d,\"%s\"\n",i,fcode);
     	fprintf(fp,"PUSH R%d\n",i);
	fclose(fp);
	j=getreg();

	fp=fopen("temp.xsm","a");
	fprintf(fp,"PUSH R%d\n",j);
     	fprintf(fp,"PUSH R%d\n",j);
     	fprintf(fp,"PUSH R%d\n",j);
     	fprintf(fp,"PUSH R%d\n",j);
	sp1=sp1+5;
     	fprintf(fp,"CALL 0\n");
	fclose(fp);
	freereg();

	fp=fopen("temp.xsm","a");
     	fprintf(fp,"POP R%d\n",i);
	fclose(fp);

	j=getreg();
	fp=fopen("temp.xsm","a");
     	fprintf(fp,"POP R%d\n",j);
     	fprintf(fp,"POP R%d\n",j);
     	fprintf(fp,"POP R%d\n",j);
     	fprintf(fp,"POP R%d\n",j);
	sp1=sp1-5;
	fclose(fp);
     	freereg();
	freereg();
	return i;



   }

   else if(strcmp("Alloc",fcode)==0)
   {
	i=getreg();
	fp=fopen("temp.xsm","a");
     	fprintf(fp,"MOV R%d,\"%s\"\n",i,fcode);
     	fprintf(fp,"PUSH R%d\n",i);
	fprintf(fp,"MOV R%d,8\n",i);
	fprintf(fp,"PUSH R%d\n",i);
	fclose(fp);
	j=getreg();

	fp=fopen("temp.xsm","a");
     	fprintf(fp,"PUSH R%d\n",j);
     	fprintf(fp,"PUSH R%d\n",j);
     	fprintf(fp,"PUSH R%d\n",j);
	sp1=sp1+5;
     	fprintf(fp,"CALL 0\n");
	fclose(fp);
	freereg();

	fp=fopen("temp.xsm","a");
     	fprintf(fp,"POP R%d\n",i);
	fclose(fp);

	j=getreg();
	fp=fopen("temp.xsm","a");
     	fprintf(fp,"POP R%d\n",j);
     	fprintf(fp,"POP R%d\n",j);
     	fprintf(fp,"POP R%d\n",j);
     	fprintf(fp,"POP R%d\n",j);
	sp1=sp1-5;
	fclose(fp);
     	freereg();
	freereg();
	return i;


   }
   else if(strcmp("Free",fcode)==0)
   {
	i=getreg();
	x=getreg();
	fp=fopen("temp.xsm","a");
	fprintf(fp,"MOV R%d,R%d\n",x,arg1);
	
     	fprintf(fp,"MOV R%d,\"%s\"\n",i,fcode);
     	fprintf(fp,"PUSH R%d\n",i);
     	fprintf(fp,"MOV R%d,R%d\n",i,x);
     	fprintf(fp,"PUSH R%d\n",i);
   	fclose(fp);
	freereg();

	j=getreg();
	fp=fopen("temp.xsm","a");
     	fprintf(fp,"PUSH R%d\n",j);
     	fprintf(fp,"PUSH R%d\n",j);
	fprintf(fp,"PUSH R%d\n",j);
	sp1=sp1+5;
	
     	fprintf(fp,"CALL 0\n");
	fclose(fp);
	freereg();

    	fp=fopen("temp.xsm","a");
	fprintf(fp,"POP R%d\n",i);
	fclose(fp);

	j=getreg();
	fp=fopen("temp.xsm","a");
     	fprintf(fp,"POP R%d\n",j);
     	fprintf(fp,"POP R%d\n",j);
     	fprintf(fp,"POP R%d\n",j);
     	fprintf(fp,"POP R%d\n",j);
	sp1=sp1+5;
	fclose(fp);
     	freereg();
     
	freereg();
	return i;



   }

}

 
void generate_code(struct tnode *t,char *fname)
{
	FILE *fp;
   	int fl;
	int i;
	int x;
	fp=fopen("temp.xsm","a");
	//fprintf(fp,"FUNCTION NAME_____________________________%s\n",fname);
fclose(fp);
   	if(strcmp(fname,"MAIN")==0)
   	{
		fl=0;
   	}
	else if(currclass!=NULL)
	{
		struct Memberfunclist *mfunc;
		mfunc=Class_MLookup(currclass,fname);
		fl=mfunc->flabel;
	}
  	else
  	{
		fl=GLookup(fname)->flabel;
	}

	fp=fopen("temp.xsm","a");
	fprintf(fp,"F%d:\n",fl);
	fprintf(fp,"PUSH BP\n");
	fprintf(fp,"MOV BP,SP\n");
	fclose(fp);
	//allocating space ..for local variables...
	for(i=1;i<local_binding;i++)
	{
		fp=fopen("temp.xsm","a");
		fprintf(fp,"PUSH R0\n");
		fclose(fp);
	}
	sp1=sp1+i;
	x=codegen(t);

}

int codegen(struct tnode *t)
{
	FILE *fp;
	int l,m,r,i,j,buff,data,v,n,x;
	struct Gsymbol *global;
	struct Lsymbol *local;
	struct Paramstruct *paramlist;
	struct tnode *arglist,*temp;
	struct Classtable *Cptr;
	struct Memberfunclist *mfunc;
	struct Fieldlist *f;
	printf("codegen:");
	print_node(t);
	switch(t->nodetype)
	{
		
		case read_node:
			//printf("read c:%d\n",c);
			buff=getaddr(t->left);
			for(n=0;n<=c;n++)
			{
			  fp=fopen("temp.xsm","a");
			  fprintf(fp,"PUSH R%d\n",n);
			  fclose(fp);
			 sp1=sp1+1;
			}
			i=scall("Read",-1,buff);			
			for(n=c;n>=0;n--)
			{
			  fp=fopen("temp.xsm","a");
			  fprintf(fp,"POP R%d\n",n);
			  fclose(fp);
			  sp1=sp1-1;
			}
///
			freereg();
			printf("read c:%d\n",c);
			return i;
			break;

		case write_node:
			//printf("read c:%d\n",c);
			l=codegen(t->left);
///
			freereg();
			for(n=0;n<=c;n++)
			{
			  fp=fopen("temp.xsm","a");
			  fprintf(fp,"PUSH R%d\n",n);
			  fclose(fp);
			  sp1=sp1+1;
			}
			i=scall("Write",-2,l);
			for(n=c;n>=0;n--)
			{
			  fp=fopen("temp.xsm","a");
			  fprintf(fp,"POP R%d\n",n);
			  fclose(fp);
			  sp1=sp1-1;
			}
			printf("write c:%d\n",c);
			return i;
			break;

		case assg_node:
		   if(t->left->ctype==NULL)
		   {
			v=getaddr(t->left);
			r=codegen(t->right);
			
			fp=fopen("temp.xsm","a");
			fprintf(fp,"MOV [R%d],R%d\n",v,r);
			fclose(fp);
			freereg();
			if(t->right->nodetype!=initialize_node&&t->right->nodetype!=alloc_node)
			{
			freereg();
			}
			printf("assg-1 c:%d\n",c);
			return v;
		   }
		   else
		   {
//say first=new(B);
			if(t->right->nodetype==new_node)
			{
//get base of virtual func table stack 
				Cptr=t->right->ctype;
				int index=Cptr->class_index -1;
				index=index*8+4096;
				v=getaddr(t->left);
//alloc() call which return location in heap
				r=codegen(t->right);
//store heap location and virtual func table base to variable
				fp=fopen("temp.xsm","a");
				fprintf(fp,"MOV [R%d],R%d\n",v,r);
				fprintf(fp,"ADD R%d,1\n",v);
				fprintf(fp,"MOV [R%d],%d\n",v,index);
				fclose(fp);
				freereg();
				printf("assg-2 c:%d\n",c);
				return v;
			}
			else
			{
//say first=new(B); second=new(C); **first=second;**
				v=getaddr(t->left);
				x=getaddr(t->right);
				i=getreg();
				fp=fopen("temp.xsm","a");
//copy heap location
				fprintf(fp,"MOV R%d,[R%d]\n",i,x);
				fprintf(fp,"MOV [R%d],R%d\n",v,i);
				fprintf(fp,"ADD R%d,1\n",v);
				fprintf(fp,"ADD R%d,1\n",x);
//copy vfunc table location				
				fprintf(fp,"MOV R%d,[R%d]\n",i,x);
				fprintf(fp,"MOV [R%d],R%d\n",v,i);
				fclose(fp);
				freereg();
				freereg();
				freereg();
				printf("assg-3 c:%d\n",c);
				return v;

			}
		   }
			break;

		case conn_node:
			
			l=codegen(t->left);
			l=codegen(t->right);
			printf("conn c:%d\n",c);
			return l;
			break;

		case iconst_node:
			
			i=getreg();
			fp=fopen("temp.xsm","a");
			fprintf(fp,"MOV R%d,%d\n",i,t->val);
			fclose(fp);
			printf("iconst c:%d\n",c);
			return i;
			break;
//##CHECK>>CHANGED TO ...ARRAY AND VAR

		case var_node:
			
			v=getaddr(t);
			fp=fopen("temp.xsm","a");
			fprintf(fp,"MOV R%d,[R%d]\n",v,v);
			fclose(fp);
			printf("var c:%d\n",c);
			return v;
			break;
			
		case aop_node:
			
			l=codegen(t->left);
			r=codegen(t->right);
			switch(*(t->varname))
			{
				case '+':
					fp=fopen("temp.xsm","a");
					fprintf(fp,"ADD R%d,R%d\n",l,r);
					fclose(fp);
					freereg();
					break;
				case '-':
					fp=fopen("temp.xsm","a");
					fprintf(fp,"SUB R%d,R%d\n",l,r);
					fclose(fp);
					freereg();
					break;
				case '*':
					fp=fopen("temp.xsm","a");
					fprintf(fp,"MUL R%d,R%d\n",l,r);
					fclose(fp);
					freereg();
					break;
				case '/':
					fp=fopen("temp.xsm","a");
					fprintf(fp,"DIV R%d,R%d\n",l,r);
					fclose(fp);
					freereg();
					break;
				case '%':
					fp=fopen("temp.xsm","a");
					fprintf(fp,"MOD R%d,R%d\n",l,r);
					fclose(fp);
					freereg();
					break;
			}
			printf("aop c:%d\n",c);
			return l;
			break;

		case lop_node:
			
			if(strcmp(t->varname,">=")==0)
			{ 
				l=codegen(t->left);
				r=codegen(t->right);
				fp=fopen("temp.xsm","a");
				fprintf(fp,"GE R%d,R%d\n",l,r);
				fclose(fp);
				freereg();
				printf(">= c:%d\n",c);
				return l;
			}
			else if(strcmp(t->varname,"<=")==0)
			{ 
				l=codegen(t->left);
				r=codegen(t->right);
				fp=fopen("temp.xsm","a");
				fprintf(fp,"LE R%d,R%d\n",l,r);
				fclose(fp);
				freereg();
				printf("<= c:%d\n",c);
				return l;
			}
			else if(strcmp(t->varname,">")==0)
			{ 
				l=codegen(t->left);
				r=codegen(t->right);
				fp=fopen("temp.xsm","a");
				fprintf(fp,"GT R%d,R%d\n",l,r);
				fclose(fp);
				freereg();
				printf("> c:%d\n",c);
				return l;
			}
			else if(strcmp(t->varname,"<")==0)
			{ 
				l=codegen(t->left);
				r=codegen(t->right);
				fp=fopen("temp.xsm","a");
				fprintf(fp,"LT R%d,R%d\n",l,r);
				fclose(fp);
				freereg();
				printf("< c:%d\n",c);
				return l;
			}
			else if(strcmp(t->varname,"==")==0)
			{ 
				l=codegen(t->left);
				r=codegen(t->right);
				fp=fopen("temp.xsm","a");
				fprintf(fp,"EQ R%d,R%d\n",l,r);
				fclose(fp);
				freereg();
				printf("== c:%d\n",c);
				return l;
			}
			else if(strcmp(t->varname,"!=")==0)
			{ 
				l=codegen(t->left);
				r=codegen(t->right);
				fp=fopen("temp.xsm","a");
				fprintf(fp,"NE R%d,R%d\n",l,r);
				fclose(fp);
				freereg();
				printf("!= c:%d\n",c);
				return l;
			}
			else if(strcmp(t->varname,"&&")==0)
			{ 
				l=codegen(t->left);
				r=codegen(t->right);
				i=getlabel();
				j=getlabel();
				fp=fopen("temp.xsm","a");
				fprintf(fp,"JZ R%d,L%d\n",l,i);
				fprintf(fp,"JZ R%d,L%d\n",r,i);
				fprintf(fp,"MOV R%d,1\n",l);
				fprintf(fp,"JMP L%d\n",j);
				fprintf(fp,"L%d:\n",i);
				fprintf(fp,"MOV R%d,0\n",l);
				fprintf(fp,"L%d:\n",j);
				fclose(fp);
				freereg();
				printf("&& c:%d\n",c);
				return l;
			}
			else if(strcmp(t->varname,"||")==0)
			{ 
				l=codegen(t->left);
				r=codegen(t->right);
				i=getlabel();
				j=getlabel();
				fp=fopen("temp.xsm","a");
				fprintf(fp,"JNZ R%d,L%d\n",l,i);
				fprintf(fp,"JNZ R%d,L%d\n",r,i);
				fprintf(fp,"MOV R%d,0\n",l);
				fprintf(fp,"JMP L%d\n",j);
				fprintf(fp,"L%d:\n",i);
				fprintf(fp,"MOV R%d,1\n",l);
				fprintf(fp,"L%d:\n",j);
				fclose(fp);
				freereg();
				printf("|| c:%d\n",c);
				return l;
			}
			else if(strcmp(t->varname,"!")==0)
			{ 
				l=codegen(t->left);
				i=getlabel();
				j=getlabel();
				fp=fopen("temp.xsm","a");
				fprintf(fp,"JZ R%d,L%d\n",l,i);
				fprintf(fp,"MOV R%d,0\n",l);
				fprintf(fp,"JMP L%d\n",j);
				fprintf(fp,"L%d:\n",i);
				fprintf(fp,"MOV R%d,1\n",l);
				fprintf(fp,"L%d:\n",j);
				fclose(fp);
				printf("! c:%d\n",c);
				return l;
			}
			break;

		case if_node:
			{	
				l=codegen(t->left);
				freereg();
					
				i=getlabel();
				fp=fopen("temp.xsm","a");
				fprintf(fp,"JZ R%d,L%d\n",l,i);
				fclose(fp);
				m=codegen(t->middle);
				if(t->right!=NULL)
				{
					j=getlabel();
					fp=fopen("temp.xsm","a");
					fprintf(fp,"JMP L%d\n",j);
					fprintf(fp,"L%d:\n",i);
					fclose(fp);
					r=codegen(t->right);
					fp=fopen("temp.xsm","a");
					fprintf(fp,"L%d:\n",j);
					fclose(fp);
					printf("if c:%d\n",c);
					return l;
					break;
				}
				else
				{
					fp=fopen("temp.xsm","a");
					fprintf(fp,"L%d:\n",i);
					fclose(fp);
					printf("if c:%d\n",c);
					return l;
					break;	
				}
			}

		case while_node:
			{
				
				
				i=getlabel();
				fp=fopen("temp.xsm","a");
				fprintf(fp,"L%d:\n",i);
				fclose(fp);
				push_label_stack(i);
				l=codegen(t->left);
				freereg();
				j=getlabel();
				fp=fopen("temp.xsm","a");
				fprintf(fp,"JZ R%d,L%d\n",l,j);
				fclose(fp);
				r=codegen(t->right);
				fp=fopen("temp.xsm","a");
				fprintf(fp,"JMP L%d\n",i);
				fprintf(fp,"L%d:\n",j);
				fclose(fp);
				pop_label_stack();
				printf("while c:%d\n",c);
				return l;
				break;
			}

		case continue_node:
			
			if(label_stack_top!=NULL)
			{
			 	fp=fopen("temp.xsm","a");
				fprintf(fp,"JMP L%d\n",label_stack_top->val);
				fclose(fp);
			}
			printf("continue c:%d\n",c);
			return -1;
			break;

		case break_node:
			
			if(label_stack_top!=NULL)
			{
				fp=fopen("temp.xsm","a");
				fprintf(fp,"JMP L%d\n",(label_stack_top->val)+1);
				fclose(fp);
			}
			printf("break c:%d\n",c);
			return -1;
			break;

		case sconst_node:
				
				i=getreg();
				fp=fopen("temp.xsm","a");
				fprintf(fp,"MOV R%d,%s\n",i,t->varname);
				fclose(fp);
				printf("sconst c:%d\n",c);
				return i;
				break;

		case arr_node:
				if(t->Gentry==NULL)
				{
					printf("HEY ITS NULL HERE ALSO___________\n");
				//exit(1);
				}
				v=getaddr(t);
				fp=fopen("temp.xsm","a");
				fprintf(fp,"MOV R%d,[R%d]\n",v,v);
				fclose(fp);
				printf("arr_node c:%d\n",c);
				return v;
				break;

		case func_node:
			
//SAVING MACHINE STATE by pushing all the registers before function call....
				for(n=0;n<=c;n++)
				{				
					fp=fopen("temp.xsm","a");
					fprintf(fp,"PUSH R%d\n",n);
					fclose(fp);
					sp1=sp1+1;
				}
//evaluate arguments and push.......
				arglist=t->left;
				while(arglist!=NULL)
				{
					x=codegen(arglist);
					fp=fopen("temp.xsm","a");
					fprintf(fp,"PUSH R%d\n",x);
					fclose(fp);
					sp1=sp1+1;
					freereg();
					arglist=arglist->middle;
				}
//space for return value....
				fp=fopen("temp.xsm","a");
				fprintf(fp,"PUSH R0\n");
				fclose(fp);
				sp1=sp1+1;
//function call.....
				global=t->Gentry;
				fp=fopen("temp.xsm","a");
				fprintf(fp,"CALL F%d\n",global->flabel);
				fclose(fp);
//poping and saving...return value....after call
				i=getreg();
				fp=fopen("temp.xsm","a");
				fprintf(fp,"POP R%d\n",i);
				fclose(fp);
				sp1=sp1-1;
//saving..arguments....
				arglist=t->left;
				j=getreg();
				while(arglist!=NULL)
				{
					fp=fopen("temp.xsm","a");
					fprintf(fp,"POP R%d\n",j);
					fclose(fp);
					sp1=sp1-1;
					arglist=arglist->middle;
				}
				freereg();
//poping MACHINE STATE......
				for(n=i-1;n>=0;n--)
				{				
					fp=fopen("temp.xsm","a");
					fprintf(fp,"POP R%d\n",n);
					fclose(fp);
					sp1=sp1-1;
				}
				printf("func c:%d\n",c);
				return i;
				break;

		case ret_node:
				
//evaluating return value and saving it space allocated....
				l=codegen(t->left);
				i=getreg();
				fp=fopen("temp.xsm","a");
				fprintf(fp,"MOV R%d,BP\n",i);
				fprintf(fp,"SUB R%d,2\n",i);
				fprintf(fp,"MOV [R%d],R%d\n",i,l);
				fclose(fp);
				
//pop all the local variables.....
				for(n=1;n<local_binding;n++)
				{
					fp=fopen("temp.xsm","a");
					fprintf(fp,"POP R%d\n",l);
					fclose(fp);
					sp1=sp1-1;
				}
				freereg();
				freereg();
//pop old BP value...
				fp=fopen("temp.xsm","a");
				fprintf(fp,"POP BP\n");
				fclose(fp);
				sp1=sp1-1;
//return stmt
				fp=fopen("temp.xsm","a");
				fprintf(fp,"RET\n");
				fclose(fp);
				printf("ret c:%d\n",c);
				return l;
				break;
		case field_node:
			
			v=getaddr(t);
			fp=fopen("temp.xsm","a");
			fprintf(fp,"MOV R%d,[R%d]\n",v,v);
			fclose(fp);
			printf("field c:%d\n",c);
			return v;
			break;
		case initialize_node:
			printf("init c:%d\n",c);
			for(n=0;n<=c;n++)
			{
			  fp=fopen("temp.xsm","a");
			  fprintf(fp,"PUSH R%d\n",n);
			  fclose(fp);
			  sp1=sp1+1;
			}
			i=scall("Heapset",0,0);
			for(n=c;n>=0;n--)
			{
			  fp=fopen("temp.xsm","a");
			  fprintf(fp,"POP R%d\n",n);
			  fclose(fp);
			  sp1=sp1-1;
			}
			//freereg();
			printf("init c:%d\n",c);
			return i;
			break;
		case new_node:
		case alloc_node:
			for(n=0;n<=c;n++)
			{
			  fp=fopen("temp.xsm","a");
			  fprintf(fp,"PUSH R%d\n",n);
			  fclose(fp);
			  sp1=sp1+1;
			}
			i=scall("Alloc",8,0);
			for(n=c;n>=0;n--)
			{
			  fp=fopen("temp.xsm","a");
			  fprintf(fp,"POP R%d\n",n);
			  fclose(fp);
			  sp1=sp1-1;
			}
			//freereg();
			printf("alloc or new c:%d\n",c);
			return i;
			break;
		case free_node:
			l=codegen(t->left);
			for(n=0;n<=c;n++)
			{
			  fp=fopen("temp.xsm","a");
			  fprintf(fp,"PUSH R%d\n",n);
			  fclose(fp);
			  sp1=sp1+1;
			}
			i=scall("Free",l,0);
			for(n=c;n>=0;n--)
			{
			  fp=fopen("temp.xsm","a");
			  fprintf(fp,"POP R%d\n",n);
			  fclose(fp);
			  sp1=sp1-1;
			}
			//freereg();
			printf("free c:%d\n",c);
			return i;
			break;
		case null_node:
			i=getreg();
			fp=fopen("temp.xsm","a");
			fprintf(fp,"MOV R%d, 0\n",i);
			fclose(fp);
			printf("null c:%d\n",c);
			return i;
			break;
		case fieldfunction_node:
//say self.obj.f1( );
			temp=t;
			local=LLookup(t->varname);
//get addr of field func node
			if(local==NULL)
			{
		   		i=getreg();
				fp=fopen("temp.xsm","a");
				fprintf(fp,"MOV R%d,%d\n",i,t->Gentry->binding);
				fclose(fp);
			}
			else
			{
				i=getreg();
				fp=fopen("temp.xsm","a");
				fprintf(fp,"MOV R%d,BP\n",i);
				fprintf(fp,"ADD R%d,%d\n",i,local->binding);
				fclose(fp);
			}
			while(temp->faccess->faccess!=NULL)
			{
				fp=fopen("temp.xsm","a");
				fprintf(fp,"MOV R%d,[R%d]\n",i,i);
				fprintf(fp,"ADD R%d,%d\n",i,temp->faccess->val);
				fclose(fp);
				temp=temp->faccess;
			}
//mov vfuncptr and heap location of obj at [addr] to registers 
			j=getreg();
			fp=fopen("temp.xsm","a");
			fprintf(fp,"MOV R%d,R%d\n",j,i);
			fprintf(fp,"ADD R%d,1\n",j);
			fprintf(fp,"MOV R%d,[R%d]\n",j,j);
			fprintf(fp,"MOV R%d,[R%d]\n",i,i);
			fclose(fp);
//get memberfunc entry of obj
			mfunc=Class_MLookup(temp->ctype,temp->faccess->varname);
			temp=temp->faccess;
//SAVING MACHINE STATE by pushing all the registers before function call....
			for(n=0;n<i;n++)
			{				
				fp=fopen("temp.xsm","a");
				fprintf(fp,"PUSH R%d\n",n);
				fclose(fp);
				sp1=sp1+1;
			}
//push self address
			fp=fopen("temp.xsm","a");
			fprintf(fp,"PUSH R%d\n",i);
			fclose(fp);
			sp1=sp1+1;
//push base address of vfunc table
			fp=fopen("temp.xsm","a");
			fprintf(fp,"PUSH R%d\n",j);
			fclose(fp);
			sp1=sp1+1;
//evaluate arguments and push.......
			arglist=temp->left;
			while(arglist!=NULL)
			{
				x=codegen(arglist);
				fp=fopen("temp.xsm","a");
				fprintf(fp,"PUSH R%d\n",x);
				fclose(fp);
				sp1=sp1+1;
				freereg();
				arglist=arglist->middle;
			}
//space for return value....
			fp=fopen("temp.xsm","a");
			fprintf(fp,"PUSH R0\n");
			fclose(fp);
			sp1=sp1+1;
//function call to the address in vfunc table..
			
			fp=fopen("temp.xsm","a");
			fprintf(fp,"ADD R%d,%d\n",j,mfunc->funcposition-1);
			fprintf(fp,"MOV R%d,[R%d]\n",j,j);
			fprintf(fp,"CALL R%d\n",j);
			fclose(fp);
//poping and saving...return value....after call
		//	i=getreg();
			fp=fopen("temp.xsm","a");
			fprintf(fp,"POP R%d\n",i);
			fclose(fp);
			sp1=sp1-1;
//dealloc........arguments....
			arglist=temp->left;
			while(arglist!=NULL)
			{
				fp=fopen("temp.xsm","a");
				fprintf(fp,"POP R%d\n",j);
				fclose(fp);
				sp1=sp1-1;
				arglist=arglist->middle;
			}
//poping self address
			fp=fopen("temp.xsm","a");
			fprintf(fp,"POP R%d\n",j);
			fprintf(fp,"POP R%d\n",j);
			fclose(fp);
			sp1=sp1-2;
			freereg();
//poping MACHINE STATE......
			for(n=i-1;n>=0;n--)
			{				
				fp=fopen("temp.xsm","a");
				fprintf(fp,"POP R%d\n",n);
				fclose(fp);
				sp1=sp1-1;
			}
			printf("fieldfunction c:%d\n",c);
			return i;
			break;

	}		
	

}




int getaddr(tnode *t)
{
  	int i,j,l,base;
 	FILE *fp;
	struct Lsymbol *local;
	struct Gsymbol *global;
	printf("get addr:");
	print_node(t);
   	if(t->nodetype==arr_node)
   	{
		if(t->Gentry==NULL)
		{
			printf("HEY ITS NULL___________\n");
			exit(1);
		}
		base=t->Gentry->binding;
		//printf("addr of base:%d\n",base);
 		l=codegen(t->left);
		//freereg();
		fp=fopen("temp.xsm","a");
		fprintf(fp,"ADD R%d,%d\n",l,t->Gentry->binding);
		fclose(fp);
		printf("arr_node c:%d\n",c);
		return l;
   	}

	if(t->nodetype==var_node)
	{
		local=LLookup(t->varname);
		if(local==NULL)
		{
	   		i=getreg();
			fp=fopen("temp.xsm","a");
			fprintf(fp,"MOV R%d,%d\n",i,t->Gentry->binding);
			fclose(fp);
			//printf("addr of global variable:%d\n",t->Gentry->binding);
			//freereg();
			printf("varnode-1 c:%d\n",c);
			return i;
		}
		else
		{
			i=getreg();
			fp=fopen("temp.xsm","a");
			fprintf(fp,"MOV R%d,BP\n",i);
			fprintf(fp,"ADD R%d,%d\n",i,local->binding);
			fclose(fp);
			//printf("relative addr of local variable:%d\n",local->binding);
			printf("varnode-2 c:%d\n",c);
			return i;
		}
	}
	if(t->nodetype==field_node)
	{
		int addr;
		struct tnode *temp;
		
		local=LLookup(t->varname);
		if(local==NULL)
		{
	   		i=getreg();
			fp=fopen("temp.xsm","a");
			fprintf(fp,"MOV R%d,%d\n",i,t->Gentry->binding);
			fclose(fp);
		}
		else
		{
			i=getreg();
			fp=fopen("temp.xsm","a");
			fprintf(fp,"MOV R%d,BP\n",i);
			fprintf(fp,"ADD R%d,%d\n",i,local->binding);
			fclose(fp);
		}
		fp=fopen("temp.xsm","a");
		fprintf(fp,"MOV R%d, [R%d]\n",i,i);
		fclose(fp);
		temp=t->faccess;
		while(temp!=NULL)
		{
			fp=fopen("temp.xsm","a");
////////
			fprintf(fp,"ADD R%d, %d\n",i,temp->val);
			fclose(fp);
			if(temp->faccess!=NULL)
			{
				fp=fopen("temp.xsm","a");
				fprintf(fp,"MOV R%d, [R%d]\n",i,i);
				fclose(fp);
			}
			temp=temp->faccess;
		}
		printf("field_node c:%d\n",c);
		return i;
	}
}



int getlabel()
{
	label++;	
	return label;
	
}

void insertlabel(char *labelname)
	{
		struct labeltable *temp=(struct labeltable*)malloc(sizeof(struct labeltable));
		
 		temp->name=malloc((strlen(labelname)+2)*sizeof(char));
		strcpy(temp->name,labelname);
		//temp->val=labelnum;
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
		printf("%s\t\t%d\n",temp->name,temp->address);
		
		temp=temp->next;
	}
}
int searchlabel(char *labelname)
{
	struct labeltable *temp=label_table_head;
	while(temp!=NULL)
	{
		if(strcmp(temp->name,labelname)==0)
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
	if(temp->next==NULL)
	{
		label_stack_bottom=NULL;
		label_stack_top=NULL;
	}
	else
	{
		while(temp->next!=NULL)
		{
			prev=temp;
			temp=temp->next;
		}
		label_stack_top=prev;
		label_stack_top->next=NULL;
		free(temp);
	}
}

int hasSameSignatureArg(struct Paramstruct *p1,struct tnode *t)
{

	struct Paramstruct *plist;
	plist=copylist(p1);
	plist=reverse_param(plist);
	while(plist!=NULL && t!=NULL)
	{
		if(plist->type!=t->type)
			return 0;
		plist=plist->next;
		t=t->middle;
	}
	if(plist!=NULL || t!=NULL)
		return 0;
	return 1;
}





