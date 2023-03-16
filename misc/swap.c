#include<stdio.h>
void swap(int *p1, int *p2)
{
    int temp = *p2;
    *p2 = *p1;
    *p1 = temp;
}

void main(){
    int n1, n2;

    printf("Enter first no.: ");
    scanf("%d", &n1);
    printf("Enter second no.: ");
    scanf("%d", &n2);
    
    printf("Numbers before swapping:\n");
    printf("%d  %d\n", n1, n2);

    swap(&n1, &n2);

    printf("Numbers after swapping:\n");
    printf("%d  %d\n", n1, n2);
}