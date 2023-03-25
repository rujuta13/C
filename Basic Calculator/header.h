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

//bc headers
void removeZero(node **);
int compare(node *, node *);
void negate(node **);
node *add(node *, node *);
node *subtract(node *, node *);
node *multiply(node *, node *);
node *divide(node *, node *);
void evaluate(char *, int);
int precedence(char);
int isOperator(char);
node *operate(charstack*, nodestack* );

//linked list headers
void init(node **);
void display(node *);
void insert(node  **, int);
void append(node **, int);
int count(node *L);
void reverse(node **);

//stack headers
void initNodeStack(nodestack **);
void displayNodeStack(nodestack *);
void pushnode(nodestack **, node *);
int isEmptyNode(nodestack *);
void popnode(nodestack **, node **);

void initCharStack(charstack **);
void displayCharStack(charstack *);
void pushchar(charstack **, char);
node *popchar(charstack **);
int isEmptyChar(charstack *);
char peek(charstack *);