#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

void main(){
    heap h;
    initHeap(&h, 10);

    //type = 0 for maxheap
    //type = 1 for minheap

    int type = 0; 
    
    insert(&h, 12, type);
    insert(&h, 7, type);
    insert(&h, 10, type);
    insert(&h, 6, type);
    insert(&h, 5, type);
    insert(&h, 15, type);
    display(h);
    HeapSort(&h,type);
}