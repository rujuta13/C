#include <stdio.h>
void ArrPrint(int A[],int s){
	for(int i = 0; i <s; i++)
		printf("%d ",A[i]);

}
int Merge(int A[], int low, int mid, int high){
    int i, j, k, B[high];
    i = k = low;
    j = mid + 1;
    
    while ( i <= mid && j <= high){
        if(A[i] < A[j])
            B[k] = A[i++];
        else
            B[k] = A[j++];  
        k ++;
    }

    while(i <= mid)
        B[k++] = A[i++];

    while(j <= high)
        B[k++] = A[j++];

    for(int i = low; i <= high; i ++)//copy merged array to A
        A[i] = B[i];

}
void MS(int A[], int low, int high){
    if(low == high)
        return;
    
    int mid = (low + high) /2;
    MS(A, low, mid);
    MS(A, mid+1, high);
    Merge(A, low, mid, high);
}

void main(){
    int A[] = {8, 7, 6, 5, 4, 3, 2, 1};
    int s = sizeof(A)/sizeof(int);
    printf("before: ");
    ArrPrint(A, s);
    
    printf("\nafter: ");
    MS(A, 0, s-1);
    ArrPrint(A, s);
}