#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct graphNode{
    int vertex;
    int weight;
    struct graphNode *next;
}graphNode;


typedef struct graph{ 
    int n;
    graphNode** adjList;
}graph;

typedef graphNode **spTree;
void initGraph(graph *g, char *filename);
void displayGraph(graph g);
void BFS(graph g, int start);
spTree Prims(graph G, int s);
void printMST(spTree t, int num);
