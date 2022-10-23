#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct linknode
{
    int data;
    struct linknode *next;
} node;

node *start, *last, *temp, *p;

void enqueue()
{
    printf("\nEnter the number:");
    temp = (node *)malloc(sizeof(node));
    scanf("%d", &temp->data);
    temp->next = NULL;

    if (last == NULL)
    {
        start=temp;
        last = temp;
        last->next = last;
    }

    else
    {
        temp->next = last->next;
        last->next = temp;
        last = temp;
    }
}

void dequeue()
{
    if (last == NULL)
    {
        printf("\nUnderflow\n");
    }
    else if(last->next==last)
    {
    printf("%d is deleted\n",last->data);
      last=NULL;
      free(last);
    }
    else
    {
       printf("%d is deleted\n",last->next->data);
        temp=start;
        start = start->next;
        last->next = start;
        temp->next = NULL;
        free(temp);

    }
}

void display()
{

    if (last == NULL)
    {
        printf("Underflow\n");
    }
    else
    {
        p = last->next;
        do
        {
            printf("%d\n", p->data);
            p = p->next;
        } while (p != last->next);
    }
}

int main()
{
    int ch;
    while (1)
    {
        printf("Enter the choice:");
        printf("\n1:Enqueue\n2:Dequeue\n3:Display\n4:Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            enqueue();
            break;

        case 2:
            dequeue();
            break;

        case 3:
            display();
            break;
        case 4:
            exit(0);
            break; 
        }
    }

    return 0;
}
