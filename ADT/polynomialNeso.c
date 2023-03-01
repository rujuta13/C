
#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    float co;
    int expo;
    struct node* next;
}node;

node* insert(node* head,float co,int expo)
{
    node* temp = malloc(sizeof(node));
    temp->co = co;
    temp->expo = expo;
    temp->next=NULL;

    if(head==NULL || head->expo < expo)
    {
        temp->next = head;
        head=temp;
    }
    else
    {
        node* p=head;
        while(p->next != NULL && p->next->expo >= expo)
        {
            p = p->next;
        }
        temp->next = p->next;
        p->next = temp;
    }
    return head;
}

node* add(node* head,node* head1)
{
    node* temp = head;
    node* p=head1;
    node* head2=NULL;
    int res;
    while(temp!=NULL && p!=NULL)
    {

        if(temp->expo == p->expo)
        {
            res = temp->co+p->co;
            head2=insert(head2,res,temp->expo);
            temp=temp->next;
            p=p->next;
        }
        else if(temp->expo > p->expo)
        {
            head2=insert(head2,temp->co,temp->expo);
            temp=temp->next;
        }
        else if(p->expo>temp->expo)
        {
            head2=insert(head2,p->co,p->expo);
            p=p->next;
        }
    }
    while(temp!=NULL)
    {
        head2=insert(head2,temp->co,temp->expo);
        temp=temp->next;
    }
    while(p!=NULL)
    {
        head2=insert(head2,p->co,p->expo);
        p=p->next;
    }
    return head2;
}


node* create(node* head)
{
    int n,expo;
    float co;
    
    printf("Enter the number of terms: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("\tEnter the coefficient of term %d: ",i+1);
        scanf("%f",&co);
        printf("\tEnter the exponent of term %d:",i+1);
        scanf("%d",&expo);
        head=insert(head,co,expo);
        printf("\n");
    }
    printf("\n");
    return head;
}

int main()
{
    node* head=NULL;
    node* head1=NULL;
    node* head2=NULL;
    head=create(head);
    head1=create(head1);
    head2=add(head,head1); 
    node* ptr=head2;
    while(ptr!=NULL)
    {
        printf("(%.1f x^%d)",ptr->co,ptr->expo);
        ptr=ptr->next;
        if(ptr!=NULL)
        {
            printf("+");
        }
        else
        printf("\n");  
    }
}