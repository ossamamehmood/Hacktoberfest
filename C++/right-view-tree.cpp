// C++ program to print right view of Binary Tree
#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	struct Node *left, *right;
};

// A utility function to
// create a new Binary Tree Node
struct Node* newNode(int item)
{
	struct Node* temp
		= (struct Node*)malloc(sizeof(struct Node));
	temp->data = item;
	temp->left = temp->right = NULL;
	return temp;
}

// Recursive function to print
// right view of a binary tree.
void rightViewUtil(struct Node* root, int level,
				int* max_level)
{
	// Base Case
	if (root == NULL)
		return;

	// If this is the last Node of its level
	if (*max_level < level) {
		cout << root->data << "\t";
		*max_level = level;
	}

	// Recur for right subtree first,
	// then left subtree
	rightViewUtil(root->right, level + 1, max_level);
	rightViewUtil(root->left, level + 1, max_level);
}

// A wrapper over rightViewUtil()
void rightView(struct Node* root)
{
	int max_level = 0;
	rightViewUtil(root, 1, &max_level);
}

// Driver Code
int main()
{
	struct Node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	root->right->right = newNode(7);
	root->right->right->right = newNode(8);

	rightView(root);

	return 0;
}