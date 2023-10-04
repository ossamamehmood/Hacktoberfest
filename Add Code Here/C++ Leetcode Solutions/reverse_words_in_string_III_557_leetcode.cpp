class Solution {
public:
    string reverseWords(string s) {
        
        int st=0;
        for(int i=0;i<s.length();i++){
            if(s[i]==' ' || i==s.length()-1){
                int end=0;
                if(i==s.length()-1 && s[i]!=' '){
                end=i+1;
                }else{
                    end=i;
                }

                while(st<end){
                    swap(s[st], s[end-1]);
                    st++;
                    end--;
                }

                st = i+1;
            }
        }
        return s;
    }
};

//code by Mugdha Kshirsagar
// Leetcode profile link : https://leetcode.com/mugdha_kshirsagar21/
// Question Link : https://leetcode.com/problems/reverse-words-in-a-string-iii/
