#include <iostream>
using namespace std;
struct node
{
int data;
struct node *next;
};
void append(struct node **,int);
void display(struct node*);

int main()
{
struct node *start=NULL;
int choice,n;
do
{
cout<<"\n slect an operation:";
cout<<"\n1.Append a node \n2. display \n3.countnodes\n4. quit";
cout<<"enetr your choice";
cin>>choice;
switch(choice)
{
case 1:
cout<<"Enter the value to be added";
cin>>n;
append(&start,n);
break;
case 2:
display(start);
break;


case 3:
cout<<"Thank you for using the program";
break;
default:
cout<<"Wrong choice! Try again";
}

}
while(choice!=3);
return 0;
}

void append(struct node **ps,int x)
{
struct node *p,*temp;
p=(struct node *)malloc(sizeof(struct node));
if (p==NULL)
{
cout<<" Cannot add new node";
return;
}
p->data=x;
p->next=NULL;
if (*ps==NULL)
{
*ps=p;
cout<<"\n Node sucessfully added";
return;
}
temp=*ps;
while(temp->next!=NULL)
{
temp=temp->next;
}
temp->next=p;
cout<<"\n Node is succesfully added";
}

void display(struct node *p)
{
if(p==NULL)
{
cout<<"list is emepty";
return;
}
while(p!=NULL)
{
cout<<"\n "<<p->data;
p=p->next;
}
}
