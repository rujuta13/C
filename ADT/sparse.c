#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	int i,j;
	struct node *right , *down;
}node;
typedef struct sparse{
	node **row, **col;
	int r,c;
}sparse;

void insertnode(sparse *s, node *n , int i , int j){
	node *pr , *pc;
	if(s->row[i]==NULL)
		s->row[i] = n;
	else{
		pr = s->row[i];
		while(pr->right)
			pr = pr->right;
		pr->right = n;
	}
	if(s->col[j]==NULL)
		s->col[j] = n;
	else{
		pc = s->col[j];
		while(pc->down)
			pc = pc->down;
		pc->down = n;
	}
}

void init_matrix(sparse *s , char *filename){
	FILE *fp = fopen(filename , "r");
	if(!fp) 
		return;
		
	int r , c;
	fscanf(fp , "%d\n" , &r);
	s->r = r;
	fscanf(fp , "%d\n" , &c);
	s->c = c;
	s->row = (node**)malloc(sizeof(node*)*r);
	s->col = (node**)malloc(sizeof(node*)*c);
	for(int i = 0 ; i<r ; i++)
		s->row[i] = NULL;
	for(int i = 0 ; i< c ; i++)
		s->col[i] = NULL;
	int val;
	node *nn;
	for(int i = 0 ; i<r ; i++)
		for(int j = 0 ; j<c ; j++){
			fscanf(fp , "%d" , &val);
			if(val!=0){
				nn =(node*)malloc(sizeof(node));
				nn->down = NULL;
				nn->right = NULL;
				nn->data = val;
				nn->i = i;
				nn->j = j;
				insertnode(s , nn , i , j);
			}
		}
	fclose(fp);
	return;
}

void display(sparse s){
	node*p;
	printf("Row  Col  Data : \n");
	for(int i = 0 ; i<s.r ; i++){
		p = s.row[i];
		while(p){
			printf("%d    %d    %d\n", p->i , p->j , p->data);
			p = p->right;
		}
	}
	return;
}
void init(sparse *s , int r , int c){
        s->r = r;
        s->c = c;
	s->row = (node**)malloc(sizeof(node*)*r);
	s->col = (node**)malloc(sizeof(node*)*c);
        for(int i = 0 ; i<r ; i++)
                s->row[i] = NULL;
        for(int i = 0 ; i<c ; i++)
                s->col[i] = NULL;
}

sparse addsparse(sparse s1 , sparse s2){
	sparse s3;
	init(&s3 , s1.r , s1.c);

	//matrices need to have same dimensions
	if(s1.r != s2.r && s1.c != s2.c) 
		return s3;
	node *n , *p , *q;
	int val;
	for(int i = 0 ; i < s1.r ; i++){
		p = s1.row[i];
		q = s2.row[i];
		while(p && q){
			if(p->j == q->j){
				val = p->data + q->data;

				n = (node*)malloc(sizeof(node));
				n->right = NULL;
				n->down = NULL;

				n->i = p->i;
				n->j = p->j;
				n->data = val;

				insertnode(&s3 , n , p->i , p->j);
				p = p->right;
				q = q->right;
			}
			else if(p->j < q->j){
				val = p->data;

				n = (node*)malloc(sizeof(node));
				n->right = NULL;
				n->down = NULL;

				n->i = p->i;
				n->j = p->j;
				n->data = val;
				insertnode(&s3 , n , p->i , p->j);
				p = p->right;
			}
			else {
				val = q->data;

				n = (node*)malloc(sizeof(node));
				n->right = NULL;
				n->down = NULL;

				n->i = i;
				n->j = q->j;
				n->data = val;
				insertnode(&s3 , n , i , q->j);
				q = q->right;
			}
		}

		while(p){
			val = p->data;

			n = (node*)malloc(sizeof(node));
			n->right = NULL;
			n->down = NULL;

			n->i = p->i;
			n->j = p->j;
			n->data = val;
			insertnode(&s3 , n , i , p->j);
			p = p->right;
		}

		while(q){
			val = q->data;

			n = (node*)malloc(sizeof(node));
			n->right = NULL;
			n->down = NULL;

			n->i = q->i;
			n->j = q->j;
			n->data = val;
			insertnode(&s3 , n , i , q->j);
			q = q->right;
		}
	}
	return s3;	
}
sparse subtractsparse(sparse s1 , sparse s2){
	sparse s3;
	init(&s3 , s1.r , s1.c);

	//matrices need to have same dimensions
	if(s1.r != s2.r && s1.c != s2.c) 
		return s3;

	node *n , *p , *q;
	int val;
	for(int i = 0 ; i<s1.r ; i++){
		p = s1.row[i];
		q = s2.row[i];
		while( p&& q){
		if(p->j == q->j){
			val = p->data - q->data;
			n = (node*)malloc(sizeof(node));
			n->right = NULL;
			n->down = NULL;
			n->i = p->i;
			n->j = p->j;
			n->data = val;
			insertnode(&s3 , n , p->i , p->j);
			p = p->right;	
			q = q->right;
		}
		else if(p->j < q->j){
			val = p->data;
			n = (node*)malloc(sizeof(node));
			n->right = NULL;
			n->down = NULL;
			n->i = p->i;
			n->j = p->j;
			n->data = val;
			insertnode(&s3 , n , p->i , p->j);
			p = p->right;
		}
		else {
			val = -q->data;
			n = (node*)malloc(sizeof(node));
			n->right = NULL;
			n->down = NULL;
			n->i = i;
			n->j = q->j;
			n->data = val;
			insertnode(&s3 , n , i , q->j);
			q = q->right;
		}
		}
		while(p){
			val = p->data;
			n = (node*)malloc(sizeof(node));
			n->right = NULL;
			n->down = NULL;
			n->i = p->i;
			n->j = p->j;
			n->data = val;
			insertnode(&s3 , n , i , p->j);
			p = p->right;
		}
		while(q){
			val = -q->data;
			n = (node*)malloc(sizeof(node));
			n->right = NULL;
			n->down = NULL;
			n->i = q->i;
			n->j = q->j;
			n->data = val;
			insertnode(&s3 , n , i , q->j);
			q = q->right;
		}
	}
	return s3;                
}
sparse transpose(sparse s){
	sparse s1;
	init(&s1 , s.r , s.c);
	node *nn ; node *p;
	for(int i = 0 ; i<s.r ; i++){
		p = s.row[i];
		while(p){
			nn = (node*)malloc(sizeof(node));
			nn->right  = NULL;
			nn->down = NULL;

			nn->data = p->data;
			
			//swap indices
			nn->i = p->j;
			nn->j = p->i;
			
			insertnode(&s1 , nn , nn->i , nn->j);
			p = p->right;
		}
	}
	return s1;
}
int checksymmetric(sparse s){
	if(s.r != s.c)
		return 0;
	node *p;
	node *q;
	for(int i = 0 ; i<s.r ; i++){
		p = s.row[i];
		q = s.col[i];
		while(p&&q){
			if(p->data != q->data)
				return 0;
			p = p->right;
			q = q->down;
		}
	}
	return 1;
}

int main(){
	sparse s1 , s2 , s3 , s4 , s5;
	init_matrix(&s1 , "M1.txt");
	init_matrix(&s2 , "M2.txt");
	printf("Matrix 1: \n");
	display(s1);
	printf("\nMatrix 2 : \n");
	display(s2);
	printf("\nSymmetric check for M2:\n");
	printf("%d\n",checksymmetric(s2));
	printf("\nM1 + M2:\n");
	s4 = addsparse(s1,s2);
	display(s4);
	printf("\nM1 - M2:\n");
	s5 = subtractsparse(s1,s2);
	display(s5);
	printf("\nTranspose of M1:\n");
	s3 = transpose(s1);
	display(s3);
	return 0 ;
}
