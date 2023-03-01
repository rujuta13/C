#include<stdio.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void ArrPrint(int A[],int s){
	for(int i = 0; i <s; i++)
		printf("%d ",A[i]);

}

int Partition(int A[], int low, int high){
    int pivot = low;
    int i = low;
    int j = high;
   
    while(i < j){
        while(A[i] <= A[pivot])
            i++;
        while(A[j] > A[pivot])
            j--;
        if(i<j)
            swap(&A[i], &A[j]);
    }
    swap(&A[pivot], &A[j]);
    //pivot is now at jth index

    return j;
}

void QS(int A[], int low, int high){
    if(low >= high)
        return;
    int p = Partition(A, low, high);
    QS(A, low, p-1);
    QS(A, p+1, high);
}

void main(){
    int A[] = {8, 7, 6, 5, 4, 3, 2, 1};
    int s = sizeof(A)/sizeof(int);
    printf("before: ");
    ArrPrint(A, s);
    
    printf("\nafter: ");
    QS(A, 0, s-1);
    ArrPrint(A, s);
}

