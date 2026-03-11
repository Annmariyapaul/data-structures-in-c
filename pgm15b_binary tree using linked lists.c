//BINARY TREE USING LINKED LISTTS
#include<stdio.h>
#include<stdlib.h>

struct node
{
int data;
struct node *left;
struct node *right;
};
struct node *root=NULL, *new_node=NULL, *loc=NULL, *ploc=NULL;
int ch, key, item;

void build(struct node *ptr);
void inorder(struct node *ptr);
void preorder(struct node *ptr);
void postorder(struct node *ptr);
void search(struct node *par, struct node *ptr);
void insert(struct node *ptr);
void delete_node();

void main()
{
int choice;
do
{
printf("\n\nBINARY TREE USING LINKED LISTS:\n");
printf("1.Build tree\n");
printf("2.Inorder\n");
printf("3.Preorder\n");
printf("4.Postorder\n");
printf("5.Search\n");
printf("6.Insertion\n");
printf("7.Delete node\n");
printf("8.Exit.\n");
printf("Enter your choice: ");
scanf("%d", &choice);

switch(choice)
{
case 1:
{
if (root == NULL)
{
root = (struct node *)malloc(sizeof(struct node));
root->left = NULL;
root->right = NULL;
build(root);
}
else
printf("Tree already built.\n");
break;
}

case 2:
{
printf("\nINORDER TRAVERSAL\n");
inorder(root);
break;
}

case 3:
{
printf("\nPREORDER TRAVERSAL\n");
preorder(root);
break;
}

case 4:
{
printf("\nPOSTORDER TRAVERSAL\n");
postorder(root);
break;
}

case 5:
{
printf("\nEnter the key to search: \n");
scanf("%d", &key);

loc = NULL;
ploc = NULL;
search(NULL, root);

if(loc == NULL)
printf("\nKey not found\n");
else
printf("\nKey found\n");

break;
}

case 6:
{
if(root != NULL)
{
printf("Enter the key of the node to insert: ");
scanf("%d", &key);

loc = NULL;
ploc = NULL;
search(NULL, root);
if(loc != NULL)
insert(loc);
else
printf("Node not found for insertion.\n");
}
else
printf("Tree is not built yet\n");

break;
}

case 7:
{
delete_node();
break;
}

case 8:
{
printf("\nEXIT.\n");
break;
}

default:
{
printf("\nWRONG CHOICE!!!\n");
break;
}}
} while(choice != 8);
}

void build(struct node *ptr)
{
printf("Enter the item: ");
scanf("%d", &ptr->data);

printf("Do you want to create left child for %d? If yes, enter 0: ", ptr->data);
scanf("%d", &ch);
if(ch == 0)
{
new_node = (struct node *)malloc(sizeof(struct node));
ptr->left = new_node;
new_node->left = new_node->right = NULL;
build(new_node);
}

printf("Do you want to create right child for %d? If yes, enter 0: ", ptr->data);
scanf("%d", &ch);
if(ch == 0)
{
new_node = (struct node *)malloc(sizeof(struct node));
ptr->right = new_node;
new_node->left = new_node->right = NULL;
build(new_node);
}}

void inorder(struct node *ptr)
{
if(ptr != NULL)
{
inorder(ptr->left);
printf("%d ", ptr->data);
inorder(ptr->right);
}}

void preorder(struct node *ptr)
{
if(ptr != NULL)
{
printf("%d ", ptr->data);
preorder(ptr->left);
preorder(ptr->right);
}}

void postorder(struct node *ptr)
{
if(ptr != NULL)
{
postorder(ptr->left);
postorder(ptr->right);
printf("%d ", ptr->data);
}}

void search(struct node *par, struct node *ptr)
{
if(ptr != NULL)
{
if(ptr->data == key)
{
ploc = par;
loc = ptr;
}
else
{
search(ptr, ptr->left);
search(ptr, ptr->right);
}}}

void insert(struct node *ptr)
{
printf("\nEnter the item: ");
scanf("%d", &item);

printf("\nDo you want to insert %d as left child of %d? If yes, enter 0: ", item, ptr->data);
scanf("%d", &ch);

if(ch == 0)
{
if(ptr->left == NULL)
{
new_node = (struct node *)malloc(sizeof(struct node));
ptr->left = new_node;
new_node->data = item;
new_node->left = new_node->right = NULL;
}
else
{
printf("\nLEFT CHILD EXISTS.\n");
}}
else
{
printf("Do you want to insert %d as right child of %d? If yes, enter 0: ", item, ptr->data);
scanf("%d", &ch);

if(ch == 0)
{
if(ptr->right == NULL)
{
new_node = (struct node *)malloc(sizeof(struct node));
ptr->right = new_node;
new_node->data = item;
new_node->left = new_node->right = NULL;
}}
else
{
printf("\nRIGHT CHILD EXISTS.\n");
}}}

void delete_node()
{
printf("\nEnter the key to delete: ");
scanf("%d", &key);
search(NULL, root);

if(loc == NULL)
{
printf("Key not found\n");
}
else
{
if(loc->left == NULL && loc->right == NULL)
{
if(ploc->left == loc)
{
ploc->left = NULL;
}
else
{
ploc->right = NULL;
}
free(loc);
}
else
{
printf("\nCannot delete a non-leaf node\n");
}}}




/*
OUTPUT:



BINARY TREE USING LINKED LISTS:
1.Build tree
2.Inorder
3.Preorder
4.Postorder
5.Search
6.Insertion
7.Delete node
8.Exit.
Enter your choice: 1
Enter the item: 1
Do you want to create left child for 1? If yes, enter 0: 0
Enter the item: 2
Do you want to create left child for 2? If yes, enter 0: 1
Do you want to create right child for 2? If yes, enter 0: 1
Do you want to create right child for 1? If yes, enter 0: 0
Enter the item: 3
Do you want to create left child for 3? If yes, enter 0: 1
Do you want to create right child for 3? If yes, enter 0: 1


BINARY TREE USING LINKED LISTS:
1.Build tree
2.Inorder
3.Preorder
4.Postorder
5.Search
6.Insertion
7.Delete node
8.Exit.
Enter your choice: 2

INORDER TRAVERSAL
2 1 3

BINARY TREE USING LINKED LISTS:
1.Build tree
2.Inorder
3.Preorder
4.Postorder
5.Search
6.Insertion
7.Delete node
8.Exit.
Enter your choice: 3

PREORDER TRAVERSAL
1 2 3

BINARY TREE USING LINKED LISTS:
1.Build tree
2.Inorder
3.Preorder
4.Postorder
5.Search
6.Insertion
7.Delete node
8.Exit.
Enter your choice: 4

POSTORDER TRAVERSAL
2 3 1

BINARY TREE USING LINKED LISTS:
1.Build tree
2.Inorder
3.Preorder
4.Postorder
5.Search
6.Insertion
7.Delete node
8.Exit.
Enter your choice: 5

Enter the key to search:
3

Key found


BINARY TREE USING LINKED LISTS:
1.Build tree
2.Inorder
3.Preorder
4.Postorder
5.Search
6.Insertion
7.Delete node
8.Exit.
Enter your choice: 6
Enter the key of the node to insert: 3

Enter the item: 4

Do you want to insert 4 as left child of 3? If yes, enter 0: 0


BINARY TREE USING LINKED LISTS:
1.Build tree
2.Inorder
3.Preorder
4.Postorder
5.Search
6.Insertion
7.Delete node
8.Exit.
Enter your choice: 2

INORDER TRAVERSAL
2 1 4 3

BINARY TREE USING LINKED LISTS:
1.Build tree
2.Inorder
3.Preorder
4.Postorder
5.Search
6.Insertion
7.Delete node
8.Exit.
Enter your choice: 7

Enter the key to delete: 4


BINARY TREE USING LINKED LISTS:
1.Build tree
2.Inorder
3.Preorder
4.Postorder
5.Search
6.Insertion
7.Delete node
8.Exit.
Enter your choice: 2

INORDER TRAVERSAL
2 1 3

BINARY TREE USING LINKED LISTS:
1.Build tree
2.Inorder
3.Preorder
4.Postorder
5.Search
6.Insertion
7.Delete node
8.Exit.
Enter your choice: 8

EXIT.



*/