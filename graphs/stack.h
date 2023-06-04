#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
typedef struct stack{
    int data;
    struct stack * next;
} stack;

void initS(stack **head);
void push(stack **s, int key);
int isEmptyS(stack *s);
int pop(stack **s);