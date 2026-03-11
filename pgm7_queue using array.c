//QUEUE USING ARRAY
#include<stdio.h>
#define SIZE 5
int a[SIZE];
int front=-1;
int rear=-1;
void enqueue();
void dequeue();
void traverse();
void main()
{
int ch;
do
{
printf("\n\nMENU\n");
printf("Enter 1 for enqueue\n");
printf("Enter 2 for dequeue\n");
printf("Enter 3 for displaying queue\n");
printf("Enter 4 for exit\n");
printf("Enter your choice: ");
scanf("%d",&ch);
switch(ch)
{
case 1:
{
enqueue();
break;
}
case 2:
{
dequeue();
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

void enqueue()
{
int num;
if(rear==SIZE-1)
printf("Queue is full!!!\n");
else
{
rear++;
printf("Enter the element to be inserted: ");
scanf("%d",&num);
a[rear]=num;
 if(front=-1)
 {
 front=0;
 }
}
}

void dequeue()
{
if(front==-1)
printf("Queue is empty!!!");
else
{
printf("Element to be deleted: %d\n",a[front]);
  if(front==rear)
  {
  front=-1;
  rear=-1;
  }
  else
  front++;
}
}

void traverse()
{
int i;
if(front==-1)
printf("Queue is empty!!!\n");
else
{
printf("\nQUEUE:\n");
for(i=front;i<=rear;i++)
{
printf("%d",a[i]);
}
}
}

/*SAMPLE OUTPUT:

MENU
Enter 1 for enqueue
Enter 2 for dequeue
Enter 3 for displaying queue
Enter 4 for exit
Enter your choice: 1
Enter the element to be inserted: 5


MENU
Enter 1 for enqueue
Enter 2 for dequeue
Enter 3 for displaying queue
Enter 4 for exit
Enter your choice: 1
Enter the element to be inserted: 4


MENU
Enter 1 for enqueue
Enter 2 for dequeue
Enter 3 for displaying queue
Enter 4 for exit
Enter your choice: 1
Enter the element to be inserted: 3


MENU
Enter 1 for enqueue
Enter 2 for dequeue
Enter 3 for displaying queue
Enter 4 for exit
Enter your choice: 1
Enter the element to be inserted: 2


MENU
Enter 1 for enqueue
Enter 2 for dequeue
Enter 3 for displaying queue
Enter 4 for exit
Enter your choice: 1
Enter the element to be inserted: 1


MENU
Enter 1 for enqueue
Enter 2 for dequeue
Enter 3 for displaying queue
Enter 4 for exit
Enter your choice: 2
Element to be deleted: 5


MENU
Enter 1 for enqueue
Enter 2 for dequeue
Enter 3 for displaying queue
Enter 4 for exit
Enter your choice: 3

QUEUE:
4321

MENU
Enter 1 for enqueue
Enter 2 for dequeue
Enter 3 for displaying queue
Enter 4 for exit
Enter your choice: 4

EXIT
*/