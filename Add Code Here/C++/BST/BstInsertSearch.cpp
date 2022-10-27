#include<bits/stdc++.h>
#include<iostream>
using namespace std;

struct BstNode
{
    int data;
    BstNode* left;
    BstNode* right;
};

BstNode* GetNewNode(int data)//function to create a new node 
{
    BstNode* NewNode=new BstNode();
    NewNode -> data=data;
    NewNode -> left=NewNode -> right=NULL;
}

BstNode* InsertNode(BstNode* root, int data)
{
    if(root==NULL)
    {root=GetNewNode(data);
     return root;}
    else if(data<=root->data)
    {root->left=InsertNode(root->left,data);}
    else
    {root->right=InsertNode(root->right,data);}
    return root;
}

bool Search(BstNode* root,int data)
{
    if(root==NULL)
    return false;
    else if(root->data==data)
    return true;
    else if(data<=root->data)
    return Search(root->left,data);
    else
    return Search(root->right,data);
}

int main()
{
    int data;
    BstNode* root=NULL;//creating empty tree
    cout<<"\nEnter data to enter in bst root"<<endl;
    cin>>data;
    InsertNode(root,data);
    InsertNode(root,15);
    InsertNode(root,10);
    InsertNode(root,20);

}

