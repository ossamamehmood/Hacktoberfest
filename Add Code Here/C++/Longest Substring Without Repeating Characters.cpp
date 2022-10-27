class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> set;
        int max=0;
        int l=0;
        int r=0;
        while(r<s.length()){
            if(set.find(s[r])==set.end()){
                if((r-l+1)>max){
                    max=r-l+1;
                }
                set.insert(s[r]);
                r++;
            }
            else{
                set.erase(s[l]);
                l++;
            }
        }
        return max;
        
        
        
    }
};