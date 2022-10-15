 vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> minh ;
        vector<int> dis(V,INT_MAX-1) ;
        dis[S] = 0 ;
        minh.push({0,S}) ;
        while(!minh.empty())
        {
            auto it = minh.top() ;
            minh.pop() ;
            int a = it.first ;
            int b = it.second ;
            
            for(auto i : adj[b])
            {
                int m = i[0] ;
                int n = i[1] ;
                if(dis[m] > a + n ){
                    dis[m] = a+n ;
                    minh.push({dis[m],m}) ;
                }
            }
        }
        
        return dis ;
    }
