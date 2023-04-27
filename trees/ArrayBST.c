#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct aBST{
    int *A;
    int s;
} aBST;

void insert(aBST *t, int key){
    int p = 0;

    //root node
    if(t->s == 0){
        t->A = (int *)malloc(sizeof(int));
        if(!(t->A))
            return;
        t->A[0] = key;
        (t->s) ++;
        return;
    }

    while(p < t->s && t->A[p] != INT_MIN){
        if(key == t->A[p])
            return;
        if(key < t->A[p])
            p = 2*p + 1;
        else
            p = 2*p + 2;
    }
    if(p < t->s && t->A[p] == INT_MIN){
        t->A[p] = key;
        return;
    }

    //no space left
    t->A = realloc(t->A, (p+1)*sizeof(int));
    if(!(t->A))
        return;
    
    for(int i = t->s; i < p; i++)
        t->A[i] = INT_MIN;
    
    t->A[p] = key;
    t->s = p+1;
}
void inorder(aBST t, int p){
	if(t.A[p] != INT_MIN && p < t.s){
        inorder(t, 2*p+1); 
        printf("%d  ", t.A[p]);
        inorder(t, 2*p+2);
    }
    return;
}

void preorder(aBST t, int p){
	if(t.A[p] != INT_MIN && p < t.s){
        printf("%d  ", t.A[p]);
        preorder(t, 2*p+1); 
        preorder(t, 2*p+2);
    }
    return;
}

void postorder(aBST t, int p){
	if(t.A[p] != INT_MIN && p < t.s){
        postorder(t, 2*p+1); 
        postorder(t, 2*p+2);
        printf("%d  ", t.A[p]);
    }
    return;
}


void main(){
    aBST t;
    initaBST(&t);
    insert(&t, 8);
	insert(&t, 3);
	insert(&t, 1);
	insert(&t, 6);
	insert(&t, 4);
	insert(&t, 7);
	insert(&t, 10);
	insert(&t, 14);
	insert(&t, 13);
/*
    printf("Inorder:\n");
    inorder(t, 0);
    printf("\nPreorder:\n");
    preorder(t, 0);
    printf("\nPostorder:\n");
    postorder(t, 0);    
    printf("\n");
    printf("Size: %d\n", t.s);
    */
    levelorder(t);
    
    printf("Leaf Nodes: %d\n", countLeaf(t));
    //printf("Complete? %d\n", isComplete(t));
printf("%d\n", t.s);
}