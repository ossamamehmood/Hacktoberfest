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
void PreOrder_Iterative(Node* root)
{
    // Base case
    if(root == NULL)
    {
        return;
    }

    // create empty stack and push root to it
    stack<Node *>s;
    s.push(root);

    /* Pop all items one by one. Do following for every popped item
       a) print it
       b) push its right child
       c) push its left child
    Note that right child is pushed first so that left is processed first */
    while( !s.empty())
    {
        Node *temp = s.top();
        cout<<temp->data<<" ";

        s.pop();

        if(temp ->right)
        {
            s.push(temp->right);
        }

        if(temp ->left)
        {
            s.push(temp->left);
        }
    }
}

int main()
{
    Node *root = NULL;
    
    root = CreateTree(root);

    // preorder traversal
    PreOrder_Iterative(root);
    return 0;
}