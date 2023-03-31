#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node *left, *right;
}node;

typedef struct stack{
    node *data;
    struct stack *next;
} stack;

void initStack(stack **head){
	*head = (stack *) malloc(sizeof(stack));
	if(*head == NULL)
		return;

	*head = NULL;
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

int isEmptyStack(stack *s){
    if(s == NULL)
        return 1;
    return 0;
}

/*
void pop(stack **s, node **popped){
    stack *temp = *s;
    
    if(isEmptyStack(*s)){
        (*popped) = NULL;
        return;
    }

    *s =  (*s) -> next;
    (*popped) = temp->data;
    free(temp);
}
*/

node *pop(stack **s){
    stack *temp = *s;
    node *popped;
    
    if(isEmptyStack(*s)){
        popped = NULL;
        return popped;
    }

    *s =  (*s) -> next;
    popped = temp->data;
    free(temp);
    return popped;
}
