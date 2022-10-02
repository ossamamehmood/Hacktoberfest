#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *plink;
	struct node *nlink;
};

struct node *head , *tail , *temp , *newnode ;
int length = 0;

void createList() {
	newnode = 0;
	tail = 0;
	head = 0;
	temp = 0;
	int cont = 1;
	while (cont) {
		newnode = (struct node *)malloc(sizeof(struct node));
		newnode -> plink = 0;
		newnode -> nlink = 0;
		printf("Enter a number :-\n");
		scanf("%d",&newnode->data);
		if (head == 0) {
			head = newnode;
			temp = newnode;
		}
		else {
			newnode -> plink = temp;
			temp -> nlink = newnode;
			temp = newnode;
		}
		printf("Enter 1 to continue else 0 to terminate...\n");
		scanf("%d",&cont);
		length++;
	}
	tail = temp;
	head -> plink = tail;
	tail -> nlink = head;
}

void displayList() {
	temp = head;
	do {
		printf("%d ",temp -> data);
		temp = temp -> nlink;
	}
	while (temp != head);
	printf("\n");
}

void insertAtBeginning() {
	newnode = (struct node *)malloc(sizeof(struct node));
	newnode -> plink = 0;
	newnode -> nlink = 0;
	printf("Enter a number :-\n");
	scanf("%d",&newnode->data);
	newnode -> nlink = head;
	head -> plink = newnode;
	head = newnode;
	head -> plink = tail;
	tail -> nlink = head;
	length++;
}

void insertAtEnd() {
	newnode = (struct node *)malloc(sizeof(struct node));
	newnode -> plink = 0;
	newnode -> nlink = 0;
	printf("Enter a number :-\n");
	scanf("%d",&newnode->data);
	tail -> nlink = newnode;
	newnode -> plink = tail;
	newnode -> nlink = head;
	head -> plink = newnode;
	tail = newnode;
	length++;
}

void insertAtPosition(int pos) {
	if (pos < 1 || pos > length+1)
		printf("Invalid position.\n");
	else {
		if (pos == 1)
			insertAtBeginning();
		else if (pos == length+1)
			insertAtEnd();
		else {
			newnode = (struct node *)malloc(sizeof(struct node));
			newnode -> plink = 0;
			newnode -> nlink = 0;
			printf("Enter a number :-\n");
			scanf("%d",&newnode->data);
			int i = 1;
			temp = head;
			while (i < pos-1) {
				temp = temp -> nlink;
				i++;
			}
			newnode -> nlink = temp -> nlink;
			newnode -> plink = temp;
			temp -> nlink -> plink = newnode;
			temp -> nlink = newnode;
			length++;
		}
	}
}

int main() {
	createList();
	printf("Original doubly circular linked list :-\n");
	displayList();
	printf("Enter 1 to insert at beginning.\n");
	printf("Enter 2 to insert at end.\n");
	printf("Enter 3 to insert at a specific position.\n");
	printf("Enter your choice.\n");
	int choice;
	scanf("%d",&choice);
	switch(choice) {
		case 1 : insertAtBeginning();
		break;
		case 2 : insertAtEnd();
		break;
		case 3 : printf("Enter a position :-\n");
		int pos;
		scanf("%d",&pos);
		insertAtPosition(pos);
		break;
		default : printf("Invalid input.\n");
	}
	printf("Updated doubly circular linked list :-\n");
	displayList();
	return 0;
}