class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<int>q; vector<vector<int>>q1;
        for(int i=0;i<numRows;i++)
        {
            for(int k=0;k<=i;k++)
            {
                if(k==0||k==i)
                q.push_back(1);
                else {
                    q.push_back(q1[i-1][k-1]+q1[i-1][k]);
                }
            
            }
            q1.push_back(q);
            q.clear();
        }
        return q1;
    }
};
