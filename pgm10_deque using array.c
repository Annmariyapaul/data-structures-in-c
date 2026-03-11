//DEQUE USING ARRAY
#include <stdio.h>
int a[100], n, front = -1, rear = -1;
void insertFront(int item);
void deleteFront();
void insertRear(int item);
void deleteRear();
void traverse();
void main()
{
int ch,ele;
printf("Enter the size of the queue: ");
scanf("%d", &n);
do
{
printf("\nEnter 1 for INSERT FRONT\n");
printf("Enter 2 for DELETE FRONT\n");
printf("Enter 3 for INSERT REAR\n");
printf("Enter 4 for DELETE REAR\n");
printf("Enter 5 for TRAVERSE\n");
printf("Enter 6 for EXIT\n");
printf("ENTER YOUR CHOICE: ");
scanf("%d", &ch);
switch (ch)
{
case 1:
{ printf("The element to be enqueued at front: ");
scanf("%d",&ele);
insertFront(ele);
break;
}
case 2:
{
deleteFront();
break;
}
case 3:
{
printf("The element to be enqueued at rear: ");
scanf("%d", &ele);
insertRear(ele);
break;
}
case 4:
deleteRear();
break;
case 5:
{
traverse();
break;
}
case 6:
{
printf("\nEXIT\n");
break;
}
default:
{
printf("\nINVALID CHOICE\n");
break;
}
}
}while(ch!=6);
}
void insertFront(int item)
{
int i;
if (front == 0 && rear == n - 1)
{
printf("Queue is Full\n");
}
else
{
if (front == -1 && rear==-1)
{
front = 0;
rear = 0;
a[front] = item;
}
else if (front == 0 && rear<n-1)
{
for(i=rear;i>=front;i--)
{
a[i+1]=a[i];
}
rear++;
a[front] = item;
}
else
{
front--;
a[front] = item;
}
traverse();
}
}
void deleteFront()
{
if (front == -1 && rear==-1)
{
printf("Queue is empty\n");
}
else
{
printf("Dequeued item from front is %d\n", a[front]);
if (front == rear)
{
front = -1;
rear = -1;
}
else
{
front++;
}
traverse();
}
}
void insertRear(int item)
{
int i;
if (rear == n - 1 && front == 0)
{
printf("Queue is Full\n");
}
else
{
if (rear == -1)
{
front = 0;
rear = 0;
a[rear] = item;
}
else if (rear < n - 1)
{
rear++;
a[rear] = item;
}
else
{
for(i=0;i<n-1;i++)
{
a[i]=a[i+1];
}
a[rear] = item;
front--;
}
traverse();
}
}
void deleteRear()
{
if (front == -1 && rear==-1)
{
printf("Queue is empty\n");
}
else
{
printf("Dequeued item from rear is %d\n", a[rear]);
if (front == rear)
{
front = -1;
rear = -1;
}
else
{
rear--;
}
traverse();
}
}
void traverse()
{
if (front == -1)
{
printf("Queue is empty\n");
}
else
{
int i;
for(i=front;i<=rear;i++)
{
printf("%d\t", a[i]);
}
}
}

/*OUTPUT:
Enter the size of the queue: 3

Enter 1 for INSERT FRONT
Enter 2 for DELETE FRONT
Enter 3 for INSERT REAR
Enter 4 for DELETE REAR
Enter 5 for TRAVERSE
Enter 6 for EXIT
ENTER YOUR CHOICE: 1
The element to be enqueued at front: 5
5
Enter 1 for INSERT FRONT
Enter 2 for DELETE FRONT
Enter 3 for INSERT REAR
Enter 4 for DELETE REAR
Enter 5 for TRAVERSE
Enter 6 for EXIT
ENTER YOUR CHOICE: 1
The element to be enqueued at front: 2
2	5
Enter 1 for INSERT FRONT
Enter 2 for DELETE FRONT
Enter 3 for INSERT REAR
Enter 4 for DELETE REAR
Enter 5 for TRAVERSE
Enter 6 for EXIT
ENTER YOUR CHOICE: 3
The element to be enqueued at rear: 8
2	5	8
Enter 1 for INSERT FRONT
Enter 2 for DELETE FRONT
Enter 3 for INSERT REAR
Enter 4 for DELETE REAR
Enter 5 for TRAVERSE
Enter 6 for EXIT
ENTER YOUR CHOICE: 2
Dequeued item from front is 2
5	8
Enter 1 for INSERT FRONT
Enter 2 for DELETE FRONT
Enter 3 for INSERT REAR
Enter 4 for DELETE REAR
Enter 5 for TRAVERSE
Enter 6 for EXIT
ENTER YOUR CHOICE: 4
Dequeued item from rear is 8
5
Enter 1 for INSERT FRONT
Enter 2 for DELETE FRONT
Enter 3 for INSERT REAR
Enter 4 for DELETE REAR
Enter 5 for TRAVERSE
Enter 6 for EXIT
ENTER YOUR CHOICE: 5
5
Enter 1 for INSERT FRONT
Enter 2 for DELETE FRONT
Enter 3 for INSERT REAR
Enter 4 for DELETE REAR
Enter 5 for TRAVERSE
Enter 6 for EXIT
ENTER YOUR CHOICE: 6

EXIT
*/