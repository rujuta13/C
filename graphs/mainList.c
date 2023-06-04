#include "graphList.h"

void main(int s, char* A[]){
    graph g;
    initGraph(&g, A[1]);
    //displayGraph(g);

    printf("BFS\n");
    for(int i = 0; i<g.n; i++){
    	printf("Start=%d: ",i);
        BFS(g, i);
    }
        
    printf("\nDFS\n");
    for(int i = 0; i<g.n; i++){
    	printf("Start=%d: ",i);
        DFS(g, i);
    }
     
	Kruskal(g);
}
