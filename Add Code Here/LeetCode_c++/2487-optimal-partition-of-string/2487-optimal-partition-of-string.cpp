class Solution {
public:
    int partitionString(string s) 
    {
        vector<int>lastseen(26,-1);
        // storing the last seenof each letter

        int subset=1;
        int newstart=0;

        for(int i=0;i<s.length();i++)
        {
          if(lastseen[s[i]-'a']>=newstart)
          {
              subset++;
              newstart=i;
          }
          lastseen[s[i]-'a']=i;
        
        }
        return subset;
    }
};