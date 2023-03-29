#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node * next;
} node;

typedef node * List;

int count(List L){
    int c = 0; 
    node * pn;
    pn = L;
    while(pn != 0){
        c ++;
        pn = pn -> next;
    }
    return c;
}
void main(){
    List L1, L2; //created 2 pointers of to node 
    L1 = (node *)malloc(sizeof(node));
    L2 = (node *)malloc(sizeof(node));
    L2 -> data = 2;
    L2 -> next = NULL;

    L1 -> data = 1;
    L1 -> next = L2;
    
    printf("No. of nodes: %d", count(L1));
   
}