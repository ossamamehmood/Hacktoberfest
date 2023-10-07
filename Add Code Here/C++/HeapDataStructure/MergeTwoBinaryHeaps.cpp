//{ Driver Code Starts
// Initial Template for C++

// C++ program to merge two max heaps.

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    
    void heapify(vector<int> &ans,int i,int n) {
        int largest = i;
        int left = 2*i+1;
        int right = 2*i+2;
        
        if(left < n and ans[largest] < ans[left])
            largest = left;
        if(right < n and ans[largest] < ans[right])
            largest = right;
            
        if(largest != i)
        {
            swap(ans[largest],ans[i]);
            heapify(ans,largest,n);
        }
    }
    
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        // your code here
        vector<int> ans(m+n);
        int i = 0;
        int j = 0;
        int k = 0;
        while(i<n and j<m) {
            if(a[i] < b[j]){
                ans[k++] = a[i++];
            }
            else {
                ans[k++] = b[j++];
            }
        }
        // if there are any left over elements
        while(i<n) {
            ans[k++] = a[i++];
        }
        
        while(j<m) {
            ans[k++] = b[j++];
        }
        
        for(int i = (ans.size()/2) - 1;i>=0;i--) {
            heapify(ans,i,ans.size());
        }
        return ans;
    }
};

//{ Driver Code Starts.

bool isMerged(vector<int> &arr1, vector<int> &arr2, vector<int> &merged){
    if (arr1.size() + arr2.size() != merged.size()){
        return false;
    }
    arr1.insert(arr1.end(),arr2.begin(),arr2.end());
    sort(arr1.begin(),arr1.end());
    vector<int> mergedCopy =merged;
    sort(mergedCopy.begin(),mergedCopy.end());
    if (arr1 != mergedCopy){
        return false;
    }
    for(int i = 1; i<merged.size(); i++){
        if(merged[i] > merged[(i-1)/2])
            return false;
    }
    return true;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, i;
        cin >> n >> m;
        vector<int> a(n,0),b(m,0);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (i = 0; i < m; i++) {
            cin >> b[i];
        }
        vector<int> merged, copyA = a, copyB = b;
        Solution obj;
        merged = obj.mergeHeaps(a, b, n, m);
        bool flag = isMerged(copyA, copyB, merged);
        if(flag == false) cout<<0<<endl;
        else cout<<1<<endl;
    }
    return 0;
}

// } Driver Code Ends