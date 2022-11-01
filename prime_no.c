#include <stdio.h>
void main(){
    int pr_count = 0;
    int fact_count;
    int num = 1;
    printf("\nFirst ten prime numbers:\n");
    while(pr_count < 10){
        fact_count = 0;

        // counting no. of factors
        for(int i = 1; i <= num/2; i++){
            if(num % i == 0){
                fact_count++;
            }
        }//eo for

        // checking if prime
        if(fact_count == 1){
            printf("%d\n",num); //print prime no
            pr_count ++;        
        }

        num ++;
        
        
    }//eo while

}//eo main