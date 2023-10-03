class Solution {
public:
    int strStr(string haystack, string needle) 
    {
        int j=0;
        for( int i=0;i<haystack.size();i++)
        {
            if( haystack[i] == needle[j])
                j++;
            
            else
            {
              i =i-j;
              j=0;
            }
            if( j== needle.size())
            {
                return i-j+1;
            }
        }
        return -1;
    }
};