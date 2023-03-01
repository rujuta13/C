#include<stdio.h>
void ArrPrint(int A[],int s){
	for(int i = 0; i <s; i++)
		printf("%d ",A[i]);

}
void swap(int * p1, int * p2)
{
    int temp = * p1;
    * p1 = * p2;
    * p2 = temp;
}

void SelSort(int A[], int s){
	int min_id;
	for(int i = 0; i < s; i++){
		min_id = i;
		for(int j = i+1; j < s; j ++){
			if(A[j] < A[min_id]){
				min_id = j;
			}
		}
		swap(&A[i], &A[min_id]);
	}
}

void main(){
    int A[] = {8, 7, 6, 5, 4, 3, 2, 1};
    int s = sizeof(A)/sizeof(int);
    printf("before: ");
    ArrPrint(A, s);
    
    printf("\nafter: ");
    SelSort(A, s);
    ArrPrint(A, s);
}