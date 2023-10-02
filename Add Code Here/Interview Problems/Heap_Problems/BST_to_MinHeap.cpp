#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* getNode(int k)
{
    struct Node* newnode = new Node;
    newnode->data = k;

    // set left and right node to null
    newnode->left = NULL;
    newnode->right = NULL;

    // return the node
    return newnode;
}

void InOrder_Traversal(Node* root, vector<int>&v)
{
    if(root == NULL)
    {
        return;
    }

    // traverse the left part
    InOrder_Traversal(root->left, v);

    // insert into the vector
    v.push_back(root->data);

    // traverse the right part
    InOrder_Traversal(root->right, v);
}

void ConvertToMinHeap(Node* root, vector<int> arr, int* i)
{
    if (root == NULL)
    {
        return;
    }
 
    root->data = arr[++*i];
 
    ConvertToMinHeap(root->left, arr, i);
 
    ConvertToMinHeap(root->right, arr, i);
}
 

void Convert_BST_to_MinHeap(struct Node* root)
{
    vector<int>v;
    int i = -1;

    // inorder traversal
    InOrder_Traversal(root, v);

    // convert in the minheap
    ConvertToMinHeap(root, v, &i);
}

void PrintHeap(struct Node* root)
{
    if(root)
    {
        PrintHeap(root->left);
        cout<<root->data<<" ";
        PrintHeap(root->right);        
    }

}

int main()
{
    struct Node* root = getNode(4);
    root->left = getNode(2);
    root->right = getNode(6);
    root->left->left = getNode(1);
    root->left->right = getNode(3);
    root->right->left = getNode(5);
    root->right->right = getNode(7);
    
    PrintHeap(root);
    return 0;
}