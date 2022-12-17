#include <stdio.h>
int Merge(int A[], int f, int m, int l){
    int i, j, k, B[l];
    i = f;
    j = m + 1;
    k = f;
    while ( i <= m && j <= l){
        if(A[i] < A[j]){
            B[k] = A[i];
            i ++;
        }
        else{
            B[k] = A[j];
            j ++;
        }
        k ++;
    }

    while(i <= m){
        B[k] = A[i];
        i ++;
        k ++;
    }
    while(j <= l){
        B[k] = A[j];
        j ++;
        k ++;
    }

    for(int i = f; i <= l; i ++){
        A[i] = B[i];
    }
}
void MS(int A[], int f, int l){
    if(f == l){
        return ;
    }
    int m = (f + l) /2;
    MS(A, f, m);
    MS(A, m+1, l);
    Merge(A, f, m, l);
}
void main(){
    int A[] = {8, 7, 6, 5, 4, 3, 2, 1};
    int s = sizeof(A)/sizeof(int);
    int i;
    printf("before: ");
    for(i = 0; i < s; i ++){
        printf("%d ", A[i]);
    }
    
    printf("\nafter: ");
    MS(A, 0, s);
    for(i = 0; i < s; i ++){
        printf("%d ", A[i]);
    }
}