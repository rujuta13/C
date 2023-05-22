#include "header.h"
#include "helper.h"

void initGraph(graph *g, char *filename){
    FILE *fp = fopen(filename, "r");
    if(!fp)
        return;
    fscanf(fp, "%d", &g->n);
    g->A = (int **)malloc(g->n * sizeof(int *));
    for(int i =0; i < g->n ; i++){
        g->A[i] = (int *)malloc(g->n * sizeof(int));
        for(int j = 0; j < g->n; j++){
            fscanf(fp, "%d", &g->A[i][j]);
        }
    }
}

void BFS(graph g, int start){
    queue q;
    initQ(&q);
    enqueue(&q, 1);
    enqueue(&q, 1);
    enqueue(&q, 1);
    enqueue(&q, 1);
    displayQ(q);
    printf("%d\n",dequeue(&q));  
    printf("%d\n",dequeue(&q));  
    printf("%d\n",dequeue(&q));
    printf("%d\n",dequeue(&q));
    printf("%d\n",dequeue(&q));
}