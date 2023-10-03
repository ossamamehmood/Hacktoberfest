#include<bits/stdc++.h>
using namespace std;

/*
given tree follow the below paths



*/

struct Node
{
    struct Node *left;
    int data;
    struct Node *right;
};

struct Node *BinaryTree(int value)
{
    // memory initialization
    struct Node* Newnode =(struct Node*)malloc(sizeof(struct Node));

    Newnode->data = value;

    // left and right subtree
    Newnode->left = NULL;
    Newnode->right = NULL;

    return(Newnode);
}

int print_All_Ancestors(struct Node *root, int node)
{
    // base case
    if(root == NULL)
    {
        return 0;
    }

    if(root->data == node)
    {
        // it prints the target node as well
        cout<<root->data<<" ";
        return 1; 
    }

    if(print_All_Ancestors(root->left, node) || print_All_Ancestors(root->right, node))
    {
        // it will print all the ancestors of the target node
        cout<<root->data<<" ";
        return 1;        
    }
    return 0;
}

int main()
{
    // root node
    Node *root = BinaryTree(10); 

    root->left = BinaryTree(2);
    root->right = BinaryTree(3);
    root->left->left = BinaryTree(7);
    root->left->right = BinaryTree(8);
    root->right->right = BinaryTree(15); 
    root->right->left = BinaryTree(12);
    root->right->right->left = BinaryTree(14);

    int arr[1000];
    Node *node = BinaryTree(14);
    print_All_Ancestors(root, 14);

    return 0;
}