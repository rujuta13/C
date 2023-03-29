#include<stdio.h>
#include<stdlib.h>
#include <limits.h>
typedef struct node{
    int data;
    struct node * next;
} node;

typedef node * List;

void display(List L){
    node * pn;
    pn = L;
    printf("[");
    while(pn != 0){
        printf(" %d", pn -> data);
        pn = pn -> next;
    }
    printf(" ]\n");

}

int pop(List *L){
    node *p;
    p = *L;
    if(*L == 0)
        return INT_MIN;

    int ele = p -> data;
    *L = (*L) ->next;
    free(p);
    return ele;

}

void main(){
    List L1, L2; //created 2 pointers of to node 
    L1 = (node *)malloc(sizeof(node));
    L2 = (node *)malloc(sizeof(node));
    L2 -> data = 2;
    L2 -> next = NULL;

    L1 -> data = 1;
    L1 -> next = L2;
    
    printf("Linked List: ");
    display(L1);

    printf("After pop: ");
    pop(&L1);
    display(L1);
}