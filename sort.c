void ArrPrint(int A[],int s){
	for(int i = 0; i <s; i++)
		printf("%d ",A[i]);

}

void InSort(int A[], int s){
	int i, j, temp;
	for(i = 1; i < s; i ++){
		j = i-1;
		temp = A[i];
		while(A[j] > temp && j >=0){
			A[j+1] = A[j];
			j --;	
			ArrPrint(A,s);
			printf("\n");
		}
		A[j+1] = temp;
		printf("\n");

	}
}

void BubbleSort(int A[], int s){
	int temp;
	for(int i = s-1; i >= 0; i --){
		for(int j = 0; j < i;j++){
			if(A[j] > A[j+1]){
				temp = A[j];
				A[j] = A[j+1];
				A[j+1] = temp;
			
				ArrPrint(A,s);
				printf("\n");
			}
		}
		printf("\n");	 
	}
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
		ArrPrint(A,s);
		printf("\n");
	}
}
