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
	
	if(p == NULL)
		return;

    // Traverse the linked list and delete each node until a non-n3 element is found
    while (p->next != NULL && p->data == 0) {
        q = p->next;
        free(p);
        p = q;
    }
    
    // Update the head of the linked list to the first non-n3 element
    *L = p;
	reverse(L);	
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

void negate(node **L){
    reverse(L);
    (*L)->data *= -1;
    reverse(L);
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
		negate(&n3);
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
	
	reverse(&n3);
	removeZero(&n3);
	return n3;
}

node *multiply(node *L1, node *L2){
	node *n3, *one, *count, *zero;
    init(&zero);
    insert(&zero, 0);

	init(&n3);
	insert(&n3, 0);
   
	removeZero(&L1);
	removeZero(&L2);

    //if either L1 or L2 is 0
    if(compare(L1, zero) == -1 || compare(L2, zero) == -1)
        return zero;

/*
    //both negative
    if(compare(L1, zero) == 0 && compare(L2, zero) == 0){
        negate(&L1);
        negate(&L2);
        n3 = multiply(L1,L2);
        negate(&L1);
        negate(&L2);
        return n3;
    }
    //L1 negative
    else if(compare(L1, zero) == 0){
        negate(&L1);
        n3 = multiply(L1,L2);
        negate(&L1);

        negate(&n3);
        return n3;
    }
    //L2 negative
    else if(compare(L2, zero) == 0){
        negate(&L2);
        n3 = multiply(L1,L2);
        negate(&L2);
        negate(&n3);
        return n3;
    }*/

    if(compare(L1, L2) == 0){
		n3 = multiply(L2,L1);
		return n3;
	}

	init(&one);
	insert(&one, 1);

	init(&count);
	insert(&count, 0);
	
	while(compare(L2, count) != -1){
		
		n3 = add(n3, L1);
		count = add(one, count);
	}
    return n3;
}

node *divide(node *L1, node *L2){
	node *temp, *one, *quotient, *zero;
    init(&zero);
    insert(&zero, 0);

	init(&quotient);
	insert(&quotient, 0);

	removeZero(&L1);
	removeZero(&L2);

    //if L2 greater than L1
	if(compare(L1, L2) == 0){
		return zero;
	}

	//if L2 is equal to 0
	if(compare(L2, zero) == -1){
		return NULL;
	}
    //if L1 is equal to 0
	if(compare(L1, zero) == -1){
		return zero;
	}

/*
    //both negative
   if(compare(L1, zero) == 0 && compare(L2, zero) == 0){
        negate(&L1);
        negate(&L2);
        quotient = divide(L1,L2);
        negate(&L1);
        negate(&L2);
        return quotient;
    }

    //L1 negative
    else if(compare(L1, zero) == 0){
        negate(&L1);
        quotient = divide(L1,L2);
        negate(&L1);
        negate(&quotient);
        return quotient;
    }

    //L2 negative
    else if(compare(L2, zero) == 0){
        negate(&L2);
        quotient = divide(L1,L2);
        negate(&L2);
        negate(&quotient);
        return quotient;
    }
   */

	init(&one);
	insert(&one, 1);

	init(&temp);
	insert(&temp, 0);
	
	while(compare(L1, temp)){
		temp = add(L2, temp);
		if(compare(L1,temp) == 0)
			break;
		
		quotient = add(quotient, one);
	}
	
    return quotient;
}

node *mod(node *L1, node *L2){
	node *temp, *one, *quotient, *zero;
    init(&zero);
    insert(&zero, 0);

	init(&quotient);
	insert(&quotient, 0);

	removeZero(&L1);
	removeZero(&L2);

	//if L2 is 0
	if(compare(L2, quotient) == -1)
		return NULL;

	//if L2 is greater than or equal to L1
	if(compare(L1, L2) != 1)
		return zero;
	
	init(&one);
	insert(&one, 1);
	
	init(&temp);
	insert(&temp, 0);
	
	while(compare(L1, temp)){
		temp = add(L2, temp);
		if(compare(L1,temp) == 0)
			break;
		quotient = add(quotient, one);
	}
	
	temp = multiply(quotient, L2);
	temp = subtract(L1, temp);
	return temp;

}

node *power(node *L1, node *L2){
	node *n3, *one, *count, *zero;
    init(&zero);
    insert(&zero, 0);
    
	init(&n3);
	insert(&n3, 1);

	removeZero(&L1);
	removeZero(&L2);
	
	init(&count);
	insert(&count, 0);
	
	init(&one);
	insert(&one, 1);

	//if L1 and L2 are 0
	if(compare(L1,count) == -1 && compare(L2,count) == -1)
		return NULL;

	//if L1 is 0
	if(compare(L1,count) == -1)
		return one;
    
    //if L2 is negative
    if(compare(L2,zero) == 0)
        return NULL;

    //if L1 is negative
    if(compare(L1,zero) == 0){
        //odd power
        if(L2->data % 2 == 1){
            negate(&L1);
            n3 = power(L1,L2);
            negate(&L1);

            negate(&n3);
            return n3;
        }
        else{
            negate(&L1);
            n3 = power(L1,L2);
            negate(&L1);

            return n3;
        }

    }
	while(compare(L2, count) != -1){
		n3 = multiply(n3, L1);
		count = add(one, count);
	}
    return n3;
}

int precedence(char operator) {
	switch (operator) {
		case '+':
		case '-':
			return 1;
		case '*':
		case '/':
		case '%':
			return 2;
		case '^':
			return 3;
		default:
			return -1;
	}
}

int isOperator(char ch) {
	return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%' || ch == '^');
}

node *operate(charstack **operator, nodestack **operand){
    node *n1, *n2, *n3;
    char op_temp;

	init(&n1);
	init(&n2);
	init(&n3);
	insert(&n3, 0);

    op_temp = popchar(operator);
    n1 = popnode(operand);
	n2 = popnode(operand);
   
    switch(op_temp){
        case '+': n3 = add(n2, n1); break;
        case '-': n3 = subtract(n2, n1); break;
        case '*': n3 = multiply(n2, n1); break;
        case '/': n3 = divide(n2, n1); break;
        case '%': n3 = mod(n2, n1); break;
        case '^': n3 = power(n2, n1); break;
    }   
    
    return n3;
}

void evaluate(char expr[], int s){
	nodestack *operand;
	charstack *operator;
    node *result;
	int n_op = 0; //number of operators
    int count = 0; 
    
	initNodeStack(&operand);
	initCharStack(&operator);
	init(&result);
	insert(&result, 0);

    for(int i = 0; i < s; i ++){
        if(isOperator(expr[i]))
            n_op ++;
    }
    
    node *num[n_op + 1]; //no of numbers = n_op + 1
	
	//initialising numbers
	for(int j =0; j <= n_op+1; j++)
		init(&num[j]);

	//inserting numbers in array
	for(int i = 0; i < s; i++){
		if(isdigit(expr[i]))
			insert(&num[count], expr[i] - '0');
		else if(isOperator(expr[i]))
			count ++;
	}

	count = 0;
	char temp;
	for(int i = 0; i < s; i++){
		if(isdigit(expr[i])){ 
            //traverse till operator is reached
            while(isdigit(expr[i]))
                i++;

            //now i is at operator
            i --;
            //display(num[count]);
			//push numbers onto the operand stack
			pushnode(&operand, num[count++]);
            
			//count++;
		}		
		else if(isOperator(expr[i])){
            while(isEmptyChar(operator) == 0 && precedence(expr[i]) <= precedence(peek(operator))){
                result = operate(&operator, &operand);
				pushnode(&operand, result);
            }
            pushchar(&operator, expr[i]);
		}
        else if(expr[i] == '(')
			pushchar(&operator, expr[i]);
		
		else if(expr[i] == ')' ){		
			while(peek(operator) != '(' ){
				result = operate(&operator, &operand);
				pushnode(&operand, result);
            
			}
			temp = popchar(&operator);
			
		}
	}

	while(isEmptyChar(operator) == 0){
        result = operate(&operator, &operand);
        pushnode(&operand, result);
	}

	result = popnode(&operand);
	reverse(&result);
	display(result);
}