// Creation of Binary Tree

// Create the Following Binary Tree and find Inorder traversal
/*

                   1 
                  /  \
                 /    \
                3      5
               / \    / \ 
              /   \  /   \
             7    11 17   NULL(-1)

    InOrder Traversal - 7 3 11 1 17 5

*/

#include<bits/stdc++.h>
using namespace std;

//create the class
class Node
{
    public:
        int data;
        Node *left;
        Node *right;

    Node(int d)
    {
        this ->data = d;
        this ->left = NULL;
        this ->right = NULL;
    }
};

// create the binary tree
Node *CreateTree(Node *root)
{
    int data;

    cout<<"Enter the Root Node : "<<endl;
    cin>>data;

    // initialize the memory for rroot node
    root = new Node(data);

    // if node 
    if(data == -1)
    {
        return NULL;
    }

    cout<<"Enter Data for Insert In Left Node of "<<data<<endl;
    root->left = CreateTree(root->left);    // recursive statement

    cout<<"Enter Data for Insert In Right Node of "<<data<<endl;
    root->right = CreateTree(root->right);   // recursive statement

    return root;
}

// Inorder traversal
// Left -> Root Node -> Right

void InOrder(Node *root)
{
    if(root)
    {
        InOrder(root->left);
        cout<<root->data<<" ";
        InOrder(root->right);
    }
}

int main()
{
    Node *root = NULL;

    // creating the tree
    root = CreateTree(root);

    InOrder(root);
    return 0;
}