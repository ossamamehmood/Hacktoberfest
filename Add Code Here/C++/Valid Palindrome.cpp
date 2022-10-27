class Solution {
public:
    bool palindrome(string st){
        int i=0;
        int j=st.length()-1;
        while(i<j){
            if(st[i]!=st[j]){
                return false;
            }
            else{
                i++;
                j--;
            }
        }
        return true;
    }
    bool isPalindrome(string s) {
        string str="";
        for(int i=0;i<s.length();i++){
            if(isupper(s[i])){
                
                str+=char(s[i]+32);
            }
            else if(islower(s[i])){
                str+=s[i];
            }
            else if(isdigit(s[i])){
                str+=s[i];
            }
        }
        return palindrome(str);
        
    }
};