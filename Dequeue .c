

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 10

int deque[max];
static int item, option;
int left = -1;
int right = -1;
void inputdeque(void);
void outputdeque(void);
void insertright();
void insertleft();
void deleteright();
void deleteleft();
void displaydeque();
int main()
{
    int x;
    do
    {
        printf("\n--------MENU--------\n");
        printf("1.For Input Restricted Dequeue:\n");
        printf("2.For Output Restricted Dequeue:\n");
        printf("Enter Your Choice:\n");
        scanf("%d", &x);
        switch (x)
        {
        case 1:
            left = right = -1;
            inputdeque();
            break;
        case 2:
            left = right = -1;
            outputdeque();
            break;
        }
    } while (x <= 2);
}
void inputdeque()
{
    do
    {
        printf("** Input Restricted Dequeue **\n");
        printf("1.To Insert At Right\n");
        printf("2.To Delete From Left\n");
        printf("3.To Delete From Right\n");
        printf("4.To Dispaly Input restricted\n");
        printf("5.To Quit\n");
        printf("Enter Your Choice\n");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            insertright();
            break;
        case 2:
            deleteleft();
            break;
        case 3:
            deleteright();
            break;
        case 4:
            displaydeque();
            break;
        }
    } while (option <= 4);
}

void outputdeque()
{
    do
    {
        printf("** Output Restricted Dequeue Operation**\n");
        printf("1.To Insert At Right\n");
        printf("2.To Insert At Left\n");
        printf("3.To Delete From Left\n");
        printf("4.To Display\n");
        printf("5.To Quit\n");
        printf("Enter Your Choice\n");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            insertright();
            break;
        case 2:
            insertleft();
            break;
        case 3:
            deleteleft();
            break;
        case 4:
            displaydeque();
            break;
        }
    } while (option <= 4);
}
void insertright()
{
    printf("Enter item you want to insert\n");
    scanf("%d", &item);
    if (left == right + 1)
    {
        printf("Overflow\n");
        exit(0);
    }
    if (left == -1 && right == -1)
    {
        left = 0;
        right = 0;
    }
    else
    {
        if (right == max - 1)
        {
            right = 0;
        }
        else
        {
            right = right + 1;
        }
    }
    deque[right] = item;
    printf("\n**Item inserted at right successfully**\n");
}

void insertleft()
{
    printf("Enter item you want to insert\n");
    scanf("%d", &item);
    if ((left == right + 1) || (left == 0 && right == max-1))
    {
        printf("Overflow\n");
        exit(0);
    }
    if (left == -1 && right == -1)
    {
        left = 0;
        right = 0;
    }
    else
    {
        if (left == 0)
        {
            left = max - 1;
        }
        else
        {
            left = left - 1;
        }
    }
    deque[left] = item;
    printf("\n**Item inserted at left successfully**\n");
}

void deleteright()
{
    if (left == -1 && right == -1)
    {
        printf("underflow\n");
        exit(0);
    }
    item = deque[right];
    if (left == right)
    {
        left = -1;
        right = -1;
    }
    else
    {
        if (right == 0)
        {
            right = max - 1;
        }
        else
        {
            right = right - 1;
        }
    }
    printf("\n**Item deleted successfully**\n");
}
void deleteleft()
{
    if (left == -1 && right == -1)
    {
        printf("underflow\n");
        exit(0);
    }
    item = deque[left];
    if (left == right)
    {
        left = -1;
        right = -1;
    }
    else
    {
        if (left == max - 1)
        {
            left = 0;
        }
        else
        {
            left = left + 1;
        }
    }
    printf("\n**Item deleted successfully**\n");
}
void displaydeque()
{
    int i;
    if (left == -1 && right == -1)
    {
        printf("underflown\n");
        exit(0);
    }
    printf("Elements in the queue are:\n");
    i = left;
    if (left <= right)
    {
        while (i <= right)
        {
            printf("Item = %d\n", deque[i]);
            i++;
        }
    }
    else
    {
        while (i <= max - 1)
        {
            printf("%d\n", deque[i]);
            i++;
        }
        i = 0;
        while (i <= right)
        {
            printf("%d\n", deque[i]);
            i++;
        }
        printf("\n");
    }
}
