class Solution {
public:
    vector<vector<int>> generate(int n ) 
    {
        vector<vector<int>>ans;
        ans.push_back({1});
        if(n==1)
         return ans;
        for(int i=1;i<n;i++)
        {
            vector<int>temp;
            temp.push_back(1);
            for(int j =1;j<i;j++)
            {
             temp.push_back(ans[i-1][j-1]+ans[i-1][j]);
            }
            temp.push_back(1);

            ans.push_back(temp);
        }
        return ans;
    }
};