// So;ution to a classical leetcode problem
// https://leetcode.com/problems/reverse-prefix-of-word/

class Solution {
public:
    string reversePrefix(string word, char ch) {
        string r="";
        int i,j;
        size_t found = word.find(ch);
        if(found==string::npos){
            return word;
        }
        for(i=0;i<=found;i++){
            r+=word[i];
        }
        reverse(r.begin(),r.end());
        for(j=i;j<word.length();j++){
            r+=word[j];
        }
        return r;
    }
};
