#include<bits/stdc++.h>
using namespace std;

void dfs(vector<int> adj[],vector<int>& low,vector<int>& disc, vector<int>& instack, stack<int>& s, vector<vector<int>>& ans, int u)
{
    static int t=0;
    static int count=0;
    disc[u]=t;
    low[u]=t;
    t++;
    instack[u]=1;
    s.push(u);

    for(int v:adj[u])
    {
        if(disc[v]==-1)
        {
            dfs(adj,low,disc,instack,s,ans,v);
            low[u] = min(low[u],low[v]);
        }
        else if(instack[v])
        low[u] = min(low[u],disc[v]);
    }

    if(low[u]==disc[u])
    {
        ans.resize(count+1);
        cout<<count<<endl;
        while(s.top()!=u)
        {
            instack[s.top()]=0;
            cout<<s.top();
            s.pop();
        }
        cout<<s.top()<<endl;
        instack[s.top()]=0;
        s.pop();
        count++;
    }
}

    void tarjans(int V, vector<int> adj[])
    {
        vector<vector<int>> ans;
        vector<int> low(V,-1),disc(V,-1),instack(V,0);
        stack<int> s;

        for(int i=0; i<V; i++)
        {
            if(disc[i]==-1)
            dfs(adj,low,disc,instack,s,ans,i);
        }
    }

int main()
{
    int V,E;
    cin>>V>>E;

    vector<int> adj[V];

    for(int i=0; i<E; i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }

    tarjans(V,adj);
}
