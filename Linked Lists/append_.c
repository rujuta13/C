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
void append(List *L, int key){
    node * nn;
    nn = (node *)malloc(sizeof(node *));
    if(!nn) //if nn is NULL then return
        return;
    
    //nn not NULL:
    nn -> data = key;
    nn -> next = NULL;

    node * pn;
    pn = *L; // pn points to start of LL

    //LL empty
    if(pn == NULL){
        *L = nn;
        return;
    }

    while((pn -> next) != 0)
        pn = pn -> next;
    //traverse till last node

    pn -> next = nn;    
}

void main(){
    List L1, L2; //created 2 pointers of to node 
    //display(L1);
    L1 = (node *)malloc(sizeof(node *));
    L2 = (node *)malloc(sizeof(node *));

    L2 -> data = 2;
    L2 -> next = NULL;

    L1 -> data = 1;
    L1 -> next = L2;    
    
    printf("Linked List: ");
    display(L1);

    append(&L1, 3);

    printf("Linked List (after appending): ");
    display(L1);
    //append(&L1, 2);
   
}