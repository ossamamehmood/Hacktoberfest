#include<bits/stdc++.h>
using namespace std;

/*
            10
          /   \
        8      2
      /  \    /
    3     5  2

    PreOrder - 10 8 3 5 2 2
*/

class Node
{
    public:
    int data;
    Node *left;
    Node *right;

    Node(int x)
    {
        this->data = x;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *CreateTree(Node *root)
{
    int data;
    cout<<"Enter the Data in Root Node : ";
    cin>>data;

    root = new Node(data);

    if(data == -1)
    {
        return NULL;
    }

    cout<<"Enter the Data for Insert in Left : "<<data<<endl;
    root->left = CreateTree(root->left);

    cout<<"Enter the Data for Insert in Right : "<<data<<endl;
    root->right = CreateTree(root->right);

    return root;
}

// Root -> L -> R
void PreOrder(Node* root)
{
    if(root)
    {
        cout<<root->data<<" ";
        PreOrder(root->left);
        PreOrder(root->right);
    }
}

int main()
{
    Node *root = NULL;
    
    root = CreateTree(root);

    // preorder traversal
    PreOrder(root);
    return 0;
}