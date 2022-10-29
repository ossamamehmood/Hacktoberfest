#include <bits/stdc++.h>
using namespace std;
class node
{
	public:
	int data;
	node *left, *right;
};
node* createnode(int data)
{
	node* temp = new node();
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}
void morrispreorder(node* root)
{
	while (root)
	{

		if (root->left == NULL)
		{
			cout<<root->data<<" ";
			root = root->right;
		}
		else
		{

			node* current = root->left;
			while (current->right && current->right != root)
				current = current->right;
			if (current->right == root)
			{
				current->right = NULL;
				root = root->right;
			}

			else
			{
				cout<<root->data<<" ";
				current->right = root;
				root = root->left;
			}
		}
	}
}

void preorder(node* root)
{
	if (root)
	{
		cout<<root->data<<" ";
		preorder(root->left);
		preorder(root->right);
	}
}

int main()
{
	node* root = NULL;
	root = createnode(1);
	root->left = createnode(2);
	root->right = createnode(3);
	root->left->left = createnode(4);
	root->left->right = createnode(5);
	root->right->left = createnode(6);
	root->right->right = createnode(7);
	root->left->left->left = createnode(8);
	root->left->left->right = createnode(9);
	root->left->right->left = createnode(10);
	root->left->right->right = createnode(11);
	morrispreorder(root);

	cout<<"\n";
	preorder(root);
	return 0;
}

