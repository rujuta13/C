#include "graphList.h"

void main(int s, char* A[]){
    graph g;
    initGraph(&g, A[1]);
    displayGraph(g);
}