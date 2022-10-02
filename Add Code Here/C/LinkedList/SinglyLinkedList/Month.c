#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
	char month[10];
	struct node *link;
};

struct node *head , *temp , *newnode;

void createNode(){
	head = 0;
	temp = 0;
	newnode = 0;
	int i = 1;
	while (i <= 12){
		newnode = (struct node *)malloc(sizeof(struct node));
		newnode -> link = 0;
		switch (i){
			case 1 : strcpy(newnode->month,"January");
			break;
			case 2 : strcpy(newnode->month,"Feburary");
			break;
			case 3 : strcpy(newnode->month,"March");
			break;
			case 4 : strcpy(newnode->month,"April");
			break;
			case 5 : strcpy(newnode->month,"May");
			break;
			case 6 : strcpy(newnode->month,"June");
			break;
			case 7 : strcpy(newnode->month,"July");
			break;
			case 8 : strcpy(newnode->month,"August");
			break;
			case 9 : strcpy(newnode->month,"September");
			break;
			case 10 : strcpy(newnode->month,"October");
			break;
			case 11 : strcpy(newnode->month,"November");
			break;
			default : strcpy(newnode->month,"December");
		}
		if (head == 0){
			head = newnode;
			temp = newnode;
		}
		else{
			temp->link = newnode;
			temp = newnode;
		}
		i++;
	}
}

int main(){
	createNode();
	int days[12] = {31,29,31,30,31,30,31,31,30,31,30,31};
	char str_month[10];
	printf("Enter a month :-\n");
	gets(str_month);
	temp = head;
	int i = 0;
	while (temp != 0){
		if (strcmp(temp->month,str_month) == 0){
			printf("%ddays\n",days[i]);
			break;
		}
		i++;
		temp = temp->link;
	}
}