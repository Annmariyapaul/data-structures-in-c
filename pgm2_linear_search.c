//LINEAR SEARCH,BUBBLE SORT
#include<stdio.h>
int linearSearch(int a[100],int n);
int bubbleSort(int a[100],int n);
void main()
{
int ch,n,i;
int a[100];
printf("Enter the no:of elements in the array: ");
scanf("%d",&n);
printf("Enter the elements:\n");
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
do	
{
printf("\nMENU\n");
printf("Enter 1 for linear search.\n");
printf("Enter 2 for Bubble Sort.\n");
printf("Enter your choice: ");
scanf("%d",&ch);
switch(ch)
{
case 1:
{
linearSearch(a,n);
break;
}
case 2:
{
bubbleSort(a,n);
break;
}
default:
{
printf("WRONG CHOICE!!!");
break;
}
}
}while(ch!=2);
}
int linearSearch(int a[100],int n)
{
int flag=0;
int i,num;
printf("Enter the number to be searched:  ");
scanf("%d",&num);
for(i=0;i<n;i++)
{
if(a[i]==num)
{
flag =1;
break;
}
}
if(flag==0)
printf("Number is not present.\n");
else
printf("Number is present.\n");
}
int bubbleSort(int a[100],int n)
{
int temp=0;
int i,j;
for(i=0;i<n-1;i++)
{
for(j=0;j<n-i-1;j++)
{
if(a[j]>a[j+1])
{
temp=a[j];
a[j]=a[j+1];
a[j+1]=temp;
}
}
}
printf("\nSorted Array\n");
for(i=0;i<n;i++)
{
printf("%d ",a[i]);
}
}















/*SAMPLE OUTPUT:
Enter the no:of elements in the array: 5
Enter the elements:
2 6 1 8 4

MENU
Enter 1 for linear search.
Enter 2 for Bubble Sort.
Enter your choice: 1
Enter the number to be searched:  8
Number is present.

MENU
Enter 1 for linear search.
Enter 2 for Bubble Sort.
Enter your choice: 2

Sorted Array
1 2 4 6 8*/
