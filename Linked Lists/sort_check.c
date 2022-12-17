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

int sort_check(List L){
    node *p1, *p2;
    p1 = L;
    p2 = p1 -> next;

    if(L == 0 || L->next == 0)
        return 1;
    while(p2 != 0){
        if(p1->data > p2->data)
            return 0;

        p1 = p2;
        p2 = p2->next;
    }
    return 1;

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
    if(sort_check(L1) == 1)
        printf("Sorted List");
    else    
        printf("Unsorted List");
   
}