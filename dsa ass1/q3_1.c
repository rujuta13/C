#include <stdio.h>
#include <ctype.h>
void main(){

	char  c;
	printf("Enter an alphabet\n");
	scanf("%c", &c);
	
	if(c == 'a' || c == 'A' || c == 'e' || c=='E' || c=='i' || c=='I' ||c=='O'||c=='o'||c=='u'||c=='U')
            printf("Vowel\n"); 
	else if(isalpha(c) == 0)
		printf("Error! Not an alphabet\n");
	else
		printf("Consonant\n");

}
