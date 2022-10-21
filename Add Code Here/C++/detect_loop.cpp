#include <bits/stdc++.h>

using namespace std;

// Structure of node
struct Node {
	int data;
	struct Node* next;
};

void push(struct Node** head, int new_data)
{
	// Creating new node
	struct Node* new_node = new Node;

	// Adding data to new node
	new_node->data = new_data;

	// Link the old list off the new node
	new_node->next = (*head);

	// Move the head to point to the new node
	(*head) = new_node;
}

// Detect loop function
bool detectLoop(struct Node* head)
{
	unordered_set<Node*> s;
	while (head != NULL) {
		// If this node is already present in hashmap it means there is a cycle
		// (Because you will be encountering the node for the second time).
		if (s.find(head) != s.end())
			return true;

		// If we are seeing the node for the first time, insert it in hash
		s.insert(head);

		head = head->next;
	}

	return false;
}

// Main function
int main()
{
	// Creating an empty linked list
	struct Node* head = NULL;

	push(&head, 20);
	push(&head, 4);
	push(&head, 15);
	push(&head, 10);

	// Create a loop for testing
	head->next->next->next->next = head;

	if (detectLoop(head))
		cout << "Loop found";
	else
		cout << "No Loop";

	return 0;
}