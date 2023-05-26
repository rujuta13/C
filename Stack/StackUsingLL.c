#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
typedef struct stack{
    int data;
    struct stack * next;
} stack;

void initS(stack **head){
	*head = (stack *) malloc(sizeof(stack));
	if(*head == NULL)
		return;

	*head = NULL;
}

void displayS(stack *s){
    stack * p;
    p = s;
    printf("[");
    while(p != 0){
        printf(" %d", p -> data);
        p = p -> next;
    }
    printf(" ]\n");

}

void push(stack **s, int key){
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

int pop(stack **s){
    stack *temp = *s;
    int popped;
    if(isEmptyS(*s)){
        printf("Stack empty\n");
        return INT_MIN;
    }

    *s =  (*s) -> next;
    popped = temp->data;
    free(temp);
    
    return popped;
}

void main(){
    //stack *s =NULL;
    stack *s;
    initS(&s);
    push(&s, 1); 
    push(&s, 2);
    push(&s, 3);
    displayS(s);
    printf("Popped %d\n", pop(&s));
    push(&s, 4);
    displayS(s);
    printf("Popped %d\n", pop(&s));
    printf("Popped %d\n", pop(&s));
    printf("Popped %d\n", pop(&s));
    displayS(s);
    printf("Popped %d\n", pop(&s));
    
}