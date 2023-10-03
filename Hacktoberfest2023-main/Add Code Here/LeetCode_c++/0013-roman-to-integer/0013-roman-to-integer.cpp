class Solution {
public:
    int romanToInt(string s) 
    {
        //when a smaller value appears before a larger value, it represents subtraction,
 //while when a smaller value appears after or equal to a larger value, it represents addition
        unordered_map<char,int>mp;
        mp['I']  = 1;
        mp['V']  = 5;
        mp['X']  = 10;
        mp['L']  = 50;
        mp['C']  = 100;
        mp['D']  = 500;
        mp['M']  = 1000;

        int ans=0;
        for( int i=0;i<s.length();i++)
        {
          if(mp[s[i]]<mp[s[i+1]])
           ans-=mp[s[i]];
          else 
           ans+=mp[s[i]]; 
        }
        return ans;
    }
};