class Solution {
public:
    bool closeStrings(string word1, string word2) 
    {
        if(word1.size()!=word2.size())
         return false;

        // unordered_map<char,int>mp1,mp2;

        // for(auto it :word1)
        //  mp1[it]++;

        // for( auto it:word2)
        //  mp2[it]++;

        // for( auto it: mp1)
        //  {
        //      if(mp2.find(it.first)==mp2.end())
        //       return false;
        //  }

        unordered_map<char,int>mp1;

        for(auto it :word1)
         mp1[it]++;

        for( auto it:word2)
         mp1.erase(it);
         
        if(!mp1.empty())
         return false; 

        vector<int>v1(26,0);
        vector<int>v2(26,0);

        for( int i=0;i<word1.length();i++)
        {
           v1[word1[i]-'a']++;
           v2[word2[i]-'a']++;
        }
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());

        for(int i=0;i<26;i++)
        {
            if(v1[i]!=v2[i])
             return false;
        }
         return true;


    }
};