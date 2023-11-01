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
    if (root == NULL)
        return 0;

    return max(maxDepth(root->left), maxDepth(root->right)) + 1;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    int depth = maxDepth(root);
    cout << "Maximum depth of the binary tree: " << depth << endl;

    return 0;
}
