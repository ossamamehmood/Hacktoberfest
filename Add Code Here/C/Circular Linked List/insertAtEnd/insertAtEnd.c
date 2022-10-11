#include <stdio.h>
#include <stdlib.h>

// create node
struct cNode
{
    int data;
    struct cNode *next;
} * head, *temp, *first, *second, *third, *fourth;

// display node
void traversal()
{
    struct cNode *ptr;
    ptr = head;
    if (head == NULL)
    {
        printf("List is empty  !\n");
    }
    else
    {
        printf("\n Elements are :");
        do
        {
            printf(" %d", ptr->data);
            ptr = ptr->next;
        } while (ptr != head);
    }
}

// insert at end function
void insertAtEnd(int value)
{
    if (head == NULL)
    {
        printf("List is Empty ! \n ");
    }
    else
    {
        struct cNode *newNode;
        temp = head;
        newNode = (struct cNode *)malloc(sizeof(struct cNode));
        newNode->data = value;

        while (temp->next != head)
        {
            temp = temp->next;
        }
        newNode->next = head;
        temp->next = newNode;
    }
}

// driver program
int main()
{
    head = NULL;
    first = (struct cNode *)malloc(sizeof(struct cNode));
    second = (struct cNode *)malloc(sizeof(struct cNode));
    third = (struct cNode *)malloc(sizeof(struct cNode));
    fourth = (struct cNode *)malloc(sizeof(struct cNode));

    head = first;
    first->data = 12;
    first->next = second;
    second->data = 48;
    second->next = third;
    third->data = 63;
    third->next = fourth;
    fourth->data = 53;
    fourth->next = first;

    traversal();
    insertAtEnd(88);
    insertAtEnd(90);
    traversal();
}
