#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

void main(){
    heap h;
    initHeap(&h,10);
    
    insert(&h,15);
    insert(&h, 12);
    insert(&h, 10);
    insert(&h, 6);
    insert(&h, 7);
    
    insert(&h, 5);
    display(h);
    printf("Deleted element is: %d\n",delete(&h));
    display(h);
}