#include <bits/stdc++.h>
using namespace std;
 
struct Node {
    Node* left;
    Node* right;
    int hd;
    int data;
};
 
Node* newNode(int key)
{
    Node* node = new Node();
    node->left = node->right = NULL;
    node->data = key;
    return node;
}
void topview(Node* root)
{
    if (root == NULL)
        return;
    queue<Node*> q;
    map<int, int> m;
    int hd = 0;
    root->hd = hd;
    q.push(root);
    cout << "The top view of the tree is : \n";
    while (q.size()) {
        hd = root->hd;
        if (m.count(hd) == 0)
            m[hd] = root->data;
        if (root->left) {
            root->left->hd = hd - 1;
            q.push(root->left);
        }
        if (root->right) {
            root->right->hd = hd + 1;
            q.push(root->right);
        }
        q.pop();
        root = q.front();
    }
 
    for (auto i = m.begin(); i != m.end(); i++) {
        cout << i->second << " ";
    }
}
 
int main()
{
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->right = newNode(4);
    root->left->right->right = newNode(5);
    root->left->right->right->right = newNode(6);
    cout << "Following are nodes in top view of Binary "
            "Tree\n";
    topview(root);
    return 0;
}
