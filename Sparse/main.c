#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    int i,j;
    struct node *right, *down;
}node;

typedef struct sparse{
    node **row, **col;
    int r,c;
}sparse;

void init_matrix(sparse *s, char *filename){
    FILE *fp = fopen(filename, "r"); //read mode
    if(!fp) 
        return;

    int r,c; //number of rows and columns
    fscanf(fp,"%d\n",&r);
    s -> r = r;
    fscanf(fp,"%d\n",&c);
    s -> c = c;

    //printf("No. of rows: %d columns: %d \n", r,c); 

    s -> row = (node**)malloc(sizeof(node*)*r); //array of size r
    s -> col = (node**)malloc(sizeof(node*)*c); //array of size c

    for(int i = 0; i < r; i++){
        (s -> row)[i] = NULL;
    }
    for(int i = 0; i < c; i++){
        (s -> col)[i] = NULL;    
    }
    
    int value;
    node *nn;
    for(int i = 0;i<r;i++){
        for(int j = 0;j<c;j++){
            fscanf(fp,"%d",&value);
            // printf("\n %d \n ", value); //
            if(value != 0){
                nn = (node*)malloc(sizeof(node));
                nn -> down = NULL;
                nn -> right = NULL;
                nn -> i = i;
                nn -> j = j;
                nn -> data = value;
                insertnode(s,nn,i,j);
            }
        }
    }
    fclose(fp);
    return;
}

void insertnode(sparse *s, node *nn, int i, int j){
    node *tr, *tc;
    if(s -> row[i] == NULL){
        s -> row[i] = nn;
    }
    else{
        tr = s -> row[i];
        while(tr -> right != NULL){
            tr = tr -> right;   
        }
         tr -> right = nn;
    }
    if(s -> col[j] == NULL){
            s -> col[j] = nn;
        }
    else{
            tc = s -> col[j];
        while(tc -> down != NULL){
                tc = tc -> down;   
            }
             tc -> down = nn;
        }
        return;
}

void display(sparse s){
    node *p;
    for(int i = 0; i<s.r; i++){
        p = s.row[i];
        while(p){
            printf("%d ", p->data);
            p = p->right;
        }
        printf("\n");
    }
    return;
}

int main(int argc, char *argv[]){
    sparse s1,s2;
    init_matrix(&s1,"mat1.txt");
    display(s1);
    printf("\n");
    init_matrix(&s2,"mat2.txt");
    display(s2); //
    printf("\n");
}