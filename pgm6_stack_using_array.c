//STACK USING ARRAY
#include<stdio.h>
#define SIZE 5
int a[SIZE];
int top=-1;
void push();
void pop();
void traverse();
void main()
{
int ch;
do
{
printf("\n\nMENU\n");
printf("Enter 1 for push\n");
printf("Enter 2 for pop\n");
printf("Enter 3 for displaying stack\n");
printf("Enter 4 for exit\n");
printf("Enter your choice: ");
scanf("%d",&ch);
switch(ch)
{
case 1:
{
push();
break;
}
case 2:
{
pop();
break;
}
case 3:
{
traverse();
break;
}
case 4:
{
printf("\nEXIT\n");
break;
}
default:
{
printf("\nWRONG CHOICE!!!\n");
break;
}
}
}while(ch!=4);
}
void push()
{
int num;
if(top==SIZE-1)
printf("Stack is full!!!\n");
else
{
top++;
printf("Enter the element to be inserted: ");
scanf("%d",&num);
a[top]=num;
}
}
void pop()
{
if(top==-1)
printf("Stack is empty!!!");
else
{
printf("Element to be deleted: %d",a[top]);
top--;
}
}
void traverse()
{
int i;
if(top==-1)
printf("Stack is empty!!!");
else
{
printf("\nSTACK:\n");
for(i=top;i>=0;i--)
{
printf("%d",a[i]);
}
}
}

/*SAMPLE OUTPUT:
MENU
Enter 1 for push
Enter 2 for pop
Enter 3 for displaying stack
Enter 4 for exit
Enter your choice: 1
Enter the element to be inserted: 5


MENU
Enter 1 for push
Enter 2 for pop
Enter 3 for displaying stack
Enter 4 for exit
Enter your choice: 1
Enter the element to be inserted: 4


MENU
Enter 1 for push
Enter 2 for pop
Enter 3 for displaying stack
Enter 4 for exit
Enter your choice: 1
Enter the element to be inserted: 3


MENU
Enter 1 for push
Enter 2 for pop
Enter 3 for displaying stack
Enter 4 for exit
Enter your choice: 1
Enter the element to be inserted: 2


MENU
Enter 1 for push
Enter 2 for pop
Enter 3 for displaying stack
Enter 4 for exit
Enter your choice: 1
Enter the element to be inserted: 1


MENU
Enter 1 for push
Enter 2 for pop
Enter 3 for displaying stack
Enter 4 for exit
Enter your choice: 2
Element to be deleted: 1

MENU
Enter 1 for push
Enter 2 for pop
Enter 3 for displaying stack
Enter 4 for exit
Enter your choice: 3

STACK:
2345

MENU
Enter 1 for push
Enter 2 for pop
Enter 3 for displaying stack
Enter 4 for exit
Enter your choice: 4

EXIT

*/