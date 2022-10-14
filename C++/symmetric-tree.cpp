#include<iostream>
#include<algorithm>
using namespace std;
struct Node{
    int item;
    struct Node *left,*right;
};

// helper function to check if tree is symmetric
bool sym(Node* l,Node* r)
{
    if(l==nullptr&&r==nullptr) return true;
    if(l==nullptr||r==nullptr) return false;
    if(l->item!=r->item) return false;
    // left subtree's left child,right subtree's right child
    // left subtree's right child,right subtree's left child
    return (sym(l->left,r->right)&&sym(l->right,r->left));
}

// function to check if tree is symmetric
bool isSymmetric(Node* root) 
{
    return(root==nullptr||sym(root->left,root->right));
}


// creating node
struct Node *createNode(int value)
{
    struct Node *new_node=new Node();
    new_node->item=value;
    new_node->left=NULL;
    new_node->right=NULL;
    return new_node;
}
// left subtree
struct Node *instleft(struct Node *root,int value)
{
    root->left=createNode(value);
    return root->left;
}
// right subtree
struct Node *instright(struct Node *root,int value)
{
    root->right=createNode(value);
    return root->right;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    struct Node *root=createNode(1);
    instleft(root,12);
    instright(root,12);
    instleft(root->left,5);
    instright(root->right,5);
    if(isSymmetric(root)) cout<<"Symmetric\n";
    else cout<<"Not symmetric\n";
    return 0;
}
