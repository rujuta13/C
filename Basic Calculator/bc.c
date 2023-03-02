#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include <ctype.h>

typedef struct node{
    int data;
    struct node * next;
} node;

void display(node *L){
    node * pn;
    pn = L;
	
    printf("[");
    while(pn != NULL){
        printf(" %d", pn -> data);
        pn = pn -> next;
    }
    printf(" ]\n");

}

void insert(node  **head, int key){
    	node * nn;
    	nn = (node *)malloc(sizeof(node *));
    	if(!nn) 
        	return;
    
    	nn -> data = key;
	nn -> next = (*head);
	(*head) = nn;
}

void init(node **head){
	(*head) = (node *) malloc(sizeof(node *));
	if((*head) == NULL)
		return;

	(*head) = NULL;
}


void main(){
	node *n1, *n2;
	init(&n1);
	init(&n2);
	//insert(&n1, 1);
	
	char *A;
	printf("bc\n");
	//scanf("\n %s", A);
	A = "123+456";
	int s = strlen(A);
	//printf("Size %d\n", strlen(A));

	//first number
	
	
	int i = 0;
	while(i < s && isdigit(A[i]) != 0) { //A[i] - '0' >= 0 && A[i] - '0' <= 9){
		//printf("%c\n", A[i]);
		insert(&n1, A[i] - '0');
		i++;
	}
	display(n1);

	i += 1; //skip '+' symbol
	
	//second number
	for(; i < s; i ++){
		//printf("%c\n", A[i]);
		insert(&n2, A[i] - '0');
	}
	display(n2);
	
}