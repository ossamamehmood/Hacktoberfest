class Solution{
    private:
    
    bool issafe(int x,int y,int n,vector<vector<int>>visited,vector<vector<int>> &m){
        if((x>=0&&x<n)&&(y>=0&&y<n)&&visited[x][y]==0&&m[x][y]==1) return true;
        return false;
    }
    
    void solve(vector<vector<int>> &m, int n,vector<vector<int>>visited, vector<string>&ans,int x,int y,string s){
        if(x==n-1&&y==n-1){
            ans.push_back(s);
            return;
        }
        visited[x][y]=1;
        
        // down
        int newx=x+1;
        int newy=y;
        if(issafe(newx,newy,n,visited,m)){
            s.push_back('D');
            solve(m,n,visited,ans,newx,newy,s);
            s.pop_back();
        }
        // left
        newx=x;
        newy=y-1;
        if(issafe(newx,newy,n,visited,m)){
            s.push_back('L');
            solve(m,n,visited,ans,newx,newy,s);
            s.pop_back();
        }
        // right
        newx=x;
        newy=y+1;
        if(issafe(newx,newy,n,visited,m)){
            s.push_back('R');
            solve(m,n,visited,ans,newx,newy,s);
            s.pop_back();
        }
        // Up
        newx=x-1;
        newy=y;
        if(issafe(newx,newy,n,visited,m)){
            s.push_back('U');
            solve(m,n,visited,ans,newx,newy,s);
            s.pop_back();
        }
        visited[x][y]=0;
    }
    
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<vector<int>> visited=m;
        string s="";
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                visited[i][j]=0;
            }
        }
        vector<string>ans;
        if(m[0][0]==0) return ans;
        int srcx=0;
        int srcy=0;
        solve(m,n,visited,ans,srcx,srcy,s);
        sort(ans.begin(),ans.end());
        return ans;
    }
};
