#include "header.h"

void main(){
    graph g;
    initGraph(&g, "graph.txt");
    BFS(g, 0);
}