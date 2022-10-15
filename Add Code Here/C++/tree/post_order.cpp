#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left, *right;
};

void Postorder(struct Node *node)
{
    if (node == NULL)
        return;

    Postorder(node->left);

    Postorder(node->right);
    cout << node->data << " ";
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
    Postorder(root);

    return 0;
}