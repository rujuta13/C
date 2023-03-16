#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int coeff;
	int pow;
	struct Node* next;
};

void readPolynomial(struct Node** poly)
{
	int coeff, exp, count;
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	*poly = temp;
	do{
		printf("\n Coeffecient: ");
		scanf("%d", &coeff);
		printf("\n Exponent: ");
		scanf("%d", &exp);
		temp->coeff = coeff;
		temp->pow = exp;
		temp-> next = NULL;
		printf("\nDo you want more elements? 1 for y and 0 for no: ");
		scanf("%d", &count);
		if(count)
		{
			temp->next = (struct Node*)malloc(sizeof(struct Node));
			temp = temp->next;
			temp->next = NULL;
		}
	}while(cont);
}

void displayPolynomial(struct Node* poly)
{
	printf("\nPolynomial expression is: ");
	while(poly != NULL)
	{
		printf("%dX^%d", poly->coeff, poly->pow);
		poly = poly->next;
		if(poly != NULL)
			printf("+");
	}
}

void addPolynomials(struct Node** P3, struct Node* P1, struct Node* P2)
{
 	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
 	temp->next = NULL;
 	*P3 = temp;
 	while(P1 && P2)
 	{
 		if(P1->pow > P2->pow)
 		{
 			temp->coeff = P1->coeff;
 			temp->pow = P1->pow;
 			P1 = P1->next;
 		}
 		else if(P1->pow < P2->pow)
 		{
 			temp->coeff = P2->coeff;
 			temp->pow = P2->pow;
 			P2 = P2->next;
 		}
 		else
 		{
 			temp->coeff = P1->coeff + P2->coeff;
 			temp->pow = P1->pow;
 			P1 = P1->next;
 			P2 = P2->next;
 		}

 		if(P1 && P2)
 		{
 			temp->next = (struct Node*)malloc(sizeof(struct Node));
 			temp = temp->next;
 			temp->next = NULL;
 		}
 	}
 	while(P1 || P2)
 	{
 		temp->next = (struct Node*)malloc(sizeof(struct Node));
 		temp = temp->next;
 		temp->next = NULL;

 		if(P1)
 		{
 			temp->coeff = P1->coeff;
 			temp->pow = P1->pow;
 			P1 = P1->next;
 		}

 		else if(P2)
 		{
 			temp->coeff = P2->coeff;
 			temp->pow = P2->pow;
 			P2 = P2->next;
 		}
 	}
}

int main()
{

	struct Node* P1 = NULL;
	struct Node* P2 = NULL;
	struct Node* P3 = NULL;

	printf("\nEnter the corresponding data:-\n");
	printf("\nFirst polynomial:\n");
	readPolynomial(&P1);
	displayPolynomial(P1);
	printf("\nSecond polynomial:\n");
	readPolynomial(&P2);
	displayPolynomial(P2);
	addPolynomials(&P3, P1, P2);
	printf("\n\nAddition of polynomials is:");
	displayPolynomial(P3);
	return 0;
}
