#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

int minDepth(Node *root)
{
    if(root==NULL)
    return 0;

    if(root->left==NULL)
    return minDepth(root->right) + 1;

    if(root->right==NULL)
    return minDepth(root->left) + 1;

    return min(minDepth(root->left), minDepth(root->right)) + 1;
}

int main()
{

    return 0;
}