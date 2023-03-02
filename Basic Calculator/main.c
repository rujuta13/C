#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "header.h"

void main(){
	node *n1, *n2;
	init(&n1);
	init(&n2);
	//insert(&n1, 1);
	
	char *A;
	printf("bc\n");
	A = "1234+5678";
	printf("%s\n", A);
	int s = strlen(A);
	
	//first number
	int i = 0;
	while(i < s && isdigit(A[i]) != 0) { //A[i] - '0' >= 0 && A[i] - '0' <= 9){
		//printf("%c\n", A[i]);
		insert(&n1, A[i] - '0');
		i++;
	}
	//display(n1);

	i += 1; //skip '+' symbol
	
	//second number
	for(; i < s; i ++){
		//printf("%c\n", A[i]);
		insert(&n2, A[i] - '0');
	}
	//display(n2);
	
	display(add(n1, n2));
}