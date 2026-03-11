//BINARY SEARCH TREE USING LIST
#include <stdio.h>
#include <stdlib.h>

struct node
{
int data;
struct node* left;
struct node* right;
};

int ch, item, flag = 0;
struct node *root = NULL, *ptr = NULL, *parent = NULL, *new;

void insert();
void inorder(struct node* ptr);
struct node* insucc(struct node* y);
void delete(int item);

void main()
{
do
{
printf("\n\nBinary Search Tree Operations:\n");
printf("1. Insert\n");
printf("2. Delete\n");
printf("3. Inorder Traversal\n");
printf("4. Exit\n");
printf("Enter your choice: ");
scanf("%d", &ch);

switch (ch)
{
case 1:
{
insert();
break;
}

case 2:
{
printf("\nEnter the item to delete: ");
scanf("%d", &item);
delete(item);
break;
}

case 3:
{
printf("\nInorder Traversal: ");
inorder(root);
break;
}

case 4:
{
printf("\nEXIT.");
break;
}

default:
printf("\nWRONG CHOICE!!!.");
break;
}
}while(ch!=4);
}

void insert()
{
printf("Enter the item to insert: ");
scanf("%d", &item);

if (root == NULL)
{
new = (struct node*)malloc(sizeof(struct node));
new->data = item;
new->left = NULL;
new->right = NULL;
root = new;
}
else
{
ptr = root;
flag = 0;
while (ptr != NULL && flag == 0)
{
if (ptr->data == item)
{
printf("\nItem already exists");
flag = 1;
return;
}
else if (item < ptr->data)
{
parent = ptr;
ptr = ptr->left;
}
else
{
parent = ptr;
ptr = ptr->right;
}}

if (ptr == NULL)
{
new = (struct node*)malloc(sizeof(struct node));
new->data = item;
new->left = NULL;
new->right = NULL;

if (item < parent->data)
parent->left = new;
else
parent->right = new;
}}}

void inorder(struct node* ptr)
{
if (ptr != NULL)
{
inorder(ptr->left);
printf("%d ", ptr->data);
inorder(ptr->right);
}}

struct node* insucc(struct node* y)
{
while (y->left != NULL)
{
y = y->left;
}
return y;
}

void delete(int item)
{
if (root == NULL)
{
printf("\nThe tree is empty.");
}
else
{
ptr = root;
flag = 0;
parent = NULL;
while (ptr != NULL && flag == 0)
{
if (ptr->data == item)
{
flag = 1;
break;
}
else if (item < ptr->data)
{
parent = ptr;
ptr = ptr->left;
}
else
{
parent = ptr;
ptr = ptr->right;
}}

if (flag == 0)
{
printf("\nItem does not exist.");
}
else
{
if (ptr->left == NULL && ptr->right == NULL)
{
if (parent == NULL)
root = NULL;
else if (parent->left == ptr)
parent->left = NULL;
else
parent->right = NULL;
free(ptr);
}
else if (ptr->left != NULL && ptr->right == NULL)
{
if (parent == NULL)
root = ptr->left;
else if (parent->left == ptr)
parent->left = ptr->left;
else
parent->right = ptr->left;
free(ptr);
}
else if (ptr->left == NULL && ptr->right != NULL)
{
if (parent == NULL)
root = ptr->right;
else if (parent->left == ptr)
parent->left = ptr->right;
else
parent->right = ptr->right;
free(ptr);
}
else
{
struct node* temp = insucc(ptr->right);
printf("\nInorder successor: %d", temp->data);
int x = temp->data;
delete(x);
ptr->data = x;
}}}}


/*
OUTPUT:


Binary Search Tree Operations:
1. Insert
2. Delete
3. Inorder Traversal
4. Exit
Enter your choice: 1
Enter the item to insert: 10


Binary Search Tree Operations:
1. Insert
2. Delete
3. Inorder Traversal
4. Exit
Enter your choice: 1
Enter the item to insert: 5


Binary Search Tree Operations:
1. Insert
2. Delete
3. Inorder Traversal
4. Exit
Enter your choice: 1
Enter the item to insert: 14


Binary Search Tree Operations:
1. Insert
2. Delete
3. Inorder Traversal
4. Exit
Enter your choice: 3

Inorder Traversal: 5 10 14

Binary Search Tree Operations:
1. Insert
2. Delete
3. Inorder Traversal
4. Exit
Enter your choice: 2

Enter the item to delete: 10

Inorder successor: 14

Binary Search Tree Operations:
1. Insert
2. Delete
3. Inorder Traversal
4. Exit
Enter your choice: 4

EXIT.


*/