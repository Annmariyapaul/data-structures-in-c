//HASHING
#include <stdio.h>
#include <stdlib.h>

int ht[100], m;

int hash(int key)
{
    return key % m;
}

void insert(int key)
{
    int index = hash(key);
    int start_index = index;

    while (ht[index] != -1)
    {
        index = (index + 1) % m;

        if (index == start_index)
        {
            printf("Error: Hash table is full\n");
            return;
        }
    }
    ht[index] = key;
}

void display()
{
    printf("Hash Table:\n");
    for (int i = 0; i < m; i++)
    {
        if (ht[i] != -1)
        {
            printf("Index %d: %d\n", i, ht[i]);
        }
        else
        {
            printf("Index %d: Empty\n", i);
        }
    }
}

int main()
{
    int choice, key;

    printf("Enter size of hash table: ");
    scanf("%d", &m);

    if (m <= 0 || m > 100)
    {
        printf("Error: Invalid hash table size. Size must be between 1 and 100.\n");
        return 1;
    }

    // Initialize hash table with -1 (indicating empty slots)
    for (int i = 0; i < m; i++)
    {
        ht[i] = -1;
    }

    do
    {
        printf("\nMenu:\n");
        printf("1. Insert an element\n");
        printf("2. Display the hash table\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter an element to insert: ");
                scanf("%d", &key);
                insert(key);
                break;
            case 2:
                display();
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}

/*
OUTPUT:
Enter size of hash table: 5

Menu:
1. Insert an element
2. Display the hash table
3. Exit
Enter your choice: 1
Enter an element to insert: 5

Menu:
1. Insert an element
2. Display the hash table
3. Exit
Enter your choice: 1
Enter an element to insert: 1

Menu:
1. Insert an element
2. Display the hash table
3. Exit
Enter your choice: 2
Hash Table:
Index 0: 5
Index 1: 1
Index 2: Empty
Index 3: Empty
Index 4: Empty

Menu:
1. Insert an element
2. Display the hash table
3. Exit
Enter your choice: 1
Enter an element to insert: 6

Menu:
1. Insert an element
2. Display the hash table
3. Exit
Enter your choice: 1
Enter an element to insert: 8

Menu:
1. Insert an element
2. Display the hash table
3. Exit
Enter your choice: 1
Enter an element to insert: 2

Menu:
1. Insert an element
2. Display the hash table
3. Exit
Enter your choice: 1
Enter an element to insert: 3
ERROR!
Error: Hash table is full

Menu:
1. Insert an element
2. Display the hash table
3. Exit
Enter your choice: 1
Enter an element to insert: 9ERROR!

Error: Hash table is full

Menu:
1. Insert an element
2. Display the hash table
3. Exit
Enter your choice: 2
Hash Table:
Index 0: 5
Index 1: 1
Index 2: 6
Index 3: 8
Index 4: 2

Menu:
1. Insert an element
2. Display the hash table
3. Exit
Enter your choice: 3
Exiting...


*/