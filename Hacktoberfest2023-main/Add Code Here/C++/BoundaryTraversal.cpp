//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends

class Solution
{   
    public:
    vector<int> boundaryTraversal(vector<vector<int> > matrix, int n, int m) 
    {
       vector<int> out;
       int i = 0, j = 0;
       for(; j < m;++j) out.push_back(matrix[i][j]);
       ++i; --j; 
       if(n > 1){
           for(; i < n;++i) out.push_back(matrix[i][j]);
           --i; --j;
            if(m > 1){
                for(; j >= 0;--j) out.push_back(matrix[i][j]);
                --i; ++j;
                for(; i > 0;--i) out.push_back(matrix[i][j]);
            }
       }
       return out;    
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int n,m;
        cin>>n>>m;
        vector<vector<int> > matrix(n); 

        for(int i=0; i<n; i++)
        {
            matrix[i].assign(m, 0);
            for( int j=0; j<m; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.boundaryTraversal(matrix, n, m);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends
