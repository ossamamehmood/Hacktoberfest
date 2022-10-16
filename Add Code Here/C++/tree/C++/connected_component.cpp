// Dfs using adj as vector of vector

#include <bits/stdc++.h>

#define ll long long
#define vi vector<int>
#define vb vector<bool>
#define vil vector<int64_t>
#define mapii map<int,int>
#define mapci map<char,int>
#define mapcc map<char,char>
#define mod 1e9+7
#define INF 1e18

using namespace std;
vector<vector<int>> adj;
vector<bool> vis;	
void cc(int node)
{	
	vis[node]=true;
	for(int child:adj[node])
	{
		if(!vis[child])
			cc(child);
	}
}
int main(void)
{

	ll a,b,n,m; //n=nodes m=edges
	int count=0;
	cin>>n>>m; //input number of nodes and edges
	adj=vector<vector<int>>(n,vector<int>());  //initializing adjacency list
	vis=vector<bool>(n,false);
	for(int i=1;i<=m;i++)
	{
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for(int i=0;i<n;i++)
	{
		if(vis[i]==false)
		{
			cc(i),
			count++;
		}
	}
	cout<<"Connected components:"<<count<<endl;
	return 0;
}


	