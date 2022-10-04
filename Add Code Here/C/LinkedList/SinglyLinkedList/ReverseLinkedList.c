#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *link;
};

int main() {
	struct node *temp1,*newnode,*temp2,*temp3,*head;
	newnode = 0;
	temp1 = 0;
	temp2 = 0;
	temp3 = 0;
	head = 0;
	int cont = 1;
	while(cont) {
		newnode = (struct node *)malloc(sizeof(struct node));
		newnode -> link = 0;
		printf("Enter a number :-\n");
		scanf("%d",&newnode -> data);
		if (head == 0) {
			head = newnode;
			temp1 = newnode;
		}
		else {
			temp1 -> link = newnode;
			temp1 = newnode;
		}
		printf("Enter 1 to continue else 0 to terminate...\n");
		scanf("%d",&cont);
	}
	printf("Original linked list elements :-\n");
	temp1 = head;
	while(temp1 != 0) {
		printf("%d ",temp1 -> data);
		temp1 = temp1 -> link;
	}
	printf("\n");
	temp1 = head;
	while (temp1 -> link != 0) {
		temp2 = temp1 -> link;
		temp1 -> link = temp3;
		temp3 = temp1;
		temp1 = temp2;
	}
	temp1 -> link = temp3;
	head = temp1;
	printf("Reversed linked list elements :-\n");
	while (temp1 != 0) {
		printf("%d ",temp1 -> data);
		temp1 = temp1 -> link;
	}
	printf("\n");
	return 0;
}