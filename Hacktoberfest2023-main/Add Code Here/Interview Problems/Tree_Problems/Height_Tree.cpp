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

int Height(Node *root)
{
    int total_height;
    if(root == NULL)
    {
        return 0;
    }
    else
    {
        int Left = Height(root->left);
        int Right = Height(root->right);

        if(Left > Right)
        {
            total_height = Left;
        }
        else
        {
            total_height = Right;
        }
    }

    return total_height + 1;
}

int main()
{
    // root node
    Node *root = Tree(10);

    // child nodes of the tree
    root->left = Tree(2);
    root->right = Tree(3);
    root->left->left = Tree(7);
    root->left->right = Tree(8);
    root->right->right = Tree(15);
    root->right->left = Tree(12);
    root->right->right->left = Tree(14);

    cout<<"Height of the Tree is "<<Height(root)<<endl;

    return 0;
}
