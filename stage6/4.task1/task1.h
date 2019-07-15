#define read_node   	1
#define write_node	2
#define assg_node  	3
#define conn_node    	4
#define iconst_node 	5
#define var_node    	6
#define aop_node   	7
#define lop_node   	8
#define if_node	   	9
#define while_node 	10
#define continue_node 	11
#define break_node 	12
#define sconst_node 	13
#define arr_node	14
#define func_node 	15
#define ret_node	16
#define field_node      17
#define alloc_node	18
#define initialize_node	19
#define free_node	20
#define null_node	21




#define nulltype -1
#define inttype   0
#define booltype  1
#define strtype   2


typedef struct tnode
{
	int val;
	struct Typetable *type;
	char *varname;
	int nodetype;
	struct Gsymbol *Gentry;
	struct tnode *left,*middle,*right,*faccess;
}tnode;


typedef struct Gsymbol
{
	char *name;
	struct Typetable *type;
	int size;
	int binding;
	struct Paramstruct *paramlist;
	int flabel;
	struct Gsymbol *next;
}Gsymbol;

typedef struct Paramstruct
{
	struct Typetable *type;
	char *name;	
	struct Paramstruct *next;

}Paramstruct;

typedef struct Lsymbol
{
	char *name;
	struct Typetable *type;
	int binding;
 	struct Lsymbol *next;
}Lsymbol;

typedef struct Typetable
{
	char *name;
	int size;
	struct Fieldlist *fields;
	struct Typetable *next;
}Typetable;

struct Fieldlist
{
	char *name;
	int fieldIndex;
	struct Typetable *type;
	struct Fieldlist *next;
}Fieldlist;


extern int declflag;
extern int bodyflag;
extern int typedeclflag;
int yyerror(char const *s);
int yyparse(void);
void GInstall(char *name,struct Typetable *type,int size,struct Paramstruct *paramlist);

struct Gsymbol *GLookup(char *name);

struct Paramstruct *create_param_node(char *name,struct Typetable *type);

void  PInstall(struct Paramstruct *Param);

struct Paramstruct *PLookup(char *pname);

void reset_paramlist();

void print_Gsymbol_table();

void print_paramlist(struct Paramstruct *paramlist);

struct tnode* create_tree(int val,struct Typetable *type,char *varname,int node_type,struct tnode*l,struct tnode *m,struct tnode *r);

//struct Typenode *create_typenode(char *type);

void name_equivalence(struct Typetable *function_rettype,char *function_name,struct Paramstruct *paramlist);

void createLsymbolEntries(struct Paramstruct *paramlist);

void LInstall(char *name,struct Typetable *type);

struct Lsymbol *LLookup(char *name);

void reset_Lsymbol_table();

void print_Lsymbol_table(char *name);

void typecheck(struct tnode *t);

void argcheck(char *function_name,struct tnode *t);

void print_node(struct tnode *t);

void preorder(struct tnode *t);

void TypeTableCreate();

struct Typetable *TLookup(char *name);

struct Typetable * TInstall(char *name,int size,struct Fieldlist *fields);

void FInstall(char *name,struct Typetable *type);

struct Fieldlist *field_check(char *name);

void reset_fieldlist();

struct Fieldlist *FLookup(Typetable *struct_type,char *name);

int getSize(Typetable *type);

void print_Typetable();




int getreg();

void freereg();

int scall(char *fcode,int arg1, int arg2);

void generate_code(struct tnode *t,char *fname);

int codegen(struct tnode *t);

int getaddr(tnode *t);

struct labeltable
	{
		char *name;
		int address;
		struct labeltable *next;
	};
struct labelstack
{
	int val;
	struct labelstack *next;

};	

int getlabel();

void insertlabel(char *labelname);

void print_label_table();

int searchlabel(char *labelname);

void push_label_stack(int num);

void pop_label_stack();

struct Paramstruct *reverse_param(struct Paramstruct *plist);

int count(struct Paramstruct *plist);

struct Paramstruct *copylist(struct Paramstruct *plist);
