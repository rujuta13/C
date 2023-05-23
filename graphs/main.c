#include "header.h"

void main(){
    graph g;
    initGraph(&g, "graph.txt");
    for(int i = 0; i<g.n; i++){
    	printf("Start node %d: ",i);
    	BFS(g, i);
    	printf("\n");
    }
}
