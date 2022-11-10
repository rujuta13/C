#include<stdio.h>
#include<math.h>

void main(){
	int dec;
	printf("enter a no.: ");
	scanf("%d", &dec);

	int bin[8] = {0,0,0,0,0,0,0,0};

	for(int i = 8-1; i>=0; i--){
		bin[i]= dec%2;
		dec = dec/2;
	}

	printf("Binary:\n");
	for(int j = 0; j < 8; j++){
		printf("%d ",bin[j]);
	}

}



