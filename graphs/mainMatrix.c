#include "graphMatrix.h"

void main(int s, char *A[]){
    graph g;
    initGraph(&g, A[1]);
    for(int i = 0; i<g.n; i++){
    	printf("Start node %d: ",i);
    	BFS(g, i);
    	printf("\n");
    }
}
