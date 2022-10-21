class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>inedge(n,0),outedge(n,0);
        for(int i=0;i<trust.size();i++){
            outedge[trust[i][0]]++;
            inedge[trust[i][1]]++;
            
        }
        for(int i=0;i<n;i++){
            if(inedge[i]==n-1 and outedge[i]==0) return i;
        }
        return -1;
        
    }
};