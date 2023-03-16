int LinSearch(int A[], int s, int key){
	for(int i = 0; i < s; i++){
		if( key == A[i]){
			return 1;
		}
	}	
	return 0;
}

int BinSearch(int A[], int s, int key){
	int low = 0, high = s, mid;
	while (low <= high){
		
        	mid = (low + high)/2;
		if(key == A[mid]){
			return 1;
		}
		else if(key < A[mid]){
			high = mid - 1;
		}
		else{
			low = mid + 1;
		}
	}
	return 0;
}