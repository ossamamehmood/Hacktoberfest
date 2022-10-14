
/*
###############################################
Cpp program to count the number of occurence of element in the link list

@author: Tapati
Student at GCETTB
###############################################
*/

#include <iostream>
#include <stdlib.h>

using namespace std;

/*Link list Node*/
class Node
{
	public:
	int data;
	Node *next;
};

/*Given a reference(pointer to pointer) to the head of the list
	push an element to the link list */
void push(Node **head, int x)
{
	//Allocate a Node
	Node * ptr = new Node();

	//Put the data to the new node
	ptr->data = x;

	//Link the list to the new node
	ptr->next = (*head);
	//Move the head to point the new node
	(*head) = ptr;

}

/*Method to calculate a number's no of existence in the list*/
int count(Node *head, int val)
{
	Node *p = head;
	int count = 0;

	while(p != NULL)
	{
		if(p->data == val)
			count++;
		p = p->next;
	}
	return count;
}

int main()
{
	//Start a new list
	Node *head = NULL;
	cout << "linkedlist has been created successfully\n" << endl;

	//Insert element to the link list
	push(&head, 6);
	push(&head, 6);
	push(&head, 5);
	push(&head, 6);
	push(&head, 4);

	cout << "6 is present: " << count(head, 6) << "times" << endl;

	return 0;
}

/*###########################################

Output:
linkedlist has been created successfully

6 is present: 3times

############################################*/

