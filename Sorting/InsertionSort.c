#include<stdio.h>
void ArrPrint(int A[],int s){
	for(int i = 0; i <s; i++)
		printf("%d ",A[i]);

}
void InSort(int A[], int s){
	int i, j, temp;
	for(i = 1; i < s; i ++){ //0th element already sorted
		j = i-1;
		temp = A[i];
		while(A[j] > temp && j >=0){
			A[j+1] = A[j];
			j --;	
			//ArrPrint(A,s);
			printf("\n");
		}
		A[j+1] = temp;
		printf("\n");

	}
}

void main(){
    int A[] = {8, 7, 6, 5, 4, 3, 2, 1};
    int s = sizeof(A)/sizeof(int);
    printf("before: ");
    ArrPrint(A, s);
    
    printf("\nafter: ");
    InSort(A, s);
    ArrPrint(A, s);
}