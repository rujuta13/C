#include "header.h"
#include "queue.h"

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
	int *visited = (int *)calloc(g.n, sizeof(int));

	enqueue(&q, start);
	visited[start] = 1;
	int v;
	while(!isEmpty(q)){
		v = dequeue(&q);
		printf("%d ", v);
		
		for(int i = 0; i<g.n; i++){
			if(g.A[v][i] && visited[i]!=1){
				enqueue(&q, i);
				visited[i]=1;
			}
		}
	}
}
