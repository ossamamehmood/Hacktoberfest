class Solution 
{
public:
    unordered_map<string,vector<string>>adj;
    vector<string>ans;
    int numTickets=0;

    bool dfs(string str,vector<string>&path)
    {
        path.push_back(str);
        if(path.size() == numTickets+1)
        {
            ans=path;
            return true ;
        }
        vector<string> &nodes= adj[str];
        for( int i =0;i<nodes.size();i++)
        {
            string next =nodes[i];
            nodes.erase(nodes.begin()+i);
            if (dfs(next,path))
               return true;
            nodes.insert(nodes.begin()+i,next);
        }
        path.pop_back();
        return 0;
    }
   

    vector<string> findItinerary(vector<vector<string>>& tickets) 
    {
        for( int i=0;i<tickets.size();i++)
        {
            string from = tickets[i][0];
            string to = tickets[i][1];

            adj[from].push_back(to);
        }
        for( auto &it : adj)
        {
            sort( it.second.begin(),it.second.end());
        }
        numTickets= tickets.size();
        vector<string> path;
        dfs("JFK",path);
        return ans;
    }
   
};