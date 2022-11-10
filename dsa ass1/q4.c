#include <stdio.h>
void main(){
    float da;
    float sal;
    printf("Enter the salary\n");
    scanf("%f", &sal);
    if (sal >= 10000 && sal <= 20000){
        da = 0.1 * sal; 
        printf("DA: %.2f", da);
    }
    else if ( sal > 20000 && sal <= 50000){
        da = 0.15 * sal;
        printf("DA: %.2f", da);
    }
    else if (sal > 50000 && sal <= 100000){
       da = 0.2 * sal;
       printf("DA: %.2f", da);
    }
    else
        printf("DA not known");
    
}
