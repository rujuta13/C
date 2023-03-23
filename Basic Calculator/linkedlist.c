#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
} node;

void init(node **head){
	(*head) = (node *) malloc(sizeof(node *));
	if((*head) == NULL)
		return;

	(*head) = NULL;
}

void display(node *L){
    node * pn;
    pn = L;
	
    //printf("[");
    while(pn != NULL){
        printf("%d", pn -> data);
        pn = pn -> next;
    }
    printf(" \n");

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

void append(node **L, int key){
    node * nn;
    nn = (node *)malloc(sizeof(node *));
    if(!nn) //if nn is NULL then return
        return;
    
    nn -> data = key;
    nn -> next = NULL;

    node * pn;
    pn = *L; 

    if(pn == NULL){
        *L = nn;
        return;
    }

    while((pn -> next) != 0)
        pn = pn -> next;

    pn -> next = nn;    
}

int count(node *L){
    int c = 0; 
    node * pn;
    pn = L;
    while(pn != 0){
        c ++;
        pn = pn -> next;
    }
    return c;
}


void reverse(node **L){
    node * p1, *p2, *temp;

    p1 = *L;
    if(p1 == NULL)
        return;
        
    p2 = p1 -> next;
    temp = NULL;
    p1 -> next = NULL;
    while(p2!=0){
        temp = p2 -> next;
        p2 -> next = p1; //reversing
        p1 = p2;
        p2 = temp; //increment p2
    }
    *L = p1;
}