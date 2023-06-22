#include "graphMatrix.h"
#include "queue.h"
#include "stack.h"

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
	while(!isEmptyQ(q)){
		v = dequeue(&q);
		printf("%d ", v);
		
		for(int i = 0; i<g.n; i++){
			if(g.A[v][i] && visited[i]==0){
				enqueue(&q, i);
				visited[i]=1;
			}
		}
	}
}

void DFS(graph g, int start) {
    stack *s;
    initS(&s);
    int *visited = (int *)calloc(g.n, sizeof(int));

    visited[start] = 1;
    push(&s, start);
	int v, i;
    while (!isEmptyS(s)) {
        v = pop(&s);
        printf("%d ", v);

        for (i = 0; i < g.n; i++) {
            if (g.A[v][i] && visited[i] == 0) {
                visited[i] = 1;
                push(&s, i);
            }
        }
    }
}

int* dijkstras(graph g, int start){
  int *cost= (int *)malloc(sizeof(int) * g.n);
  if(!cost)
    return NULL;

  int *visited = (int *)calloc(g.n, sizeof(int));
  if(!visited){
    free(cost);
    return NULL;
  }  
  for(int i = 0; i < g.n; i++){
    if(g.A[start][i])
      cost[i] = g.A[start][i];
    else
      cost[i] = INT_MAX;
  }
  
  visited[start] = 1;
  int mini, min;
  
  for(int i = 0; i < g.n; i++){
    min = INT_MAX;
    for(int j = 0; j < g.n; j++){
      if(visited[j] == 0 && cost[j] < min){
        min = cost[j];
        mini = j;
      }
    }
    visited[mini] = 1;

    //relaxation
    for(int j = 0; j < g.n; j++){
      if(!visited[j]){
        if(cost[j] > min + g.A[mini][j])
          cost[j] = min + g.A[mini][j];
      }
    }
  }
  return cost;
}