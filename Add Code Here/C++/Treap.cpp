#include <iostream>
#include <cstdlib>
#include <ctime>

struct Node {
    int key;
    int priority;
    Node* left;
    Node* right;
};

Node* createNode(int key) {
    Node* newNode = new Node;
    newNode->key = key;
    newNode->priority = rand();
    newNode->left = newNode->right = nullptr;
    return newNode;
}

Node* rotateRight(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    return x;
}

Node* rotateLeft(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    return y;
}

Node* insert(Node* root, int key) {
    if (!root) return createNode(key);

    if (key <= root->key) {
        root->left = insert(root->left, key);
        if (root->left->priority > root->priority)
            root = rotateRight(root);
    } else {
        root->right = insert(root->right, key);
        if (root->right->priority > root->priority)
            root = rotateLeft(root);
    }

    return root;
}

void inorderTraversal(Node* root) {
    if (root) {
        inorderTraversal(root->left);
        std::cout << "(" << root->key << ", " << root->priority << ") ";
        inorderTraversal(root->right);
    }
}

int main() {
    Node* root = nullptr;
    srand(time(nullptr));

    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    std::cout << "Inorder traversal of the treap:" << std::endl;
    inorderTraversal(root);
    std::cout << std::endl;

    return 0;
}
