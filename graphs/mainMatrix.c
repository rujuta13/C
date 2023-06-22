#include "graphMatrix.h"

void main(int s, char *A[]){
    //COMMAND LINE ARGUMENTS REQUIRED
    graph g;
    initGraph(&g, A[1]);

    DFS(g, 3);
    printf("\n");
   
}
