typedef struct tnode
{
	int val;			//value of for the expression tree
	char *op;			//indicates the opertor branch
	struct tnode *left,*right;  	//left and right branches
}tnode;

/*Make a leaf tnode and set the value of val field*/
struct tnode* makeLeafNode(int n);

/*Make a tnode with opertor, left and right branches set*/
struct tnode* makeOperatorNode(char c,struct tnode *l,struct tnode *r);
void postfix(struct tnode *t);
void prefix(struct tnode *t);
int getreg();
void freereg();
int codegen(struct tnode*t);
void scall(char *fcode,int arg1,int arg2);
void infix(struct tnode *t);
