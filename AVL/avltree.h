typedef struct node{
    int data;
    struct node *parent, *left, *right;
    int bf;
}node;

typedef node * avl;

void initAVL(avl *t);
void inorder(avl t);
void insert(avl *t, int key);