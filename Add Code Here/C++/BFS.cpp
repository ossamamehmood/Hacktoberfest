#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void adjacencyList(unordered_map<int,list<int>>&adj,int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void display(unordered_map<int,list<int>>adj){
    for(auto i:adj){
        cout<<i.first<<"->";
        for(auto j:i.second)
            cout<<j<<",";
        cout<<endl;
    }
}

void bfs(unordered_map<int,list<int>>adj,vector<int>&ans,unordered_map<int,bool>&visited,int sourceNode){
    queue<int>q;
    q.push(sourceNode);
    visited[sourceNode]=1;

    while(!q.empty()){
        int front=q.front();
        q.pop();

        ans.push_back(front);

        for(auto i:adj[front]){
            if(!visited[i]){
                q.push(i);
                visited[i]=1;
            }
        }
    }
}

int main(){
    //0 1 1 2 2 3 3 1 3 4 0 4 - 5 6
    //ans 0 1 4 2 3
    unordered_map<int,list<int>>adj;
    vector<int>ans;
    unordered_map<int,bool>visited;
    int edges,vertex,u,v;
    cout<<"Enter no of vertex :";
    cin>>vertex;
    cout<<"Enter no of edges :";
    cin>>edges;

    for(int i=0;i<edges;i++){
        cin>>u>>v;
        adjacencyList(adj,u,v);
    }

    //display(adj);
    for(int i=0;i<vertex;i++){
        if(!visited[i]){
            bfs(adj,ans,visited,i);
        }
    }
    
    for(auto i:ans)
        cout<<i<<" ";

    return 0;
}