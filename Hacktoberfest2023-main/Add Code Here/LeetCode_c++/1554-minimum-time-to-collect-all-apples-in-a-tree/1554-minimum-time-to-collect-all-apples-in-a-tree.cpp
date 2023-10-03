class Solution {
public:
    int dfs( unordered_map<int,vector<int>>&adj ,
    vector<bool>& hasApple, vector<bool>&vis ,int cost,int node )
    {
         if(vis[node])
          return 0;
        
        vis[node]=true;

        int childcost=0;

        for( auto it: adj[node])
            childcost += dfs( adj,hasApple,vis,2,it);
        
        if( childcost==0 && !hasApple[node])
        return 0;

        return childcost+cost;
    }

    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) 
    {
      unordered_map<int,vector<int>>adj;
      vector<bool>vis(n,0);

       for( auto it :edges)
       {
           adj[it[0]].push_back(it[1]);
           adj[it[1]].push_back(it[0]);
       }   

        return  dfs( adj,hasApple,vis,0,0);

    }
};