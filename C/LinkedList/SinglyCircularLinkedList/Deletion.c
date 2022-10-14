#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *link;
};

struct node *head , *tail , *temp , *newnode ;
int length = 0;

void createList() {
	head = 0;
	tail = 0;
	temp = 0;
	newnode = 0;
	int cont = 1;
	while(cont) {
		newnode = (struct node *)malloc(sizeof(struct node));
		newnode -> link = 0;
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
		printf("Enter 1 to continue else 0 to terminate...\n");
		scanf("%d",&cont);
		length++;
	}
	head = temp -> link;
	tail = temp;
}

void displayList() {
	temp = head;
	do {
		printf("%d ",temp -> data);
		temp = temp -> link;
	}
	while (temp != head);
	printf("\n");
}

void deletion() {
	printf("Enter 1 to delete 1st node.\n");
	printf("Enter 2 to delete the last node.\n");
	printf("Enter 3 to delete the node at certain position.\n");
	printf("Enter your choice.\n");
	int choice;
	scanf("%d",&choice);
	switch(choice) {
		case 1 : temp = head;
		if (length != 1) {
			head = head -> link;
			tail -> link = head;
		}
		else {
			head = 0;
			tail = 0;
		}
		free(temp);
		break;
		case 2 : temp = head;
		if (length != 1) {
			int i = 1;
			while (i < length-1) {
				temp = temp -> link;
				i++;
			}
			free(temp -> link);
			temp -> link = head;
			tail = temp;
		}
		else {
			head = 0;
			tail = 0;
			free(temp);
		}
		break;
		case 3 : printf("Enter the position of the element to be deleted :-\n");
		int pos;
		scanf("%d",&pos);
		if (pos < 1 || pos > length)
			printf("Invalid position.\n");
		else if (length == 1) {
			temp = head;
			head = 0;
			tail = 0;
			free(temp);
		}
		else if (pos == 1) {
			temp = head;
			head = head -> link;
			tail -> link = head;
			free(temp);
		}
		else {
			temp = head;
			int i = 1;
			while (i < pos-1) {
				temp = temp -> link;
				i++;
			}
			struct node *ptr = temp -> link;
			temp -> link = ptr -> link;
			if (ptr == tail)
				tail = temp;
			free(ptr);
		}
		break;
		default : printf("Wrong choice.\n");
	}
}

int main() {
	createList();
	printf("Original singly circular linked list elemets :-\n");
	displayList();
	deletion();
	printf("Updated singly circular linked list elemets :-\n");
	displayList();
	return 0;
}