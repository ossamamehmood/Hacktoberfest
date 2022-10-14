#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *link;
};

int main() {
	struct node *head;
	struct node *temp;
	struct node *newnode;
	head = 0;
	temp = 0;
	newnode = 0;
	int cont = 1;
	while (cont) {
		newnode = (struct node *)malloc(sizeof(struct node));
		printf("Enter a number :-\n");
		scanf("%d",&newnode -> data);
		newnode -> link = 0;
		if (head == 0) {
			head = newnode;
			temp = newnode;
		}
		else {
			temp -> link = newnode;
			temp = newnode;
		}
		printf("Enter 1 to continue or 0 to terminate :-\n");
		scanf("%d",&cont);
	}
	printf("Original linked list elements :-\n");
	temp = head;
	int count = 0;
	while (temp!=0) {
		printf("%d ",temp -> data);
		temp = temp -> link;
		count += 1;
	}
	printf("\nEnter 1 to add node at the beginning.\n");
	printf("Enter 2 to add node at the end.\n");
	printf("Enter 3 to add the node after a certain position.\n");
	int choice;
	scanf("%d",&choice);
	int pos;
	switch(choice) {
		case 1 : newnode = (struct node *)malloc(sizeof(struct node));
                 printf("Enter a number to be added :-\n");
                 scanf("%d",&newnode -> data);
                 newnode -> link = head;
                 head = newnode;
                 break;
        case 2 : newnode = (struct node *)malloc(sizeof(struct node));
                 printf("Enter a number to be added :-\n");
                 scanf("%d",&newnode -> data);
                 newnode -> link = 0;
                 temp = head;
                 while (temp -> link != 0) {
                 	temp = temp -> link;
                 }
                 temp -> link = newnode;
                 break;
        case 3 : pos;
                 printf("Enter the position :-\n");
                 scanf("%d",&pos);
                 if (pos > count)
                 	printf("Invalid position.\n");
                 else {
                 	newnode = (struct node *)malloc(sizeof(struct node));
                 	printf("Enter a number to be added :-\n");
                 	scanf("%d",&newnode -> data);
                 	int i = 1;
                 	temp = head;
                 	while (i < pos) {
                 		temp = temp -> link;
                 		i++;
                 	}
                 	newnode -> link = temp -> link;
                 	temp -> link = newnode;
                 }
                 break;
        default : printf("Wrong choice.\n");
	}
	temp = head;
	printf("Elements of new linked list :-\n");
	while (temp != 0) {
		printf("%d ",temp -> data);
		temp = temp -> link;
	}
	printf("\n");
	return 0;
}