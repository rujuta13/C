#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node *left, *right;
}node;

typedef node *BST;

void initBST(BST *t){
	*t = NULL;
	return;
}

void insert(BST *t, int key){
	if(t == NULL){
		node *nn = (node *)malloc(sizeof(node *));
		*t = nn;
		return;
	}
	if(key == (*t)->data)
		return;

	if(key < (*t)->data){
		if((*t)->left != NULL)
			insert(&((*t)->left), key);
	}
	else
		if((*t)->right != NULL)
			insert(&((*t)->right), key);
		
}

void inorder(BST t){
	if(!t)	return;
	inorder(t -> left);
	printf("%d\t", t -> data);
	inorder(t -> right);
}

void postorder(BST t){
	if(!t)	return;
	postorder(t -> left);
	postorder(t -> right);
	printf("%d\t", t -> data);
}

void preorder(BST t){
	if(!t)	return;
	printf("%d\t", t -> data);
	preorder(t -> left);
	preorder(t -> right);
}

int countNodes(BST t){
	if(t == NULL)
		return 0;
	return 1 + countNodes(t->left) + countNodes(t->right);
}

int countLeaves(BST t){
	if(t == NULL)
		return 0;
	if(t->left == NULL && t->right == NULL)
		return 1;
	return countLeaves(t->left) + countLeaves(t->right);
}

int height(BST t) {
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

void main(){
	BST t;
	initBST(&t);
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
	inorder(t);
	printf("\n Postorder:\n");
	postorder(t);
	
	printf("\n Preorder:\n");
	preorder(t);
	
}
