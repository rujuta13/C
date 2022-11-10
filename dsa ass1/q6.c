#include <stdio.h>
void main(){
    float area, r, pi = 3.14;

    printf("Enter radius of the circle: ");
    scanf("%f", &r);
    
    area = pi * r * r;
    printf("Area of the cicle is %.2f", area);

}