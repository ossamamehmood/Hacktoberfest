#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *nlink;
	struct node *plink;
};

int main() {
	struct node *head;
	struct node *temp;
	struct node *newnode;
	head = 0;
	temp = 0;
	newnode = 0;
	int cont = 1;
	while(cont) {
		newnode = (struct node *)malloc(sizeof(struct node));
		printf("Enter a number :-\n");
		scanf("%d",&newnode -> data);
		newnode -> plink = 0;
		newnode -> nlink = 0;
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
	printf("Inputted elements in order :-\n");
	temp = head;
	while (temp -> nlink != 0) {
		printf("%d ",temp -> data);
		temp = temp -> nlink;
	}
	printf("%d ",temp -> data);
	printf("\nInputted elements in reverse order :-\n");
	while (temp != 0) {
		printf("%d ",temp -> data);
		temp = temp -> plink;
	}
	printf("\n");
	return 0;
}