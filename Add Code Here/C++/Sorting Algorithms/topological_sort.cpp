#include<bits/stdc++.h>
using namespace std;
#define mx 200005

vector<int>g[mx];
vector<int>ans; //storing topological sorted vertex

int indegree[mx];

/*int visited[mx];
vector<int>rg[mx];
vector<int>s;
void dfs1(int u)
{
    visited[u]=1;
    for(int i=0; i<g[u].size(); i++)
    {
        int v=g[u][i];
        if(visited[v]==0) dfs1(v);
    }
    s.push_back(u);
}
*/
int main()
{
    int n;
    cin>>n; //number of vertex

    int m;
    cin>>m; //number of edges
    while(m--)
    {
        int u,v;
        cin>>u>>v;
        indegree[v]++;
        g[u].push_back(v); //making one directional graph
        //rg[v].push_back(u);
    }
    priority_queue<int, vector<int>, greater<int> >q; //using priority queue to get smallest toposort
    for(int i=1; i<=n; i++)
    {
        if(indegree[i]==0)
        {
            q.push(i); //indegree of any vertex can be root node
        }
    }
    while(!q.empty())
    {
        int u=q.top();

        q.pop();
        ans.push_back(u);
        for(int i=0; i<g[u].size(); i++)
        {
            indegree[g[u][i]]--;
            if(indegree[g[u][i]]==0)
            {
                q.push(g[u][i]); //decreasing indegree
            }
        }
    }



    for(int i=0; i<n; i++)
    {

        cout<<ans[i]<<" ";

    }
    cout<<endl;

}