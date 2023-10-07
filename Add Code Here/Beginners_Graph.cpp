#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+1;
/*
//int g[N][N];
//vector<pair<int,int>> g[N];
//ector<int>g[N];
//bool vis[N];
	
void dfs(int v){
	
	cout<<v<<"\n";
	vis[v]=true;
	
	for(int i=0;i<g[v].size();i++){
		if(!vis[g[v][i]])
			dfs[g[v][i]];
	}

	-----------------------------------------------------------------------------------------------------------
unordered_map<int,vector<int>> g;
unordered_map<int,bool>vis;

void dfs(int v){
	
	cout<<v<<" ";
	vis[v]=true;

	for(int i:g[v])
	    if(!vis[i])
	        dfs(i);
	
}

int main(){
	
    g[1]={3,5};
    g[2]={3,6};
    g[3]={1,2,4,5,6};
    g[4]={3,6};
    g[5]={1,3,6};
    g[6]={2,3,4,6};

    dfs(1);
}
-----------------------------------------------------------------------------------------------------------
for connected component
 for(int i=1;i<=n;i++){
        if(!vis[i])
        {
            dfs(i);
            ans++;
        }
    }
    cout<<"Connected componants "<<ans;
    
    bool iscycle(int v,int p){
    
    vis[v]=true;
    bool isloop = false;
    for(int i:g[v]){
        
        if(vis[i]&&i==p) continue;
        
        if(vis[i]) return true;
        
        isloop |= dfs(i,v);
        
    }
    
    return isloop;
    
}

// Tree height and depth using dfs-----------------------------------------------------------------------------------------------------------
int depth[N],height[N];

void dfs(int v,int p=0){
	
	for(int i:g[v]) {
	    if(i==p) continue;
	        depth[i]=depth[v]+1;
	        dfs(i,v);
	        height[v]=max(height[v],height[i]+1);	}
}

// Given q query in each query given v print subtree sum of V and Number of even numbers in subtree of V-----------------------------------------------------------------------------------------------------------
int subtree_sum[N],even_count[N];

void dfs(int v,int p=0){
	
	if(v%2==0) even_count[v]++;

	subtree_sum[v] += v;
	
	for(int i:g[v]){
	    
	    if(i==p) continue;
	    
	        dfs(i,v);
	        
	        subtree_sum[v] += subtree_sum[i];
	        even_count[v] += even_count[i];
	}
	
}
// max diameter or width in tree-----------------------------------------------------------------------------------------------------------

int d[N];
void dfs(int v,int p=-1){
	
	for(int i:g[v])
	    if(i==p) continue;
	        d[i]=d[v]+1;
	        dfs(i,v);	}
}

int main(){
	
	int n; cin>>n;
	
	for(int i=0;i<n-1;i++){
	    int x,y; cin>>x>>y;
	    g[x].push_back(y);
	    g[y].push_back(x);
	}
	dfs(1);
   
   int mxd=-1,mxnd;
   
    for(int i=0;i<n;i++){
        if(mxd<d[i]){
            mxd = d[i];
            mxnd = i;
        }
        d[i]=0;
    }
   
   dfs(mxnd);
   
   for(int i=0;i<n;i++){
        if(mxd<d[i]){
            mxd = d[i];
            mxnd = i;
        }
        d[i]=0;
    }
    
    cout<<"Max Diameter "<<mxd;
   
   // LCA in tree-----------------------------------------------------------------------------------------------------------
   const int N = 1e3+10;
unordered_map<int,vector<int>> g;
unordered_map<int,bool>vis;

int pr[N];

void dfs(int v,int p=-1){
	
	for(int i:g[v]){
	    
	    pr[v]=p;
	    if(i==p) continue;
	        dfs(i,v);
	        
	}
	
}

vector<int> path(int v)
{
    vector<int>ans;
    
    while(v!=-1){
        ans.push_back(v);
        v = pr[v];
    }
    
    reverse(ans.begin(),ans.end());
    return ans;
    
}

int main(){
	
	int n; cin>>n;
	
	for(int i=0;i<n-1;i++){
	    int x,y; cin>>x>>y;
	    g[x].push_back(y);
	    g[y].push_back(x);
	}
	
	dfs(1);
	
    int x,y; cin>>x>>y;
    vector<int>pathx = path(x);
    vector<int>pathy = path(y);
    
    int mnl = min(pathx.size(),pathy.size());
    int LCA=-1;
    
    for(int i=0;i<mnl;i++){
        if(pathx[i]==pathy[i])
            LCA=pathy[i];
        else break;
    }
    cout<<"LCA is : "<<LCA;
   
}
}
   
// After delete edge fing multiplication of sum of two subtrees after deleteing edge-----------------------------------------------------------------------------------------------------------

int st_s[N],val[ ]={10,5,12,6};

void dfs(int v,int p=0){
	
	st_s += val[v];
	for(int i:g[v]){
	    
	    if(i==p) continue;
	        dfs(i,v);
	        st_s[v]+=st_s[i];
	        
	}
	
}

int main(){
	
	int n; cin>>n;
	
	for(int i=0;i<n-1;i++){
	    int x,y; cin>>x>>y;
	    g[x].push_back(y);
	    g[y].push_back(x);
	}
	dfs(1);
	long long ans=0,p1,p2;
	
	for(int i=2;i<=n;i++){
	    p1 = st_s[i];
	    p2 = st_s[1]-p1;
	    ans = max(ans,p1*p2);
	}
	
	cout<<ans; 
    
	
}  

void bfs(int v){

BFS -----------------------------------------------------------------------------------------------------------
int level[N];

void bfs(int s){
    
    queue<int>q;
    q.push(s);
    vis[s]=true;
    
    while(!q.empty()){
        int c = q.front();
        q.pop();
        cout<<c<<" ";
        for(auto i:g[c])
            if(!vis[i]){
                q.push(i);
                vis[i]=true;
                level[i]=level[c]+1;
            }
                
        
    }
    
}
-----------------------------------------------------------------------------------------------------
In chess bourd of 8X8 given starting position a1 and destination position h8 fing how many minimum jump require to reach destination 
with hourse

int vis[8][8];
int level[8][8];

int getx(string s){ return s[0]-'a'; }
int gety(string s){ return s[1]-'1'; }

vector<pair<int,int>> mov={
    {1,2},{-1,2},{-1,-2},{1,-2},
    {-2,-1},{-2,1},{2,1},{2,-1}
};

bool isvalid(int x,int y){
    return (x>=0 && y>=0 && x<8 && y<8);    
}

int bfs(string s,string d){
    
   int sx = getx(s),sy = gety(s);
   int dx = getx(d),dy = gety(d);
   
   queue<pair<int,int>> q;
   q.push({sx,sy});
   vis[sx][sy]=1;
   
   while(!q.empty()){
       pair<int,int> v = q.front();
       int x = v.first , y = v.second;
       q.pop();
       
       for(auto i:mov){
           int cx = i.first+x;
           int cy = i.second+y;
           
           if(!isvalid(cx,cy)) continue;
           if(!vis[cx][cy]){
               q.push({cx,cy});
               level[cx][cy]=level[x][y]+1;
               vis[cx][cy]=1;
           }
           
       }
       
   }
    return level[dx][dy];
}

void reset(){
    
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            vis[i][j]=0;
            level[i][j]=0;
        }
    }
    
}

int main(){
	
	int t; cin>>t;
	
	while(t--){
	    reset();
	    string s1,s2; cin>>s1>>s2;
	    cout<<bfs(s1,s2)<<"\n";
	}
	
}
-----------------------------------------------------------------------------------------------------
** 0-1 BFS weight only 0 or 1

	** Given directed graph 
	what is minimum number of edges he need to reverse in order to have at least one path 
	from vertex 1 to N **

const int N = 1e3+10;
const int M = 1e9+10;
    
   vector<pair<int,int>> g[N];
    vector<int>level;
    
int n,m;

int bfs(){
    
    deque<int> q;
    q.push_back(1);
    level[1]=0;
    
    while(!q.empty()){
        int c = q.front();
        q.pop_front();
        
        for(auto i:g[c]){
            
            int l = i.first;
            int w = i.second;
            
            if(level[c]+w < level[l]){
                level[c] = level[l] + w;
                if(w==1){
                    q.push_back(l);
                }else{
                    q.push_front(l);
                }
            }
            
        }
        
    }
    return level[n];
    
}

int main(){
    cin>>n>>m;
    
    for(int i=0;i<m;i++){
        int x,y;    cin>>x>>y;
        g[x].push_back({y,0});
        g[y].push_back({x,0});
    }
    cout<<bfs();
}
-----------------------------------------------------------------------------------------------------
// MULTI soource BFS
const int INF 1e9+10;
int n,m;
int val[N][N];
int vis[N][N];
int level[N][N];

void reset(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            level[i][j]=INF;
            vis[i][j]=0;
        }
    }
}

vector<pair<int,int>> mov = {
    {0,1},{0,-1},{1,0},{-1,0},
    {1,1},{1,-1},{-1,1},{-1,-1}
};

bool isvalid(int i,int j){
    return i>=0 && j>=0 && i<n && j<m;
}

int bfs(){
    
    int mx =0;
    
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            mx = max(mx,val[i][j]);
            
    queue<pair<int,int>> q;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mx==val[i][j]){
                q.push({i,j});
                level[i][j]=0;
                vis[i][j]=1;
            }
        }
    }
       
    int ans=0;
       
    while(!q.empty()){
        auto v = q.front();
        int vx = v.first;
        int vy = v.second;
        q.pop();
        
        for(auto m:mov){
            int cx = m.first+vx;
            int cy = m.second+vy;
            
            if(!isvalid(cx,cy)) continue;
            
            if(vis[cx][cy]) continue;
            
            q.push({cx,cy});
            level[cx][cy] = level[vx][vy]+1;
            vis[cx][cy]=1;
            ans = max(ans,level[cx][cy]);
        }
        
    }
    
    return ans;
}

int main(){
    
    int t; cin>>t;
    
    while(t--){
       
        cin>>n>>m;
        reset();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>val[i][j];
            }
        }
        cout<<bfs()<<"\n";
    }
    
}
-> input 
3
2 2
1 1
1 1
2 2
1 1
1 2
3 4
1 2 1 2
1 1 1 2
1 1 2 2

in this example given matrix in each hour the vertex will be max of neighbour of 8


-----------------------------------------------------------------------------------------------------
DIJKSTRA ALGORITHM --********************************************************************************

 Max HEAP  ==  priority_queue <int, vector<int>> pq;
 Min HEAP  == priority_queue <int, vector<int>, greater<int> > pq;

also we can use multiset instead of priority queue

#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+10;
const int M = 1e9+10;
const int INF = 1e9+11;

// Dijkstra
vector<pair<int,int>> g[N];

vector<int> dis(N,INF);
vector<int> vis(N,0); 
      
void Dijkstra(int s){
    
    
    set<pair<int,int>> st;
    
    st.insert({0,s});
    dis[s]=0;
    
    while(st.size()>0){
        
        auto n = *st.begin();
        
        auto d = n.first; 
        auto v = n.second;
        
        st.erase(st.begin());
        
        if(vis[v]==1) continue;
        vis[v]=1;
        
        for(auto i:g[v]){
            int cv = i.first;
            int cw = i.second;
            
            if(dis[v]+cw < dis[cv]){
                dis[cv] = dis[v] + cw;
            }
            st.insert({dis[cv],cv});
            
        }
        
    }
    
}

int main(){
    int n,m;
    cin>>n>>m;
    
    for(int i=0;i<m;i++){
        int x,y,w;
        cin>>x>>y>>w;
        g[x].push_back({y,w});
    }
    
    Dijkstra(1);
    cout<<"+++++++++++\n";
    for(int i=1;i<=n;i++)
        cout<<dis[i]<<" ";
    
}
*/
/*const int INF = 1e9+10; 
int d[N][N];
// floyd warshall   
int main(){
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            if(i==j) d[i][j]=0;
            else  d[i][j]=INF;

    int n,m; cin>>n>>m;

    for(int i=0;i<m;i++){

        int x,y,w;
        cin>>x>>y>>w;

        d[x][y]=w;

    }   

    for(int k=1;k<=n;k++){

        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(d[i][k]!=INF && d[j][k]!=INF)
                    d[i][j]= min( d[i][j], d[i][k]+d[k][j] );
            }
        }

    }

   for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){

        if(d[i][j]==INF) cout<<"I ";
        else cout<<d[i][j]<<" ";

    }
    cout<<"\n";
   }

}
*/

// disjoint set union
int parent[N],si[N];

void make(int v){
	parent[v]=v;
	si[v]=1;
}

int find(int v){
    if(v==parent[v]) return v;
    return parent[v]= find(parent[v]);
}

void Union(int a,int b){
    a =find(a);
    b =find(b);

        if(a!=b){
			if(si[a] < si[b])
				swap(a,b);
			parent[b]=a;
			si[a]+=si[b];

		} 

}

int main(){
	int n,m;
	cin>>n>>m;
	vector<pair<int,pair<int,int>>>a;
	
	for(int i=0;i<m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		a.push_back({w,{u,v}});
	}
	sort(a.begin(),a.end());
	
	for(int i=1;i<=n;i++) make(i);

	int cost=0;
	
	for(auto i:a){
		int w = i.first;
		int u = i.second.first;
		int v = i.second.second;

		if(find(u)==find(v)) continue;
		Union(u,v);
		cost += w;
		cout<<u<<" "<<v<<endl;
	}
	cout<<cost<<endl;

}
