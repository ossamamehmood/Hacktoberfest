class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) 
    {
        // string ans = strs[0];
        // for( int i=1;i<strs.size();i++)
        // {
        //     string temp="";
        //     int j=0;
        //     while( j<strs[i].size() && ans[j]==strs[i][j])
        //     {
        //         temp+= strs[i][j];
        //           j++;
        //     }
        //     ans=temp;
        // }
        // return ans;

        sort(strs.begin(),strs.end());
         int n =strs.size();

        string ans="";
        for( int i=0;i<strs[0].size();i++)
        {
            if( strs[0][i] == strs[n-1][i])
             ans+= strs[0][i];
            else 
            break; 
        } 
        return ans;
    }
};