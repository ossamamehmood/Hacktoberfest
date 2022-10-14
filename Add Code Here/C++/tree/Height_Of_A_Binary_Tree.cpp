#include <bits/stdc++.h>
using namespace std;

class node {
public:
	int data;
	node* left;
	node* right;
};

int maxHeight(node* node)
{
	if (node == NULL)
		return 0;
	else 
	{
		int lHeight = mmaxHeight(node->left);
		int rHeight = maxHeight(node->right);

		return max(lHeight+1,rHeight+1);
		
	}
}


node* newNode(int data)
{
	node* Node = new node();
	Node->data = data;
	Node->left = NULL;
	Node->right = NULL;

	return (Node);
}

// Driver code
int main()
{
	node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);

	cout<<"Height of tree is "<<maxHeight(root);
	return 0;
}


