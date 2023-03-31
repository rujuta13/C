#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node *left, *right;
}node;

typedef struct stack{
    node *data;
    struct stack *next;
} stack;

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
	stack *s;
	initStack(&s);
	node *p = t;

	while(p || isEmptyStack(s) == 0){
		if(p != NULL){ 
			//push node as we print it later
			push(&s, p);
			p = p->left;
		}
		else{
			p = pop(&s);
			printf("%d ", p->data);
			p = p->right;
		}
	}
}
/*
void postorder(BST t){
	stack *s;
	initStack(&s);
	node *p = t;

	while(p){
		if(p){ 
			//push node as we print it later
			push(&s, p);
			p = p->left;
			if(p ->right != NULL) 
				push(&s, p);
		}
		else{
			p = pop(&s);				
			printf("%d ", p->data);		
		}
	}
}
*/
void preorder(BST t){
	stack *s;
	initStack(&s);
	node *p = t;

	while(p || isEmptyStack(s) == 0){
		if(p != NULL){ 
			printf("%d ", p->data);
			//push node as we use it to traverse to rhs
			push(&s, p);
			p = p->left;
		}
		else{
			p = pop(&s);
			p = p->right;
		}
	}
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
	inorder(t);
	printf("\n");
	preorder(t);
	printf("\n");
	postorder(t);
}