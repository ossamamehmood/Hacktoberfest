#include <bits/stdc++.h>
using namespace std;

//SINGLE BST NODE STRUCT
struct node {
	int data;
	node* left;
	node* right;

	node(int val) {
	data=val;
	left=NULL;
	right=NULL;
  }
};

//CREAT/ADD BST NODE FUNCTION
node* addBST(node* root, int val) {
	if (root==NULL) {
		return new node(val);
	}
	else if (val<root->data) {
		root->left=addBST(root->left, val);
	}
	else {
		root->right=addBST(root->right, val);
	}
	return root;
}

//FUNCTION FOR INORDER TRAVERSAL
void Inorder(node* root) {
	if (root==NULL) {
        return;
    }
    Inorder(root->left);
    cout << root->data << endl;
    Inorder(root->right);
}

//DRIVER CODE
int main() {
	node* root=NULL;
	root=addBST(root, 1);
	for (int i=1; i<7; i++) {
		addBST(root, 2*i);
	}
	Inorder(root);
	return 0;
}
