public:
bool ans=false;
int arrx[8]={2,2,1,-1,-2,-2,1,-1};
int arry[8]={1,-1,2,2,1,-1,-2,-2};
bool valid(int x,int y,int N)
{
    if(x>=0 && x<N && y>=0 && y<N)
    {
        return true;
    }
    return false;
}

void BFS(vector<vector<bool>>&visited,vector<vector<int>>&distance,int x,int y,int targetposX,int targetposY,int N) 
{
    queue<pair<int,int>>q;
    q.push({x,y});
    visited[x][y]=true;
    while(q.size()>0)
    {
        pair<int,int>p;
        p=q.front();
        q.pop();
        int x=p.first;
        int y=p.second;
        if(x==targetposX && y==targetposY)
        {
            ans=true;
            return;
        }
        for(int i=0;i<8;i++)
        {
            if(valid(x+arrx[i],y+arry[i],N) && visited[x+arrx[i]][y+arry[i]]==false)
            {
                distance[x+arrx[i]][arry[i]+y]=distance[x][y]+1;
                visited[x+arrx[i]][y+arry[i]]=true;
                q.push({x+arrx[i],y+arry[i]});
            }
        }
    }
}

	int minStepToReachTarget(vector<int>&KnightPos, vector<int>&TargetPos, int N){
	    int knightposX=KnightPos[0]-1;
	    int knightposY=KnightPos[1]-1;
	    int targetposX=TargetPos[0]-1;
	    int targetposY=TargetPos[1]-1;
	    vector<vector<bool>>visited(N,vector<bool>(N,false));
	    vector<vector<int>>distance(N,vector<int>(N,0));
	    BFS(visited,distance,knightposX,knightposY,targetposX,targetposY,N);
	    if(ans==true)
	    {
	        return distance[targetposX][targetposY];
	    }
	    return -1;
	}
};
