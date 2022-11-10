#include<stdio.h>
int gcd(int,int);
int lcm(int,int);

void main(){
    int n1, n2;
    printf("Enter a no.: ");
    scanf("%d",&n1);
    printf("Enter a no.: ");
    scanf("%d",&n2);

    printf("GCD: %d\n", gcd(n1,n2));
    printf("LCM: %d\n", lcm(n1,n2));
}

int gcd(int a, int b){
    if(a==b)
        return a;

    int big = a>b ?a:b;

    for(int i = big/2; i >= 1; i --){
        if(a%i ==0 && b%i ==0 )
            return i;
    }
    
}

int lcm(int a, int b){

    int big = a>b ?a:b;
    int n = big;
    while(1){
        if(n%a ==0 && n%b ==0)
                return n;
        n ++;
    }


}