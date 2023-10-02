#include<bits/stdc++.h>
using namespace std;

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

// L -> Root -> R
void InOrder(Node *root)
{
    stack<Node *>s;
    Node *ptr = root;
    
    while(ptr != NULL || s.empty() == false)
    {
        // reach the left node of the ptr node
        while(ptr != NULL)
        {
            // place the pointer for traversing in left subtree
            s.push(ptr);
            ptr = ptr->left;
        }

        ptr = s.top();
        s.pop();
        cout<<ptr->data<<" ";
        
        // we have visited the node and its left subtree
        // now we have visit right subtree
        ptr = ptr->right;
    }
}

int main()
{
    Node *root = NULL;
    
    root = CreateTree(root);

    InOrder(root);
    return 0;
}