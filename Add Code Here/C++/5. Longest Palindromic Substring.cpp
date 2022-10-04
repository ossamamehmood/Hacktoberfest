    string longestPalindrome(string s) {
         int n = s.size();
    	int dp[n][n];
    	
	    memset(dp,0,sizeof(dp));
    	int end=1;
    	int strt=0;
	
	    for(int i=0;i<n;i++){
	        dp[i][i] = 1;
    	}
	    for(int i=0;i<n-1;i++){
	        if(s[i]==s[i+1]){
    	    	dp[i][i+1]=1;
        		strt=i;end=2;
       		}
	    }
    	for(int j=2;j<n;j++){
	        for(int i=0;i< n-j;i++){  
           		int lft=i;
            	int rght = i+j;
        	    
    	        if(dp[lft+1][rght-1]==1 && s[lft]==s[rght]) 
	            {
                	dp[lft][rght]=1; strt=i; end=j+1; 
            	}        
        	}
    	}
    return s.substr(strt, end);
    }
