#include <stdio.h>
#include <stdlib.h>
#include "avltree.h"

void initAVL(avl *t){
    *t = NULL; 
}

int height(avl t) {
    //if tree empty or only root
	if(t == NULL)
		return -1;

    if(t->left == NULL && t->right == NULL)
        return 0;

    int lHeight = height(t -> left);
    int rHeight = height(t -> right);
    
    //max height is the height
    if(lHeight >= rHeight)
        return lHeight + 1;
    else 
        return rHeight + 1;
}

void adjustbf(avl t){
    if(!t)
        return;
    t->bf = height(t->left) - height(t->right);
}

node *insert(avl t, int key){
	if(t == NULL){
		node *nn = (node *)malloc(sizeof(node));
		t = nn;
		nn -> data = key;
		nn->left = nn->right = NULL;
		return t;
	}
	
	if(key < t->data)
		t->left = insert(t->left, key);
	else
		t->right = insert(t->right, key);
	return t;
}