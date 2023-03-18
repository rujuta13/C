#include <stdio.h>
#include <stdlib.h>
#include "header.h"

typedef struct node{
    int data;
    struct node *next;
} node;

typedef struct stack{
    node *data;
    struct stack *next;
} stack;

void main(){
	char A[100];
	printf("bc\n");
	scanf("%s", A);
	//printf("%s\n", A);
	int s = strlen(A);
	evaluate(A, s);
}