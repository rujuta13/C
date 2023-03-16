#include<stdio.h>
struct cricketer{
        char name[30];
        float str_rate;
} typedef ru;
void main(){
    ru A[] = {
        {"a",100.1}, 
        {"b",120}, 
        {"c",102.4}, 
        {"d",200}
    };
   
    float max=0;
    for(int i = 0; i < 4; i ++){
        if(A[i].str_rate > max)
            max = A[i].str_rate;
    }
    printf("Max. strike rate: %f\n", max);
}