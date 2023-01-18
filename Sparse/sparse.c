#include<stdio.h>
#include<stdlib.h>
#include "sparse.h"

void init_matrix(sparse *s,char *filename){
    FILE *fp = fopen(filename,"r");
    if(!fp) return;
    int r,c;
    fscanf(fp,"%d\n",&r);
    s -> r = r;
    fscanf(fp,"%d\n",&c);
    s -> c = c;
    // printf(" \n %d %d \n", r,c); //

    s -> row = (node**)malloc(sizeof(node*)*r);
    s -> col = (node**)malloc(sizeof(node*)*c);
    for(int i = 0; i < r; i++){
        s -> row[i] = NULL;
    }
    for(int i = 0; i < c; i++){
        s -> col[i] = NULL;    
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
    for(int i = 0;i<s.r;i++){
        p = s.row[i];
        while(p){
            printf("%d %d %d \n", p->i, p->j, p->data);
            p = p->right;
        }
    }
    return;
}