#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int A[100];
int n;
int num;
struct node
{
    float info;
    struct node *link;
};
struct node *start = NULL;
struct node *Insertionsort(struct node *list);
void printbuckets(struct node *list);
void bucketsort(float A[], int n);
void printarray(float A[], int n);
int main()
{
    int choice, i, n;
    float A[20];
    printf("Enter number of element in array:---> ");
    scanf("%d", &n);
    printf("Enter the %d Array elements--->\n", n);
    for (i = 1; i <= n; i++)
    {
        printf("A[%d] = ", i);
        scanf("%f", &A[i]);
    }
    bucketsort(A, n);
    printarray(A, n);
    return 0;
}

void printarray(float A[], int n)
{
    printf("\n****Sorted Array****\n");
    for (int i = 1; i <= n; ++i)
        printf("%.2f  ", A[i]);
}
void printbuckets(struct node *head)
{
    struct node *ptr = head;
    while (ptr != NULL)
    {
        printf("%.2f ", ptr->info);
        ptr = ptr->link;
    }
}
struct node *sort(struct node *node1, struct node *arranged)
{
    if (arranged == NULL || arranged->info >= node1->info)
    {
        node1->link = arranged;
        arranged = node1;
    }
    else
    {
        struct node *ptr = arranged;
        while (ptr->link != NULL && ptr->link->info < node1->info)
        {
            ptr = ptr->link;
        }
        node1->link = ptr->link;
        ptr->link = node1;
    }
    return arranged;
}
struct node *Insertionsort(struct node *head)
{
    struct node *ptr = head;
    struct node *arranged = NULL;
    while (ptr != NULL)
    {
        struct node *next = ptr->link;
        arranged = sort(ptr, arranged);
        ptr = next;
    }
    return arranged;
}
void bucketsort(float A[], int n)
{
    int j;
    struct node *B[n];
    for (int i = 1; i <= n; i++)
    {
        B[i] = NULL;
    }
    for (int i = 1; i <= n; i++)
    {
        j = floor(n * A[i]);
        struct node *ptr3;
        ptr3 = (struct node *)malloc(sizeof(struct node));
        ptr3->info = A[i];
        ptr3->link = B[j];
        B[j] = ptr3;
    }
    for (int i = 1; i <= n; i++)
    {
        B[i] = Insertionsort(B[i]);
    }
    int choice;
    printf("press 1 if you want to print bucket\n");
    scanf("%d",&choice);
    if(choice == 1)
    {
        printf("<-----Bucket Lists---->\n");
    }
    int i = 1;
    while (i <= n)
    {
        for (int j = 1; j <= n; j++)
        {
            if (B[j] == NULL)
            {
                printf("%d : NULL\n",j);
                continue;
            }
            else
            {
                struct node *ptr = B[j];

                if (choice == 1)
                {   
                    printf("%d : ",j);
                    printbuckets(B[j]);
                    printf("\n");
                }
                while (ptr != NULL)
                {
                    A[i] = ptr->info;
                    i++;
                    ptr = ptr->link;
                }
            }
        }
    }
}
