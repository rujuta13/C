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