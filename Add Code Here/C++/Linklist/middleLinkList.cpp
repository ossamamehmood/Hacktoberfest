/*
###############################################
CPP program to print the middle element of a link list

@author: Tapati
Student at GCETTB
###############################################
*/

/* Here we use two pointer. At first two pointers point at the head. Then we move
	first pointer by one and the second pointer by two.When second pointer will
	reach at the last node at that time first pointer will reach the middle
	of the link list*/

#include <iostream>
#include <stdlib.h>

using namespace std;

//link list Node
struct Node
{
	int data;
	Node *next;
};

//Method to print the middle element of the link list
void printMiddle(struct Node *head)
{
	struct Node *first_ptr = head;//-----first pointer (move by one)
	struct Node *second_ptr = head;//-----second pointer (move by two)

	if(head != NULL)
	{
		while(second_ptr != NULL && second_ptr->next != NULL)
		{
			second_ptr = second_ptr->next->next;
			first_ptr = first_ptr->next;
		}
		cout << "The middle element of the list is: " << first_ptr->data << endl;
	}
}

//Method to insert element to the link list
void push(struct Node **head, int val)
{
	//Allocate a Node
	struct Node *ptr = new Node();

	//Put the data to the new node
	ptr->data = val;

	//Link the list to the new node
	ptr->next = (*head);
	//Move the head to point the new node
	(*head) = ptr;
}

//Print the link list
void linklistTraversal(struct Node *ptr)
{
	while(ptr != NULL)
	{
		cout << "The element is: " << ptr->data << endl;
		ptr = ptr->next;
	}
}

int main()
{
	//Start the empty list
	struct Node *head = NULL;

	//Iterate and add element
	for(int i = 0; i < 5; i++)
	{
		push(&head, i);

	}
	linklistTraversal(head);
	printMiddle(head);

	return 0;
}

/*#################################################
Output:

The element is: 4
The element is: 3
The element is: 2
The element is: 1
The element is: 0
The middle element of the list is: 2

#################################################*/