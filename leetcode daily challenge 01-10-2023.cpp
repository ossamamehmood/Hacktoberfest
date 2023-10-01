class Solution {
public:
    string reverseWords(string s) {
        string ans="";
        string temp="";

        for(int i=0;i<s.size();i++){
            if(s[i]!=' '){
                temp+=s[i];
            }else{
                reverse(temp.begin(),temp.end());
                if(ans.size()>0){
                    ans+=" "+temp;
                }else{
                    ans+=temp;
                }
                temp="";
            }
        }
        reverse(temp.begin(),temp.end());
        if(ans.size()>0){
            if(temp.size()>0){
                ans+=" "+temp;
            }
        }else{
            return temp;
        }
        return ans;
    }
};
