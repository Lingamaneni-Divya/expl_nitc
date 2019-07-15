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
void Install(char *name,int type,int size);
struct Gsymbol *Lookup(char *name);
void print_symbol_table();
struct tnode* create_tree(int val,int type,char *varname,int node_type,struct tnode*l,struct tnode *m,struct tnode *r);
void typecheck(struct tnode *t);
void print_node(struct tnode *t);
void preorder(struct tnode *t);


extern int declflag;
