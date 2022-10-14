#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *plink;
	struct node *nlink;
};

int main() {
	struct node *head,*tail,*temp,*newnode;
	head = 0 ; tail = 0 ; newnode = 0 ; temp = 0 ;
	int cont = 1; int length = 0;
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
	tail = temp;
	temp = head;
	printf("Elements of the original doubly linked list :-\n");
	while(temp != 0) {
		printf("%d ",temp -> data);
		temp = temp -> nlink;
		length++;
	}
	printf("\nEnter 1 to delete first node.\n");
	printf("Enter 2 to delete last node.\n");
	printf("Enter 3 to delete a node at a certain position.\n");
	printf("Enter your choice :-\n");
	int choice;
	scanf("%d",&choice);
	switch(choice) {
		case 1 : temp = head;
		         if(length == 1) {
		         	head = 0;
		         	tail = 0;
		         }
		         else {
			        head = head -> nlink;
			        head -> plink = 0;
		         }
		         free(temp);
		         break;
		case 2 : temp = tail;
		         if (length == 1) {
		         	tail = 0;
		         	head = 0;
		         }
		         else {
		         tail = tail -> plink;
		         tail -> nlink = 0;
		         }
		         free(temp);
		         break;
		case 3 : printf("Enter the position :-\n");
		         int pos;
		         scanf("%d",&pos);
		         if (pos < 1 || pos > length)
		         	printf("Invalid position.\n");
		         else if (length == 1) {
		         	temp = head;
		         	head = 0;
		         	tail = 0;
		         	free(temp);
		         }
		         else if (pos == 1) {
		         	temp = head;
		         	head = head -> nlink;
		         	head -> plink = 0;
		         	free(temp);
		         }
		         else if (pos == length) {
		         	temp = tail;
		         	tail = tail -> plink;
		         	tail -> nlink = 0;
		         	free(temp);
		         }
		         else {
		         	int i = 1;
		         	temp = head;
		         	while (i < pos) {
		         		temp = temp -> nlink;
		         		i++;
		         	}
		         	temp -> plink -> nlink = temp -> nlink;
		         	temp -> nlink -> plink = temp -> plink;
		         	free(temp);
		         }
		         break;
		default : printf("Invalid choice.\n");
	}
	temp = head;
	printf("Elements of the updataed doubly linked list :-\n");
	while (temp != 0) {
		printf("%d ",temp -> data);
		temp = temp -> nlink;
	}
	printf("\n");
	return 0;
}