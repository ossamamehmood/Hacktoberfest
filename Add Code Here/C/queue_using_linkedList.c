// C program to implement the concept of queue using single linked list.

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} NODE;

typedef struct Queue
{
    NODE *front;
    NODE *rear;
} QUEUE;

QUEUE *createQueue(QUEUE *);
QUEUE *enqueue(QUEUE *, int);
QUEUE *dequeue(QUEUE *);
void display(QUEUE *);

int main()
{
    QUEUE *q;
    q = createQueue(q);
    display(q);
    q = dequeue(q);

    q = enqueue(q, 11);
    q = enqueue(q, 12);
    q = enqueue(q, 13);
    q = enqueue(q, 14);
    display(q);

    q = dequeue(q);
    q = dequeue(q);
    q = enqueue(q, 15);
    display(q);

    return 0;
}

QUEUE *createQueue(QUEUE *q)
{
    q->front = NULL;
    q->rear = NULL;
    return q;
}

QUEUE *enqueue(QUEUE *q, int val)
{
    NODE *newNode = (NODE *)malloc(sizeof(NODE));
    newNode->data = val;
    if (q->front == NULL)
    {
        q->front = q->rear = newNode;
        q->front->next = q->rear->next = NULL;
    }
    else
    {
        q->rear->next = newNode;
        q->rear = newNode;
        q->rear->next = NULL;
    }
    return q;
}

QUEUE *dequeue(QUEUE *q)
{
    if (q->front == NULL)
        printf("UNDERFLOW!\n");
    else
    {
        NODE *ptr = (NODE *)malloc(sizeof(NODE));
        ptr = q->front;
        q->front = q->front->next;
        free(ptr);
    }
    return q;
}

void display(QUEUE *q)
{
    NODE *ptr;
    ptr = q->front;
    if (ptr == NULL)
    {
        printf("Queue is Empty\n");
        return;
    }
    printf("FRONT");
    while (ptr != NULL)
    {
        printf(" -> %d", ptr->data);
        ptr = ptr->next;
    }
    printf(" <- REAR\n");
}
