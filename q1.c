#include <stdio.h>
#include <string.h>
#include<stdlib.h>
void main(int s, char* A[]){
	printf("Size of array: %d\n",s);
	for(int i = 0; i < s; i++){
		int A[i] = atoi(A[i]);
		printf("%d\t",A[i]);
	}
}