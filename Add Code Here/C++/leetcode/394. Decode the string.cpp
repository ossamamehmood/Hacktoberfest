class Solution {
    string decodeString(string s , int &n){
        string result;
        while(n < s.length() && s[n] != ']'){
            if(isdigit(s[n])){
                int k = 0;
                while(n < s.length() && isdigit(s[n]))
                    k = k*10 + s[n++] - '0';
                n++;
                string r = decodeString(s, n);
                while(k-- > 0)
                    result += r;
                n++;
            } 
            else
                result += s[n++];
        }
        return result;
    }
public:
    string decodeString(string s){
        int n = 0;
        return decodeString(s, n);
    }
};