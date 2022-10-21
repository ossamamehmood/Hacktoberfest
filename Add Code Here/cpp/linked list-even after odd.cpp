/*Arrange elements in a Linked List such that all even numbers are placed after odd numbers.

Input Format
Enter N space separated Elements

Constraints
None

Output Format
Linked list with all the odd numbers before even numbers

Sample Input
5
1 2 2 2 1
Sample Output
1 1 2 2 2*/

#include <iostream>
using namespace std;

class node {
public:
	int data;
	node * next;
	node(int d) {
		data = d;
		next = NULL;
	}
};
node* insert_atTail(node *head, int d) {
	if (head == NULL) {
		return new node(d);
	}
	node *temp = head;
	while (temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = new node(d);
	return head;
}
void insert_afterNode(node* x, node *y) {
	node*temp = x->next;
	x->next = y;
	y->next = temp;
}

node* evenAfterOdd(node*head) {
	if (head == NULL)return head;
	node*curr = head;
	node*partition = NULL;
	// first find partition node
	if (curr->data & 1) {
		partition = head;
	} else {
		while (curr && !curr->data & 1) {
			curr = curr->next;
		}
		//swapping of data
		int temp = curr->data;
		curr->data = head->data;
		head->data = temp;
		partition = head;
	}
	node*prev = curr;
	curr = curr->next;
	while (curr) {
		if (curr->data & 1) {
			prev->next = curr->next;
			insert_afterNode(partition, curr);
			partition=partition->next;
		}
		prev = curr;
		curr = curr->next;
	}
	return head;
}

void print(node*head) {
	if(head==NULL)return;
	while (head) {
		cout << head->data << " ";
		head=head->next;
	}
	cout<<endl;
}

int main() {
	// freopen("input.txt","r",stdin);
	int n; cin >> n;
	node*head = nullptr;
	int x;
	for (int i = 0; i < n; i++) {
		cin >> x;
		head = insert_atTail(head, x);
	}
	head = evenAfterOdd(head);
	print(head);
}
