#include <stdio.h>
#include <stdlib.h>
#include "heap.h"
#include "heapsort.h"

void main(){
    FILE *fp; 
    fp = fopen("numbers.txt", "r");

    if(!fp){
        ("Unable to open file");
        return;
    }

    heap h;
    initHeap(&h, 20);
    int key;

    for(int i = 0; i < 20; i ++){
		//reading numbers from input file
		fscanf(fp, "%d", &key); 
        insert(&h, key);
    }
    
    printf("Min-heap before sorting\n");
    display(h);

    //HeapSort(&h, 1);
    HeapSort(&h, 0);
    
    printf("Min-heap after sorting\n");
    display(h);
}
