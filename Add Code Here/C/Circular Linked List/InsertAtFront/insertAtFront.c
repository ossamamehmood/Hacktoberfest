#include <stdio.h>
#include <stdlib.h>

// create node
struct cNode
{
    int data;
    struct cNode *next;
} * head, *temp, *first, *second, *third, *fourth, *newNode;

// display node
void traversalNode()
{
    struct cNode *ptr;
    ptr = head;
    if (head == NULL)
    {
        printf("List is empty !");
    }
    else
    {
        printf("\n Elements are:");

        do
        {
            printf(" %d", ptr->data);
            ptr = ptr->next;
        } while (ptr != head);
    }
}

// insert at front program
void insertAtFront(int value)
{
    newNode = (struct cNode *)malloc(sizeof(struct cNode));

    if (head == NULL)
    {
        newNode->data = value;
        newNode->next = newNode;
        head = newNode;
    }
    else
    {
        // temp = head;
        newNode->data = value;

        // while (temp->next != head)
        // {
        //     temp = temp->next;
        // }
        newNode->next = head->next;
        // head = newNode;
        head->next = newNode;
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
    // head = first;

    first->data = 12;
    first->next = second;

    second->data = 28;
    second->next = third;

    third->data = 78;
    third->next = fourth;

    fourth->data = 80;
    fourth->next = first;

    traversalNode();
    insertAtFront(33);
    insertAtFront(46);
    insertAtFront(99);
    insertAtFront(26);

    traversalNode();
}