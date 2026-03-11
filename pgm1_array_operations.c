//MENU DRIVEN_ARRAY OPERATIONS
#include <stdio.h>
int binsert(int a[100], int n);
int einsert(int a[100], int n);
int ginsert(int a[100], int n);
int bdlt(int a[100], int n);
int edlt(int a[100], int n);
int posdlt(int a[100], int n);
int gdlt(int a[100], int n);
void display(int a[100], int n);

void main() 
{
int ch, n, i;
int a[100];
printf("\nARRAY OPERATIONS\n");
printf("Enter the number of elements in the array:  ");
scanf("%d", &n);
printf("Enter the elements:\n");
for (i = 0; i < n; i++)
{
scanf("%d", &a[i]);
}
do
{
printf("\nMENU\n");
printf("Enter 1 for inserting an element at the beginning\n");
printf("Enter 2 for inserting an element at the end\n");
printf("Enter 3 for inserting at a given position\n");
printf("Enter 4 for deleting the element from the beginning\n");
printf("Enter 5 for deleting the element from the end\n");
printf("Enter 6 for deleting the element at a given position\n");
printf("Enter 7 for deleting a given element\n");
printf("Enter 8 for displaying the array\n");
printf("Enter your choice:  ");
scanf("%d", &ch);
switch (ch)
{
case 1:
{
n = binsert(a, n);
break;
}
case 2:
{
n = einsert(a, n);
break;
}
case 3:
{
n = ginsert(a, n);
break;
}
case 4:
{
n = bdlt(a, n);
break;
}
case 5:
{
n = edlt(a, n);
break;
}
case 6:
{
n = posdlt(a, n);
break;
}
case 7:
{
n = gdlt(a, n);
break;
}
case 8:
{
display(a, n);
break;
}
default:
{
printf("WRONG CHOICE!!!\n");
break;
}
}
} while (ch != 8);
}

int binsert(int a[100], int n)
{
int num, i;
printf("Enter the number to be inserted at the beginning:  ");
scanf("%d", &num);
for (i = n; i > 0; i--)
{
a[i] = a[i - 1];
}
a[0] = num;
n++;
for(i = 0; i < n; i++)
{
printf("%d ", a[i]);
}
printf("\n");
return n;
}

int einsert(int a[100], int n)
{
int i,num;
printf("Enter the number to be inserted at the end:  ");
scanf("%d", &num);
a[n] = num;
n++;
for(i = 0; i < n; i++)
{
printf("%d ", a[i]);
}
printf("\n");
return n;
}

int ginsert(int a[100], int n)
 {
int pos, num, i;
printf("Enter the position to insert:  ");
scanf("%d", &pos);
printf("Enter the number to be inserted at the given position:  ");
scanf("%d", &num);
for (i = n; i >= pos; i--)
{
a[i] = a[i - 1];
}
a[pos - 1] = num;
n++;
for(i = 0; i < n; i++)
{
printf("%d ", a[i]);
}
printf("\n");
return n;
}

int bdlt(int a[100], int n) 
{
int i;
for (i = 0; i < n - 1; i++)
{
a[i] = a[i + 1];
}
n--;
for(i = 0; i < n; i++)
{
printf("%d ", a[i]);
}
printf("\n");
return n;
}

int edlt(int a[100], int n)
{
int i;
n--;
for(i = 0; i < n; i++)
{
printf("%d ", a[i]);
}
printf("\n");
return n;
}

int posdlt(int a[100], int n)
{
int pos, i;
printf("Enter the position to be deleted:  ");
scanf("%d", &pos);
for (i = pos - 1; i < n - 1; i++)
{
a[i] = a[i + 1];
}
n--;
for(i = 0; i < n; i++)
{
printf("%d ", a[i]);
}
printf("\n");
return n;
}

int gdlt(int a[100], int n)
{
int i, j, num;
printf("Enter the number to be deleted:  ");
scanf("%d", &num);
for (i = 0; i < n; i++)
{
if (a[i] == num)
{
for (j = i; j < n - 1; j++)
{
a[j] = a[j + 1];
}
n--;
i--;
}
}
for(i = 0; i < n; i++)
{
printf("%d ", a[i]);
}
printf("\n");
return n;
}

void display(int a[100], int n)
 {
int i;
printf("\nARRAY ELEMENTS\n");
for (i = 0; i < n; i++)
 {
printf("%d ", a[i]);
}
printf("\n");

}


/*
OUTPUT:

ARRAY OPERATIONS
Enter the number of elements in the array:  5
Enter the elements:
2 5 3 6 4

MENU
Enter 1 for inserting an element at the beginning
Enter 2 for inserting an element at the end
Enter 3 for inserting at a given position
Enter 4 for deleting the element from the beginning
Enter 5 for deleting the element from the end
Enter 6 for deleting the element at a given position
Enter 7 for deleting a given element
Enter 8 for displaying the array
Enter your choice:  1
Enter the number to be inserted at the beginning:  1
1 2 5 3 6 4 

MENU
Enter 1 for inserting an element at the beginning
Enter 2 for inserting an element at the end
Enter 3 for inserting at a given position
Enter 4 for deleting the element from the beginning
Enter 5 for deleting the element from the end
Enter 6 for deleting the element at a given position
Enter 7 for deleting a given element
Enter 8 for displaying the array
Enter your choice:  2
Enter the number to be inserted at the end:  8
1 2 5 3 6 4 8 

MENU
Enter 1 for inserting an element at the beginning
Enter 2 for inserting an element at the end
Enter 3 for inserting at a given position
Enter 4 for deleting the element from the beginning
Enter 5 for deleting the element from the end
Enter 6 for deleting the element at a given position
Enter 7 for deleting a given element
Enter 8 for displaying the array
Enter your choice:  3
Enter the position to insert:  2
Enter the number to be inserted at the given position:  7
1 7 2 5 3 6 4 8 

MENU
Enter 1 for inserting an element at the beginning
Enter 2 for inserting an element at the end
Enter 3 for inserting at a given position
Enter 4 for deleting the element from the beginning
Enter 5 for deleting the element from the end
Enter 6 for deleting the element at a given position
Enter 7 for deleting a given element
Enter 8 for displaying the array
Enter your choice:  4
7 2 5 3 6 4 8 

MENU
Enter 1 for inserting an element at the beginning
Enter 2 for inserting an element at the end
Enter 3 for inserting at a given position
Enter 4 for deleting the element from the beginning
Enter 5 for deleting the element from the end
Enter 6 for deleting the element at a given position
Enter 7 for deleting a given element
Enter 8 for displaying the array
Enter your choice:  5
7 2 5 3 6 4 

MENU
Enter 1 for inserting an element at the beginning
Enter 2 for inserting an element at the end
Enter 3 for inserting at a given position
Enter 4 for deleting the element from the beginning
Enter 5 for deleting the element from the end
Enter 6 for deleting the element at a given position
Enter 7 for deleting a given element
Enter 8 for displaying the array
Enter your choice:  6
Enter the position to be deleted:  3
7 2 3 6 4 

MENU
Enter 1 for inserting an element at the beginning
Enter 2 for inserting an element at the end
Enter 3 for inserting at a given position
Enter 4 for deleting the element from the beginning
Enter 5 for deleting the element from the end
Enter 6 for deleting the element at a given position
Enter 7 for deleting a given element
Enter 8 for displaying the array
Enter your choice:  7
Enter the number to be deleted:  7
2 3 6 4 

MENU
Enter 1 for inserting an element at the beginning
Enter 2 for inserting an element at the end
Enter 3 for inserting at a given position
Enter 4 for deleting the element from the beginning
Enter 5 for deleting the element from the end
Enter 6 for deleting the element at a given position
Enter 7 for deleting a given element
Enter 8 for displaying the array
Enter your choice:  8

ARRAY ELEMENTS
2 3 6 4
*/