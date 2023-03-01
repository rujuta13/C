#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <math.h>
#define MAX_STR_LEN 100

typedef struct stack{
    int *A;
    int size;
    int top;
} stack;

void init_stack(stack *s, int size){
    s -> A = (int *)malloc(sizeof(int)*size); 
    s -> size = size;
    s -> top = -1;
}

int isFull(stack s){
        return (s.top == s.size - 1);
}

void push(stack *s, int key){
    if(isFull(*s)==1){
        printf("Error: Stack Overflow\n");
        return;
    }
    (s -> A)[++ s->top] = key;
}

int pop(stack *s){
    return (s -> A)[s->top --]; 
}


int isOperator(char c){
    if(c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
		return 1;
    return 0;
}

int isNum(char c){
    if(c >= '0' && c <= '9') 
        return 1;
    return 0;
}

int Operate(int a, int b, char o){
    if(o == '+')
        return a+b;
    else if(o == '-')
        return a-b;
    else if(o == '*')
        return a*b;
    else if(o == '/')
        return a/b;
    else if(o == '^')
        return pow(a,b);
}

int evalPostfix(char expr[]){
    stack s;
    init_stack(&s, MAX_STR_LEN);

    int n1, n2, i=0;
    char *ch;
    while( i != '\"' ){
        if(isOperator(expr[i]) == 1){
            n2 = pop(&s);
            n1 = pop(&s);
            push(&s, Operate(n1, n2, expr[i]));
        }
        else if(isNum(expr[i]) == 1)
            push(&s, expr[i] - '0'); //convert char to int
        
        i++;
    }
    return pop(&s);
}

void main(){
    char expr[MAX_STR_LEN];
    printf("Enter postfix expression: ");
    scanf("%s", &expr);
    printf("Answer: %d", evalPostfix(expr));
}