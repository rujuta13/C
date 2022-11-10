#include <stdio.h> 
#include <math.h>

int fact(int); 

void main(){
    int deg;
    printf("Enter x: ");
    scanf("%d",&deg);
    float rad = 3.14159 * deg / 180;
    float cos=0, sin=0, exp = 0;

    for(int i = 0; i<= 10; i+= 2){
        cos += pow(-1, i/2) * pow(rad, i) / fact(i) ;
    }

    for(int j = 1; j<= 10; j+= 2){
        sin += pow(-1, j/2) * pow(rad, j) / fact(j) ;
    }

    int x = deg;
    for(int k = 0; k<= 10; k++){
        exp += pow(x, k) / fact(k) ;
    }
    printf("Cos: %.3f\n", cos);
    printf("Sin: %.3f\n", sin);
    printf("Exp: %.3f\n", exp);
}

int fact(int num){
    int prod = 1;
    if(num == 0)
        return 1;
    for(int i=1; i <= num ; i ++)
        prod = prod * i;
    return prod;
}