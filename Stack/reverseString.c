#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//stack

typedef struct stack{
    char *A;
    int size;
    int top;
} stack;

void *init_stack(stack *s, int size){
    s -> A = (char *) malloc(sizeof(char)*size); 
    s -> size = size;
    s -> top = -1;
}


int isFull(stack *s){
        return (s->top == s->size - 1);
}

int isEmpty(stack *s){
    if(s-> top == -1)
        return 1;
    return 0;
}

void push(stack *s, char key){
    if(isFull(s)==1){
        printf("Error: Stack Overflow\n");
        return;
    }
    
    (s -> A)[++ s->top] = key;
}

char pop(stack *s){
    char ele;
    if(isEmpty(s) == 1)
        return '0';
    return s->A[s->top --];
}

void revString(char str1[]){
    stack s; 
    init_stack(&s, strlen(str1));

    //store string in stack
    for(int i = 0; i < strlen(str1); i++){
        push(&s, str1[i]);
    }

    for(int j = 0; j < strlen(str1); j ++){
        str1[j] = pop(&s);
    }
}

void main(){
    char str[] = "hello";
    revString(str);
    printf("%s", str);
}
