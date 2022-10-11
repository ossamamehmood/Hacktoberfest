#include <stdio.h>
#include <stdlib.h>

// create node
struct cNode
{
    int data;
    struct cNode *next;
} * head, *temp, *newNode, *first, *second, *third, *fourth;

// display elements
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
            printf("\n %d \n", ptr->data);
            ptr = ptr->next;
        } while (ptr != head);
    }
}

// delete at front
void deletionAtFront()
{
    temp = (struct cNode *)malloc(sizeof(struct cNode));
    temp = head;
    if (head == NULL)
    {

        printf(" \n List is Empty !");
    }
    else if (temp->next == head)
    {
        head = NULL;
    }
    else
    {
        do
        {
            temp = temp->next;
        } while (temp->next != head);
        head = head->next;
        temp->next = head;
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
    deletionAtFront();
    deletionAtFront();
    deletionAtFront();
    traversal();
}