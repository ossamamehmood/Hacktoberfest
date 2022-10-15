#include <bits/stdc++.h>
using namespace std;

struct Node 
{
	int data;
	struct Node *next;
	Node(int x)
	{
		data = x;
		next = NULL;
	}
};
//typedef struct node Node;

void display(Node *head)
{
	Node *ptr = head;
	while(ptr != NULL)
	{
		cout << ptr->data << endl;
	}
}
Node *reverseList(Node *head)
{
	Node *prev = NULL;
	Node *curr = head;
	Node *forw = NULL;
	
	while(curr != NULL)
	{
		forw = curr->next;
		curr->next = prev;
		prev = curr;
		curr = forw;
	}
	return prev; 
}
int main()
{
	Node *head = new Node(1);
	head->next = new Node(2);
	head->next = new Node(3);
	head->next = new Node(4);
	head->next = new Node(5);
	
	display(head);
	head = reverseList(head);

	display(head);

	return 0;
}
