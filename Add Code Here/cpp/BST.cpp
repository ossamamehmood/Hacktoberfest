#include <iostream>
using namespace std;

class BST {
	int data;
	BST *left, *right;

public:
	BST();
	BST(int);
	BST* Insert(BST*, int);
	void Inorder(BST*);
};
BST ::BST()
	: data(0)
	, left(NULL)
	, right(NULL)
{
}
BST ::BST(int value)
{
	data = value;
	left = right = NULL;
}
BST* BST ::Insert(BST* root, int value)
{
	if (!root) {
		return new BST(value);
	}

	if (value > root->data) {
		root->right = Insert(root->right, value);
	}
	else if (value < root->data){
		root->left = Insert(root->left, value);
	}

	return root;
}
void BST ::Inorder(BST* root)
{
	if (!root) {
		return;
	}
	Inorder(root->left);
	cout << root->data << endl;
	Inorder(root->right);
}

int main()
{
	BST b, *root = NULL;
	root = b.Insert(root, 50);
	b.Insert(root, 30);
	b.Insert(root, 20);
	b.Insert(root, 40);
	b.Insert(root, 70);
	b.Insert(root, 60);
	b.Insert(root, 80);

	b.Inorder(root);
	return 0;
}
