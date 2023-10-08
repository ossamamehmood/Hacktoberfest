#include<bits/stdc++.h>
using namespace std;

const int N=1e4+1;
int vis[N];
std::vector<int> graph[N];

void dfs(int starting_node)
{
	cout << starting_node << ' ';
	vis[starting_node] = 1;

	for(auto child:graph[starting_node]) 
		if(!vis[child]) dfs(child);
}


int main()
{
	freopen("in.txt","r", stdin);
	int node,edges; cin>>node>>edges;

	for(int i=0;i<edges;i++)
	{
		int x,y; cin>>x>>y;
		graph[x].push_back(y); graph[y].push_back(x);
	}

	dfs(1);
	
	cout<<endl;
}