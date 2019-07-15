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

#define nulltype -1
#define inttype   0
#define booltype  1
#define strtype   2


typedef struct tnode
{
	int val;
	int type;
	char *varname;
	int nodetype;
	struct Gsymbol *Gentry;
	struct tnode *left,*middle,*right;
}tnode;


typedef struct Gsymbol
{
	char *name;
	int type;
	int size;
	int binding;
	struct Paramstruct *paramlist;
	int flabel;
	struct Gsymbol *next;
}Gsymbol;

typedef struct Paramstruct
{
	int type;
	char *name;	
	struct Paramstruct *next;

}Paramstruct;

typedef struct Lsymbol
{
	char *name;
	int type;
	int binding;
 	struct Lsymbol *next;
}Lsymbol;

typedef struct Typenode
{
	int type;
}Typenode;
extern int declflag;
extern int bodyflag;

int yyerror(char const *s);
int yyparse(void);
void GInstall(char *name,int type,int size,struct Paramstruct *paramlist);

struct Gsymbol *GLookup(char *name);

struct Paramstruct *create_param_node(char *name,int type);

struct Paramstruct *PInstall(struct Paramstruct *Paramlist,struct Paramstruct *Param);

struct Paramstruct *PLookup(struct Paramstruct *Paramlist,char *pname);

void print_Gsymbol_table();

void print_paramlist(struct Paramstruct *paramlist);

struct tnode* create_tree(int val,int type,char *varname,int node_type,struct tnode*l,struct tnode *m,struct tnode *r);

struct Typenode *create_typenode(int type);

void name_equivalence(int function_rettype,char *function_name,struct Paramstruct *paramlist);

void createLsymbolEntries(struct Paramstruct *paramlist);

void LInstall(char *name,int type);

struct Lsymbol *LLookup(char *name);

void reset_Lsymbol_table();

void print_Lsymbol_table(char *name);

void typecheck(struct tnode *t);

void argcheck(char *function_name,struct tnode *t);

void print_node(struct tnode *t);

void preorder(struct tnode *t);

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


