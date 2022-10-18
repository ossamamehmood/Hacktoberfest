#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
and a pointer to right child */
class node {
public:
	int data;
	node* left;
	node* right;
};

/* Helper function that allocates a new node with the
given data and NULL left and right pointers. */
node* newNode(int data)
{
	node* Node = new node();
	Node->data = data;
	Node->left = NULL;
	Node->right = NULL;

	return (Node);
}

/* Given two trees, return true if they are
structurally identical */
int identicalTrees(node* a, node* b)
{
	/*1. both empty */
	if (a == NULL && b == NULL)
		return 1;

	/* 2. both non-empty -> compare them */
	if (a != NULL && b != NULL) {
		return (a->data == b->data
				&& identicalTrees(a->left, b->left)
				&& identicalTrees(a->right, b->right));
	}

	/* 3. one empty, one not -> false */
	return 0;
}

int main()
{
	node* root1 = newNode(1);
	node* root2 = newNode(1);
	root1->left = newNode(2);
	root1->right = newNode(3);
	root1->left->left = newNode(4);
	root1->left->right = newNode(5);

	root2->left = newNode(2);
	root2->right = newNode(3);
	root2->left->left = newNode(4);
	root2->left->right = newNode(5);

	// Function call
	if (identicalTrees(root1, root2))
		cout << "Both trees are identical.";
	else
		cout << "Trees are not identical.";

	return 0;
}

