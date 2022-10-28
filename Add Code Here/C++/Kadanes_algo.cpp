//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    long long maxSubarraySum(int arr[], int n){
        int sum =0;
        int maxi = INT_MIN;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            
            maxi = max(maxi,sum);
            if(sum<0)
                 sum = 0;
        }
        return maxi;
    }
};


int main()
{
    int t,n;
    
    cin>>t; 
    while(t--) 
    {
        
        cin>>n; 
        
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; 
            
        Solution ob;
        
        cout << ob.maxSubarraySum(a, n) << endl;
    }
}

