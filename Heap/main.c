#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct heap{
    int *A;
    int s;
    int last;
}heap;

void main(){
    heap *h;
    initHeap(h);
    insert(h, 16);
    insert(h, 14);
    insert(h, 10);
    insert(h, 8);
    insert(h, 7);
    insert(h, 9);
    insert(h, 3);
    insert(h, 2);
    insert(h, 4);
    insert(h, 1);
    insert(h, 15);
    levelorder(*h);
}