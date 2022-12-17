#include<stdio.h>
#include<stdlib.h>
void main(){
    int *A, *B;
    A = (int *)calloc(4, sizeof(int));
    int i;
    for(i = 0; i < 4; i ++){
        printf("%d ", *(A+i));
    }
    printf("\n");
    B = (int *)malloc(4 * sizeof(int));
    for(i = 0; i < 4; i ++){
        printf("%d ", *(B+i));
    }
}