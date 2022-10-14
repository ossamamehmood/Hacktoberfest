    string longestCommonPrefix(vector<string>& strs) {
        
        sort(strs.begin(), strs.end());
       
        int i=0, j=0, n=strs.size();
        string ans="", a=strs[0], b=strs[n-1];
       
        while(i < a.size() && j < b.size()){
            if(a[i]!=b[j]) break;
            else {
                ans+=a[i];
                i++,j++;
            }
        }
    
        return ans;
    }
