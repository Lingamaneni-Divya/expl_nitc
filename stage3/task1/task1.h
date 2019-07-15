#define read_node  1
#define write_node 2
#define assg_node  3
#define conn_node  4
#define const_node 5
#define var_node   6
#define aop_node   7
#define lop_node   8
#define if_node	   9
#define while_node 10

#define inttype   0
#define booltype  1
#define nulltype -1
struct tnode* create_tree(int val,int type,char *varname,int nodetype,struct tnode *l,struct tnode *m,struct tnode *r);
void preorder(struct tnode *t);
void print_node(struct tnode *t);
typedef struct tnode
{
	int val;
	int type;
	char *varname;
	int nodetype;
	struct tnode *left,*middle,*right;
}tnode;


