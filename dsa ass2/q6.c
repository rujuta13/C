#include<stdio.h>

int pattern1(int);
int pattern2(int);
int pattern3(int);
int pattern4(int);

void main(){
    int n;
    printf("Enter no. of rows: ");
    scanf("%d", &n);
    pattern1(n);
    pattern2(n);
    pattern3(n);
    pattern4(n);
}

int pattern1(int n){
    int i, j, k;
    for(i = 1; i <= n; i++){ 
            for(k = (n - i); k >= 0; k--){
                printf(" "); //1 spaces
            }
            for(j = 1; j <= (2*i-1); j++){
                printf("*");
            }
        printf("\n");
    }
    printf("\n");
    return 0;
}

int pattern2(int n){
    int i, j;
    int number = 1;
    for(i = 1; i <=n; i++){
        for(j = 1; j<=i; j++){
            printf("%d ", number);
            number ++;
        }
        printf("\n");
    }
    printf("\n");
    return 0;
}

int pattern3(int n){
    int i,j,k;
    for(i=1; i <= n; i ++){
        
        for(j = 1; j <= i; j++){
            if( ! (j%2) )
                printf("1");
            else 
                printf("0");

        }
        for(k = (n -i); k > 0; k--){
            printf("  "); //2 spaces
        }
        for(j = 1; j <= i; j++){
            if( ! (j%2) )
                printf("1");
            else 
                printf("0");

        }
        printf("\n");
    }
    printf("\n");
}

int fact(int num){
    int prod = 1;
    if(num == 0)
        return 1;
    for(int i=1; i <= num ; i ++)
        prod = prod * i;
    return prod;
}

int pattern4(int n){
    int i, j, k, calc;
    for(i = 0; i <= n; i++){ 
            for(k = (n - i); k >= 0; k--){
                printf(" "); //1 spaces
            }
            for(j = 0; j <= i; j++){
                calc = fact(i) / (fact(i-j) * fact(j));
                printf("%d ",calc);
            }
        printf("\n");
    }
    printf("\n");
    return 0;
}