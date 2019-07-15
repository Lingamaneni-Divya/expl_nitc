#define read_node  1
#define write_node 2
#define assg_node  3
#define conn_node  4
#define iconst_node 5
#define var_node   6
#define aop_node   7
#define lop_node   8
#define if_node	   9
#define while_node 10
#define continue_node 11
#define break_node 12
#define sconst_node 13


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
	struct Gsymbol *next;
}Gsymbol;
struct labeltable
	{
		int val;
		int address;
		struct labeltable *next;
	};
struct labelstack
{
	int val;
	struct labelstack *next;

};	
void Install(char *name,int type,int size);
struct Gsymbol *Lookup(char *name);
void print_symbol_table();
struct tnode* create_tree(int val,int type,char *varname,int node_type,struct tnode*l,struct tnode *m,struct tnode *r);
void typecheck(struct tnode *t);
void print_node(struct tnode *t);
void preorder(struct tnode *t);
int getreg();
void freereg();
int codegen(struct tnode *t);
int scall(char *fcode,int arg1, int arg2);
int getlabel();
void insertlabel(int labelnum);
void print_label_table();
int searchlabel(int labelnum);
void push_label_stack(int num);
void pop_label_stack();

extern int declflag;
extern int instcnt,wrapcnt;
extern struct labeltable *label_table_head,*label_table_tail;
