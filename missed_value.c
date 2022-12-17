#include <stdio.h>
//missing value
void main(){
    int A[] = {1, 3, 2, 5};
    int s = sizeof(A)/sizeof(int);

    int sum = (s + 1) * (s + 2) / 2;
    int sum_arr = 0;
    for(int i =0; i < s; i++){
        sum_arr += A[i];
    } 
    
    printf("Missing value is: %d",sum - sum_arr);
}