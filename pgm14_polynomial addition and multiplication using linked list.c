//POLYNOMIAL ADDITION AND MULTIPLICATION USING LINKED LISTS
#include<stdio.h>
#include<stdlib.h>
struct node
{
int coeff;
int expo;
struct node*link;
};

struct node *Phead=NULL, *Qhead=NULL,*Rhead=NULL;

struct node *read();
void display(struct node *ptr);
void sum();
void multiply();

void main()
{
printf("Enter the first polynomial: \n");
Phead=read();
printf("\nEnter the second polynomial: \n");
Qhead=read();
printf("\nFIRST POLYNOMIAL: ");
display(Phead);
printf("\nSECOND POLYNOMIAL: ");
display(Qhead);
printf("\n\nSUM: ");
sum();
printf("\n\nPRODUCT: ");
multiply();
}

struct node *read()
{
int c,e;
int n,i;

struct node *head=NULL,*tail=NULL;

printf("Enter the no:of terms in the polynomial: ");
scanf("%d",&n);

for(i=0;i<n;i++)
{
printf("Enter the coefficient and exponent: ");
scanf("%d %d",&c,&e);

struct node *new=(struct node*)malloc(sizeof(struct node));

new->coeff=c;
new->expo=e;
new->link=NULL;

if(head==NULL)
{
head=tail=new;
}

else
{
tail->link=new;
tail=new;
}
}

return head;
}

void display(struct node *ptr)
{
if(ptr==NULL)
{
printf("EMPTY...!!!\n");
return;
}

while(ptr!=NULL)
{
printf("%dx^%d",ptr->coeff,ptr->expo);
ptr=ptr->link;

if(ptr!=NULL)
{
printf(" + ");
}
}
printf("\n");
}


void sum()
{
struct node *P=Phead,*Q=Qhead,*R=NULL;
Rhead=NULL;

while(P!=NULL && Q!=NULL)
{
struct node *new=(struct node*)malloc(sizeof(struct node));

if(P->expo == Q->expo)
{
new->coeff = P->coeff + Q->coeff;
new->expo = P->expo;
new->link=NULL;
P=P->link;
Q=Q->link;
}

else if(P->expo > Q->expo)
{
new->coeff = P->coeff;
new->expo = P->expo;
new->link=NULL;
P=P->link;
}

else
{
new->coeff = Q->coeff;
new->expo = Q->expo;
new->link=NULL;
Q=Q->link;
}

if(Rhead==NULL)
{
Rhead=R=new;
}

else
{
R->link=new;
R=new;
}
}

while(P!=NULL)
{
struct node *new=(struct node *)malloc(sizeof(struct node));
new->coeff = P->coeff;
new->expo = P->expo;
new->link = NULL;

if(Rhead==NULL)
{
Rhead=R=new;
}
else
{
R->link=new;
R=new;
}

P = P->link;
}

while(Q!=NULL)
{
struct node *new=(struct node*)malloc(sizeof(struct node));

new->coeff = Q->coeff;
new->expo = Q->expo;
new->link = NULL;

if(Rhead==NULL)
{
Rhead=R=new;
}
else
{
R->link=new;
R=new;
}
Q=Q->link;
}
display(Rhead);
}

void multiply()
{
struct node *P=Phead,*R=NULL;
Rhead=NULL;

while(P!=NULL)
{
struct node *Q=Qhead;
while(Q!=NULL)
{
struct node *new=(struct node*)malloc(sizeof(struct node));
new->coeff = P->coeff * Q->coeff;
new->expo = P->expo + Q->expo;
new->link =NULL;

if(Rhead == NULL)
{
Rhead=R=new;
}

else
{
R->link=new;
R=new;
}
Q=Q->link;
}
P=P->link;
}

struct node *ptr=Rhead;
while(ptr!=NULL)
{
struct node *prev=ptr;
struct node *curr=ptr->link;
while(curr!=NULL)
{
if(ptr->expo == curr->expo)
{
ptr->coeff +=curr->coeff;
prev->link = curr->link;
struct node *temp=curr;
free(temp);

curr=prev->link;
}

else
{
prev=curr;
curr=curr->link;
}

}
ptr=ptr->link;
}
display(Rhead);
}



/*OUTPUT:
Enter the first polynomial:
Enter the no:of terms in the polynomial: 2
Enter the coefficient and exponent: 1 2
Enter the coefficient and exponent: 1 1

Enter the second polynomial:
Enter the no:of terms in the polynomial: 2
Enter the coefficient and exponent: 1 1
Enter the coefficient and exponent: 1 0

FIRST POLYNOMIAL: 1x^2 + 1x^1

SECOND POLYNOMIAL: 1x^1 + 1x^0


SUM: 1x^2 + 2x^1 + 1x^0


PRODUCT: 1x^3 + 2x^2 + 1x^1
*/