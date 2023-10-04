/*

                10
              /    \
             2      3
            / \    / \
           7   8  12  15
                     /
                    14
    O/P: 10 7 8 12 15
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

Node* DeepestNode(Node *root)
{
    struct Node * temp;
    if(root == NULL)
    {
        return 0;
    }

    queue<Node *>q;
    q.push(root);

    while(!q.empty())
    {
        temp = q.front();
        q.pop();

        if(root->left)
        {
            q.push(root->left);
        }

        if(root->right)
        {
            q.push(root->right);
        }
    }
    q.pop();
    return temp;
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

    
    cout<<DeepestNode(root);

    return 0;
}