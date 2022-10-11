#include <stdio.h>
#include <stdlib.h>

struct dllNode
{
    int data;
    struct dllNode *pre;
    struct dllNode *next;
} * head, *temp, *pos, *del, *first, *second, *third, *fourth;

void deleteAtPosition(int index)
{

    if (head == NULL)
    {
        printf("\n List is Empty");
    }
    else if (index == 0)
    {
        temp = head;
        head = temp->next;
        head->pre = NULL;
        free(temp);
    }
    else
    {
        // ------------------------ Deletion based on value --------------------------
        // temp = head;
        // while (temp->data != index)
        // {
        //     temp = temp->next;
        // }
        // temp->pre->next = temp->next;
        // temp->next->pre = temp->pre;
        // free(temp);

        // ------------------- Deletion based on index ------------------------------
        // pos = head;
        // del = head->next;
        // temp = del->next;
        // for (int k = 0; k < index - 1; k++)
        // {
        //     pos = pos->next;
        //     del = del->next;
        //     temp = temp->next;
        // }
        // pos->next = temp;
        // temp->pre = pos;
        // free(del);

        // -------------------- Optimized code for above code -------------------------------
        pos = head;
        del = head->next;
        for (int k = 0; k < index - 1; k++)
        {
            pos = pos->next;
            del = del->next;
        }
        pos->next = del->next;
        del->next->pre = del->pre;
        free(del);
    }
}

void traversalNode()
{
    struct dllNode *temp = head;
    printf(" \n\n Elements are :");
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
    deleteAtPosition(3);
    traversalNode();
}