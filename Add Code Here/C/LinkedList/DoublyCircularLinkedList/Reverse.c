#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *plink;
	struct node *nlink;
};

struct node *head , *tail , *temp , *newnode ;

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
		printf("Enter a number :-\n");
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

void reverseList() {
	temp = head;
	do {
		struct node *ptr = temp->plink;
		temp->plink = temp->nlink;
		temp->nlink = ptr;
		temp = temp -> plink;
	}
	while (temp != head);
	temp = head;
	head = tail;
	tail = temp;
}

int main() {
	createList();
	printf("Original doubly circular linked list :-\n");
	displayList();
	reverseList();
	printf("Reversed doubly circular linked list :-\n");
	displayList();
	return 0;
}