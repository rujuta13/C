#include "graphList.h"

node * createNode(int vertex, int weight){
    node *nn = (node *)malloc(sizeof(node));
    if(!nn)
        return NULL;

    nn -> vertex = vertex;
    nn -> weight = weight;
    nn -> next = NULL;
    return nn;
}

void initGraph(graph *g, char *filename){
    FILE *fp = fopen(filename, "r");
    if(!fp)
        return;

    fscanf(fp, "%d", &g->n);
    g->adjList = (node **)malloc(g->n * sizeof(node *));
    if(!g->adjList)
        return;

    //initialise adjlist to null
    for(int i =0; i < g->n ; i++)
        g->adjList[i]= NULL;
    
    int w;
    node *nn;
    for(int i =0; i < g->n ; i++){
        //printf("%d:  ",i);
        for(int j = 0; j < g->n; j++){
            //store weight
            fscanf(fp, "%d", &w);
            if(w){ //nn created only if edge exists
                nn = createNode(j, w);
                if(!g->adjList[i]){
                    g->adjList[i]= nn;
                }
                else{
                    nn->next = g->adjList[i];
                    g->adjList[i] = nn;
                }
                    //printf("%d-%d  ", g->adjList[i]->vertex,  g->adjList[i]->weight);
            }
        }
        //printf("\n");
    }
    printf("Graph created with %d vertices\n", g->n);
    return;
}

void displayGraph(graph g){
    node *p;
    for(int i = 0; i < g.n; i++){
        printf("%d:  ",i); //start vertex
        p = g.adjList[i];
        while(p){
            printf("%d-%d  ", p->vertex, p->weight);
            p = p->next;
        }
        printf("\n");
    }
}