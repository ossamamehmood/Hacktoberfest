class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length()!=t.length()){
            return false;
        }
        
        int m1[256]={0};
        int m2[256]={0};
        for(int i=0;i<s.length();i++){
            if(!m1[s[i]] and !m2[t[i]]){
                m1[s[i]]=t[i];
                m2[t[i]]=s[i];
            }
            else if(m1[s[i]]!=t[i]){
                return false;
            }
        }
        return true;
        
    }
};