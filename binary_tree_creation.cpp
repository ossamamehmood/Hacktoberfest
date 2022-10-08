#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
//   this is the structure of the node
    int data=0;
    Node*left=NULL;
    Node*right=NULL;
    Node (int key){
        data=key;
    }

};


// This is the insert function  
Node * insert(Node * root,int data){
 if(root==0){
     Node * p=new Node( data);
     return p;
 }
 else{ 
     if (root->data>data){
         root->left=insert(root->left,data);

     }
     else{
         root->right=insert(root->right,data);
     }
 return root;}
 }



// This is the inorder Traversal    function


 void INORDER(Node* root){
     if (root==0){
         return ;
     }
     else{
         INORDER(root->left);
         cout<<root->data<<" ";
         INORDER(root->right);
     }}

// The below function calculates the Height if the  tree.

int Height(Node * root){
    if(root==0){
        return 0;
    }
    else{
        int leftl=Height(root->left);
        int rightl =Height(root->right);
        return (max(rightl+1,leftl+1)); 
    }
}

}
int main ()
{
    Node * root=0;
    root=insert(root,6);
    insert(root,67);
    insert(root,90);
    insert(root,103);
    cout<< Height(root)<<" "<<endl;
    INORDER(root);

return 0;
}
