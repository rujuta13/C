#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

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

int height(aBST t){
    int i, height = 0;

    //tree is empty
    if(t.A[0] == INT_MIN)
        return -1;

    //find last node in the array
    for(i = t.s - 1; i >= 0; i--){
        if(t.A[i] != INT_MIN) 
            break;
    }
    // i is the index at which last
    // node is present

    //retracing till node
    while(i){
        i = (i- 1) / 2;        
        height++;
    }
    return height;
}

int countLeaf(aBST t){
    //tree empty
    if(t.A[0] == INT_MIN)
        return 0;

    //only root
    if(t.s == 1)
        return 1;
    
    int count = 0;
    int i = t.s 
    ;
    while(i){
        if(t.A[i] != INT_MIN){ 
            if(t.A[2*i + 1] == -1 && t.A[2*i + 2] == -1)
                count++;
            if(2*i + 1 >= t.s && 2*i + 2 >= t.s)
                count++;
        }
        i--;
    }
    return count;
}

int isComplete(aBST t){
	int flag = 1;
	for (int i = 0; i < t.s ; i++){
		if (t.A[i] == INT_MIN && t.A[i + 1] != INT_MIN){
			flag = 0;
			break;
		}
	}
	return flag;
}

void levelorder(aBST t){
    for (int i = 0; i < t.s; i++)
		if (t.A[i] != INT_MIN)
                printf("%d ",t.A[i]);
    printf("\n");        
}

void main(){
    aBST t;
    initaBST(&t);
    insert(&t, 8);
	insert(&t, 3);
	insert(&t, 1);
	insert(&t, 6);/*
	insert(&t, 4);
	insert(&t, 7);
	insert(&t, 10);
	insert(&t, 14);
	insert(&t, 13);*/

    printf("Height: %d\n", height(t));
    printf("Leaf Nodes: %d\n", countLeaf(t));
    printf("Complete? %d\n", isComplete(t));
    printf("Level Order: ");
    levelorder(t);
}