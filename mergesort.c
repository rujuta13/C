#include <stdio.h>
int Merge(int A[], int f, int m, int l){

}
void MS(int A[], int f, int l){
    if(f == 1){
        return ;
    }
    int m = (f + l) /2;
    MS(A, f, m);
    MS(A, m+1, l);
    Merge(A, f, m, l);
}

void main(){
    int A[] = {4, 3, 2, 1};
    int s = sizeof(A)/sizeof(int);
    MS(A, 0, s);
}