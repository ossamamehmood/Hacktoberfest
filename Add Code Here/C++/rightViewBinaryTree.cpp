#include<iostream>
#include<bits/stdc++.h>
using namespace std;
//structure for tree node
struct Node{
  int data;
  Node* left;
  Node* right;
};
//function to create node
Node* create(int x){
  Node* temp=(Node*)malloc(sizeof(Node));
  temp->data=x;
  temp->left=NULL;
  temp->right=NULL;
  return temp;
}
//function to print the right view 
void rightView(Node *root)
{
   queue<Node*>q;
   q.push(root);
   q.push(NULL);
   while(!q.empty()){
       Node* temp=q.front();
       q.pop();
       if(temp==NULL){
           q.push(NULL);
           if(q.front()==NULL)return;
           continue;
       }
       if(q.front()==NULL)cout<<temp->data<<" ";
       if(temp->left!=NULL)q.push(temp->left);
       if(temp->right!=NULL)q.push(temp->right);
   }
}
int main(){
  Node* root=create(1);
  root->left=create(2);
  root->left->right=create(3);
  root->left->right->left=create(4);
  root->left->right->right=create(5);
  root->right=create(6);
  root->right->left=create(7);
  root->right->left->right=create(8);
  root->right->right=create(9);
  cout<<"right view of the given binary tree is: ";
  rightView(root);
  return 0;
}
