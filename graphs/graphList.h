#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int vertex;
    int weight;
    struct node *next;
}node;


typedef struct graph{ 
    int n;
    node** adjList;
}graph;

void initGraph(graph *g, char *filename);
void displayGraph(graph g);