
#include<stdio.h>

void ArrPrint(int A[],int s){
	for(int i = 0; i <s; i++)
		printf("%d ",A[i]);

}
void BubbleSort(int A[], int s){
	int temp;
	for(int i = s-1; i >= 0; i --){
		for(int j = 0; j < i;j++){
			if(A[j] > A[j+1]){
				temp = A[j];
				A[j] = A[j+1];
				A[j+1] = temp;
			
				//ArrPrint(A,s);
				//printf("\n");
			}
		}
		//printf("\n");	 
	}
}

void main(){
    int A[] = {8, 7, 6, 5, 4, 3, 2, 1};
    int s = sizeof(A)/sizeof(int);
    printf("before: ");
    ArrPrint(A, s);
    
    printf("\nafter: ");
    BubbleSort(A, s);
    ArrPrint(A, s);
}