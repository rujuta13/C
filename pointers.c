#include <stdio.h>
void main(){
    
    int a = 5;
    int *p = &a;
    printf("Value of var = %d \n", a);
    printf("Value of p = %d \n", p);
    printf("Value of *p = %d \n", *p);

    int A[] = {1, 2, 3, 4, 5};
    for(int i = 0; i < 5; i ++){
        printf("%d ", A[i]);
    }
    printf("\n\n");

    int *p1 = &A[0];
    int *p2 = &A[3];
    printf("%d\n", p1 - p2);
    printf("%d\n", p2 - p1);
    * p1 = 11;
    //p1 = 1;
    printf("Array: ");
    for(int i = 0; i < 5; i ++){
        printf("%d ", A[i]);
    }
    printf("\n");
    *p1 = *p2 +1;

    printf("Array after \"*p1 = *p2 +1\": ");
    for(int i = 0; i < 5; i ++){
        printf("%d ", A[i]);
    }
    printf("\n\n");
    printf("Value of p1 = %d \n", p1);
    printf("Value of p2 = %d \n", p2);
    p1 = p2 +1;
    printf("Value of p1 = %d \n\n", p1);
    
   int *p3;
   int B[] = {11, 12, 13, 14, 15};
   p3 = &B[0];
   printf("%d, %d\n", *p3, B[0]);
   printf("%d, %d\n", p3, &B[0]);

    int *p4;
    p4 = &B[2];
    printf("%d\n", *(p4-1));
    
}

