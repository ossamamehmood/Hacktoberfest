//print topview
// T=O(n) S = O(n)
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

//sabhi vertical lines ke first node ko lenge from left to right

vector<int> topview(node* head){
    vector<int> ans;
    if(head==NULL) return ans;
    map<int , int > m;          //map me line and value of node store karenge 
    queue<pair<node*,int>> q;
    q.push({head,0});
    while(q.size()){
        auto t = q.front();
        q.pop();
        node* temp = t.first;
        int vert=t.second;
        if(m.find(vert)==m.end()) m[vert]=temp->data; //map me phle se key present nahi hai to he insert karenge (to make it the first node of that vertical line);
        if(temp->left) q.push({temp->left,vert-1});
        if(temp->right) q.push({temp->right,vert+1});
    }

    for(auto &i : m) ans.push_back(i.second);
    return ans;

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
    ans=topview(head);
    
        for(int j=0;j<ans.size();j++){
            cout<<ans[j]<<" ";
        }
        cout<<endl;
    
    return 0;
}