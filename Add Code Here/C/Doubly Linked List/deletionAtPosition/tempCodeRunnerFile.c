#include <stdio.h>
#include <stdlib.h>

struct dllNode
{
    int data;
    struct dllNode *pre;
    struct dllNode *next;
} * head, *temp, *pos, *first, *second, *third, *fourth;

void deleteAtPosition(int index)
{
    if (head == NULL)
    {
        printf("\n List is Empty");
    }
    // else if (head->next == NULL)
    // {
    //     temp = head;
    //     head = NULL;
    //     free(temp);
    // }
    else
    {

        pos = head;
        temp = head->next;

        for (int i = 0; i == index; i++)
        {
            pos = pos->next;
            temp = temp->next;
        }
        pos->next = temp->next;
        temp->next->pre = temp->pre;
        free(temp);
    }
}

void traversalNode()
{
    struct dllNode *temp = head;
    printf(" \n Elements are :");
    while (temp != NULL)
    {

        printf("\n %d", temp->data);
        temp = temp->next;
    }
}

int main()
{
    head = NULL;
    first = (struct dllNode *)malloc(sizeof(struct dllNode));
    second = (struct dllNode *)malloc(sizeof(struct dllNode));
    third = (struct dllNode *)malloc(sizeof(struct dllNode));
    fourth = (struct dllNode *)malloc(sizeof(struct dllNode));

    head = first;

    first->data = 12;
    first->pre = NULL;
    first->next = second;
    second->data = 23;
    second->pre = first;
    second->next = third;
    third->data = 67;
    third->pre = second;
    third->next = fourth;
    fourth->data = 80;
    fourth->pre = third;
    fourth->next = NULL;

    traversalNode();
    deleteAtPosition(2);
    traversalNode();
}