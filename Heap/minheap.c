#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct heap{
    int *A;
    int s;
    int last;
}heap;

void initHeap(heap *h){
    h->s = MAX;
    h->A = (int *)malloc(sizeof(int) * h->s);
    h->last = -1;
}

void levelorder(heap h){
    for (int i = 0; i <= h.last; i++)
		printf("%d ",h.A[i]);
    printf("\n");        
}

void adjust_min(heap *h){
    //parent = (child-1)//2 (floor div 2)
    int i = h->last;
   
    int parent;
    int temp;
    while(i > 0){
        parent = (i-1)/2;
        if(h->A[parent] > h->A[i])
            swap(&h->A[parent], &h->A[i]);

        i = (i-1)/2;
    }
}

void insert(heap *h, int key){
   //insert at (last+1)th location to preserve completeness
   h->A[++h->last] = key;
   int parent = h->A[(h->last-1)/2];

   //adjust only if newly added number is < parent
   if(key < parent)
       adjust_min(h);
   
}

