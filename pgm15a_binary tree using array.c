//BINARY TREE USING ARRAY
#include <stdio.h>
#include <stdlib.h>

int a[16], i, item, key, ch, loc = 0;

void build(int index);
void display();
void search(int index);
void insert();
void delete_node();

void main()
{
int choice;
for (i = 1; i <= 15; i++)
{
a[i] = -1;
}

do
{
printf("\n\nBINARY TREE USING ARRAY:\n");
printf("1. Build tree\n");
printf("2. Display Tree\n");
printf("3. Search for a node\n");
printf("4. Insert a Node\n");
printf("5. Delete a node\n");
printf("6. Exit.\n");
printf("Enter your choice: ");
scanf("%d", &choice);

switch (choice)
{
case 1:
{
if (a[1] == -1)
build(1);
else
printf("\nTree already exists.");
break;
}
case 2:
{
printf("\nCurrent Tree: ");
display();
break;
}
case 3:
{
printf("\nEnter key to search: ");
scanf("%d", &key);
loc = 0;
search(1);
if (loc == 0)
printf("\nKey not found");
else
printf("\nKey found");
break;
}
case 4:
{
if (a[1] != -1)
{
printf("\nEnter the key of the node where you want to insert (search it first): ");
scanf("%d", &key);

loc = 0;
search(1);
if (loc != 0)
insert();
else
printf("\nNode not found for insertion.");
}
else
printf("\nTree is not built yet.");
break;
}
case 5:
{
delete_node();
display();
break;
}
case 6:
{
printf("\nEXIT.\n");
break;
}
default:
{
printf("\nWRONG CHOICE!!!\n");
break;
}
}
} while (choice != 6);
}

void display()
{
for (i = 1; i <= 15; i++)
{
if (a[i] != -1)
printf("%d ", a[i]);
else
printf("_ ");
}
printf("\n");
}

void build(int index)
{
if (index > 15)
{
printf("Cannot insert more nodes, tree is full.\n");
return;
}

printf("Enter item: ");
scanf("%d", &a[index]);

printf("\nDo you want to insert left child for %d? If yes enter 0: ", a[index]);
scanf("%d", &ch);
if (ch == 0 && 2 * index <= 15)
build(2 * index);

printf("\nDo you want to insert right child for %d? If yes enter 0: ", a[index]);
scanf("%d", &ch);
if (ch == 0 && 2 * index + 1 <= 15)
build(2 * index + 1);
}

void search(int index)
{
if (index <= 15)
{
if (a[index] == key)
loc = index;
else
{
search(2 * index);
search(2 * index + 1);
}
}
}

void insert()
{
printf("\nEnter item to insert: ");
scanf("%d", &item);
printf("\nDo you want to insert %d as left child of %d? If yes enter 0: ", item, key);
scanf("%d", &ch);
if (ch == 0)
{
if (2 * loc <= 15 && a[2 * loc] == -1)
a[2 * loc] = item;
else
printf("\nLeft child exists or invalid position");
}
else
{
printf("\nDo you want to insert %d as right child of %d? If yes enter 0: ", item, key);
scanf("%d", &ch);
if (ch == 0)
{
if (2 * loc + 1 <= 15 && a[2 * loc + 1] == -1)
a[2 * loc + 1] = item;
else
printf("\nRight child exists or invalid position");
}
}
}

void delete_node()
{
printf("\nEnter key to delete: ");
scanf("%d", &key);

search(1);
if (loc == 0)
printf("\nKey not found");
else
{
if (a[2 * loc] == -1 && a[2 * loc + 1] == -1)
{
a[loc] = -1;
printf("\nNode deleted ");
}
else
printf("\nNot a leaf node, deletion denied");
}
}





/*OUTPUT:



BINARY TREE USING ARRAY:
1. Build tree
2. Display Tree
3. Search for a node
4. Insert a Node
5. Delete a node
6. Exit.
Enter your choice: 1
Enter item: 1

Do you want to insert left child for 1? If yes enter 0: 0
Enter item: 2

Do you want to insert left child for 2? If yes enter 0: 1

Do you want to insert right child for 2? If yes enter 0: 1

Do you want to insert right child for 1? If yes enter 0: 0
Enter item: 3

Do you want to insert left child for 3? If yes enter 0: 1

Do you want to insert right child for 3? If yes enter 0: 1


BINARY TREE USING ARRAY:
1. Build tree
2. Display Tree
3. Search for a node
4. Insert a Node
5. Delete a node
6. Exit.
Enter your choice: 2

Current Tree: 1 2 3 _ _ _ _ _ _ _ _ _ _ _ _


BINARY TREE USING ARRAY:
1. Build tree
2. Display Tree
3. Search for a node
4. Insert a Node
5. Delete a node
6. Exit.
Enter your choice: 3

Enter key to search: 2

Key found

BINARY TREE USING ARRAY:
1. Build tree
2. Display Tree
3. Search for a node
4. Insert a Node
5. Delete a node
6. Exit.
Enter your choice: 4

Enter the key of the node where you want to insert (search it first): 2

Enter item to insert: 4

Do you want to insert 4 as left child of 2? If yes enter 0: 0


BINARY TREE USING ARRAY:
1. Build tree
2. Display Tree
3. Search for a node
4. Insert a Node
5. Delete a node
6. Exit.
Enter your choice: 2

Current Tree: 1 2 3 4 _ _ _ _ _ _ _ _ _ _ _


BINARY TREE USING ARRAY:
1. Build tree
2. Display Tree
3. Search for a node
4. Insert a Node
5. Delete a node
6. Exit.
Enter your choice: 5

Enter key to delete: 4

Node deleted 1 2 3 _ _ _ _ _ _ _ _ _ _ _ _


BINARY TREE USING ARRAY:
1. Build tree
2. Display Tree
3. Search for a node
4. Insert a Node
5. Delete a node
6. Exit.
Enter your choice: 2

Current Tree: 1 2 3 _ _ _ _ _ _ _ _ _ _ _ _


BINARY TREE USING ARRAY:
1. Build tree
2. Display Tree
3. Search for a node
4. Insert a Node
5. Delete a node
6. Exit.
Enter your choice: 6

EXIT.



*/