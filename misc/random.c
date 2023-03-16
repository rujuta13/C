// C program for generating a
// random number in a given range.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

// Generates and prints 'count' random
// numbers in range [lower, upper].
void randomGen(int lower, int upper, int count, char fname[])
{
	FILE *fp;
	//char fname[] = "/home/rujuta/dsa/ass1/data.txt";
	fp = fopen(fname, "w");
	if(fp == NULL)//unable to open file
		return;
	
	for (int i = 0; i < count; i++) {
		int num = (rand() % (upper - lower + 1)) + lower;
		//printf("%d\n", num);
		fprintf(fp, "%d",num); 
		fputs("\n",fp);
	}
	fclose(fp);
}

// Driver code
void main(int s, char *A[])
{
	//input: ./a.out n lower upper
	//generate n numbers between lower and upper
	char fname[] = "/home/rujuta/dsa/data1.txt";
	int count, lower, upper;
	int i = 0;
	char c[] = "a";
	while(i<s && isspace(A[i] - '0') != 0){
		printf("%s\n", c);
		printf("%s\n", A[i]);
		strcat(c, A[i]);
		i ++;
	}
	
	printf("%s\n", c);
	/*
	count = atoi(A[1]);
	lower = atoi(A[2]);
	upper = atoi(A[3]);
	*/

	// if seed is set as a number, pseudo-random numbers
	// are generated
	//srand(time(0));
	//srand(2);
	//randomGen(lower, upper, count, fname);
	
}
