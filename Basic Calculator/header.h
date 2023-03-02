typedef struct node{
    int data;
    struct node * next;
} node;

void display(node *);
void insert(node  **, int);
void append(node **, int);
void init(node **);
node *add(node *, node *);