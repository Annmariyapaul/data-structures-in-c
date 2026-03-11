//SINGLY LINKED LIST
#include<stdio.h>
#include<stdlib.h>
struct Node
{
int data;
struct Node *link;
};
struct Node *head = NULL;

void insert_end();
void insert_front();
void delete_end();
void delete_front();
void insertAfter_SpecifiedNode();
void delete_SpecifiedPosition();
void traverse();

void main()
{
int ch;

do
{
printf("\nLINKED LIST\n");
printf("Enter 1 for Insert at end\n");
printf("Enter 2 for Insert at front\n");
printf("Enter 3 for delete from end\n");
printf("Enter 4 for delete from front\n");
printf("Enter 5 for Insert After Specified Node\n");
printf("Enter 6 for delete at specified position\n");
printf("Enter 7 for Traverse\n");
printf("Enter 8 for Exit\n");
printf("Enter your choice: ");

scanf("%d",&ch);
switch(ch)
{
case 1:
{
 insert_end();
 traverse();
break;
}

case 2:
{
 insert_front();
 traverse();
break;
}

case 3:
{
 delete_end();
traverse();
break;
}

case 4:
{
 delete_front();
traverse();
break;
}

case 5:
{
 insertAfter_SpecifiedNode();
traverse();
break;
}

case 6:
{
delete_SpecifiedPosition();
traverse();
break;
}

case 7:
{
traverse();
break;
}

case 8:
{
printf("\nEXIT\n");
break;
}

default:
{
printf("WRONG CHOICE!!!\n");
break;
}
}
}while(ch!=8);
}

void insert_end()
{
int n;
printf("Enter the element to be inserted at end: ");
scanf("%d",&n);

struct Node *newNode=(struct Node *)malloc(sizeof(struct Node));
newNode->data=n;
newNode->link=NULL;

if(head==NULL)
{
head=newNode;
}
else
{
struct Node *ptr=head;
while(ptr->link!=NULL)
{
ptr=ptr->link;
}
ptr->link=newNode;
}
}

void insert_front()
{
struct Node *newNode=(struct Node *)malloc(sizeof(struct Node));
printf("Enter the element to be inserted at front: ");
scanf("%d",&newNode->data);

newNode->link=head;
head=newNode;
}

void delete_end()
{
if(head==NULL)
{
printf("List is empty\n");
}

else if(head->link==NULL)
{
struct Node *temp=head;
head=NULL;
free(temp);
}

else
{
struct Node *prev=head;
struct Node *curr=head->link;

while(curr->link!=NULL)
{
prev =curr;
curr=curr->link;
}

prev->link=NULL;
free(curr);
}
}

void delete_front()
{
if(head==NULL)
{
printf("List is empty\n");
return;
}

struct Node *temp=head;
head=head->link;
free(temp);
printf("Node deleted from the front");
}


void insertAfter_SpecifiedNode()
{
int n;
int key;
printf("Enter the element to be inserted: ");
scanf("%d",&n);
printf("Enter the key after which to insert: ");
scanf("%d",&key);

struct Node *newNode=(struct Node *)malloc(sizeof(struct Node));

if(head==NULL)
{
printf("Insertion is not possible\n");
return;
}

struct Node *ptr=head;
while(ptr->data!=key && ptr->link!=NULL)
{
ptr=ptr->link;
}

if(ptr->data!=key)
{
printf("Insertion is not possible\n");
return;
}

newNode->data=n;
newNode->link=ptr->link;
ptr->link=newNode;
}


void delete_SpecifiedPosition()
{

int key;
printf("Enter the data of node to delete: ");
scanf("%d",&key);

if(head==NULL)
{
printf("List is empty\n");
return;
}

if(head->data==key)
{
struct Node *temp=head;
head=head->link;
free(temp);
printf("Node with data %d deleted from the list.\n",key);
return;
}


struct Node *prev=head;
struct Node *curr=head;

while(curr!=NULL && curr->data!=key)
{
prev=curr;
curr=curr->link;
}
if(curr ==NULL && curr->data!=key)
{
printf("Search key not found.\n");
return;
}
prev->link=curr->link;
free(curr);
printf("Node with data %d deleted from the list.\n",key);
}


void traverse()
{
if(head==NULL)
{
printf("LIST IS EMPTY");
return;
}

struct Node *ptr=head;
printf("\nLINKED LIST ELEMENTS:\n");
while(ptr!=NULL)
{
printf("%d-> ",ptr->data);
ptr=ptr->link;
}
printf("NULL\n");
}


/*OUTPUT:
LINKED LIST
Enter 1 for Insert at end
Enter 2 for Insert at front
Enter 3 for delete from end
Enter 4 for delete from front
Enter 5 for Insert After Specified Node
Enter 6 for delete at specified position
Enter 7 for Traverse
Enter 8 for Exit
Enter your choice: 1
Enter the element to be inserted at end: 1

LINKED LIST ELEMENTS:
1-> NULL

LINKED LIST
Enter 1 for Insert at end
Enter 2 for Insert at front
Enter 3 for delete from end
Enter 4 for delete from front
Enter 5 for Insert After Specified Node
Enter 6 for delete at specified position
Enter 7 for Traverse
Enter 8 for Exit
Enter your choice: 1
Enter the element to be inserted at end: 2

LINKED LIST ELEMENTS:
1-> 2-> NULL

LINKED LIST
Enter 1 for Insert at end
Enter 2 for Insert at front
Enter 3 for delete from end
Enter 4 for delete from front
Enter 5 for Insert After Specified Node
Enter 6 for delete at specified position
Enter 7 for Traverse
Enter 8 for Exit
Enter your choice: 2
Enter the element to be inserted at front: 8

LINKED LIST ELEMENTS:
8-> 1-> 2-> NULL

LINKED LIST
Enter 1 for Insert at end
Enter 2 for Insert at front
Enter 3 for delete from end
Enter 4 for delete from front
Enter 5 for Insert After Specified Node
Enter 6 for delete at specified position
Enter 7 for Traverse
Enter 8 for Exit
Enter your choice: 2
Enter the element to be inserted at front: 6

LINKED LIST ELEMENTS:
6-> 8-> 1-> 2-> NULL

LINKED LIST
Enter 1 for Insert at end
Enter 2 for Insert at front
Enter 3 for delete from end
Enter 4 for delete from front
Enter 5 for Insert After Specified Node
Enter 6 for delete at specified position
Enter 7 for Traverse
Enter 8 for Exit
Enter your choice: 3

LINKED LIST ELEMENTS:
6-> 8-> 1-> NULL

LINKED LIST
Enter 1 for Insert at end
Enter 2 for Insert at front
Enter 3 for delete from end
Enter 4 for delete from front
Enter 5 for Insert After Specified Node
Enter 6 for delete at specified position
Enter 7 for Traverse
Enter 8 for Exit
Enter your choice: 4
Node deleted from the front
LINKED LIST ELEMENTS:
8-> 1-> NULL

LINKED LIST
Enter 1 for Insert at end
Enter 2 for Insert at front
Enter 3 for delete from end
Enter 4 for delete from front
Enter 5 for Insert After Specified Node
Enter 6 for delete at specified position
Enter 7 for Traverse
Enter 8 for Exit
Enter your choice: 5
Enter the element to be inserted: 6
Enter the key after which to insert: 8

LINKED LIST ELEMENTS:
8-> 6-> 1-> NULL

LINKED LIST
Enter 1 for Insert at end
Enter 2 for Insert at front
Enter 3 for delete from end
Enter 4 for delete from front
Enter 5 for Insert After Specified Node
Enter 6 for delete at specified position
Enter 7 for Traverse
Enter 8 for Exit
Enter your choice: 4
Node deleted from the front
LINKED LIST ELEMENTS:
6-> 1-> NULL

LINKED LIST
Enter 1 for Insert at end
Enter 2 for Insert at front
Enter 3 for delete from end
Enter 4 for delete from front
Enter 5 for Insert After Specified Node
Enter 6 for delete at specified position
Enter 7 for Traverse
Enter 8 for Exit
Enter your choice: 5
Enter the element to be inserted: 4
Enter the key after which to insert: 1

LINKED LIST ELEMENTS:
6-> 1-> 4-> NULL

LINKED LIST
Enter 1 for Insert at end
Enter 2 for Insert at front
Enter 3 for delete from end
Enter 4 for delete from front
Enter 5 for Insert After Specified Node
Enter 6 for delete at specified position
Enter 7 for Traverse
Enter 8 for Exit
Enter your choice: 6
Enter the data of node to delete: 1
Node with data 1 deleted from the list.

LINKED LIST ELEMENTS:
6-> 4-> NULL

LINKED LIST
Enter 1 for Insert at end
Enter 2 for Insert at front
Enter 3 for delete from end
Enter 4 for delete from front
Enter 5 for Insert After Specified Node
Enter 6 for delete at specified position
Enter 7 for Traverse
Enter 8 for Exit
Enter your choice: 7

LINKED LIST ELEMENTS:
6-> 4-> NULL

LINKED LIST
Enter 1 for Insert at end
Enter 2 for Insert at front
Enter 3 for delete from end
Enter 4 for delete from front
Enter 5 for Insert After Specified Node
Enter 6 for delete at specified position
Enter 7 for Traverse
Enter 8 for Exit
Enter your choice: 8

EXIT
*/