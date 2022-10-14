#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *link;
};

int main() {
	struct node *head,*tail,*temp,*newnode;
	int size = 0;
	head = 0 ; tail = 0 ; newnode = 0 ; temp = 0;
	int cont = 1;
	while (cont) {
		newnode = (struct node *)malloc(sizeof(struct node));
		newnode -> link = 0 ;
		printf("Enter a number :-\n");
		scanf("%d",&newnode -> data);
		if (temp == 0) {
			temp = newnode;
			temp -> link = newnode;
		}
		else {
			newnode -> link = temp -> link;
			temp -> link = newnode;
			temp = newnode;
		}
		printf("Enter 1 to continue or enter 0 to terminate...\n");
		scanf("%d",&cont);
		size++;
	}
	head = temp -> link;
	tail = temp;
	temp = head;
	printf("Original singly circular linked list :-\n");
	do {
		printf("%d ",temp -> data);
		temp = temp -> link;
	}
	while (temp != head);
	printf("\nEnter 1 to insert at the beginning.\n");
	printf("Enter 2 to insert at end.\n");
	printf("Enter 3 to insert after any inputted position.\n");
	printf("Enter your choice :-\n");
	int choice;
	scanf("%d",&choice);
	switch(choice) {
		case 1 : newnode = (struct node *)malloc(sizeof(struct node));
		newnode -> link = 0;
		printf("Enter a number :-\n");
		scanf("%d",&newnode -> data);
		newnode -> link = head;
		head = newnode;
		tail -> link = newnode;
		break;
		case 2 : newnode = (struct node *)malloc(sizeof(struct node));
		newnode -> link = 0;
		printf("Enter a number :-\n");
		scanf("%d",&newnode -> data);
		tail -> link = newnode;
		newnode -> link = head;
		tail = newnode;
		break;
		case 3 : printf("Enter a position :-\n");
		int pos;
		scanf("%d",&pos);
		if (pos < 1 || pos > size)
			printf("Invalid position.\n"); 
		else {
			newnode = (struct node *)malloc(sizeof(struct node));
			newnode -> link = 0;
			printf("Enter a number :-\n");
			scanf("%d",&newnode -> data);
			temp = head;
			int i = 1;
			while (i < pos) {
				temp = temp -> link;
				i++;
			}
			newnode -> link = temp -> link;
			temp -> link = newnode;
			if (pos == 5)
				tail = newnode;
		}
		break;
		default : printf("Wrong input.\n");
	}
	printf("Updated singly circular linked list :-\n");
	temp = head;
	do {
		printf("%d ",temp -> data);
		temp = temp -> link;
	}
	while (temp != head);
	printf("\n");
	return 0;
}