#include <stdio.h>
#include <stdlib.h>
#include "avltree.h"

void main(){
    avl t;
	initAVL(&t);
	t = insert(t, 8);
	t = insert(t, 3);
	t = insert(t, 1);
	t = insert(t, 6);
	t = insert(t, 4);
	t = insert(t, 7);
	t = insert(t, 10);
	t = insert(t, 14);
	t = insert(t, 13);
}