class Solution {
public:
    int countPairs(vector<vector<int>>& coordinates, int k) 
    {
        map<pair<int,int>,int>mp;
        int ans=0;
        for( auto cod : coordinates)
        {
            int x1= cod[0];
            int y1= cod[1];

            for( int i=0;i<=k;i++)
            {
                int x2= x1^i;
                int y2= y1^(k-i);
                ans+=mp[{x2,y2}];
            }
             mp[{x1,y1}]++;
        }
        return ans;
    }
};