class Solution {
public:
    int dist(vector<int>&v1 , vector<int>&v2)
    {
      return abs(abs(v1[0]-v2[0])+abs(v1[1]-v2[1]));
    }
    int minCostConnectPoints(vector<vector<int>>& points) 
    {
        int n = points.size();
        vector<vector<pair<int,int>>>adj(n);
        // make a adj list 
        for( int i=0;i<points.size();i++)
        {
            for( int j=0;j<points.size();j++)
            {
              adj[i].push_back({j,dist(points[i],points[j])});
              adj[j].push_back({i,dist(points[i],points[j])});
            }   
        }
        
        // {distance ,point}
        // using pq to choose the smallest distance first
        priority_queue<pair<int,int>,vector<pair<int,int>>,
        greater<pair<int,int>>>pq;
        
        //vis array
        vector<int>vis(n,0);

        pq.push({0,0});
        int cost =0;

        while(!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            int curr = it.second;
            int edwgt = it.first;

            if( vis[curr] )
            continue;

            vis[curr]=1;
            cost+=edwgt;
            for( auto it : adj[curr] )
            {
                int adjpoint =it.first;
                int wgt =it.second;

                if(!vis[adjpoint])
                pq.push({wgt,adjpoint});
            }
        }
        return cost;
    }
};