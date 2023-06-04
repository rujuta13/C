#include <stdio.h>
#include <stdlib.h>

typedef struct graphNode{
    int vertex;
    int weight;
    struct graphNode *next;
}graphNode;


typedef struct graph{ 
    int n;
    graphNode** adjList;
}graph;

void initGraph(graph *g, char *filename);
void displayGraph(graph g);
void BFS(graph g, int start);
void DFS(graph g, int start);
