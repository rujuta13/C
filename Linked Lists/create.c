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
void main(){
    List L1, L2; //created 2 pointers of to node 
    L1 = (node *)malloc(sizeof(node *));
    L2 = (node *)malloc(sizeof(node *));
    L2 -> data = 2;
    L2 -> next = NULL;

    L1 -> data = 1;
    L1 -> next = L2;
    
    display(L1);
   
}