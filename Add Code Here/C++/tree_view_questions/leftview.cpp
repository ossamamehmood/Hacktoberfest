//print leftview
// T=O(n) S = O(h)
#include<bits/stdc++.h>
using namespace std ;

struct node {
    int data;
    node * left,*right;
    node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

node* insertion(node*  head, int val){
    if(head==NULL){
        return new node(val);
    }
    if(val < head->data) {
        head->left= insertion(head->left,val);
    }else{
        head->right=insertion(head->right,val);
    }
    return head;
}

void leftview(node * head,int level ,vector<int> &ans){
    
    if(head==NULL) return ;

    if(level==ans.size()) ans.push_back(head->data);    //intialy level is 0 , hum phle left side ja rahe hai and if level becomes equal to vector ka size than use data ko insert kr rahe hai . so jo data left ke baad us level pe milega wo insert nahi hoga because ans.size increase ho gaya hoga
    leftview(head->left,level+1,ans);
    leftview(head->right,level+1,ans);
    return;
}

void left(node * head,int level ,vector<int> &ans){
    
    if(head==NULL) return ;

    queue<pair<node*,int>> q;
    q.push({head,level});

    while(q.size()){
        auto temp = q.front();
        q.pop();
        auto mynode=temp.first;
        int l= temp.second;

        if(ans.size()==l)ans.push_back(mynode->data);
        if(mynode->left) q.push({mynode->left,l+1});
        if(mynode->right) q.push({mynode->right,l+1});
    }   
    return ;
}

int main(){
    node* head=NULL;
    
    head=insertion(head,9);
    head=insertion(head,6);
    head=insertion(head,19);
    head=insertion(head,2);
    head=insertion(head,8);
    head=insertion(head,5);
    head=insertion(head,3);
    head=insertion(head,13);
    head=insertion(head,25);
    head=insertion(head,11);
    head=insertion(head,10);
    head=insertion(head,12);
    
    vector<int> ans;
    leftview(head,0,ans);
    
        for(int j=0;j<ans.size();j++){
            cout<<ans[j]<<" ";
        }
        cout<<endl;

    left(head,0,ans);
    for(int j=0;j<ans.size();j++){
            cout<<ans[j]<<" ";
        }
        cout<<endl;
    
    return 0;
}