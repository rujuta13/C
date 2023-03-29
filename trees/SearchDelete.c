#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node *left, *right;
}node;

typedef node *BST;

int search(BST t, int key){
	//if key is found 1
	//if not found return 0
	node *p = t;

	//if tree is empty
	if(p == NULL)
		return 0;

	while(p){
		if(p -> data == key)
			return 1;
		if(p ->data < key)
			p = p -> right;
		else
			p = p -> left;
	}
	//number not found
	return 0;
	
}

int inorderPre(BST t, node *p){
	p = p-> left;

	if(p->right == NULL)
		return p->data;

	while(p->right != NULL){
		p = p->right;
	}
	return p->data;
}

void delete(BST *t, int key){
	node *p = *t; 
	node *q = NULL;
	
	//if tree empty
	if(*t == NULL)
		return;

	while(p != NULL){
		if(p -> data == key)
			break;
		q = p;
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
		if(q == NULL){
			*t = NULL;
			free(p);
			return;
		}
		if(p->data < q->data) //p == q->left
			q -> left = NULL;
		else
			q -> right = NULL; //p == q->right
		free(p);
		return;
	}

	//one child on the left
	if(p->left != NULL && p->right == NULL){
		if(p->left->data < q->data)
			q -> left = p ->left;
		else
			q -> right = p -> left;
		free(p);
		return;
	}

	//one child on the right
	if(p->left == NULL && p->right != NULL){
		if(p->right->data < q->data)
			q->left = p ->right;
		else
			q->right = p->right;
		free(p);
		return;
	}

	//two children	
	int inP = inorderPre(*t, p);
	p->data = inP;
	delete(&(p->left), inP);
	return;

	//delete
}