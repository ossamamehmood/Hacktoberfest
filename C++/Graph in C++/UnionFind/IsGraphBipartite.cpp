class Solution {
public:
    vector<int >v;
    int par(int p){
        if(v[p]==-1)
            return p;
        else 
            return v[p]=par(v[p]);
    }
    void unio(int x,int y){
        int p1=par(x);
        int p2=par(y);
        if(p1==p2)
            return;
        else{
            v[p1]=p2;
            
        }
    }
    
    //ex 1:unio(1,2){par(1)=2 and par(2)=2 // false}
    bool isBipartite(vector<vector<int>>& graph) {
        v.resize(graph.size(),-1);
        for(int i=0;i<graph.size();i++){
            for(int j=0;j<graph[i].size();j++){
        //if node and its adjacents have the same parent ,nobody can divide them(not bipartate)
                if(par(i)==par(graph[i][j]))
                    return false;
               //create a union for nodes reachable by the parent(its children)
                    unio(graph[i][0],graph[i][j]);
            }
        }
       return true; 
        
    }
};
