class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) 
    {
        priority_queue<pair<int,int>,
        vector<pair<int,int>> ,
        greater<pair<int,int>> >pq;

        int one=0;
    for( int i=0;i<mat.size();i++)
    {
        one=0;
         for( int j=0;j<mat[0].size();j++)
        { 
            if(mat[i][j])
             one++;
        }
        // cout<<one<<endl;
          pq.push({one,i});
      }   
      vector<int>ans;
      while(k)
      {
          ans.push_back(pq.top().second);
          pq.pop();
          k--;
      }
      return ans;
    }
};