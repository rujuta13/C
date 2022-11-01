#include <stdio.h>
void main()
{
    int c;
    
    // putchar(c);
    printf("%c",EOF);
    printf("Press a key\n\n");
    c = getchar();

    printf("The expression getchar() != EOF evaluates to %d\n", getchar() != EOF);
    /*
    while (c != EOF)
    {
        //printf("%c", c);
        putchar(c);
        
        c = getchar();
    }*/
}
