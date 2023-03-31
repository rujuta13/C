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

node *insert(BST t, int key){
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
	t = insert(t, 8);
	t = insert(t, 3);

	t = insert(t, 1);
	t = insert(t, 6);
	t = insert(t, 4);
	t = insert(t, 7);
	t = insert(t, 10);
	t = insert(t, 14);
	t = insert(t, 13);
	
	printf("Inorder:\n");
	inorder(t);
	printf("\n Postorder:\n");
	postorder(t);
	
	printf("\n Preorder:\n");
	preorder(t);
}
