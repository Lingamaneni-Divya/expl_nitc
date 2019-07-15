#define op_node    1
#define assg_node  2
#define conn_node  3
#define const_node 4
#define read_node  5
#define var_node   6
#define write_node 7
typedef struct tnode
{
	int val;
	int type;
	char *varname;
	int nodetype;
	struct tnode *left,*middle,*right;
}tnode;


struct tnode* create_tree(int val,int type,char *varname,int nodetype,struct tnode *l,struct tnode *r);
void inorder(struct tnode *t);
void preorder(struct tnode *t);
void print_node(struct tnode *t);

int codegen(struct tnode *t);
int scall(char *fcode,int arg1, int arg2);
//void saveregs(int start,int end);
//void restoreregs(int start,int end);

