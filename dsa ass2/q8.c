#include<stdio.h>
void main(){
    printf("Prime numbers from 1 to 100:\n");
    for(int i=1; i<=100; i++){ 
        int fact_count = 0;
        for(int j = 2; j<=i/2;j++){
            if(i%j == 0){
                fact_count = 1;
                break;
            }
        } 

        if(fact_count == 0)
            printf("%d\n",i);
    }
}