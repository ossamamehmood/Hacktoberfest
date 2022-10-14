#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *plink;
	struct node *nlink;
};

int main() {
	struct node *head,*tail,*temp,*newnode;
	head = 0; tail = 0; temp = 0; newnode = 0;
	int cont = 1;
	while(cont) {
		newnode = (struct node *)malloc(sizeof(struct node));
		newnode -> plink = 0;
		newnode -> nlink = 0;
		printf("Enter a number :-\n");
		scanf("%d",&newnode -> data);
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
	temp = head;
	printf("Original doubly linked list :-\n");
	while (temp != 0) {
		printf("%d ",temp -> data);
		temp = temp -> nlink;
	}
	printf("\n");
	temp = head;
	struct node *ptr = 0;
	while (temp != 0) {
		ptr = temp -> nlink;
		temp -> nlink = temp -> plink;
		temp -> plink = ptr;
		temp = ptr;
	}
	ptr = head;
	head = tail;
	tail = ptr;
	printf("Reversed doubly linked list :-\n");
	temp = head;
	while(temp != 0) {
		printf("%d ",temp -> data);
		temp = temp -> nlink;
	}
	printf("\n");
	return 0;
}