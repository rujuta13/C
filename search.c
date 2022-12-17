#include<stdio.h>
void main(){
    int A[] = {1, 2, 3, 4, 5};
    int mid, low = 0, key;

    int high = sizeof(A)/sizeof(int) - 1;

    printf("Enter no. to be searched: ");
    scanf("%d", &key);
    
    while(low <= high){
        mid = (high + low) / 2;
        if(key == mid){
            printf("Key found at index %d\n",mid-1);
            break;
        }
        else if(key > mid)
            low = mid +1;
        else 
            high = mid -1;
    }

}