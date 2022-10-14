#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *link;
};

struct node *head , *tail , *temp , *newnode;

void createList() {
	head = 0;
	tail = 0;
	temp = 0;
	newnode = 0;
	int cont = 1;
	while (cont) {
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
	while(temp != head);
	printf("\n");
}

void reverseList() {
	struct node *prev , *next;
	prev = tail;
	temp = head;
	do {
		next = temp -> link;
		temp -> link = prev;
		prev = temp;
		temp = next;
	}
	while (temp != head);
	temp = head;
	head = tail;
	tail = temp;
}

int main() {
	createList();
	printf("Original singly circular linked list :-\n");
	displayList();
	reverseList();
	printf("Reversed singly circular linked list :-\n");
	displayList();
	return 0;
}