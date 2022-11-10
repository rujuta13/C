#include <stdio.h>
void main(){
	char small = 'a', caps = 'A';
	while(small <= 'z' && caps <= 'Z'){
		int asc1 = small;
		int asc2 = caps;
		printf("ASCI of %c is %d\n",small,asc1);
		printf("ASCI of %c is %d\n",caps,asc2);
		small ++;
		caps ++;
	}
}



