#include <stdio.h>
void main(){
    struct Person{
        char name[30];
        int mis;
    };
    struct Person a = {"Rujuta Budke", 112103117};
    struct Person b = {"a",1};
    printf("%d: %s\n",a.mis, a.name);
}