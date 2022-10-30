#include<bits/stdc++.h>

using namespace std;

/* A binary tree node has data,
pointer to left child and
a pointer to right child */
class node
{
	public:
	int data;
	node* left;
	node* right;
	
	/* Constructor that allocates a new node with the
	given data and NULL left and right pointers. */
	node(int data)
	{
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}
};

void printKDistant(node *root , int k)
{
	if(root == NULL|| k < 0 )
		return;
	if( k == 0 )
	{
		cout << root->data << " ";
		return;
	}
	
		printKDistant( root->left, k - 1 ) ;
		printKDistant( root->right, k - 1 ) ;
	
}


/* Driver code*/
int main()
{

	/* Constructed binary tree is
			1
			/ \
		2	 3
		/ \	 /
		4 5 8
	*/
	node *root = new node(1);
	root->left = new node(2);
	root->right = new node(3);
	root->left->left = new node(4);
	root->left->right = new node(5);
	root->right->left = new node(8);
	
	printKDistant(root, 2);
	return 0;
}

// This code is contributed by rathbhupendra
