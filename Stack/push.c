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
int isFull(stack s){
        return (s.top == s.size - 1);
    }

void push(stack *s, int key){
    if(isFull(*s)==1){
        printf("Error: Stack Overflow\n");
        return;
    }
    s -> top ++;
    (s -> A)[s->top] = key;
    
    
}
void main(){
    stack * s;
    init_stack(s, 5);
    push(s, 2);
    push(s, 5);
    push(s, 3);
    push(s, 4);
    push(s, 1);
    push(s, 6);
    
    //for(int i = 0; i < 5; i++)
    //    printf("%d ", s->A[i]);
    

}