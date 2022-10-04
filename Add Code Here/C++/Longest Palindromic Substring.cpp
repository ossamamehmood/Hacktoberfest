class Solution {
public:
    string longestPalindrome(string s) {
        int ansR = -1, ansL = -1;
        int mxLen = 0, strLen = s.length();
        
        for (int i = 0; i < strLen; i++){
            int l = i, r = i;
            while (l > -1 && r < strLen && s[l] == s[r]){
                if (mxLen < (r-l+1)){
                    ansR = r;
                    ansL = l;
                    mxLen = (r-l+1);
                }
                l--; r++;
            }
            
            l = i; r = i+1;
            while(l > -1 && r < strLen && s[l] == s[r]){
                if (mxLen < (r-l+1)){
                    ansR = r;
                    ansL = l;
                    mxLen = (r-l+1);
                }
                l--; r++;
            }
        }
        
        return s.substr(ansL, (ansR - ansL + 1));
    }
};
