#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <math.h>
#include <limits.h>
typedef struct node{
    int data;
    struct node *next;
} node;

typedef struct stack{
    node *data;
    struct stack *next;
} stack;



void init(stack **head){
	*head = (stack *) malloc(sizeof(stack *));
	if(*head == NULL)
		return;

	*head = NULL;
}

void display(stack *s){
    stack * p;
    p = s;
    printf("[");
    while(p != 0){
        printf(" %d", p -> data);
        p = p -> next;
    }
    printf(" ]\n");

}
void push(stack **s, node *key){
    stack *nn;
    stack *temp = *s; 
    nn = (stack *)malloc(sizeof(stack ));
     if(nn == NULL)
        return;

    nn -> data = key;
    nn -> next = NULL;

    *s = nn;
    nn->next = temp;
}

int isEmpty(stack *s){
    if(s == NULL)
        return 1;
    return 0;
}

node *pop(stack **s){
    stack *temp = *s;
    node *popped;
    if(isEmpty(*s))
        return INT_MIN;

    *s =  (*s) -> next;
    popped = temp->data;
    free(temp);
    
    return popped;
}

int precedence(char operator) {
	switch (operator) {
		case '+':
		case '-':
			return 1;
		case '*':
		case '/':
			return 2;
		case '^':
			return 3;
		default:
			return -1;
	}
}

int isOperator(char ch) {
	return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

char *infix2postfix(char *infix) {
	int op = 0; //number of operators
    int s = strlen(infix);
    for(int i = 0; i < s; i ++){
        if(isOperator(infix[i]))
            op ++;
    }

    node *A[op + 1]; //no of numbers = op + 1

	
}

void main(){
    //stack *s =NULL;
    stack *s;
    init(&s);
    char *postfix;
    postfix = infix2postfix("1234+5678");
}