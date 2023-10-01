class Solution {
public:
  typedef pair<int,int> p;
    int shortestPathLength(vector<vector<int>>& graph) 
    {
         int n = graph.size();
         if (n==1 || n==0 )
          return 0;

         queue<p>q;
         set<p>vis;
         
         // pushing all elements with their value in binary
         //because we need to find the min starting frm each 
         //node
         for(int i=0;i<n;i++)
         {
             q.push({i,1<<i});
             vis.insert({i,i<<i});
         }
        int path=0;

        while(!q.empty())
        {
            int qs=q.size();
            path++;
            // level order marking every path continously
            // we will check if we had vis that previously in  
            //same path or not 
            while(qs--)
            {
                auto curr =q.front();
                 q.pop();
                for( auto it : graph[curr.first])
                 {
                     int nextmask = curr.second | (1<<it);

                     if( nextmask == (1<<n)-1 )
                          return path;
                     
                     if( vis.find({it,nextmask}) == vis.end())
                     {
                         q.push({it,nextmask});
                         vis.insert({it,nextmask});
                     }
                 }
            }
        }
       return -1;
    }
};