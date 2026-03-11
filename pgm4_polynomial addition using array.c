//POLYNOMIAL ADDITION USING ARRAY
#include<stdio.h>
struct poly
{
int coeff;
int expo;
}p1[10],p2[10],p3[10];
int readPoly(struct poly p[10]);
int addPoly(struct poly p1[10],struct poly p2[10],int t1,int t2,struct poly p3[10]);
int display(struct poly p[10],int terms);
void main()
{
int t1,t2,t3;
printf("ENTER THE COEFFICIENTS AND EXPONENETS IN DESCENDIMG ORDER:\n");
printf("Enter the first polynomial:\n");
t1=readPoly(p1);
printf("Enter the second polynomial:\n");
t2=readPoly(p2);
printf("\nFIRST POLYNOMIAL: ");
display(p1,t1);
printf("\nSECOND POLYNOMIAL: ");
display(p2,t2);
t3=addPoly(p1,p2,t1,t2,p3);
printf("\nSUM: ");
display(p3,t3);
}
int readPoly(struct poly p[10])
{
int i,t;
printf("Enter the no:of terms: ");
scanf("%d",&t);
printf("Enter the coefficients and exponents:\n");
for(i=0;i<t;i++)
{
scanf("%d %d",&p[i].coeff,&p[i].expo);
}
return t;
}

int display(struct poly p[10],int terms)
{
int k;
for(k=0;k<terms-1;k++)
{
printf("%dx^%d + ",p[k].coeff,p[k].expo);
}
printf("%dx^%d",p[terms-1].coeff,p[terms-1].expo);
}

int addPoly(struct poly p1[10],struct poly p2[10],int t1,int t2,struct poly p3[10])
{
int i=0;
int j=0;
int k=0;
while(i<t1 && j<t2)
{
if(p1[i].expo==p2[j].expo)
{
p3[k].coeff=p1[i].coeff+p2[j].coeff;
p3[k].expo=p1[i].expo;
i++;
j++;
k++;
}
else if(p1[i].expo>p2[j].expo)
{
p3[k].coeff=p1[i].coeff;
p3[k].expo=p1[i].expo;
i++;
k++;
}
else
{
p3[k].coeff=p2[j].coeff;
p3[k].expo=p2[j].expo;
j++;
k++;
}
}
}


/*
OUTPUT:
ENTER THE COEFFICIENTS AND EXPONENETS IN DESCENDIMG ORDER:
Enter the first polynomial:
Enter the no:of terms: 4
Enter the coefficients and exponents:
9 4 8 3 7 2 6 1
Enter the second polynomial:
Enter the no:of terms: 3
Enter the coefficients and exponents:
6 3 5 2 4 1

FIRST POLYNOMIAL: 9x^4 + 8x^3 + 7x^2 + 6x^1
SECOND POLYNOMIAL: 6x^3 + 5x^2 + 4x^1
SUM: 9x^4 + 14x^3 + 12x^2 + 10x^1
*/