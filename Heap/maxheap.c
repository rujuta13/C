#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

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

void swap(int *p1, int *p2){
    int temp = *p2;
    *p2 = *p1;
    *p1 = temp;
}

void adjust_max(heap *h){
    //parent = (child-1)//2 (floor div 2)
    int i = h->last;
   
    int parent;
    int temp;
    while(i > 0){
        parent = (i-1)/2;
        if(h->A[parent] < h->A[i])
            swap(&h->A[parent], &h->A[i]);

        i = (i-1)/2;
    }
}

void insert(heap *h, int key){
   //insert at (last+1)th location to preserve completeness
   h->A[++h->last] = key;
   int parent = h->A[(h->last-1)/2];

   //adjust only if newly added number is > parent
   if(key > parent)
       adjust_max(h);
   
}
void heapify(heap *h){
    int i = 0;
    int temp;
    while(i < h->last){
        //compare children
        int c1 = 2*i + 1; //left
        int c2 = 2*i + 2; //right
        if(c1 >= h->last && c2 >= h->last)
            break;
        if(h->A[i] < h->A[c1] && h->A[i] < h->A[c2]){
            if(h->A[c1] > h->A[c2]){
                swap(&h->A[c1], &h->A[i]);
                i = 2*i + 1;
            }
            else{
                swap(&h->A[c2], &h->A[i]);
                i = 2*i + 2;
            }
        }
        if(h->A[i] < h->A[c1]){
            swap(&h->A[c1], &h->A[i]);
            i = 2*i + 1;
        }
        if(h->A[i] < h->A[c2]){
            swap(&h->A[c2], &h->A[i]);
            i = 2*i + 2;
        }
    }
}
void remove(heap *h){
    //root is always deleted
    if(h->last == 0){
        h->last --;
        return;
    }
    h->A[0] = h->A[h->last --]; //last element now root
    heapify(h);
}

void main(){
    heap *h;
    initHeap(h);
    insert(h, 50);
    insert(h, 40);
    insert(h, 35);
    insert(h, 25);
    insert(h, 20);
    insert(h, 27);
    insert(h, 33);
    levelorder(*h);
    remove(h);
    levelorder(*h);
}