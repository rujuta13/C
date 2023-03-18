#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include <ctype.h>

typedef struct node{
    int data;
    struct node * next;
} node;

typedef struct nodestack{
    node *data;
    struct nodestack *next;
} nodestack;

typedef struct charstack{
    char data;
    struct charstack *next;
} charstack;


void removeZero(node **L) {
	reverse(L);
    node *p = *L;
    node *q;

    // Traverse the linked list and delete each node until a non-zero element is found
    while (p != NULL && p->data == 0) {
        q = p->next;
        free(p);
        p = q;
    }
    
    // Update the head of the linked list to the first non-zero element
    *L = p;
	
	reverse(L);
	if(*L == NULL)
		append(L, 0);
}

int compare(node *L1, node *L2){
	//returns 1 if L1 bigger or equal
	//0 if L2 bigger
	//-1 if equal
	int flag = -1;

	reverse(&L1);
	reverse(&L2);

	node *p1 , *p2;
	p1 = L1;
	p2 = L2;
	
	if(count(L1) > count(L2))
		flag = 1;
	
	else if(count(L1) < count(L2))
		flag = 0;

	else{ //same number of nodes
		while(p1 != NULL && p2 != NULL){
			if(p1->data > p2->data){
				flag = 1;
				break;
			}
			else if(p1->data < p2->data){
				flag = 0;
				break;
			}
			p1 = p1 -> next;
			p2 = p2 -> next;
		}
	}
	//numbers are equal
	reverse(&L1);
	reverse(&L2);
	return flag; 
}

node *add(node *L1, node *L2){
	node *n3;
	init(&n3);

	removeZero(&L1);
	removeZero(&L2);

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
 
	reverse(&n3);
	return n3;
}

node *subtract(node *L1, node *L2){
	//returns only absolute value
	node *n3;
	init(&n3);

	removeZero(&L1);
	removeZero(&L2);

	node *p1, *p2;
	p1 = L1;
	p2 = L2;

	if(compare(L1, L2) == 0){
		n3 = subtract(L2,L1);
		removeZero(&n3);
		return n3;
	}

	int diff, borrow = 0;
	while(p1 != NULL && p2 != NULL){
		if(p1 -> data >= p2 -> data)
			borrow = 0;
		else{
			borrow = 1;
			p1 -> next ->data = p1->next -> data -1;
		}
		
		insert(&n3, 10*borrow + p1 -> data - p2->data);
		p1 = p1 ->next;
		p2 = p2 ->next;
	}
	
	while(p1 != NULL){
		if(p1 -> data >= 0)
			borrow = 0;
		else{
			borrow = 1;
			p1 -> next ->data = p1->next -> data -1;
		}
		
		insert(&n3, 10*borrow + p1 -> data);
		p1 = p1 ->next;
	}
	removeZero(&n3);
	reverse(&n3);
	return n3;
}

node *multiply(node *L1, node *L2){
	node *n3, *one, *count;
	init(&n3);
	insert(&n3, 0);

	if(compare(L1, L2) == 0){
		n3 = multiply(L2,L1);
		return n3;
	}

	init(&one);
	insert(&one, 1);

	init(&count);
	insert(&count, 0);
	
	removeZero(&L1);
	removeZero(&L2);

	while(compare(L2, count) != -1){
		n3 = add(n3, L1);
		count = add(one, count);
	}

    return n3;
}

node *divide(node *L1, node *L2){
	node *n3, *one, *count;
	init(&n3);
	insert(&n3, 0);

	removeZero(&L1);
	removeZero(&L2);

	if(compare(L1, L2) == 0){
		return n3;
	}

	init(&one);
	insert(&one, 1);

	init(&count);
	insert(&count, 0);
	
	while(compare(L2, L1) != -1){
		L2 = subtract(L2, L1);
		count = add(count, one);
	}
    return count;
}

int precedence(char operator) {
	switch (operator) {
		case '+':
		case '-':
			return 1;
		case '*':
		case '/':
			return 2;
		default:
			return -1;
	}
}

int isOperator(char ch) {
	return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

void evaluate(char expr[], int s){
	
	int op = 0; //number of operators
    for(int i = 0; i < s; i ++){
        if(isOperator(expr[i]))
            op ++;
    }
	
    node *num[op + 1]; //no of numbers = op + 1
	printf("Operators: %d\n",op);
	int count = 0; 
	
	for(int j =0; j<=op+1; j++)
		init(&num[j]);

	int j = 0;
	for(int i = 0; i <s; i++){
		if(isdigit(expr[i]))
			insert(&num[count], expr[i] - '0');
		else
			count ++;
		
	}
	
	nodestack operand;
	charstack operator;

	initNodeStack(&operand);
	initCharStack(&operator);

	count = 0;
	node *temp, *n1, *n2;
	init(&n1);
	init(&n2);

	char op_temp;

	
	for(int i = 0; i<s; i++){
		if( (isdigit(expr[i]) && isOperator(expr[i+1])) || i == s-1){ 
			//pushing numbers onto the operand stack
			pushnode(&operand, num[count]);
			count++;
		}
		else if(isOperator(expr[i])){
			if(isEmptyChar(operator))
				pushchar(&operator, expr[i]);
				
			else{
				//printf("Current %d\n ",precedence(expr[i]));
				//printf("Stack %d\n ",precedence(peek(operator)));
				if(precedence(expr[i]) > precedence(peek(operator))){
					pushchar(&operator, expr[i]);
				}
				else{
					op_temp = popchar(&operator);
					printf("%c\n",op_temp);
					//n1 = popnode(operand);
					//n2 = popnode(operand);
					display(n1);
					display(n2);
					pushchar(&operator, expr[i]);
				}
			}
		}

	
	}
	display(popnode(operand));
	
	displayNodeStack(operand);
	displayCharStack(operator);
	
	
}