#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct aBST{
    int *A;
    int s;
} aBST;

void initaBST(aBST *t){
    t->A = NULL;
    t->s = 0;
}

void insert(aBST *t, int key){
    int p = 0;

    //root node
    if(t->s == 0){
        t->A = (int *)malloc(sizeof(int));
        if(t->A == 0)
            return;
        t->A[0] = key;
        t->s ++;
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
    if(p < t->s){
        t->A[p] = key;
        return;
    }

    //no space left
    t->A = realloc(t->A, (p+1)*sizeof(int));
    if(t->A == NULL)
        return;
    
    for(int i = t->s; i < p; i++)
        t->A[i] = INT_MIN;
    t->s = p+1;
    t->A[p] = key;
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

int isComplete(aBST t){
	int i;
	int p = 1;
	for (i = 0; i < t.s - 1; i++)
	{
		if (t.A[i] == INT_MIN && t.A[i + 1] != INT_MIN){
			p = 0;
			break;
		}
	}
	return p;
}

int countLeaf(aBST t){
    
}
/*
1. Height of the tree.
2. Count of leaf nodes.
3. Is Complete?
4. Level order.
*/

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

    printf("Inorder:\n");
    inorder(t, 0);
    printf("\nPreorder:\n");
    preorder(t, 0);
    printf("\nPostorder:\n");
    postorder(t, 0);    
    printf("\n");
    printf("Leaf Nodes: %d\n");
}