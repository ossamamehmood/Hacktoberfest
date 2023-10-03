class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordlist) 
    {
        unordered_set<string> dict( wordlist.begin(),wordlist.end());
        queue<string>q;

         if(dict.find(endWord)==dict.end())
          return 0;
        int ladder = 1;
        q.push(beginWord);

        while(!q.empty())
        {
            int n = q.size();

            for( int i=0;i<n;i++)
            {
                string str = q.front();
                 q.pop();

                if( str ==endWord)
                 return ladder;
                
                dict.erase(str);

                for( int j=0;j<str.size();j++)
                {
                    char c= str[j];
                    for(int k=0;k<26;k++)
                    {
                         str[j]= 'a'+k;
                        if( dict.find(str)!=dict.end())
                        {
                            q.push(str);
                        }
                    }
                    str[j]=c;
                }
            }
            ladder++;
        }
        return 0;
    }
};