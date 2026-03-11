
//BINARY SEARCH
#include<stdio.h>
void bubbleSort(int a[100],int n);
void binarySearch(int a[100],int low,int high);
void main()
{
int n,i;
int a[100];
printf("Enter the no:of elements in the array:  ");
scanf("%d",&n);
printf("Enter the elements:\n");
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
bubbleSort(a,n);
binarySearch(a,0,n-1);
}
void bubbleSort(int a[100],int n)
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
printf("Sorted Array\n");
for(i=0;i<n;i++)
{
printf("%d ",a[i]);
}
}
void binarySearch(int a[100],int low,int high)
{
int i;
int flag=0;
int mid;
int search;
printf("Enter the number to be searched: ");
scanf("%d",&search);
while(low<=high)
{
mid=(low+high)/2;
if(a[mid]==search)
{
flag=1;
break;
}
else if(a[mid]>search)
high=mid-1; else low=mid+1;
}
if(flag==1)
printf("Number is present.");
else
printf("Number is not present.");
}

/*OUTPUT:
Enter the no:of elements in the array: 5
Enter the elements:
8 4 1 9 2
Sorted Array
1 2 4 8 9
Enter the number to be searched: 8
Number is present.
*/

