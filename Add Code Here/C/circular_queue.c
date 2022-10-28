#include<stdio.h>
#include<stdlib.h>

int n,i,j,front = -1,rear = -1;

void enque(int a[], int k);
void display(int a[], int k);
void deque(int a[], int k);


void main()
{
  int k;

printf("enter queue size: \n");
scanf("%d",&k);

int queue[k];

while(1)
{
printf("\n--Menu--\n");
printf("1) Enque\n");
printf("2) Deque\n");
printf("3) Display\n");
printf("4) Exit\n");

scanf("%d", &n);

  switch (n)
  {
    case 1 : enque(queue, k);
             break;

    case 2 : deque(queue, k);
             break;

    case 3 : display(queue, k);
             break;

    case 4 : exit(0);
             break;
        
    default : printf("sike! that's wrong number\n");
             break;
  }
}
}

void enque( int queue[],int k)
{
     if(front == 0 && rear == k-1|| rear+1 == front)
   {
     printf("queue is full\n");
     return;
   }
      if(front == -1)
      {
        front = 0;
      }
         rear = (rear+1)%(k);
         
         printf("enter values to enqueue: \n");
         scanf("%d",&queue[rear]);
}


void deque( int queue[], int k)
{

  if(front == -1) 
  {
    printf("queue underflow\n");
    return;
  }
    printf("dequeued element is : %d\n", queue[front]);
    // queue[front] = 0;

    if(front == rear)
    {
      front = -1;
      rear = -1;
    }
    else
    {
      front = (front+1)%k;
    }
}

void display( int queue[], int k)
{
  if (front == -1)
  {
    printf("Queue is empty\n");
    return;
  }
  if(front <= rear )
  {
    for(int i= front; i<= rear; i++)
    {
      printf("%d\t",queue[i]);
    }
  }
  else
  {
    for(int i = front; i<= k-1; i++)
    {
      printf("%d\t",queue[i]);
    }
    for(int i= 0; i<= rear; i++)
    {
      printf("%d\t", queue[i]);
    }
  }

}
