class Solution {
public:
    string shortestPalindrome(string s) {
        if(s.length()<=1)
            return s;
        
        int l = 0, r = s.size()-1;

        while(r>=0){
            if(s[l]==s[r])
                l++;
            r--;
        }
        
        if(l==s.size())
            return s;

        string rem (s.begin()+l,s.end());
        reverse(rem.begin(),rem.end());
        string out = rem + shortestPalindrome(s.substr(0,l)) + s.substr(l,s.size());

        return out;
    }
};