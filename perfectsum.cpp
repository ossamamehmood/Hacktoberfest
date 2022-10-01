//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	
	
	int perfectSum(int arr[], int n, int sum)
	{
        // // Your code goes here
        int t[n+1][sum+1] ={0};
       // int c=0;
       
    //   for(int i=0;i<n;i++) if(!arr[i])   c++;
       
       
    //       for(int j=1;j<sum+1;j++)  t[0][j]=0;
        
    //     for(int i=0;i<n+1;i++)t[i][0] = 1;
        for(int i = 0;i<n+1;i++)
        {
            for(int j=0;j<sum+1;j++)
            {
                if(i==0)
                t[i][j] = 0;
                if(j==0)
                t[i][j] = 1;
            }
        }
        for(int i=1;i<n+1;i++)
        {
            for(int j=0;j<sum+1;j++)
            {
                if(arr[i-1]<=j)
                
                    t[i][j] = (t[i-1][j-arr[i-1]]%1000000007+t[i-1][j]%1000000007)%1000000007;
                
                else
                t[i][j] = t[i-1][j]%1000000007;
            }
        }
        
        return t[n][sum];
        //vector<vector<int>> dp(n+2,vector<int>(sum+2,-1));
        
        //int ans = count(sum,arr,0,&dp,n);
      //  return ans;
        
        
        
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends
