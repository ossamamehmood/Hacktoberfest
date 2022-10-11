#include<iostream>

using namespace std;



class node{
    public:
    int data;
    node *left;
    node *right;
    node(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }

};

node* buildTree(node* root){
    int d;
    cin>>d;
    if(d==-1){
        return NULL;
    }
    root=new node(d);
    root->left=buildTree(root->left);
    root->right=buildTree(root->right);
    return root;
}
int main(){
    node* root=NULL;
    root=buildTree(root);      //creating the tree
    return 0;
}