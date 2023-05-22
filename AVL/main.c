#include <stdio.h>
#include <stdlib.h>
#include "avltree.h"

void main(){
    AVL t;
	initAVL(&t);
	
	insertNode(&t, 35);
	insertNode(&t, 20);
	insertNode(&t, 70);
	insertNode(&t, 15);
	insertNode(&t, 30);
	insertNode(&t, 55);	
	insertNode(&t, 85);
	insertNode(&t, 10);
	insertNode(&t, 25);
	insertNode(&t, 40);
	insertNode(&t, 65);
	insertNode(&t, 90);
	traverse(t);
	printf("\n");
	t = removeNode(&t, 85);
	t = removeNode(&t, 90);
	t = removeNode(&t, 20);
	t = removeNode(&t, 35);
	t = removeNode(&t, 30);
	traverse(t);
}