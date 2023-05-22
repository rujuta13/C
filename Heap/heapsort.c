#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

void HeapSort(heap *h, int type){
    //type 0 (maxheap) will give asc order
    //type 1 (minheap) will give desc order
    int hs[h->s];
    int temp;

    int end = h->last;
    while(h->last != -1){ //while heap is not empty 
        temp = delete(h, type);
        h->A[h->last + 1] = temp;
    }
    
    for(int i = 0; i <= end; i++)
        printf("%d ", h->A[i]);
}