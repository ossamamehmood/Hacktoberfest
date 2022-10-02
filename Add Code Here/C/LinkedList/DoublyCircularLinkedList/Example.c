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
	newnode = 0;
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
	}
	tail = temp;
	head -> plink = tail;
	tail -> nlink = head;
}

void displayInOrder() {
	printf("Elements of the doubly circular linked list in order :-\n");
	temp = head;
	do {
		printf("%d ",temp->data);
		temp = temp -> nlink;
	}
	while (temp != head);
	printf("\n");
}

void displayReverse() {
	printf("Elements of the doubly circular linked list in reverse order :-\n");
	temp = tail;
	do {
		printf("%d ",temp->data);
		temp = temp -> plink;
	}
	while (temp != tail);
	printf("\n");
}

int main() {
	createList();
	displayInOrder();
	displayReverse();
	return 0;
}