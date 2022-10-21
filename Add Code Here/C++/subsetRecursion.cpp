/*
Input:
N = 2
arr[] = {2, 3}
Output:
0 2 3 5
Explanation:
When no elements is taken then Sum = 0.
When only 2 is taken then Sum = 2.
When only 3 is taken then Sum = 3.
When element 2 and 3 are taken then 
Sum = 2+3 = 5.
*/


#include<bits/stdc++.h> 
using namespace std; 

class Solution
{
public:
    void subset(vector<int> arr, int n, vector<int> &ans, int index, int sum) {
        if(index == n) {
            ans.push_back(sum);
            return;
        }
        
        subset(arr, n, ans, index+1, sum+arr[index]);
        subset(arr, n, ans, index+1, sum);
    }
    
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        vector<int> ans;
        int sum = 0;
        subset(arr, N, ans, 0, sum);
        return ans;
    }
};

// Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
