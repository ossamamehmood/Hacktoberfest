#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct node {
    int key;
    struct node* left;
    struct node* right;
    int height;
};

struct node* createNode(int key) {
    struct node* Node = (struct node*)malloc(sizeof(struct node));
    Node->key = key;
    Node->left = NULL;
    Node->right = NULL;
    Node->height = 1;
    return Node;
}

int Maxi(int a, int b) {
    return a > b ? a : b;
}

int getHeight(struct node* n) {
    if (n == NULL)
        return 0;
    return n->height; 
}

int getBalanceFactor(struct node* n) {
    if (n == NULL) {
        return 0;
    }
    return getHeight(n->left) - getHeight(n->right);
}

struct node* RightRotate(struct node* y) {
    struct node* x = y->left;

    struct node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = Maxi(getHeight(y->right), getHeight(y->left)) + 1;
    x->height = Maxi(getHeight(x->right), getHeight(x->left)) + 1;

    return x;
}

struct node* leftRotate(struct node* x) {
    struct node* y = x->right;
    struct node* T2 = y->left;

    y->left = x;
    x->right = T2;

    y->height = Maxi(getHeight(y->right), getHeight(y->left)) + 1;
    x->height = Maxi(getHeight(x->right), getHeight(x->left)) + 1;

    return y;  
}

struct node* insert(struct node* Node, int key) {
    if (Node == NULL)
        return createNode(key);

    if (key < Node->key)
        Node->left = insert(Node->left, key);
    else if (key > Node->key)
        Node->right = insert(Node->right, key);

    Node->height = 1 + Maxi(getHeight(Node->left), getHeight(Node->right));
    int bf = getBalanceFactor(Node);

    if (bf > 1 && key < Node->left->key)
        return RightRotate(Node);

    if (bf < -1 && key > Node->right->key)
        return leftRotate(Node);

    if (bf > 1 && key > Node->left->key) {
        Node->left = leftRotate(Node->left);
        return RightRotate(Node);
    }

    if (bf < -1 && key < Node->right->key) {
        Node->right = RightRotate(Node->right);
        return leftRotate(Node);
    }
    return Node;
}

void preorder(struct node* root) {
    if (root != NULL) {
        printf("Node Key: %d, Balance Factor: %d\n", root->key, getBalanceFactor(root));
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("Node Key: %d, Balance Factor: %d\n", root->key, getBalanceFactor(root));
    }
}

void inorder(struct node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("Node Key: %d, Balance Factor: %d\n", root->key, getBalanceFactor(root));
        inorder(root->right);
    }
}

int main() {
    struct node* root = NULL;
    int numNodes;
    printf("Enter the number of nodes: ");
    scanf("%d", &numNodes);

    for (int i = 0; i < numNodes; i++) {
        int key;
        printf("Enter key for node %d: ", i + 1);
        scanf("%d", &key);
        root = insert(root, key);
    }

    printf("Preorder traversal:\n");
    preorder(root);
    printf("\nPostorder traversal:\n");
    postorder(root);
    printf("\nInorder traversal:\n");
    inorder(root);

    return 0;
}
