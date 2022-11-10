#include <stdio.h>
void main(){
	int n, sum1 = 0, i = 1;
	printf("Enter a positive integer: ");
	scanf("%d",&n);
	
	while(i <=  n){
		sum1 += i;
		i ++;
	}
	printf("Sum using while loop: %d\n",sum1);
	
	int sum2 = 0;
	for(int j=1; j<=n;j++){
		sum2 += j;
	}
	printf("Sum using for loop: %d\n" ,sum2);	
	


}
	
	
