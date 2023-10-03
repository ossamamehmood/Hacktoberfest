class Solution {
public:
    int lengthOfLastWord(string s) 
    {
        int len=0;
        int i = s.length()-1;
        while(s[i]==' ')
         i--;

        while(  i>=0 && s[i--]!=' ')
            len++;

        return len;
    }
};