#include<stdio.h>
void main(){
	char letter;
	int asc;
	printf("Enter an alphabet:\n");
	scanf("%c",&letter);
	asc = letter;
	
	if(asc >= 65 && asc <=90){
		asc += 32;
		printf("Letter after changing case: %c\n",asc);
	}
	else if(asc >=97 && asc <=122){
		asc -= 32;
		printf("Letter after changing case: %c\n",asc);
	}
	else
		printf("Error! Not an alphabet\n");
}
