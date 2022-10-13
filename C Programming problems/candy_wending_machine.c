//Shrirish is student participating in coding competition held by KPIT company. He is given a problem statement “Candy Wending Machine”. A machine will request the selected coins to be inserted, they are 1re, 5rs, 10rs and 20rs coins only. When the value of a coin inserted is other than mentioned coins, those coins are returned by the machine.If the sum of all coins is greater than or equal to 25rs but less than 34rs then fetch Mango Candy from machine, if the sum of all the coins is greater than or equal to 35rs but less than 49rs then fetch Strawberry Candy, if the sum of all the coins is greater than or equal to 50rs but less than 70rs fetch Pista Candy, otherwise display No candy.
//The first line contains n, the number of coins to be inserted in machine.
//The second line contains n space-separated coins with given denominations.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define SI 100
struct queue
{
    int data[SI],front,rear;
};
void enqueue(struct queue *qptr,int num)
{
    if(qptr->rear==SI-1)
    {
        printf("Queue Overflow\n");
    }
    else
    {
        qptr->rear++;
        qptr->data[qptr->rear]=num;
    }
}
int dequeue(struct queue *qptr)
{
    int num=0;
    if(qptr->front==qptr->rear)
    {
        return num;
    }
    else
    {
        qptr->front++;
        num=qptr->data[qptr->front];
        return num;
    }
}
void check(int sum)
{
    if(sum>=25&&sum<34) { printf("Mango candy"); } else if(sum>=35&&sum<49) { printf("Strawberry candy"); } else if(sum>=50&&sum<70) { printf("Pista candy"); } else { printf("No candy"); } } int main() { struct queue * qptr; struct queue q; qptr=&q; qptr->front=qptr->rear=-1;
    int num,n,i,sum=0,c;
    scanf("%d",&n);
    for(i=0;i<n;i++) { scanf("%d",&num); enqueue(qptr,num); } while(qptr->rear!=qptr->front)
    {
        c=dequeue(qptr);
        switch(c)
        {
            case 1:sum=sum+1;
                break;
            case 5:sum=sum+5;
                break;
            case 10:sum=sum+10;
                break;
            case 20:sum=sum+20;
                break;    
        }
    }
    check(sum);
    return 0;
}
