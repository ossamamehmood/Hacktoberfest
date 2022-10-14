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
	int cont = 1;
	head = 0;
	temp = 0;
	newnode = 0;
	while (cont == 1) {
		newnode = (struct node*)malloc(sizeof(struct node));
		newnode -> link = 0;
		printf("Enter a number :-\n");
		scanf("%d",&newnode -> data);
		if (head == 0) {
			head = newnode;
			temp = newnode;
		}
		else {
			temp -> link = newnode;
			temp = newnode;
		}
		printf("Enter 1 to continue else press 0...\n");
		scanf("%d",&cont);
	}
	temp = head;
	printf("Inputted elements :-\n");
	while (temp != 0) {
		printf("%d\n",temp -> data);
		temp = temp -> link;
	}
	return 0;
}