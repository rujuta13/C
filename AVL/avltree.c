#include <stdio.h>
#include <stdlib.h>
#include "avltree.h"

void initAVL(avl *t){
    *t = NULL; 
}

node * createNode(int key){
    node *nn;
	nn = (node *)malloc(sizeof(node));
	if(!nn) 
        return NULL;
	
    nn -> data = key;
	nn -> right = NULL;
	nn -> left = NULL;
	nn -> parent = NULL;
    nn->bf = 0;
    return nn;
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

void inorder(avl t){
	if(!t)	return;
	inorder(t -> left);
	printf("key: %d  bf: %d\n", t -> data, t->bf);
	inorder(t -> right);
}

void adjustBF(avl *t){
    //newly added node is passed as arg
    node *p = *t;

    //we do not need to adjust BF of the new node
    p = p->parent;

    while(p){
        p->bf = height(p->left) - height(p->right);
        p = p->parent;
    }
}

node * getImbalance(avl *t){
    node *p = *t;
    node *im;
    //find imbalanced node
    while(p){
        if(p->bf == -2 || p->bf == 2){
            im = p;
            return im;
        }
        p = p->parent;
    }
    return NULL;
}

void LLrotate(avl *t, node *im){
    //imbalanced node is given as one parameter
    node *A = im;
    node *B = A -> left;
    node *Br = B ->right;
    node *Ap = A -> parent;

    //handling B's connection to its parent
    if(!Ap) //root is imbalanced (Ap is null)
        *t = B;
    else if(Ap->left == A) // A is on left of Ap
        Ap->left = B;
    else
        Ap->right = B;
    
    B->parent = Ap;

    B->right = A;
    A->parent = B;

    A->left = Br;
    if(Br)
        Br->parent = A;

    A->bf = 0;
    B->bf = 0;
    return;
}

void RRrotate(avl *t, node *im){
    //imbalanced node is given as one parameter
    node *A = im;
    node *B = A -> right;
    node *Bl = B ->left;
    node *Ap = A -> parent;

    //handling B's connection to its parent

    //root is imbalanced (Ap is null)
    if(!Ap) 
        *t = B;
    // A is on left of Ap
    else if(Ap->left == A) 
        Ap->left = B;
    // A is on right of Ap
    else
        Ap->right = B;
    
    B->parent = Ap;

    B->left = A;
    A->parent = B;

    A->right = Bl;
    if(Bl)
        Bl->parent = A;

    A->bf = 0;
    B->bf = 0;
    return;
}

void LRrotate(avl *t, node *im){
    RRrotate(t, im->left);
    LLrotate(t, im);
}

void RLrotate(avl *t, node *im){
    LLrotate(t, im->right);
    RRrotate(t, im);
}

void balanceTree(avl *t, node **nn){
    //update BF's
    adjustBF(nn);

    node *im; //imbalanced node
    im = getImbalance(t);
    
    if(!im)
        return;
    
    //imbalance is there
    printf("Imbalanced node: %d\n", im->data);
    //left imbalance
    if(im->bf == 2){
        if((*nn)->data < im->left->data)
            LLrotate(t, im);
        else
            LRrotate(t,im);
    }
    else if(im->bf == -2){
        if((*nn)->data < im->right->data)
            RLrotate(t,im);
        else
            RRrotate(t, im);
    }
}

void insert(avl *t, int key){
	node *nn;
    nn = createNode(key);
	
	//tree empty
	if(!(*t)){ 
		*t = nn;
		return;
	}
	
	node *p, *q = NULL;
	p = *t;

	while(p){
		if(key == p -> data){
            free(nn);
			return;
        }
		q = p;
		if(key < p -> data)
			p = p -> left;
		else
			p = p -> right;
	}
    //q points to a leaf node now
    nn->parent = q;

    //attach new node
	if(key < q -> data)
		q -> left = nn;
	else
		q -> right = nn;
    //node now inserted

    // we now adjust the imbalances
    balanceTree(t, &nn);
	return;
}