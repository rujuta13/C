typedef struct node{
    int data;
    struct node *next;
} node;

typedef struct stack{
    node *data;
    struct stack *next;
} stack;

void removeZero(node **);
int compare(node *, node *);
node *add(node *, node *);
node *subtract(node *, node *);
node *multiply(node *, node *);
node *divide(node *, node *);
void evaluate(char , int);
int precedence(char);
int isOperator(char);

void init(stack **);
void display(stack *);
void push(stack **, node *);
int isEmpty(stack *);
node *pop(stack **);

