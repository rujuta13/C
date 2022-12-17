#include <stdio.h>
#include <stdlib.h>
void main(int s, char * A[]){
	char *  key = A[s-1];
	int index;
	for(int i = 1; i <= s-2; i ++){
		if(atoi(key) == atoi(A[i])){
			index = i;
			break;
		}
	
	}
	if(index == s-2){
		printf("Lesser No.:%s\n", A[index-1]);
	}
	else if(index == 1){
		printf("Greater No.:%s\n", A[index+1]);
	}
	else{
		printf("Lesser No.:%s\n", A[index-1]);
		printf("Greater No.:%s\n", A[index+1]);
	}
}

