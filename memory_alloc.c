#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main(){
    /*
    int *A, *B;
    A = (int *)calloc(4, sizeof(int));
    int i;
    for(i = 0; i < 4; i ++){
        printf("%d ", *(A+i));
    }
    printf("\n");
    B = (int *)malloc(4 * sizeof(int));
    for(i = 0; i < 4; i ++){
        printf("%d ", *(B+i));
    }
    */

    char *str;

   /* Initial memory allocation */
   str = (char *) malloc(15);
   strcpy(str, "tutorialspoint");
   printf("String = %s,  Address = %u\n", str, str);

   /* Reallocating memory */
   str = (char *) realloc(str, 25);
   strcat(str, ".com");
   printf("String = %s,  Address = %u\n", str, str);

   free(str);
   
}