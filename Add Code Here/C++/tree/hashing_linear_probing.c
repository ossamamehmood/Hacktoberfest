/* This code is contributed by Ayush Raj (https://github.com/Ayush0751)
This code  deals with different operations in hashing using the method called linear probing, which includes
1. Insertion 
2. Deletion
3. Searching
4. Displaying
Note: Here the max no of element to be inserted is taken as 10. It can be changed by increasing size to the desired integer.
*/

#include <stdio.h>
#include <stdlib.h>
int size = 10;

void insert(int arr[])
{
    int num, i, count = 0;
    printf("enter the data to insert\n");
    scanf("%d", &num);
    i = num % size;
    while (arr[i] != -1)
    {
        i = ((i + 1) % 10);
    }
    if (arr[i == -1])
    {
        arr[i] = num;
    }
    else
    {
        printf("hash table is full\n");
    }
}

void search(int arr[])
{
    int num, i, count = 0;
    printf("enter the number to search\n");
    scanf("%d", &num);
    i = num % size;

    while (arr[i] != num)
    {
        if (count > 10)
        {
            break;
        }
        i = ((i + 1) % 10);
        count++;
    }
    if (arr[i] == num)
    {
        printf("%d found at index %d\n", num, i);
    }
    else
    {
        printf("%d not found\n", num);
    }
}

void delete (int arr[])
{
    int num, i, count = 0;
    printf("enter the number to delete\n");
    scanf("%d", &num);
    i = num % size;

    while (arr[i] != num)
    {
        if (count > 10)
        {
            break;
        }
        i = ((i + 1) % 10);
        count++;
    }
    if (arr[i] == num)
    {
        arr[i] = -1;
        printf("%d deleted at index %d\n", num, i);
    }
    else
    {
        printf("%d not found\n", num);
    }
}

void display(int arr[])
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] != -1)
            printf("%d is present at index %d\n", arr[i], i);
    }
}

void initialize(int arr[])
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = -1;
    }
}

int main()
{
    int arr[10];
    int i, j, choice;
    initialize(arr);
    while (1)
    {
        printf("1. Insert\n2. Search\n3. Delete\n4. Display\n5. Exit\n");
        printf("enter your choice\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insert(arr);
            break;
        case 2:
            search(arr);
            break;
        case 3:
            delete (arr);
            break;
        case 4:
            display(arr);
            break;
        case 5:
            printf("Exitting...\n");
            exit(0);

        default:
            printf("Wrong choice entered\n");
            printf("Enter from the available choices only\n\n");
            break;
        }
    }
}