#include <stdio.h>
#include <stdlib.h>

void main(int s, char * A[]){
	int sum = 0;
	for(int i = 2; i < s; i += 2 )
		sum += atoi(A[i]);
	printf("Sum: %d\n",sum);
}

