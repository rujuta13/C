#include <stdio.h>
void array_update(int A[], int s){
    int i;
    for(i = 0; i < s; i ++){
        A[i] = 1;
    }
}
void main(){
    int A[] = {1,2,3};
    int s = 3;
    int i;
    printf("before: ");
    for(i = 0; i < s; i ++){
        printf("%d ", A[i]);
    }
    printf("\nafter: ");
    array_update(A, s);
    for(i = 0; i < s; i ++){
        printf("%d ", A[i]);
    }

}