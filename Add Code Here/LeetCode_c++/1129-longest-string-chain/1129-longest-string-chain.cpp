class Solution {
public:
    int longestStrChain(vector<string>& words) 
    {
       unordered_map<string,int> chains;

       sort(words.begin(),words.end(),[]
       ( string&a ,const string&b)
        {return a.length()<b.length();});

        for( auto start :words)
        {
            chains[start]=1;
            for(int i=0;i<start.size();i++)
            {
                string pred = start.substr(0,i)+start.substr(i+1);
                // cout<< pred<<"-";
                // cout<< start.erase(i,1)<<endl;
                // if( chains.find(pred) != chains.end())
                // {
                    chains[start]= max( chains[start],chains[pred]+1);
                // }
            }
        }
        int mxchain=0;

        for( auto it:chains )
        {
            mxchain = max(mxchain,it.second);
        }
        return mxchain;

    }
};