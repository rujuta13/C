#include<stdio.h>
#include<stdlib.h>
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

void reverse(List *L){
    node * p1, *p2, *temp;
    p1 = *L;
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

void main(){
    List L1, L2; //created 2 pointers of to node 
    L1 = (node *)malloc(sizeof(node *));
    L2 = (node *)malloc(sizeof(node *));
    L2 -> data = 2;
    L2 -> next = NULL;

    L1 -> data = 1;
    L1 -> next = L2;
    
    printf("Linked List: ");
    display(L1);
    printf("\nReversed: ");
    reverse(&L1);
    display(L1);
}