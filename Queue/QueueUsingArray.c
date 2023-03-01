#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
typedef struct queue{
    int *A;
    int capacity;
    int front;
    int rear;
    int size_count;
}queue;

void init_queue(queue *q, int n){
    q -> A = (int *) malloc(sizeof(int)*n); 
    q -> capacity = n;
    q -> front = -1;
    q -> rear = -1;
    q -> size_count = 0;
    return;
}

int isEmpty(queue q){
    if(q.size_count == 0)
        return 1;
    return 0;

}

int isFull(queue q){
    if(q.rear == q.capacity)
        return 1;
    return 0;
}

void display(queue q){
    printf("[ ");
    if(isEmpty(q) ==1){
        printf("]\n");
        return;
    }
    for(int i=q.front +1; i<=q.rear; i++)
        printf("%d ", q.A[i]);
    printf("]\n");
}

void enqueue(queue *q, int key){
    if(isFull(*q) == 1)
        return;

    q->A[++ q->rear] = key;
    q->size_count ++;
}

void dequeue(queue *q){
    if(isEmpty(*q)==1)
        return;
    else if(q->front == q->rear){
        q->front = q-> rear = -1;
        q->size_count = 0;
        return;
    }
    
    q->size_count --;    
    q->front ++;
    return;
}

void main(){
    queue q;
    init_queue(&q, 5);
    enqueue(&q, 1);
    display(q);
    printf("size %d\n\n", q.size_count);

    dequeue(&q);
    enqueue(&q, 2);
    enqueue(&q, 3);
    display(q);
    printf("size %d\n\n", q.size_count);
    
    dequeue(&q);
    display(q);
    printf("size %d\n\n", q.size_count);

    enqueue(&q, 4);
    
    enqueue(&q, 5);
    dequeue(&q);
    display(q);
    printf("size %d\n\n", q.size_count);
}