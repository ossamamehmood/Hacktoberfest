class Solution {
public:
	bool predecessor(string &prev, string &curr) {
		int n = prev.size(), m = curr.size();
        
        
		if (n+1 != m) {
            return false;
        }

        int i=0, j=0;
		while (j < m) {
			if (prev[i] == curr[j]) {
				i++, j++;
			}
			else j++;
		}

       
		return i==n;
	}
    
    
    static bool compare (string& first, string& second) {
        return first.size() < second.size();
    }
    
	int longestStrChain(vector<string>& words) {
        
        
		sort(words.begin(), words.end(), compare);
        

		vector<int> dp(words.size(), 1);
		int ans = 1; 
    
		for (int curr = 0; curr < words.size(); curr++) {
			for (int prev = 0; prev < curr; prev++) {
				if (predecessor(words[prev], words[curr])) {
                    dp[curr] = max(dp[curr], dp[prev]+1);
                }
			}
		
			ans = max(ans, dp[curr]);
		}
		return ans;
	}
};