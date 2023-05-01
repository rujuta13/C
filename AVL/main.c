#include <stdio.h>
#include <stdlib.h>
#include "avltree.h"

void main(){
    avl t;
	initAVL(&t);
	insert(&t, 10);
	insert(&t, 30);
	insert(&t, 20);
	
	inorder(t);
}