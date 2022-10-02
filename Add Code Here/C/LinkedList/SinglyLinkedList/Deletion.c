#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *link;
};

int main() {
	struct node *head = 0;
	struct node *temp = 0;
	struct node *newnode = 0;
	int cont = 1;
	int count = 0;
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
		printf("Enter 1 to continue else 0 to terminate...\n");
		scanf("%d",&cont);
	}
	printf("Original linked list elements :-\n");
	temp = head;
	while (temp != 0) {
		printf("%d ",temp -> data);
		temp = temp -> link;
		count += 1;
	}
	printf("\n");
	int choice;
	printf("Enter 1 to remove the first node.\n");
	printf("Enter 2 to remove the last node.\n");
	printf("Enter 3 to remove the node after a certain position.\n");
	printf("Enter your choice.\n");
	scanf("%d",&choice);
	switch(choice) {
		case 1 : temp = head;
		         head = head -> link;
		         free(temp);
		         break;
		case 2 : temp = head;
		         int i = 1;
		         while (i < count-1) {
		         	temp = temp -> link;
		         	i++;
		         }
		         if (temp != head) {
		         struct node *newtemp = temp -> link;
		         temp -> link = 0;
		         free(newtemp);
		         }
		         else {
		         	head = head -> link;
		         	free(temp);
		         }
		         break;
 		case 3 : printf("Enter the position :-\n");
		         int pos;
		         scanf("%d",&pos);
		         if (pos < 1 || pos > count)
		         	printf("Invalid position.\n");
		         else {
			         int i = 1;
			         temp = head;
			         while (i < pos-1) {
			         	temp = temp -> link;
			         	i++;
			         }
			         if (temp != head) {
			         struct node *newtemp = temp -> link;
			         temp -> link = newtemp -> link;
			         free(newtemp);
			         }
			         else {
			         	head = head -> link;
			         	free(temp);
			         }
			     }
			     break;
		default : printf("Wrong choice.\n");
	}
	printf("Updated linked list elements :-\n");
	temp = head;
	while (temp != 0) {
		printf("%d ",temp -> data);
		temp = temp -> link;
	}
	printf("\n");
	return 0;
}