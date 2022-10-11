#include <stdio.h>
#include <stdlib.h>

// create node
struct cNode
{
    int data;
    struct cNode *next;
} * head, *temp, *pre, *newNode, *first, *second, *third, *fourth;

// display elements
void traversal()
{
    struct cNode *ptr;
    ptr = head;
    if (head == NULL)
    {
        printf("\n List is empty  !");
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

// delete at front
void deletionAtEnd()
{
    temp = (struct cNode *)malloc(sizeof(struct cNode));
    pre = head;
    temp = head->next;
    if (head == NULL)
    {
        printf("\n List is Empty !");
    }
    else if (temp == head)
    {
        head = NULL;
    }
    else
    {
        while (temp->next != head)
        {
            pre = pre->next;
            temp = temp->next;
        }
        pre->next = head;
        temp->next = NULL;
        free(temp);
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

    first->data = 14;
    first->next = second;
    second->data = 48;
    second->next = third;
    third->data = 80;
    third->next = fourth;
    fourth->data = 37;
    fourth->next = first;

    traversal();
    deletionAtEnd();
    deletionAtEnd();
    deletionAtEnd();
    deletionAtEnd();
    traversal();
}