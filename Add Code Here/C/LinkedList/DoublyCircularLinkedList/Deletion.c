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
	head = 0;
	tail = 0;
	temp = 0;
	newnode = 0;
	int cont = 1;
	while (cont) {
		newnode = (struct node *)malloc(sizeof(struct node));
		newnode -> plink = 0;
		newnode -> nlink = 0;
		printf("Enter a nunmber :-\n");
		scanf("%d",&newnode->data);
		if (head == 0) {
			head = newnode;
			temp = newnode;
		}
		else {
			temp -> nlink = newnode;
			newnode -> plink = temp;
			temp = newnode;
		}
		printf("Enter 1 to continue else 0 to terminate...\n");
		scanf("%d",&cont);
		length++;
	}
	tail = temp;
	tail -> nlink = head;
	head -> plink = tail;
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

void delFirstNode() {
	temp = head;
	if (length != 1) {
		head = head -> nlink;
		head -> plink = tail;
		tail -> nlink = head;
	}
	else {
		head = 0;
		tail = 0;
	}
	free(temp);
	length--;
}

void delLastNode() {
	temp = tail;
	if (length != 1) {
		tail = tail -> plink;
		tail -> nlink = head;
		head -> plink = tail;
	}
	else {
		head = 0;
		tail = 0;
	}
	free(temp);
	length--;
}

void delAtPos(int pos) {
	if (pos < 1 || pos > length)
		printf("Invalid position.\n");
	else if (pos == 1)
		delFirstNode();
	else if (pos == length)
		delLastNode();
	else {
		temp = head;
		int i = 1;
		while (i < pos) {
			temp = temp -> nlink;
			i++;
		}
		temp -> plink -> nlink = temp -> nlink;
		temp -> nlink -> plink = temp -> plink;
		free(temp);
		length--;
	}
}

int main() {
	createList();
	printf("Original doubly circular linked list :-\n");
	displayList();
	printf("Enter 1 to delete 1st node.\n");
	printf("Enter 2 to delete the last node.\n");
	printf("Enter 3 to delete the node at specific position.\n");
	printf("Enter your choice.\n");
	int choice;
	scanf("%d",&choice);
	switch(choice) {
		case 1 : delFirstNode();
		break;
		case 2 : delLastNode();
		break;
		case 3 : printf("Enter the position :-\n");
		int pos;
		scanf("%d",&pos);
		delAtPos(pos);
		break;
		default : printf("Wrong choice.\n");
	}
	printf("Updated doubly circular linked list :-\n");
	displayList();
	return 0;
}