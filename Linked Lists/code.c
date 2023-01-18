#include<stdio.h>
#include<stdlib.h>
#include <string.h>

typedef struct HackathonClub{
    int prn;
    char name[30];
    struct HackathonClub * next;
} node;

void append(node **L, int prn, char name[]){
    node * nn;
    nn = (node *) malloc(sizeof(node *));
    if(!nn) //if nn is NULL then return
        return;
    
    //nn not NULL:
    nn -> prn = prn;
    strcpy(nn -> name, name);
    nn -> next = NULL;

    node * pn;
    pn = *L; // pn points to start of LL

    if(pn == NULL){
        *L = nn;
        return;
    } 
    while((pn -> next) != 0){
        pn = pn -> next;
    }
    //traverse till last nod
    pn -> next = nn;    
}

int count(node *L){
    int c = 0; 
    node * p;
    p = L;
    while(p != 0){
        c ++;
        p = p -> next;
    }
    return c;
}

void delete(node **L, int key){
    node *p, *q;
    p = *L;
    //q = p->next;
    if(*L == 0)
        return;
    while(p != 0){
        if(p -> next -> prn == key){
            q = p ->next;
            p->next = q -> next;
            free(q);
            return;
        }
        p = p ->next;
    }
}

void display(node *L){
    node * pn;
    pn = L;
    printf("");
    while(pn != 0){
        printf("PRN: %d\tName: %s\n", pn -> prn, pn -> name);
        pn = pn -> next;
    }
    printf(" \n");

}

void main(){
    int year, ch;
    
    node *L;
    L = (node *)malloc(sizeof(node *));
    L  = NULL;

    int prn;
    char name[30];


    do{
        menu:
        printf("\nMenu\n");
        printf("1. Add member\n");
        printf("2. No. of members\n");
        printf("3. Delete members\n");
        printf("4. Display\n");
        
        printf("Press any other key to exit\n");
        printf("Enter choice: ");
        scanf("%d",&ch);

        if(ch == 1){
            printf("\nEnter year of study: ");
            scanf("%d", &year);
            if(year <= 1 || year > 4){
                printf("Error!\nOnly students from SY, TY and BTech permitted.\n");
                goto menu;
            }

            printf("\nEnter name: ");
            //scanf(" %s",&name);
            scanf(" %[^\n]c",name);
            
            printf("Enter prn: ");
            scanf("%d", &prn);
            append(&L, prn, name);
        }
        else if(ch == 2)
            printf("\nNo. of members: %d\n", count(L));
        else if(ch == 3){
            printf("Enter prn to be deleted: ");
            scanf("%d", &prn);
            delete(&L, prn);
        }
        else if(ch == 4)
            display(L);
    }
    while(ch != 0);
}