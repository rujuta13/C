#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <limits.h>

typedef struct node{
	int data;
	struct node *left, *right;
}node;

typedef node *BT;

void initBT(BT *t){
	*t = NULL;
	return;
}

void inorder(BT t){
	if(!t)	
        return;
	inorder(t -> left);
	printf("%d ", t -> data);
	inorder(t -> right);
}

int coinToss(){
    int num = (rand() % 2) ;
    return num;
}

void insert(BT *t, int key){	
    node *p, *nn;
    int currCount, i = 0;

    nn = malloc(sizeof(struct node));
    nn -> data = key;
    nn -> left = NULL;
    nn -> right = NULL;

    if(*t == NULL){
        *t = nn;
        return;
    }

    p = *t; 
    while(p){
        //move left if 0
		if(coinToss() == 0){
            if(p->left == NULL){
                p -> left = nn;
                return;
            }
            else
                p = p -> left;
        }
    
        //move right if 1
        else{
            if(p->right == NULL){
                p -> right = nn;
                return;
            }
            else
                p = p -> right;
        }
	}
    
}

int maxValue(BT t)
{
    if (t == NULL) 
        return INT_MIN;
 
    int leftMax = maxValue(t->left);
    int rightMax = maxValue(t->right);
 
    int value = 0;
	//if element present in left subtree
    if (leftMax > rightMax)
        value = leftMax;
	//if element present in right subtree
    else 
        value = rightMax;
	
    if (value < t->data) 
        value = t->data;
 
    return value;
}
 
int minValue(BT t)
{
    if (t == NULL) {
        return INT_MAX;
    }
 
    int leftMax = minValue(t->left);
    int rightMax = minValue(t->right);
 
    int value = 0; //finds min between left and right
    if (leftMax < rightMax)
        value = leftMax;
    else 
        value = rightMax;
    
    if (value > t->data) 
        value = t->data;
 
    return value;
}
 

int isBST(BT t)
{
    if (!t)
        return 1;
 
    // false if the max of the left is > than current root
    if (t->left && maxValue(t->left) > t->data)
        return 0;

    // false if the min of the right is <= than current root 
    if (t->right && minValue(t->right) < t->data)
        return 0;
 
    //false if, recursively, the left or right is not a BST
    if (!isBST(t->left) || !isBST(t->right))
        return 0;

    return 1;
}

void main(){
    srand(time(0));
    BT t;
    initBT(&t);
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
    printf("\nis BST? %d\n",isBST(t));
    printf("MAX %d\n",maxValue(t));
    printf("MIN %d\n",minValue(t));
}