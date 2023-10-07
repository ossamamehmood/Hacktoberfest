#include<bits/stdc++.h>
using namespace std;

//q1->counting rooms
void q1_dfs(int n, int m, int row,int col, vector<vector<char>> &grid, vector<vector<int>>& vis){
    vis[row][col]=1;
    int drow[4] = {1,0,-1,0};
    int dcol[4] = {0,-1,0,1};
    for(int i=0;i<4;++i){
        int nrow = drow[i]+row;
        int ncol = dcol[i]+col;
        if(nrow<n && nrow>=0 && ncol<m && ncol>=0 && !vis[nrow][ncol] && grid[nrow][ncol]=='.'){
            q1_dfs(n,m,nrow,ncol,grid,vis);
        }
    }
}
int q1(int n, int m, vector<vector<char>> &grid){
    //we have to count no. of provinces in this question
    vector<vector<int>> vis(n, vector<int>(m,0));
    int cnt = 0;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(!vis[i][j] && grid[i][j]=='.'){
                q1_dfs(n,m,i,j,grid,vis);
                cnt++;
            }
        }
    }
    return cnt;
}

//q2->Labyrinth->DJIKSTRA ALGORITHM
bool q2(int n, int m, vector<vector<char>> &grid, int& count, string &ans){
    //TIME COMPLEXITY-> O(N*M*4);
    pair<int,int> start,end;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(grid[i][j]=='A') start = {i,j};
            if(grid[i][j]=='B'){
                end = {i,j};
                grid[i][j] = '.';
            }
        }
    }
    vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
    dist[start.first][start.second]=0;
    vector<vector<char>> parent(n,vector<char>(m,'0'));
    queue<pair<int,int>> q;
    q.push({start.first,start.second});
    int drow[4] = {1,0,-1,0};
    int dcol[4] = {0,-1,0,1};
    char ch[4] = {'D','L','U','R'};
    while(!q.empty()){
        int row = q.front().first;
        int col = q.front().second;
        q.pop();
        if(row==end.first && col == end.second) break;
        for(int i=0;i<4;++i){
            int nrow = drow[i]+row;
            int ncol = dcol[i]+col;
            if(nrow<n && nrow>=0 && ncol<m && ncol>=0 && grid[nrow][ncol]=='.'){
                if(dist[nrow][ncol]>dist[row][col]+1){
                    parent[nrow][ncol] = ch[i];
                    dist[nrow][ncol] = dist[row][col]+1;
                    q.push({nrow,ncol});
                }
            }
        }
    }
    // cout<<"Distance array is:\n";
    // for(int i=0;i<n;++i){
    //     for(int j=0;j<m;++j){
    //         cout<<dist[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // cout<<"Parent array is:\n";
    // for(int i=0;i<n;++i){
    //     for(int j=0;j<m;++j){
    //         cout<<parent[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    if(dist[end.first][end.second]==INT_MAX) return false;
    count = dist[end.first][end.second];
    int row = end.first, col = end.second;
    while(row != start.first || col != start.second){
        char ch1 = parent[row][col];
        ans.push_back(ch1);
        if(ch1=='D') row--;
        else if(ch1=='U') row++;
        else if(ch1=='R') col--;
        else if(ch1=='L') col++; 
    }
    reverse(ans.begin(),ans.end());
    return true;
}

//Q3-> BUILDING ROADS
//I GUESS IT IS BASED ON DISJOINT SET OR TO FIND TOTAL NO. OF PROVINCES.
//I WILL TRY FIRST BY APPLYING DFS APPROACH.
void dfs_q3(int node, vector<int> &vis, vector<int> adj[]){
    vis[node]=1;
    for(auto it:adj[node]){
        if(!vis[it]) dfs_q3(it,vis,adj);
    }
}

//Q4-> MESSAGE ROUTE
//NORMAL DJIKSTRA QUES., WE HAVE TO FIND SHORTEST DISTANCE BETWEEN 1 & N AND PRINT THE 
//ALL OF NODES WHICH WE HAVE TO TRAVERSE.
void q4(int n, int m, vector<int> adj[], vector<int>& ans){
    queue<pair<int,int>> q;
    vector<int> dist(n+1,INT_MAX);
    vector<int> parent(n+1);
    dist[1] = 1;
    parent[1]=1;
    q.push({1,1});//node and distance
    while(!q.empty()){
        int node = q.front().first;
        int d = q.front().second;
        if(node==n) break;
        q.pop();
        for(auto it:adj[node]){
            if(dist[it]>d+1){
                parent[it]=node;
                dist[it]=d+1;
                q.push({it,dist[it]});
            }
        }
    }
    if(dist[n]==INT_MAX) return;
    int cnt = dist[n],i=n;
    while(cnt--){
        ans.push_back(i);
        i = parent[i];
    }
}

//Q5->BUILDING TEAMS
//ALGORITHM IS ALMOST SIMILIAR TO WHAT WE DO FOR BIPARTITE GRAPH, ALL ADJACENT EDGES MUST
//BE PUT INTO DIFFERENT GROUPS.
bool dfs_q5(int n, vector<int> adj[], vector<int>& mark,int node){
    int col = mark[node];
    for(auto it:adj[node]){
        if(mark[it]==0){
            if(col == 1) mark[it]=2;
            else if(col==2) mark[it]=1;
            if(dfs_q5(n,adj,mark,it)==false) return false;
        }
        else if(mark[it]!=0&&mark[it]==col) return false;
    }
    return true;
}

bool q5(int n, vector<int> adj[], vector<int>& mark){
    for(int i=1;i<=n;++i){
        if(mark[i]==0){
            mark[i] = 1;
            if(dfs_q5(n,adj,mark,i)==false) return false;
        }
    }
    return true;
}

//Q6->ROUND TRIP
//WE HAVE TO DETECT CYCLE AND STORE ITS NUMBER OF NODES AND RETURN ITS PATH ALSO, IF
//THERE IS NO CYCLE THEN WE CAN SAY THAT THERE IS ROUND TRIP POSSIBLE AND HENCE WOULD BE
//IMPOSSIBLE.
bool dfs_q6(int n, int node, vector<int>& vis, vector<int> adj[], int parent, int &city,
            vector<int>&path){
    vis[node]=1;
    path.push_back(node);
    for(auto it:adj[node]){
        if(!vis[it]){
            if(dfs_q6(n,it,vis,adj,node,city,path)==true) return true;
        }
        else if(vis[it]==1 && it!=parent){
            path.push_back(it);
            city = it;
            return true;//there is a cycle present in graph.
        }
    }
    path.pop_back();
    return false;
}
void q6(int n,vector<int> adj[]){
    vector<int> vis(n+1,0);
    vector<int> path(n+1);
    int city,ans=0;
    for(int i=1;i<=n;++i){
        if(!vis[i]){
            if(dfs_q6(n,i,vis,adj,0,city,path)==true){
                ans=1;
                break;
            }
        }
    }
    if(ans==0){
        cout<<"IMPOSSIBLE\n";
        return;
    }
    //city node is included in the cycle.
    int start;
    for(int i=0;i<path.size();++i){
        if(path[i]==city && i!=path.size()-1){
            start = i;
            break;
        }
    }
    cout<<path.size()-start<<endl;
    for(int i=start;i<path.size();++i) cout<<path[i]<<" ";
}

//Q7->MONSTERS
//HERE WE HAVE TO MAKE SURE THAT AT EACH CELL, WE HAVE TO REACH BEFORE THE MONSTER IN ORDER
//TO REACH THE DESTINATION, HENCE WE WILL HAVE TO FIND FOR EACH CELL THE MIN. NUMBER OF 
//STEPS IN WHICH A MONSTER CAN VISIT IT SO THAT WE ONLY GO TO THOSE CELLS WHERE WE CAN GO
//REACH EARLIER THAN MONSTER.

//HENCE FIRST DO A MULTI SOURCE BFS FOR MONSTERS AND FIND THERE MIN. DISTANCE, AFTER THAT
//FIND A PATH FROM SOURCE TO A BOUNDARY CELL SUCH THAT FOR EACH CELL N THAT PATH WE CAN 
//REACH IT EARLIER THAN ANY OTHER MONSTER.
void q7_multisource(int n,int m, vector<vector<char>> &grid,vector<vector<int>> &dist,int src_x, int src_y){
    string ans;
    queue<pair<int,pair<int,int>>> q;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(grid[i][j]=='M') q.push({0,{i,j}});//stored all of monsters initial coordinates with ini. dis. 0
            if(grid[i][j]=='M') dist[i][j] = 0;
        }
    }
    int drow[4] = {1,0,-1,0};
    int dcol[4] = {0,1,0,-1};
    char ch[4] ={'D','R','U','L'};
    while(!q.empty()){
        int d = q.front().first;
        int row = q.front().second.first;
        int col = q.front().second.second;
        q.pop();
        for(int i= 0;i<4;++i){
            int nrow = row+drow[i];
            int ncol = col+dcol[i];
            if(nrow<n && nrow>=0 && ncol<m && ncol>=0 && grid[nrow][ncol]=='.'){
                if(dist[nrow][ncol]>d+1){
                    dist[nrow][ncol] = d+1;
                    q.push({dist[nrow][ncol],{nrow,ncol}});
                }
            }
        }
    }

    //WE GOT SHORTEST DISTANCE FROM MONSTERS AND NOW WE WANT ALL PATHS FROM SOURCE TO BOUNDARY CELL.
    vector<vector<char>> path(n,vector<char>(m,'0'));
    // vector<vector<int>> dsrc(n,vector<int>(m,INT_MAX));//distance matrix from source
    // dsrc[src_x][src_y]=0;
    vector<vector<int>> vis(n,vector<int>(m,0));
    vis[src_x][src_y]=1;
    q.push({0,{src_x,src_y}});
    while(!q.empty()){
        int d = q.front().first;
        int row = q.front().second.first;
        int col = q.front().second.second;
        q.pop();
        for(int i= 0;i<4;++i){
            int nrow = row+drow[i];
            int ncol = col+dcol[i];
            if(nrow<n && nrow>=0 && ncol<m && ncol>=0 && grid[nrow][ncol]=='.' && !vis[nrow][ncol]){
                vis[nrow][ncol]=1;
                if(d+1 < dist[nrow][ncol]){
                    //dsrc[nrow][ncol] = d+1;
                    q.push({d+1,{nrow,ncol}});
                    path[nrow][ncol] = ch[i];
                }
            }
        }
    }
    if(src_x==0 || src_x==n-1 || src_y==0 || src_y==m-1){
        cout<<"YES\n"<<0;
        return;
    }
    int final_x=-1,final_y=-1;
    for(int i=0;i<n;++i){
        if(path[i][0]!='0'){
            final_x=i,final_y=0;
            break;
        }
        if(path[i][m-1]!='0'){
            final_x=i,final_y=m-1;
            break;
        }
    }
    for(int j=0;j<m;++j){
        if(path[0][j]!='0'){
            final_x=0,final_y=j;
            break;
        }
        if(path[n-1][j]!='0'){
            final_x=n-1,final_y=j;
            break;
        }
    }
    if(final_x==-1 && final_y==-1){
        cout<<"NO";
        return;
    }
    
    while(final_x!=src_x || final_y!=src_y){
        ans.push_back(path[final_x][final_y]);
        if(path[final_x][final_y]=='L') final_y++;
        else if(path[final_x][final_y]=='R') final_y--;
        else if(path[final_x][final_y]=='D') final_x--;
        else if(path[final_x][final_y]=='U') final_x++;
    }
    cout<<"YES\n"<<ans.size()<<endl;
    for(int i=ans.size()-1;i>=0;i--){
        cout<<ans[i];
    }
}

//Q8-> SHORTEST ROUTES 1
//WE HAVE TO APPLY BELLMAN FORD ALGO
void q8_floyd(int n, int m, vector<vector<int>> grid){
    
    // dist[1]=0;
    // for(int i=1;i<=n;++i){
    //     for(int i=0;i<m;++i){
    //         int node = grid[i][0];
    //         int adjNode = grid[i][1];
    //         int wt = grid[i][2];
    //         if(dist[node]==INT_MAX) continue;
    //         if(dist[adjNode]>dist[node]+wt) dist[adjNode] = dist[node]+wt;
    //     }
    // }
    vector<pair<int,int>> adj[n+1];
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    for(int i=0;i<m;++i){
        adj[grid[i][0]].push_back({grid[i][1],grid[i][2]});
    }
    cout<<0<<" ";
    for(int i=2;i<=n;++i){
        vector<int> dist(n+1,INT_MAX);
        dist[1] = 0;
        pq.push({0,1});//dist and source
        int end = i;
        while(!pq.empty()){
            int node = pq.top().second;
            int d = pq.top().first;
            pq.pop();
            if(node==end) break;
            for(auto it:adj[node]){
                int adjNode = it.first;
                int wt = it.second;
                if(dist[adjNode]>dist[node]+wt){
                    dist[adjNode] = dist[node]+wt;
                    pq.push({dist[adjNode],adjNode});
                }
            }
        }
        cout<<dist[end]<<" ";
    }
    
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> grid(m,vector<int>(3,0));
    for(int i=0;i<m;++i){
        for(int j=0;j<3;++j){
            cin>>grid[i][j];
        }
    }
    q8_floyd(n,m,grid);

    return 0;
}