#include <stdio.h>
#include <stdlib.h>

typedef struct graph{
    int **A;
    int n;
}graph;

void initGraph(graph *g, char *filename);
void display(graph g);
void BFS(graph g, int start);
