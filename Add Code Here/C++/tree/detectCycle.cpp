#include <bits/stdc++.h>

using namespace std;

struct Node
{
	int data;
	struct Node* next;

	Node(int x)
	{
		data = x;
		next = NULL;
	}
};

bool detect_Cycle(Node* head)
{
	if(head == NULL || head->next == NULL)
		return 0;

	Node* slow = head;
	Node* fast = head;

	while(fast->next != NULL && fast->next->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;

		if(slow == fast)
			return true;
	}

	return false;
}
int main()
{
	Node* head;
	head = new Node(1);
	head->next = new Node(2);
	head->next->next = new Node(3);
	head->next->next->next = new Node(4);
	head->next->next->next->next = new Node(5);


	head->next->next->next->next->next = head->next->next;

	//display(head);

	bool cycle_Present = detect_Cycle(head);

	if(cycle_Present)
		cout << "Cycle is Present" << endl;
	else
		cout << "Cycle is not present" << endl;

	return 0;
}