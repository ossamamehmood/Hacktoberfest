#include<bits/stdc++.h>

using namespace std;

class Solution{

    public:
    long long trappingWater(int arr[], int n){
        // code here
        vector<int> left(n);
        vector<int> right(n);
        
        left[0] = arr[0];
        
        for(int i=1;i<n;i++){
            left[i] = max(left[i-1],arr[i]);
        }
        
        right[n-1] = arr[n-1];
        
        for(int i=n-2;i>=0;i--){
            right[i] = max(right[i+1],arr[i]);
        }
        
        long long ans=0;
        for(int i=1;i<n;i++){
            ans += (min(left[i],right[i]) - arr[i]);
        }
        return ans;
    }
};


int main(){
    int t;
    cin >> t;
    
    while(t--){
        int n;
        cin >> n;
        int a[n];
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}
// } Driver Code Ends
