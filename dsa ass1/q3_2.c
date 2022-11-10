#include <stdio.h>
#include <ctype.h>
void main(){
	
	char l;
	printf("Enter a character: ");
	l = scanf("%c", &l);
	
	//if(isalpha(l) >0){
		switch(l){
			case 'a': 
				printf("Vowel");
				break;
			case 'A': printf("Vowel");
			break;
			case 'e': printf("Vowel");
			break;
			case 'E': printf("Vowel");
			break;
			case 'i': printf("Vowel");
			break;
			case 'I': printf("Vowel");
			break;
			case 'o': printf("Vowel");
			break;
			case 'O': printf("Vowel");
			break;
			case 'u': printf("Vowel");
			break;
			case 'U':  printf("Vowel\n");break;
			default: printf("Consonant\n");
		}
	//}
	//else
	//	printf("Error!");
	
}
