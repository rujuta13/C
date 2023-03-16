#include<stdio.h>
int a = 0;
int num(int n){
    a = 1;
    return a;
}
void main(){
    printf("%d\n", a);
    num(13);
    printf("%d\n", a);
}