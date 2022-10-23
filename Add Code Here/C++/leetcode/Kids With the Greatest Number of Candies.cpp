
class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& v, int e) {
        int m=0;
        vector<bool> ans;
        for(int i=0;i<v.size();i++)
        {
            m=max(v[i],m);
        }
        for(int i=0;i<v.size();i++)
        {
            if(v[i]+e>=m)
            {
                ans.push_back(true);
            }
            else
            {
                ans.push_back(false);
            }
        }
        return ans;
        
    }
};