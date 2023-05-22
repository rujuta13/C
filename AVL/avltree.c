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

void balanceInsert(AVL *t, node *nn){
    node *im; //imbalanced node
    im = getImbalance(&nn);
    
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
    balanceInsert(t, nn);
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

void balanceDelete(AVL *t, node *nn){
    node *im; //imbalanced node
    im = getImbalance(&nn);
    
    //no imbalance
    if(!im)
        return;

    if(im -> bf == 2){//left
        if(im->left->bf == -1)
            LRrotate(t, im);
        else //Case 0, 1
            LLrotate(t, im);
    }
    else{//right
        if(im->right->bf == 1)
            RLrotate(t, im);
        else //Case 0, 1
            RRrotate(t, im);
    }
}

node * removeNode(AVL *t, int key){
    //tree empty
    if(*t == NULL)
		return *t;

    node *p = *t;
    node *temp;
    while (p) {
        if(key == p->data)
			break;
        if (key < p->data)
            p = p->left;
        else 
            p = p->right;
    }
    //now p points to node to be deleted

    if (!p) //element not in the tree
        return *t;

    //leaf node
    if (!p->left && !p->right){
        //p is root node and the only node
        if (p == *t)
            *t = NULL;
        else {
            if (p->parent->left == p) //p is left child
                p->parent->left = NULL;
            else //p is the right child
                p->parent->right = NULL;
            updateBF(&p->parent);
            balanceDelete(t, p->parent);
        }
        free(p);
        return *t;
    }

    //one child (left)
    else if(p->left && !p->right){
        if(p->parent == NULL)//root 
            *t = p->left;
        else if (p->parent->left == p)
            p->parent->left = p->left;
        else
            p->parent->right = p->left;
        
        p->left->parent = p->parent;
        updateBF(&p->left->parent);
        balanceDelete(t, p->left->parent);  
        
        free(p);
        return *t;
    } 
    //one child (right)
    else if (!p->left && p->right){
        if(p->parent == NULL)//root 
            *t = p->right;
        else if (p->parent->left == p) //current node is left child
            p->parent->left = p->right;
        else
            p->parent->right = p->right;
        p->right->parent = p->parent;
        
        updateBF(&p->right->parent);
        balanceDelete(t, p->right->parent);  
        free(p);
        return *t;
    }

    //two children
    else {
        int inP = inorderPre(*t, p);
        p->data = inP;
        p->left = removeNode(&(p->left), inP);
    }
    return *t;
}