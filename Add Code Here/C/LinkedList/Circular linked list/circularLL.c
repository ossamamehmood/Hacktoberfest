#include<stdio.h>
#include<conio.h>
struct node {
 int data;
 struct node *link;
};
struct node *start=NULL;
void Insert();
void Delete();
void Traverse();
void Search();
int length();
void main()
{
 int ch;
 do

 {
 printf("\n\nMENU");
 printf("\n1 Insert\n2 Delete \n3 Search\n4 Display\n5 Exit");
 printf("\nChoice ? ");
 scanf("%d",&ch);
 switch(ch)
 {
 case 1: Insert(); break;
 case 2: Delete(); break;
 case 3: Search(); break;
 case 4: Traverse(); break;
 case 5: break;
 default : printf("\nWrong Choice ");
 }
 }while(ch!=5);
 printf("\nThank You ");
} // end of main
void Traverse()
{
 struct node *p;
 if(start==NULL)
 printf("\nEmpty");
 else
 {
 printf("\nList is \n");
 p=start;
 do
 {
 printf("\t%d",p->data);
 p=p->link;
 }while(p!=start);
 }
}

int length()
{
 int c=0;
 struct node *p=start;
 if(start==NULL)
 return 0;
 else
 {
 do
 {
 c++;
 p=p->link;
 }while(p!=start);
 return c;
 }
}
void Search()
{
 struct node *p;
 int item,flag=1;

 if(start==NULL)
 printf("\nEmpty");
 else
 {
 printf("\n enter the no to find ");
 scanf("%d",&item);
 p=start;

 do{
     p=p->link;
     if(p->data==item)
  {
   printf("\n found");
   flag=0;
   return;
   }
    else{
        flag=1;
    }
    }while(p!=start);
}

    if(flag!=0)
     {
     printf("\n not found");
     return;
     }
}

void Insert()
{
 struct node *p,*n;
 int i,pos;
 printf("\nEnter position ");
 scanf("%d",&pos);
 if(pos<=length()+1)
 {
 n=(struct node *)malloc(sizeof(struct node));
 printf("\nEnter number ");
 scanf("%d",&n->data);
 if(start==NULL) //List is initially empty
 {
 start=n;
 start->link=start;
 }
 else
 if(pos==1)
 {
 p=start; //traverse p up to last node
 while(p->link!=start)
 p=p->link;
 n->link=start;
 start=n;
 p->link=n;
 }
 else
 {
 p=start;
 for(i=1;i<pos-1;i++)
 p=p->link;
 n->link=p->link;
 p->link=n;
 }
 printf("\n%d is inserted at %d position ",n->data,pos);
 }
 else
 printf("\nInvalid position");
}
void Delete()
{
 struct node *p,*n;
 int pos,i;
 if(start==NULL)

 printf("\nUNDERFLOW");
 else
 {
 printf("\nEnter the position ");
 scanf("%d",&pos);
 if(pos<=length())
 {
 if(length()==1) //single node
 {
 n=start;
 start=NULL;
 printf("\n%d is deleted ",n->data);
 free(n);
 }
 else
 if(pos==1)
 {
 p=start; // traverse p up to last node
 while(p->link!=start)
 p=p->link;
 n=start;
 start=start->link;
 p->link=start;
 printf("\n%d is deleted from %d position", n->data,pos);
 free(n);
 }
 else
 {
 p=start;
 for(i=1;i<pos-1;i++)
 p=p->link;
 n= p->link;

 p->link = n->link;
 printf("\n%d is deleted from %d position", n->data,pos);
 free(n);
 }
 }
 else
 printf("\nInvalid position");
 }
} //end of Delete
////////////////END OF PROGRAM//////////////////////////
