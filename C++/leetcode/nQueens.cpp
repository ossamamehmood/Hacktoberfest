bool safe(vector<string> b,int n,int i,int j)
    {
        for(int x=0;x<i;x++)
            if(b[x][j]=='Q')
                return false;
        
        int x=i,y=j;
        
        while(x>=0&&y>=0)
        {
            if(b[x][y]=='Q')
                return false;
            x--;y--;
        }
        
        x=i;y=j;
        
        while(y<n&&x>=0)
        {
            if(b[x][y]=='Q')
                return false;
            x--;y++;
        }
        
        return true;
    }
    
    bool solve(vector<vector<string>> &a,vector<string> &b,int n,int i)
    {
        if(i==n)
        {
            a.push_back(b);
            return true;
        }
        
        for(int j=0;j<n;j++)
        {
            if(safe(b,n,i,j))
            {
                b[i][j]='Q';
                solve(a,b,n,i+1);
            }
            
            b[i][j]='.';
        }
        
        return false;
    }
    
    vector<vector<string>> solveNQueens(int n) {
        string a="";
        for(int i=0;i<n;i++)
            a+=".";
        
        vector<vector<string>> ans;
        vector<string> b(n,a);
        
        solve(ans,b,n,0);
        return ans;
    }