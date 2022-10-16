#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left, *right;
};

void Preorder(struct Node *node)
{
    if (node == NULL)
        return;
    cout << node->data << " ";

    Preorder(node->left);

    Preorder(node->right);
}

Node *creat_node(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

int main()
{
    struct Node *root = creat_node(1);
    root->left = creat_node(2);
    root->right = creat_node(3);
    root->left->left = creat_node(4);
    root->left->right = creat_node(5);

    cout << "Pre order traversal of binary tree is \n";
    Preorder(root);

    return 0;
}