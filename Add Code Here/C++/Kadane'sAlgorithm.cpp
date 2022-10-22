// Github Username: amitagoel
#include <iostream>
using namespace std;

class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    long long max(long long x, long long y){
        if(x > y){
            return x;
        }else{
            return y;
        }
    }
    
    long long maxSubarraySum(int arr[], int n){
        
        // Your code here
        long long max_current = arr[0];
        long long max_global = arr[0];
        
        for(int i=1; i<=n-1; i++){
            max_current = max(arr[i], max_current + arr[i]); 
            // cout << max_current << " " << max_global <<  endl;
            
            if(max_current > max_global){
                max_global = max_current;
            }
        }
        
        return max_global;
        
    }
};


int main()
{
    int t,n;
    
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        
        cin>>n; //input size of array
        
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; //input elements of array
            
        Solution ob;
        
        cout << ob.maxSubarraySum(a, n) << endl;
    }
}
