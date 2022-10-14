string longestPalindrome(string s) {
     
        int n=s.length();
        int in=0;
        int m=1;
        
        for(int i=0;i<n;i++)
        {
            int l=i,r=i;
            
            while(l>=0&&r<n&&s[l]==s[r])
            {
                if(r-l+1>m)
                {
                    in=l;
                    m=r-l+1;
                }
                l--;r++;
            }
            
            l=i,r=i+1;
            
            while(l>=0&&r<n&&s[l]==s[r])
            {
                if(r-l+1>m)
                {
                    in=l;
                    m=r-l+1;
                }
                l--;r++;
            }
                
        }
        
        return s.substr(in,m);
        
    }