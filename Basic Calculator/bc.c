#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include <ctype.h>

typedef struct node{
    int data;
    struct node * next;
} node;

void init(node **head){
	(*head) = (node *) malloc(sizeof(node *));
	if((*head) == NULL)
		return;

	(*head) = NULL;
}

void display(node *L){
    node * pn;
    pn = L;
	
    //printf("[");
    while(pn != NULL){
        printf("%d", pn -> data);
        pn = pn -> next;
    }
    printf(" \n");

}

void insert(node  **head, int key){
    	node * nn;
    	nn = (node *)malloc(sizeof(node *));
    	if(!nn) 
        	return;
    
    	nn -> data = key;
	nn -> next = (*head);
	(*head) = nn;
}

void append(node **L, int key){
    node * nn;
    nn = (node *)malloc(sizeof(node *));
    if(!nn) //if nn is NULL then return
        return;
    
    nn -> data = key;
    nn -> next = NULL;

    node * pn;
    pn = *L; 

    if(pn == NULL){
        *L = nn;
        return;
    }

    while((pn -> next) != 0)
        pn = pn -> next;

    pn -> next = nn;    
}

void reverse(node **L){
    node * p1, *p2, *temp;
    p1 = *L;
    p2 = p1 -> next;
    temp = NULL;
    p1 -> next = NULL;
    while(p2!=0){
        temp = p2 -> next;
        p2 -> next = p1; //reversing
        p1 = p2;
        p2 = temp; //increment p2
    }
    *L = p1;
}

node * add(node *L1, node *L2){
    //takes reversed input
	node *n3;
	init(&n3);

	node *p1, *p2;
	p1 = L1;
	p2 = L2;
	
	int sum, carry = 0;
	while(p1 != NULL && p2 != NULL){
		sum = p1 -> data + p2 -> data + carry;
		carry = sum / 10;
		insert(&n3, sum % 10);

		p1 = p1 ->next;
		p2 = p2 ->next;
	}
	while(p1 != NULL){
		sum = p1 -> data + carry;
		carry = sum / 10;
		insert(&n3, sum % 10);
		p1 = p1 ->next;
	}
	while(p2 != NULL){
		sum = p2 -> data + carry;
		carry = sum / 10;
		insert(&n3, sum % 10);
		p2 = p2 ->next;
	}

	if(carry != 0)
		insert(&n3, carry);

	return n3;
}

/*
node *subtract(node *L1, node *L2){
	node *n3;
	init(&n3);

	node *p1, *p2;
	p1 = L1;
	p2 = L2;
	
	int diff, borrow = 0;
	while(p1 != NULL && p2 != NULL){
		diff = p1->data - p2->data - borrow;

		if(diff >= 0){
			borrow = 0;
			insert(&n3, diff);
		}
		else{
			borrow = 1;
			insert(&n3, -diff);
		}		

		p1 = p1 ->next;
		p2 = p2 ->next;
	}
	
	while(p1 != NULL){
		diff = p1->data - borrow;

		if(diff >= 0)
			borrow = 0;
		else
			borrow = 1;
		
		insert(&n3, diff + (10 * borrow));
		p1 = p1 ->next;
	}
	while(p2 != NULL){
		diff = - p2->data - borrow;

		if(diff >= 0)
			borrow = 0;
		else
			borrow = 1;
		
		insert(&n3, diff + (10 * borrow));
		p2 = p2 ->next;
	}

	return n3;
}*/

int isEqual(node *L1, node *L2){
	node *p1, *p2;
	p1 = L1;
	p2 = L2;
	
	while(p1 != NULL && p2 != NULL){
		if(p1 ->data != p2 -> data)
			return 0;
		p1 = p1 ->next;
		p2 = p2 ->next;
	}
	while(p1 != NULL || p2 != NULL)
		return 0;
	
	return 1;
}

node *multiply(node *L1, node *L2){
	node *n3, *product, *one, *count;
	init(&n3);
	init(&product);
	init(&one);
	init(&count);
	append(&one, 1);	

    display(L1);
    display(L2);
	reverse(L1);
	reverse(l2);
	while(isEqual(L2, count) == 0){
		product = add(L1, product);
		count = add(count, one);
	}
    return product;

}

node *divide(node *L1, node *L2){
	node *n3;
	init(&n3);
}

void main(){
	node *n1, *n2;
	init(&n1);
	init(&n2);
	//insert(&n1, 1);
	
	char *A;
	printf("bc\n");
	A = "10-12";
	printf("%s\n", A);
	int s = strlen(A);
	
	//first number
	int i = 0;
	while(i < s ) { //A[i] - '0' >= 0 && A[i] - '0' <= 9){
		//printf("%c\n", A[i]);
		//if(isspace(A[i]) == 1)
		//	continue;
		if(isdigit(A[i]) == 0)
			break;

		insert(&n1, A[i] - '0');
		i++;
	}
	//display(n1);

	i += 1; //skip operator
	
	//second number
	for(; i < s; i ++){
		//printf("%c\n", A[i]);
		insert(&n2, A[i] - '0');
	}
	//display(n2);
	
	//display(add(n1, n2));
	//display(subtract(n2, n1));
	//printf("%d\n", isEqual(n1, n2));
    display(multiply(n1,n2));
}
