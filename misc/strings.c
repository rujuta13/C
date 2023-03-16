#include <stdio.h>
#include <string.h>
void main(){
    /*
    char ch;    
    char s[100];
    char sen[100];
    
    //fgets(sen,100,stdin);
    //puts(sen);
    
    scanf("%c\n", &ch);
    scanf("%s",s);
    scanf(" %[^\n]c",sen); // NOTE: space between " and %
    
    printf("%c\n",ch);
    printf("%s\n", s);
    printf("%s", sen);
    
    char s1[2] = {'h','i'};
    printf("S1: %s\n",s1);
    printf("Len of s1: %d\n",strlen(s1));
    char s2[6];
    strcpy(s2, s1);
    printf("S2: %s\n",s2);
    printf("Len of s2: %d\n",strlen(s2));
    */

   char s3[2] = {'h','i'};
   char s4[5] = {'h','e', 'l', 'l', 'o'};
   strcat(s3, s4);
   printf("S3: %s\n",strcat(s3, s4));
}