#include <stdio.h>
#include <stdlib.h>
typedef struct stack{
    int *A;
    int size;
    int top;
} stack;

void init_stack(stack *s, int n){
    s -> A = (int *) malloc(sizeof(int)*n); 
    s -> size = n;
    s -> top = -1;
    return;
}


int isFull(stack *s){
        return (s->top == s->size - 1);
}
void display(stack s){
    printf("[ ");
    for(int i=0; i<=s.top; i++)
        printf("%d ", s.A[i]);
    printf("]\n");
}
void push(stack *s, int key){
    if(isFull(s)==1){
        printf("Error: Stack Overflow\n");
        return;
    }
    s -> top ++;
    (s -> A)[s->top] = key;
}

int pop(stack *s){
    int temp;
    temp = (s -> A)[s->top]; //holds value of top
    s -> top --;
    return temp;
}

void main(){
    stack s;
    init_stack(&s, 5);
    push(&s, 2);
    push(&s, 5);
    push(&s, 3);
    display(s);

    printf("Popped value: %d\n",pop(&s));
    
    push(&s, 4);
    push(&s, 1);
    push(&s, 6);
    display(s);
    printf("Popped value: %d\n",pop(&s));

    display(s);
}