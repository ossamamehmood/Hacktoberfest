#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *link;
};

int main() {
	struct node *head , *temp , *newnode;
	head = 0;
	temp = 0;
	newnode = 0;
	int cont = 1;
	while (cont) {
		newnode = (struct node *)malloc(sizeof(struct node));
		printf("Enter a number :-\n");
		scanf("%d",&newnode -> data);
		newnode -> link = 0;
		if (head == 0){
			temp = newnode;
			head = newnode;
		}
		else {
			temp -> link = newnode;
			temp = temp -> link;
		}
		printf("Enter 1 to continue else 0 to terminate...\n");
		scanf("%d",&cont);
	}
	int count = 0;
	temp = head;
	printf("Elements of the linked list :-\n");
	while (temp != 0) {
		printf("%d ",temp -> data);
		count += 1;
		temp = temp -> link;
	}
	printf("\nLength of linked list :- %d\n",count);
	return 0;
}