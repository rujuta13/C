#include "queue.h"
#include <limits.h>

void initQ(queue *q){
    q->front = NULL;
    q->rear = NULL;
}

void displayQ(queue q){
    printf("[");
    while(q.front != NULL){
        printf(" %d", q.front-> data);
        q.front = q.front -> next;
    }
    printf(" ]\n");

}

void enqueue(queue *q, int key){
    node *nn;
    nn = (node *)malloc(sizeof(node *));
    if(nn == 0)
        return;

    nn -> data = key;
    nn -> next = NULL;

    if(q->front == NULL){
        q->rear = nn;
        q->front = nn;
        return;
    }
    q->rear->next = nn;
    q->rear = nn;
}

int isEmpty(queue q){
    if(q.front == NULL)
    	return 1;
    return 0;
}

int dequeue(queue *q){
    if(isEmpty(*q))
        return INT_MIN;

    node *temp = q-> front;
    int val = temp ->data;
    q->front = q->front->next;
    free(temp);
    return val;
}
