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

vector<int> morrispost(11);
int i=10;
void morrispostorder(node* root)
{
	while (root)
	{
		if (root->right == NULL)
		{
			morrispost[i--]=root->data;
			root = root->left;
		}
		else
		{
			node* current = root->right;
			while (current->left && current->left != root)
				current = current->left;
			if (current->left == root)
			{
                
				current->left = NULL;
				root = root->left;
			}
			else
			{
                morrispost[i--]=root->data;
				current->left = root;
				root = root->right;
			}
		}
	}
}
void postorder(node* root)
{
	if (root)
	{
        postorder(root->left);
		postorder(root->right);
        cout<<root->data<<" ";
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

	morrispostorder(root);
    for(auto x: morrispost){
        cout<<x<<" ";
    }
	cout<<endl;
	postorder(root);

	return 0;
}

