#include <stdio.h>
void main(){
    float f, c;
    printf("Enter temp. in Fahrenheit: ");
    scanf("%f", &f);

    c = 5 * (f - 32) / 9;
    printf("Temp. in celcius: %.2f",c);
}