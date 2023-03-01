#include <stdio.h>

int factorial(int *n){
    int fact = 1;
    for(int i =1; i <= *n; i++){
        fact *= i;
    }
    return fact;
}

void main(){
    int num;
    printf("Enter a no.: ");
    scanf("%d", &num);
    printf("%d", factorial(&num));
}