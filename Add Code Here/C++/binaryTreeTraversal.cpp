#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;
    node( int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};
void traversal(node* root,vector<int>& pre,vector<int>& in,vector<int>& post){
    if(root==NULL) return;
    stack<pair<node*,int>> st;
    st.push({root,1});
    while(!st.empty()){
        auto it=st.top();
        st.pop();
        if(it.second==1){
            pre.push_back(it.first->data);
            it.second++;
            st.push(it);
            if(it.first->left!=NULL) st.push({it.first->left,1});
        }
        else if(it.second==2){
            in.push_back(it.first->data);
            it.second++;
            st.push(it);
            if(it.first->right!=NULL) st.push({it.first->right,1});
            
        }
        else{
            post.push_back(it.first->data);
        }
    }
}
int main(){
    node* root=new node(1);
    root->left=new node(2);
    root->right=new node(7);
    root->left->left=new node(3);
    root->left->left->left=new node(4);
     root->left->left->right=new node(5);
     root->right->left=new node(6);
     root->right->right=new node(8);
     vector<int> pre,in,post;
     traversal(root,pre,in,post);
     for(auto it:pre){
         cout<<it<<" ";
     }
     cout<<endl;
     for(auto it:in){
         cout<<it<<" ";
     }
     cout<<endl;
     for(auto it:post){
         cout<<it<<" ";
     }
}