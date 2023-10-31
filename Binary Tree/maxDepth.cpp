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

int maxDepth(Node *root)
{
    if(root==NULL)
    return 0;
    
    return max(maxDepth(root->left), maxDepth(root->right)) + 1;
}

int main()
{

    return 0;
}