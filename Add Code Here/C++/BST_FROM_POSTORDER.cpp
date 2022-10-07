/*
    problem Statement:
    - Create a BST from the preorder traversal of a binary tree

    input :
    - 1st line will contain "t" test cases
    - Then immideate to above line contains an integer "n" and an array of array size n.

    output
    - single line containing preorder traversal of bst
*/

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

Node *constructTree(int[], int);

void printInorder(Node *node)
{
    if (node == NULL)
        return;
    printInorder(node->left);
    printf("%d ", node->data);
    printInorder(node->right);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        int post[n];
        for (int i = 0; i < n; i++)
            scanf("%d", &post[i]);

        Node *root = constructTree(post, n);

        printInorder(root);
        printf("\n");
    }
    return 0;
}
// } Driver Code Ends

/*struct Node
{
    int data;
    Node *left, *right;
};*/

Node *convert(int post[], int left, int right, int &i, int size)
{
    if (left > right)
        return nullptr;
    if (i == size)
        return nullptr;
    if (post[i] < left or post[i] > right)
        return nullptr;

    int x = post[i];
    Node *root = new Node(post[i--]);
    root->right = convert(post, x + 1, right, i, size);
    root->left = convert(post, left, x - 1, i, size);
    return root;
}
Node *constructTree(int post[], int size)
{

    int i = size - 1;
    return convert(post, INT_MIN, INT_MAX, i, size);
}