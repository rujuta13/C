#include "header.h"
#include<stdio.h>
#include<string.h>
void main(){
	char A[10000];
	printf("bc\n");
	scanf("%s", A);
	while(strcmp(A, "quit")){
		if(strcmp(A, "q") == 0)
			printf("Enter quit to exit\n");
		scanf("%s", A);
		int s = strlen(A);
		evaluate(A, s);
	}
}