class Solution {
public:
    int maxLen = 0;
    int startPoint = 0;
    
    void maxSubstr(string s, int moveleft, int moveright) {
        while(moveleft>=0 && moveright<s.size() && s[moveleft]==s[moveright]) {
            moveleft--;
            moveright++;
        }
        if(maxLen<moveright-moveleft-1) {
            maxLen = moveright-moveleft-1;
            startPoint = moveleft+1;
        }
    }
    
    string longestPalindrome(string s) {
        if(s.size()<=1) return s;
        
        for(int i=0; i<s.size(); i++) {
            maxSubstr(s, i, i); //for odd length; see example 1
            maxSubstr(s, i, i+1); //for even length; see example 2
        }
        string ans="";
        for(int i=startPoint; i<maxLen+startPoint; i++) {
            ans+=s[i];
        }
        return ans;
    }
};
