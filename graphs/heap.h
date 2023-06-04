#ifndef HEAP_H
#define HEAP_H

typedef struct heap{
    int *A;
    int s;
    int last;
}heap;

void initHeap(heap *h, int s);
void display(heap h);
void insert(heap *h, int key);

void HeapSort(heap *h, int order);
#endif
