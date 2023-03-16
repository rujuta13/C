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
	node *nn;
	nn = (node *)malloc(sizeof(node));
	if(!nn) return;
	
	nn -> right = NULL;
	nn -> left = NULL;
	nn -> data = key;
	
	node *p, *q = NULL;
	p = *t;
	
	//tree empty
	if(!p){ 
		*t = nn;
		return;
	}
	
	while(p){
		if(key == p -> data)
			return;
		q = p;
		if(key < p -> data)
			p = p -> left;
		else
			p = p -> right;
	}
	if(key < q -> data)
		q -> left = nn;
	else
		q -> right = nn;
	return;

}

void inorder(BST t){
	if(!t)	return;
	inorder(t -> left);
	printf("%d\t", t -> data);
	inorder(t -> right);
}

void main(){
	BST t;
	initBST(&t);
	insert(&t, 100);
	insert(&t, 75);
	insert(&t, 80);
	inorder(t);
}
