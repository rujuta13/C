#include <stdio.h>
#include <stdlib.h>
typedef struct queue{
    int data;
    struct queue * next;
} queue;

//queue * front = NULL; 
//queue * rear = NULL;

queue * front, * rear;

void display(){
    queue *pn = front;
    printf("[");
    while(pn != NULL){
        printf(" %d ", pn -> data);
        pn = pn -> next;
    }
    printf("]\n");

}

void enqueue(int key){
    queue * new = (queue *) malloc(sizeof(queue));
    new -> data = key;
    new -> next = NULL;

    if(front == NULL && rear == NULL){
		front = rear = new;
		return;
	}
    rear->next = new; // node attached
    rear = new; // rear appeneded

}

void dequeue(){
    queue *temp = front;
    if(front == NULL){
		printf("Queue is Empty\n");
		return;
	}

    else {
		front = front->next;
	}
	free(temp);
}
void main(){
    front = NULL;
    rear = NULL;
    enqueue(1);
    display();

    enqueue(2);
    display();

    dequeue();
    display();
    
    enqueue(3);
    display();
}
