int distinctSubsequences(string s)
	{
	    // Your code goes here
	    int n=s.size();
	    long long mod=1e9+7;
	    long long arr[26]={0},pre=1,cur=1;
	    for(int i=0;i<n;i++){
	        cur=(pre*2)%mod;
	        cur = (cur - arr[s[i] - 'a'] + mod) % mod;
	        arr[s[i]-'a']=pre;
	        pre=cur;
	    }
	    return cur;
	}
