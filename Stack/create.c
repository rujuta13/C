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


int isEmpty(stack s){
        return (s.top == -1);
    }
void main(){
    stack *s;
    int n;
    init_stack(s, n);
}