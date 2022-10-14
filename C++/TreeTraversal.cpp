#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* left,*right;
    Node(int x){
        data=x;
        left=NULL;
        right=NULL;
    }
};
void inorder(Node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void preorder(Node* root){
    if(root==NULL){
        return;
    }
    
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(Node* root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
int height(Node* root){
    if(root==NULL){
        return 0;
    }
    int lh=height(root->left);
    int rh=height(root->right);
    return 1+max(lh,rh);
}
int count(Node* root){
    if(root==NULL){
        return 0;
    }
   
    return 1+count(root->left)+count(root->right);
}
int getmax(Node* root){
    if(root==NULL){
        return INT_MIN;
    }
    return max(root->data,max(getmax(root->left),getmax(root->right)));
}
int main(){
    Node* root=new Node(10);
    Node* temp1=new Node(20);
    Node* temp2=new Node(40);
    Node* temp4=new Node(50);
    root->left=temp1;
    root->right=temp2;
    temp1->left=temp4;
    inorder(root);
    cout<<endl;
    preorder(root);
    cout<<endl;
    postorder(root);
    cout<<endl;
    cout<<height(root);
    cout<<endl;
    cout<<count(root);
    cout<<endl;
    cout<<getmax(root);
}
