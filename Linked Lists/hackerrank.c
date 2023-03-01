#include <stdio.h>
#include <stdlib.h>
typedef struct llist{
    int data;
    struct node * next;
} llist;
void reversePrint(llist* head) {
    llist * p = head;
    
    if(p == NULL)
        return;
    reversePrint(p -> next);
    printf("%d\n", p->data);
}