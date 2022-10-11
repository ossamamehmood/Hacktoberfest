#include <stdio.h>
#include <stdlib.h>

// create node
struct cNode
{
    int data;
    struct cNode *next;
} * head, *temp, *first, *second, *third;

// insert at position
void insertAtPosition(int value, int index)
{
    if (head == NULL)
    {
        printf("\n List is Empty !");
    }
    else
    {
        struct cNode *newNode;
        newNode = (struct cNode *)malloc(sizeof(struct cNode));
        newNode->data = value;
        temp = head;

        for (int k = 0; k < index - 1; k++)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

// Traversal function
void traversalNode()
{
    if (head == NULL)
    {
        printf("\n List is empty !");
    }
    else
    {
        struct cNode *cur = head;
        printf("\n Elements are :");
        do
        {
            printf(" %d", cur->data);
            cur = cur->next;
        } while (cur != head);
    }
}

// driver program
int main()
{
    head = NULL;
    first = (struct cNode *)malloc(sizeof(struct cNode));
    second = (struct cNode *)malloc(sizeof(struct cNode));
    third = (struct cNode *)malloc(sizeof(struct cNode));

    head = first;
    first->data = 39;
    first->next = second;
    second->data = 47;
    second->next = third;
    third->data = 90;
    third->next = first;

    traversalNode();
    insertAtPosition(56, 2);
    insertAtPosition(100, 1);
    traversalNode();
}