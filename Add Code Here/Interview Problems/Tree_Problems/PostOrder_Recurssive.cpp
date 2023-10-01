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

// L -> R -> Root 
void PostOrder(Node* root)
{
    if(root)
    {
        PostOrder(root->left);
        PostOrder(root->right);
        cout<<root->data<<" ";
    }
}

int main()
{
    Node *root = NULL;
    
    root = CreateTree(root);

    PostOrder(root);
    return 0;
}