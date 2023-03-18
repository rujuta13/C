#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
} node;

typedef struct stack{
    node *data;
    struct stack *next;
} stack;


void initStack(stack **head){
	*head = (stack *) malloc(sizeof(stack *));
	if(*head == NULL)
		return;

	*head = NULL;
}

void displayStack(stack *s){
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

