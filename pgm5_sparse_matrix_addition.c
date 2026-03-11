//SPARSE MATRIX ADDITION
#include<stdio.h>
void read(int a[20][20],int b[20][20],int m,int n);
void triplet(int a[20][20],int b[20][20],int m,int n,int s1[20][20],int s2[20][20]);
void displayTriplet(int s1[20][20],int s2[20][20]);
void add(int s1[20][20],int s2[20][20],int c[20][20],int m,int n);
void display(int c[20][20]);
void main()
{
int a[20][20],b[20][20],s1[20][20],s2[20][20],c[20][20];
int m,n,p,q;
printf("Enter the order of first matrix: ");
scanf("%d %d",&m,&n);
printf("Enter the order of second  matrix: ");
scanf("%d %d",&p,&q);
if(m==p && n==q)
{
printf("\nENTER THE ELEMENTS OF FIRST AND SECOND MATRIX:\n");
read(a,b,m,n);
triplet(a,b,m,n,s1,s2);
printf("\nTRIPLET FORM:\n");
displayTriplet(s1,s2);
add(s1,s2,c,m,n);
printf("\nRESULTANT MATRIX AFTER ADDITION:\n");
display(c);
}
else
printf("\nADDITION NOT POSSIBLE!!!");
}
void read(int a[20][20], int b[20][20], int m, int n) {
int i, j;
printf("Enter the elements of first matrix:\n");
for (i=0;i<m;i++)
{
for (j=0;j<n;j++)
{
scanf("%d", &a[i][j]);
}
}
printf("Enter the elements of second matrix:\n");
for (i=0;i<m;i++)
{
for (j=0;j<n;j++)
{
scanf("%d", &b[i][j]);
}
}
}
void triplet(int a[20][20],int b[20][20],int m,int n,int s1[20][20],int s2[20][20])
{
int i,j;
int k1=1;
int k2=1;
s1[0][0]=m;
s1[0][1]=n;
s2[0][0]=m;
s2[0][1]=n;
for(i=0;i<m;i++)
{
for(j=0;j<n;j++)
{
if(a[i][j]!=0)
{
s1[k1][0]=i;
s1[k1][1]=j;
s1[k1][2]=a[i][j];
k1++;
}
}
}
s1[0][2]=k1-1;
for(i=0;i<m;i++)
{
for(j=0;j<n;j++)
{
if(b[i][j]!=0)
{
s2[k2][0]=i;
s2[k2][1]=j;
s2[k2][2]=b[i][j];
k2++;
}
}
}
s2[0][2]=k2-1;
}
void displayTriplet(int s1[20][20],int s2[20][20])
{
int i,j;
int num1=s1[0][2];
int num2=s2[0][2];
printf("Triplet form of FIRST MATRIX:\n");
for(i=0;i<=num1;i++)
{
for(j=0;j<3;j++)
{
printf("%d ",s1[i][j]);
}
printf("\n");
}
printf("\nTriplet form of SECOND MATRIX:\n");
for(i=0;i<=num2;i++)
{
for(j=0;j<3;j++)
{
printf("%d ",s2[i][j]);
}
printf("\n");
}
}
void add(int s1[20][20],int s2[20][20],int c[20][20],int m,int n)
{
int p=1;
int q=1;
int k=1;
int t1=s1[0][2];
int t2=s2[0][2];
c[0][0]=m;
c[0][1]=n;
while(p<=t1 && q<=t2)
{
if(s1[p][0]==s2[q][0] && s1[p][1]==s2[q][1])
{
c[k][0]=s1[p][0];
c[k][1]=s1[p][1];
c[k][2]=s1[p][2]+s2[q][2];
p++;
q++;
k++;
}
else if (s1[p][0] < s2[q][0] || (s1[p][0] == s2[q][0] && s1[p][1] < s2[q][1]))
{
c[k][0]=s1[p][0];
c[k][1]=s1[p][1];
c[k][2]=s1[p][2];
p++;
k++;
}
else
{
c[k][0]=s2[p][0];
c[k][1]=s2[p][1];
c[k][2]=s2[q][2];
q++;
k++;
}
}
while (p <= t1)
{
c[k][0] = s1[p][0];
c[k][1] = s1[p][1];
c[k][2] = s1[p][2];
p++;
k++;
}
while (q <= t2)
{
c[k][0] = s2[q][0];
c[k][1] = s2[q][1];
c[k][2] = s2[q][2];
q++;
k++;
}
c[0][2] = k - 1;
}
void display(int c[20][20])
{
int i,j;
int num=c[0][2];
for(i=0;i<=num;i++)
{
for(j=0;j<3;j++)
{
printf("%d ",c[i][j]);
}
printf("\n");
}
}

/*
OUTPUT:
Enter the order of first matrix: 2 2
Enter the order of second  matrix: 2 2

ENTER THE ELEMENTS OF FIRST AND SECOND MATRIX:
Enter the elements of first matrix:
0 1
2 0
Enter the elements of second matrix:
0 5
0 2

TRIPLET FORM:
Triplet form of FIRST MATRIX:
2 2 2
0 1 1
1 0 2

Triplet form of SECOND MATRIX:
2 2 2
0 1 5
1 1 2

RESULTANT MATRIX AFTER ADDITION:
2 2 3
0 1 6
1 0 2
1 1 2

*/
