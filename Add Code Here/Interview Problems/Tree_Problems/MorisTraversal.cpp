/*

                10
              /    \
             2      3
            / \    / \
           7   8  12  15
                     /
                    14

O/P: 10 2 7 14
*/

#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// create the binary tree
struct Node* Tree(int value)
{
    // initialize the memory for newnode
    Node* Binary = (struct Node *)malloc(sizeof(struct Node));

    Binary->data = value;
    // left and right subtree should be null
    Binary->left = NULL;
    Binary->right = NULL;

    return(Binary);
}

void MorisTraversal(Node *root)
{
    Node * current, *pre;

    // base condition
    if(root == NULL)
    {
        return;
    }

    // make current points to root
    current = root;

    while(current != NULL)
    {
        if(current->left == NULL)
        {
            cout<<current->data<<" ";
            current = current->right;
        }
        else
        {  
            pre = current->left;

            while(pre->right != NULL && pre->right != current)
                pre = pre->right;

            if(pre->right == NULL)
            {
                pre->right = current;
                current = current ->left;
            }
            else
            {
                pre->right = NULL;
                cout<<current->data<<" ";
                current = current->right;
            }
        }
    }
}


void InOrderTraversal(Node *root)
{
    if(root)
    {
        InOrderTraversal(root->left);
        cout<<root->data<<" ";
        InOrderTraversal(root->right);
    }
}

int main()
{
    // root node
    Node *root = Tree(10); 

    root->left = Tree(2);
    root->right = Tree(3);
    root->left->left = Tree(7);
    root->left->right = Tree(8);
    root->right->right = Tree(15); 
    root->right->left = Tree(12);
    root->right->right->left = Tree(14);

    MorisTraversal(root);
    cout<<endl;
    InOrderTraversal(root);   
    return 0;
}