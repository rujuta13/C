typedef struct node{
    int data;
    struct node *parent, *left, *right;
    int bf;
}node;

typedef node * avl;

void initAVL(avl *t);
node *insert(avl t, int key);
void adjustbf(avl t);