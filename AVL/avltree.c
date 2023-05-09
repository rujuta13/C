#include <stdio.h>
#include <stdlib.h>
#include "avltree.h"

void initAVL(AVL *t){
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

int height(AVL t) {
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

void traverse(AVL t){
	if(!t)	return;
	traverse(t -> left);
    if(t->parent)
	    printf("name: %d  parent: %d  bf: %d\n", t -> data, t->parent->data, t->bf);
    else
        printf("name: %d  parent: NULL  bf: %d\n", t -> data, t->bf);
	traverse(t -> right);
}

void updateBF(AVL *t){
    //newly added node's parent is passed as arg
    node *p = *t;

    while(p){
        p->bf = height(p->left) - height(p->right);
        p = p->parent;
    }
}

AVL updateBFtree(AVL t){
    if(!t)	return NULL;
	updateBFtree(t -> left);
    t->bf = height(t->left) - height(t->right);
	updateBFtree(t -> right);
}

node * getImbalance(node **t){
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

void LLrotate(AVL *t, node *im){
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

    updateBF(&A);
    updateBF(&B);
    return;
}

void RRrotate(AVL *t, node *im){
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
 
    updateBF(&A);
    updateBF(&B);
    return;
}

void LRrotate(AVL *t, node *im){
    RRrotate(t, im->left);
    LLrotate(t, im);
}

void RLrotate(AVL *t, node *im){
    LLrotate(t, im->right);
    RRrotate(t, im);
}

void balanceTree(AVL *t, node *nn){
    node *im; //imbalanced node
    im = getImbalance(nn);
    
    //no imbalance
    if(!im)
        return;
    
    //imbalance is there
    //printf("Imbalanced node: %d\n", im->data);

    //left imbalance
    if(im->bf == 2){
        if(nn->data < im->left->data)
            LLrotate(t, im);
        else
            LRrotate(t,im);
    }
    //right imbalance
    else if(im->bf == -2){
        if(nn->data < im->right->data)
            RLrotate(t,im);
        else
            RRrotate(t, im);
    }
}

void insertNode(AVL *t, int key){
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

    //update BF's
    updateBF(&(nn->parent));

    // we now adjust the imbalances
    balanceTree(t, nn);
	return;
}

int inorderPre(AVL t, node *p){
	p = p-> left;

	if(p->right == NULL)
		return p->data;

	while(p->right != NULL){
		p = p->right;
	}
	return p->data;
}

void removeNode(AVL *t, int key){
	node *p = *t; 
	//node *q = NULL;
	
	//if tree empty
	if(*t == NULL)
		return;

    //searching for key in the tree
	while(p != NULL){
		if(p -> data == key)
			break;
		//q = p;
		if(p ->data < key)
			p = p -> right;
		else
			p = p -> left;
	}
	//p points to node to be deleted
	//q is parent of p

	//key not present in tree
	if(p == NULL)
		return;	

	//leaf node
	if(p->left == NULL && p->right == NULL){
		//p is root node and the only node
		if(p->parent == NULL){
			*t = NULL;
			free(p);
			return;
		}
		if(p->data < p->parent->data) //p == parent->left
			p->parent -> left = NULL;
		else
			p->parent -> right = NULL; //p == parent->right
		free(p);
		return;
	}

	//one child on the left
	if(p->left != NULL && p->right == NULL){
        if(p->parent == NULL){//root
            *t = p->left;
            p->left->parent = NULL;
        }
		else if(p->left->data < p->parent->data){
			p->parent -> left = p ->left;
            p->left->parent = p->parent;
        }
		else{
			p->parent -> right = p -> left;
            p->left->parent = p->parent;
        }
		free(p);
		return;
	}

	//one child on the right
	if(p->left == NULL && p->right != NULL){
        if(p->parent == NULL){//root
            *t = p->right;
            p->right->parent = NULL;
        }
		else if(p->right->data < p->parent->data){
			p->parent -> left = p ->right;
            p ->right->parent = p->parent;
        }
		else{
			p->parent->right = p -> right;
            p->right->parent = p->parent;
        }
		free(p);
		return;
	}

	//two children	
	int inP = inorderPre(*t, p);
	p->data = inP;
	removeNode(&(p->left), inP);
	return;
}