#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node * next;
} node;

typedef struct queue {
    node *front, *rear;
}queue;

void init_queue(queue *q){
    q->front = NULL;
    q->rear = NULL;
}

void display(queue q){
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

void dequeue(queue *q){
    if(q->front == NULL)
        return;

    node *temp = q-> front;
    q->front = q->front->next;
    free(temp);
}
void main(){
    queue q;
    init_queue(&q);
    display(q);
    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    display(q);
    dequeue(&q);
    display(q);
    dequeue(&q);
    display(q);
    dequeue(&q);
    display(q);
}