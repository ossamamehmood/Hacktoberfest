#include<bits/stdc++.h>
using namespace std;

void traverseTopoSort(vector<int> adj[],vector<int>& vis,stack<int> &st,int node ){
    vis[node]=1;
    for(auto it: adj[node]){
        if(!vis[it]){
            traverseTopoSort(adj,vis,st,it);
        }
    }
    st.push(node);
}

vector<int> topoSort(vector<int> adj[],int n){
    vector<int> vis(n,0);
    stack<int> st;
    for(int i =0;i<n;i++){
        if(!vis[i]){
            traverseTopoSort(adj,vis,st,i);
        }
    }
    vector<int> v;
    while(!st.empty()){
        v.push_back(st.top());
        st.pop();
    }
    return v;
}

int main(){
    int n,m;
    cout<<"Enter the number of Node :-"<<endl;
    cin>>n>>m;
    vector<int> adj[n];
    for(int i =0;i<m;i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
    }

    vector<int> v = topoSort(adj,n);
    for(auto it: v){
        cout<< it<<" ";
    }
    cout<<endl;
}
