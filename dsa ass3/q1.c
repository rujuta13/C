#include <stdio.h>
#include <string.h>
#include<stdlib.h>
void main(int s, char* A[]){
	for(int i = s-1; i > 0; i --){
		printf("%s\t",A[i]);
	}
	printf("\n");
}
