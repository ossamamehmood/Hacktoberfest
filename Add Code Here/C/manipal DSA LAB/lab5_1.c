#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};
struct node* make(int len)
{
    struct node *head= (struct node*)malloc(sizeof(struct node())),*p;
    printf("Enter data");
    scanf("%d",&head->data);
    p=head;
    while(len!=1)
    {
        p->next=(struct node*)malloc(sizeof(struct node()));
        printf("Enter data");
        scanf("%d",&p->next->data);
        p->next->next=head;
        p=p->next;
        len--;
    }
    return head;
}
int main()
{
    int len;
    struct node *head,*p; 
    printf("Enter length ");
    scanf("%d",&len);
    head=make(len);
    p=head;
    for(int i=0;i<len;i++)
    {
        printf("%d->",p->data);
        p=p->next;
    }
}
// bool isCircular(struct Node *head){
//     int n=0;
//     if(head==NULL||head->next==head)
//     {
//         return 1;
//     }
//     else
//     {
//     while(n<=100)
//     {
//         head=head->next;
//         n++;
//     }
//     if(n<=100)
//     {
//         return 0;
//     }
//     else
//     {
//         return 1;
//     }
//     }
// }