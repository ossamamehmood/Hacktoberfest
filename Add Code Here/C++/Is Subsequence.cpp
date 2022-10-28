class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i=t.length()-1;
        int j=s.length()-1;
        while(i>=0 && j>=0){
            if(t[i]==s[j]){
                
                i--;
                j--;
            }
            else{
                i--;
            }
            
        }
        if(j==-1){
            return true;
        }
        return false;
    }
};