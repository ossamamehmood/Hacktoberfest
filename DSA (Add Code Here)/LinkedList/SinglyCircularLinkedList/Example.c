#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *link;
};

int main() {
	struct node *head,*tail,*temp,*newnode;
	head = 0; tail = 0; temp = 0; newnode = 0;
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
		printf("Enter 1 to continue or 0 to terminate...\n");
		scanf("%d",&cont);
	}
	head = temp -> link;
	tail = temp;
	temp = head;
	printf("Elements of the single circular linked list :-\n");
	do {
		printf("%d ",temp -> data);
		temp = temp -> link;
	}
	while(temp != head);
	printf("\n");
	return 0;
}