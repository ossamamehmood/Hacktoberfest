#include<stdio.h>
#include<stdlib.h>
typedef struct linkedlist
{
	int data;
	struct linkedlist *next;
}node;

node* insertatbeg(node*);
node* insertatend(node*);
node* del(node*);
node* delfrombeg(node*);
void display(node*);

node* insertatbeg(node* head)
{
	node *temp=(node*)malloc(sizeof(node));
	printf("enter a number");
	scanf("%d",&temp->data);
	temp->next=head;
	head=temp;
	return head;
}
node* insertatend(node* head)
{
	node *curr =head;
	node *temp= (node*)malloc(sizeof(node));
	
	if(head == NULL)
	{
		printf("enter a number");
		scanf("%d",&temp->data);
		temp->next=NULL;
		head = temp;
	}
	else
	{
		while(curr->next!=NULL)
		{
			curr=curr->next;
		}
			curr->next=temp;
			printf("enter a number");
			scanf("%d",&temp->data);
			temp->next=NULL;
	}
	return head;
}

void display(node* head)
{
	node *curr=head;
	if(head == NULL)
	{
		printf("linkedlist is empty");
	}
	else
	{
		while(curr!=NULL)
		{
			printf("%d ",curr->data);
			curr=curr->next;
		}
	}
}

node* del(node* head)
{
	node *curr=head;
	node *prev=NULL;
	
	if(head==NULL)
	{
		printf("already empty dude !!!!");
		return NULL;
	}
	if(head->next==NULL)
	{
		printf("%d is deleted",head->data);
		free(head);
		return NULL;
	}
	else
	{
		while(curr->next!=NULL)
		{
			prev=curr;
			curr=curr->next;
		}
			printf("%d is deleted",curr->data);
			free(curr);
			prev->next=NULL;
	}
	return head;
}

node* delfrombeg(node* head)
{
	node *curr=head;
	node *prev=NULL;
	if(head==NULL)
	{
		printf("already empty hehe ");
		return NULL;
	}
	else
	{
		printf("%d is deleted",head->data);
		head=head->next;
	}
	return head;
}

main()
{
	node *head =NULL;
	
	int ch;
	
	do{
		printf("\n1.insert at beginning\n2.insert at end\n3.delete\n4.delete from beginning\n5.display\n6.exit\n");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1: 
				head = insertatbeg(head);
				break;
			case 2:
				head = insertatend(head);
				break;
			case 3:
				head = del(head);
				break;
			case 4:
				head = delfrombeg(head);
				break;
			case 5:
				display(head);
				break;
			case 6:
				exit(0);
			default:
				printf("enter a valid number");
				break;
		}
	}while(ch>=1 || ch<=7);
}
