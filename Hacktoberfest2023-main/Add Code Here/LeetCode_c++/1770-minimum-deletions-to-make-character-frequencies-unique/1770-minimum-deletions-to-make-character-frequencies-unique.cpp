class Solution {
public:
    int minDeletions(string s) 
    {
        vector<int>freq(26,0);
       for(int i=0;i<s.length();i++)
       {
           freq[s[i]-'a']++;
       }
       sort(freq.begin(),freq.end());
       int del=0;
       for( int i=24 ;i>=0;i--)
       {
           if(freq[i]==0)
            break;

           if(freq[i]>=freq[i+1])
           {
               int temp = freq[i];
               freq[i]= max(0,freq[i+1]-1);
               del+= temp-freq[i];
           } 
       }
       return del;

    }
};