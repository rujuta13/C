#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node * next;
} node;

typedef struct queue {
    node *front, *rear;
}queue;

void initQ(queue *q);
void enqueue(queue *q, int key);
int dequeue(queue *q);
int isEmpty(queue q);
