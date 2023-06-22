#include "header.h"

//Stacks using NODE * as data
void initNodeStack(nodestack **head){
	*head = (nodestack *) malloc(sizeof(nodestack));
	if(*head == NULL)
		return;

	*head = NULL;
}

void displayNodeStack(nodestack *s){
    nodestack * p;
    p = s;
    printf("[\n");
    while(p != 0){
        display(p->data);
        p = p -> next;
    }
    printf("]\n");

}

void pushnode(nodestack **s, node *key){
    nodestack *nn;
    nodestack *temp = *s; 
    nn = (nodestack *)malloc(sizeof(nodestack ));
     if(nn == NULL)
        return;

    nn -> data = key;
    nn -> next = NULL;

    *s = nn;
    nn->next = temp;
}

int isEmptyNode(nodestack *s){
    if(s == NULL)
        return 1;
    return 0;
}

node * popnode(nodestack **s){
    nodestack *temp = *s;
    nodestack *popped;
    
    if(isEmptyNode(*s)){
        popped = NULL;
        return popped;
    }

    *s =  (*s) -> next;
    popped = temp->data;
    free(temp);
    return popped;
}

//Stacks using CHAR as data
void initCharStack(charstack **head){
	*head = (charstack *) malloc(sizeof(charstack));
	if(*head == NULL)
		return;

	*head = NULL;
}

void displayCharStack(charstack *s){
    charstack * p;
    p = s;
    printf("[");
    while(p != NULL){
        printf(" %c", p->data);
        p = p -> next;
    }
    printf(" ]\n");

}

void pushchar(charstack **s, char key){
    charstack *nn;
    charstack *temp = *s; 
    nn = (charstack *)malloc(sizeof(charstack ));
     if(nn == NULL)
        return;

    nn -> data = key;
    nn -> next = NULL;

    *s = nn;
    nn->next = temp;
}

int isEmptyChar(charstack *s){
    if(s == NULL)
        return 1;
    return 0;
}

char popchar(charstack **s){
    charstack *temp = *s;
    char popped;
    if(isEmptyChar(*s))
        return ' ';

    *s =  (*s) -> next;
    popped = temp->data;
    free(temp);
    
    return popped;
}

char peek(charstack *s){
    /*
    if(isEmptyChar(s))
        return ' ';*/
    return s->data;
}