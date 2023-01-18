#include <stdio.h>
#include <stdlib.h>
typedef struct queue{
    int *front, *rear;
    int size;
    int *A;
    int count;
} queue;

void initQueue(queue *q, int s){
    q->front = q->rear = -1;
    q->A = (int *)malloc(sizeof(int)*s);
    q->size = s;
    q->count = 0;
    return;
}

void display(queue *q){
    int i;
    printf("[");
    for(i = 0; i < (q->size); i++){
        printf("%d ", q->A[i]);
    }
    printf("]\n");
}

int isFull(queue *q){
    if(q->count == q->size)
        return 1;
    return 0;
}
void enqueue(queue *q, int key){
    printf("enqueue");
    if(isFull(q))
        return;
     q -> rear = *(q->rear + 1); //increment rear
     *(q -> rear) = key;
}
void main(){
    queue *Q;
    int s;
    printf("Enter size of required queue: ");
    scanf("%d", &s);
    printf("size: %d\n",s);
    initQueue(Q, s);
    printf("t2\n");

    enqueue(Q, 1);
    printf("t3\n");
    enqueue(Q, 2);
    enqueue(Q, 3);
    printf("t4\n");
    display(Q);
    printf("t5\n");
}