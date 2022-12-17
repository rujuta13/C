#include <stdio.h>
#include <stdlib.h>
void main(int s, char* A[]){
	for(int i = s-1; i > 0; i --){
		for(int j = 1; j <= i; j++){
			printf("%s\t", A[j]);
		}
		printf("\n");
	}
}


