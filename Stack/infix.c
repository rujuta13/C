#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_EXPR_SIZE 100

int precedence(char operator) {
	switch (operator) {
		case '+':
		case '-':
			return 1;
		case '*':
		case '/':
			return 2;
		case '^':
			return 3;
		default:
			return -1;
	}
}

int isOperator(char ch) {
	return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

int isNum(char c){
    if(c >= '0' && c <= '9') 
        return 1;
    return 0;
}

char *infixToPostfix(char *infix) {
	int i, j;
	int len = strlen(infix);
	char *postfix = (char *)malloc(sizeof(char) * (len + 2));
	char stack[MAX_EXPR_SIZE];
	int top = -1;

	for (i = 0, j = 0; i < len; i++) {
		if (infix[i] == ' ' || infix[i] == '\t')
			continue;
		if (isNum(infix[i]))
			postfix[j++] = infix[i];
        else if (infix[i] == '(') 
			stack[++top] = infix[i];
		else if (infix[i] == ')') {
			while (top > -1 && stack[top] != '(')
				postfix[j++] = stack[top--];
			if (top > -1 && stack[top] != '(')
				return "Invalid Expression";
			else
				top--;
		} else if (isOperator(infix[i])) {
			while (top > -1 && precedence(stack[top]) >= precedence(infix[i]))
				postfix[j++] = stack[top--];
			stack[++top] = infix[i];
		}
	}

	while (top > -1)
		postfix[j++] = stack[top--];

	postfix[j] = '\0';
	return postfix;
}

int main() {
	char infix[MAX_EXPR_SIZE];
	printf("Enter an infix expression: ");
	gets(infix);
	char *postfix = infixToPostfix(infix);
	printf("Postfix expression: %s\n", postfix);
	free(postfix);
	return 0;
}