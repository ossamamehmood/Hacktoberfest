class Solution {
public:
    bool isPalindrome(int x) {
        string g=to_string(x);
        for(int i=0; i<g.size(); i++){
            if(g[i]!=g[g.size()-i-1]){
                return false;
            }
        }
        return true;
    }
};