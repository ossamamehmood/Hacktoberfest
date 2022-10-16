#include <bits/stdc++.h>

using namespace std;

struct Node
{
	int data;
	struct Node* left;
	struct Node* right;

	Node(int x)
	{
		data = x;
		left = right = NULL;
	}

};
/* 3 STEPS FOR RECURSION
1)DESIGN STEP
2)INDUCTION STEP
3)BASE STEP
*/
int height(Node* root)
{
	if(root == NULL)			//Base Step
		return 0;
	int left_Height = height(root->left);	//Design Step
	int right_Height = height(root->right); //Design Step

	int maxHeight = 1 + max(left_Height, right_Height);	//Induction Step

	return maxHeight;

}
int max(int a, int b)
{
	if(a > b)
		return a;
	else
		return b;
}
void inorder(Node* root)
{
	if(root == NULL)
		return;
	inorder(root->left);
	cout << root->data << "->";
	inorder(root->right);
}
int main()
{
	Node *root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(6);
	root->right->left = new Node(7);
	root->right->right = new Node(5);
	root->left->left->left = new Node(8);
	root->left->left->right = new Node(9);

	inorder(root);

	cout << endl;

	cout << "Height of the Binary Tree is " << height(root) << endl;

	return 0;
}