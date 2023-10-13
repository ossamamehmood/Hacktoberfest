void bfs(int V,vector<int>& inDegree,vector<int> adj[],vector<int>& ans){
	   
	   //first put those whose indegree == 0
	   //as they have need to be first
	   queue<int> q;
	   for(int i=0;i<V;i++){
	       if(inDegree[i] == 0){
	           q.push(i);
	       }
	   }
	   
	   while(!q.empty()){
	       int frontElem = q.front();
	       q.pop();
	       ans.push_back(frontElem);
	       
	       for(auto i: adj[frontElem]){
	           //reduce adjacent nodes inDegree
	           inDegree[i]--;
	           
	           if(inDegree[i] == 0){
	               q.push(i);
	           }
	       }
	       
	   }
	    
	    
	}
	
	
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int> ans;
	    vector<int> inDegree(V,0);
	    //Indegree = Incoming arrows  [Towards ME]
	    for(int i=0;i<V;i++){
	        // i is a vector
	        for( auto e: adj[i]){
	            inDegree[e]++;
	        }
	    }
	    
	    //visited Not required here
	    bfs(V,inDegree,adj,ans);
	    
	    return ans;
	}
