typedef struct node{
    int data;
    struct node *parent, *left, *right;
    int bf;
}node;

typedef node * AVL;

void initAVL(AVL *t);
void traverse(AVL t);
void insertNode(AVL *t, int key);
node * removeNode(AVL *t, int key);