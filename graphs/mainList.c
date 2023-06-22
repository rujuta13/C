#include "graphList.h"

void main(int s, char* A[]){
    graph g;
    initGraph(&g, A[1]);
    //displayGraph(g);

    //BFS from each start node
    //for(int i = 0; i<g.n; i++)
    //    BFS(g, i);
    spTree mst = Prims(g, 0);
    printMST(mst,9);
}