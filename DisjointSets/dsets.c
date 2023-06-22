#include <stdio.h>
#include <stdlib.h>
typedef struct disSet{
    int *A;
    int size;
}disSet;

disSet init(int num){
    disSet s;
    s.A = (int *) malloc (sizeof(int) * num);
    s.size = num;
    
    for(int i =0; i<s.size ; i++)
        s.A[i] = i;
        
    return s;
}

int find(disSet s, int x){
    //x is the only member
    if(s.A[x] == x)
        return x; 
    return find(s, s.A[x]);
}

void unionRank( disSet s, int a, int b){
    int x, y;
    x = find(s, a);
    y = find(s, b);
    if(x == y)
        return;
    if(x < y)
        s.A[y] = x;
    else    
        s.A[x] = y;
}

void main(){
    disSet s;
    s = init(5);
    
    unionRank(s, 3, 4);
    printf("find: %d\n", find(s,4));
    printf("find: %d\n", find(s,3));
    unionRank(s, 1, 3);
    printf("find: %d\n", find(s,4));
    printf("find: %d\n", find(s,3));
    printf("find: %d\n", find(s,1));
}