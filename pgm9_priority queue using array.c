//PRIORTY QUEUE USING ARRAY
#include <stdio.h>
struct queue
{
int item;
int priority;
} a[100];
int front = -1, rear = -1, n;
void enqueue(int item, int priority);
void dequeue();
void traverse();
void main()
{
int ch, item, priority;
printf("Enter the size of the queue: ");
scanf("%d", &n);
do
{
printf("\nEnter 1 for ENQUEUE\n");
printf("Enter 2 for DEQUEUE\n");
printf("Enter 3 for TRAVERSE\n");
printf("Enter 4 for EXIT\n");
printf("\nENTER YOUR CHOICE: ");
scanf("%d", &ch);
switch (ch)
{
case 1:
{
printf("The element to be enqueued: ");
scanf("%d", &item);
printf("Enter the priority of the element: ");
scanf("%d", &priority);
enqueue(item, priority);
break;
}
case 2:
{ dequeue();
break;
}
case 3:
{  traverse();
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

void enqueue(int item, int priority)
{
int i, loc;
if (front == 0 && rear == n - 1)
{
printf("Queue is full\n");
}
else if (front == -1)
{
front = rear = 0;
a[rear].item = item;
a[rear].priority = priority;
}
else
{
if (rear == n - 1)
{
for (i = front; i <= rear; i++)
{
a[i - front] = a[i];
}
rear = rear - front;
front = 0;
}
for (i = rear; i >= front; i--)
{
if (a[i].priority < priority)
{
break;
}
}
loc = i + 1;
for (i = rear; i >= loc; i--)
{
a[i + 1] = a[i];
}
a[loc].item = item;
a[loc].priority = priority;
rear++;
}
traverse();
}

void dequeue()
{
if (front == -1)
{
printf("Queue is empty\n");
}
else if (front == rear)
{
printf("Deleted item is %d\n", a[front].item);
front = rear = -1;
}
else
{
printf("Deleted item is %d\n", a[front].item);
front++;
}
traverse();
}

void traverse()
{
int i;
printf("PRIORITY QUEUE:\n");
if (front == -1 && rear == -1)
{
printf("Queue is empty\n");
}
else
{
for (i = front; i <= rear; i++)
{
printf("Item: %d, Priority: %d\n", a[i].item, a[i].priority);
}
}
}

/*OUTPUT:
Enter the size of the queue: 3

Enter 1 for ENQUEUE
Enter 2 for DEQUEUE
Enter 3 for TRAVERSE
Enter 4 for EXIT

ENTER YOUR CHOICE: 1
The element to be enqueued: 8
Enter the priority of the element: 2
PRIORITY QUEUE:
Item: 8, Priority: 2

Enter 1 for ENQUEUE
Enter 2 for DEQUEUE
Enter 3 for TRAVERSE
Enter 4 for EXIT

ENTER YOUR CHOICE: 1
The element to be enqueued: 4
Enter the priority of the element: 1
PRIORITY QUEUE:
Item: 4, Priority: 1
Item: 8, Priority: 2

Enter 1 for ENQUEUE
Enter 2 for DEQUEUE
Enter 3 for TRAVERSE
Enter 4 for EXIT

ENTER YOUR CHOICE: 1
The element to be enqueued: 2
Enter the priority of the element: 3
PRIORITY QUEUE:
Item: 4, Priority: 1
Item: 8, Priority: 2
Item: 2, Priority: 3

Enter 1 for ENQUEUE
Enter 2 for DEQUEUE
Enter 3 for TRAVERSE
Enter 4 for EXIT

ENTER YOUR CHOICE: 2
Deleted item is 4
PRIORITY QUEUE:
Item: 8, Priority: 2
Item: 2, Priority: 3

Enter 1 for ENQUEUE
Enter 2 for DEQUEUE
Enter 3 for TRAVERSE
Enter 4 for EXIT

ENTER YOUR CHOICE: 3
PRIORITY QUEUE:
Item: 8, Priority: 2
Item: 2, Priority: 3

Enter 1 for ENQUEUE
Enter 2 for DEQUEUE
Enter 3 for TRAVERSE
Enter 4 for EXIT

ENTER YOUR CHOICE: 4

EXIT
*/