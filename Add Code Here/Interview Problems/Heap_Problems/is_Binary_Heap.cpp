#include<bits/stdc++.h>
using namespace std;

struct Node {

    int key;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int k)
{
    struct Node* node = new Node;
    node->key = k;
    node->right = node->left = NULL;
    return node;
}

int CountNodes(struct Node* root)
{
    if(root == NULL)
    {
        return 0;
    }

    int Ans = 1 + CountNodes(root->left) + CountNodes(root->right);
    return Ans;
}

bool isCBT(struct Node* root, int i, int N)
{
    if(root == NULL)
    {
        return true;
    }

    if(i >= N)
    {
        return false;
    }
    else
    {
        bool Left = isCBT(root->left, 2*i+1, N);
        bool Right = isCBT(root->right, 2*i+2, N);

        return (Left && Right);
    }
}

bool isHeapProperty(struct Node* root)
{
    if(root == NULL)
    {
        return true;
    }

    if(root->left == NULL && root->right == NULL)
    {
        return true;
    }

    if(root->right == NULL)
    {
        return (root->key > root->left->key);
    }
    else
    {
        bool Left = isHeapProperty(root->left);
        bool Right = isHeapProperty(root->right);

        return (Left && Right && (root->key > root->left->key && root->key > root->right->key));
    }
}

bool isHeap(struct Node* root)
{
    if(root == NULL)
    {
        return true;
    }

    int i = 0;
    int N = CountNodes(root);

    if(isCBT(root, i, N) && isHeapProperty(root))
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    struct Node* root = NULL;
    root = newNode(10);
    root->left = newNode(9);
    root->right = newNode(8);
    root->left->left = newNode(7);
    root->left->right = newNode(6);
    root->right->left = newNode(5);
    root->right->right = newNode(4);
    root->left->left->left = newNode(3);
    root->left->left->right = newNode(2);
    root->left->right->left = newNode(1);

    // Function call
    if (isHeap(root))
        cout << "Given binary tree is a Heap\n";
    else
        cout << "Given binary tree is not a Heap\n";

    return 0;
}