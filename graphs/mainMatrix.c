#include "graphMatrix.h"

void main(int s, char *A[]){
    //COMMAND LINE ARGUMENTS REQUIRED
    graph g;
    initGraph(&g, A[1]);
    DFS(g, 0);
    /*
    for(int i = 0; i<g.n; i++){
    	printf("Start node %d: ",i);
    	DFS(g, i);
    	printf("\n");
    }
    */
}
