#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

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