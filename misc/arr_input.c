#include <stdio.h>
void main(){
    int A[3], B[3];
    for(int i = 0; i < 3; i ++){
        printf("Enter a no.:");
        scanf("%d", &A[i]);
    }
    printf("Size of array: %d",sizeof(A)/sizeof(int));
}