#include <stdio.h>
void main(){ 
	int n, sum = 0;
	printf("Enter a positive number: ");
	scanf("%d", &n);
	
	while(n > 0){
		sum += n % 10;
		n = n /100;
	}
	printf("Sum of digits at even location:%d\n", sum);
}
	
