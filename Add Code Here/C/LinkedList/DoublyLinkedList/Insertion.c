#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *plink;
	struct node *nlink;
};

int main() {
	struct node *head,*temp,*newnode;
	head = 0;
	temp = 0;
	newnode = 0;
	int cont = 1;
	while (cont) {
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
	temp = head;
	int count = 0;
	printf("Elements of the doubly linked list in order :-\n");
	while (temp != 0) {
		printf("%d ",temp -> data);
		temp = temp -> nlink;
		count++;
	}
	printf("\nEnter 1 to insert at the beginning.\n");
	printf("Enter 2 to insert at the end.\n");
	printf("Enter 3 to insert after a certain position.\n");
	printf("Enter your choice.\n");
	int choice;
	scanf("%d",&choice);
	switch(choice) {
		case 1 : newnode = (struct node *)malloc(sizeof(struct node));
		         newnode -> plink = 0;
		         newnode -> nlink = 0;
		         printf("Enter a number to be inserted :-\n");
		         scanf("%d",&newnode -> data);
		         newnode -> nlink = head;
		         head -> plink = newnode;
		         head = newnode;
		         break;
		case 2 : newnode = (struct node *)malloc(sizeof(struct node));
		         newnode -> plink = 0;
		         newnode -> nlink = 0;
		         printf("Enter a number to be inserted :-\n");
		         scanf("%d",&newnode -> data);
		         temp = head;
		         while (temp -> nlink != 0) {
		         	temp = temp -> nlink;
		         }
		         temp -> nlink = newnode;
		         newnode -> plink = temp;
		         break;
		case 3 : printf("Enter the position :-\n");
		         int pos;
		         scanf("%d",&pos);
		         if (pos < 1 || pos > count)
		         	printf("Invalid position.\n");
		         else {
		         	newnode = (struct node *)malloc(sizeof(struct node));
		         	newnode -> plink = 0;
		         	newnode -> nlink = 0;
		         	printf("Enter a number to be inserted :-\n");
		         	scanf("%d",&newnode -> data);
			        int i = 1;
			        temp = head;
			        while (i < pos) {
			        	temp = temp -> nlink;
			        	i++;
		         }
		         struct node *newtemp = temp -> nlink;
		         temp -> nlink = newnode;
		         newnode -> plink = temp;
		         newnode -> nlink = newtemp;
		         newtemp -> plink = newnode;
		         }
		         break;
		default : printf("Wrong choice.\n");
	}
	temp = head;
	printf("Elements of the updated doubly linked list :-\n");
	while (temp != 0) {
		printf("%d ",temp -> data);
		temp = temp -> nlink;
	}
	printf("\n");
	return 0;
}