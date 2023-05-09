#include <stdio.h>
#include <stdlib.h>
#include "avltree.h"

void main(){
    AVL t;
	initAVL(&t);
	insertNode(&t, 10);	
	insertNode(&t, 30);
	insertNode(&t, 20);
	traverse(t);
}