typedef struct node{
    int data;
    struct node *next;
} node;

typedef struct nodestack{
    node *data;
    struct nodestack *next;
} nodestack;

typedef struct charstack{
    char data;
    struct charstack *next;
} charstack;


void removeZero(node **);
int compare(node *, node *);
node *add(node *, node *);
node *subtract(node *, node *);
node *multiply(node *, node *);
node *divide(node *, node *);
void evaluate(char *, int);
int precedence(char);
int isOperator(char);

void init(node **);
void display(node *);
void insert(node  **, int);
void append(node **, int);
int count(node *L);
void reverse(node **);

void initNodeStack(nodestack **);
void displayNodeStack(nodestack *);
void pushnode(nodestack **, node *);
int isEmptyNode(nodestack *);
node *popnode(nodestack **);

void initCharStack(charstack **);
void displayCharStack(charstack *);
void pushchar(charstack **, char);
node *popchar(charstack **);
int isEmptyChar(charstack *);
char peek(charstack *);