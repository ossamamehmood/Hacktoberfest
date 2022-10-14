int longestCommonSubsequence(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();
        
        int t[n+1][m+1];
        
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                if(i==0||j==0) t[i][j]=0;
            }
        }
        
        //Top dowm
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s1[i-1]==s2[j-1])
                {
                    t[i][j] = t[i-1][j-1]+1;
                }
                else {
                    t[i][j] = max(t[i][j-1],t[i-1][j]);
                }
            }
        }
        return t[n][m];