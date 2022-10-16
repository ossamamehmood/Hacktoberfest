/*
Question:
Find the largest rectangular area possible in a given histogram where the largest rectangle can be made of a number of contiguous bars. For simplicity, assume that all bars have the same width and the width is 1 unit, there will be N bars height of each bar will be given by the array arr.


Example 1:
Input:
N = 7
arr[] = {6,2,5,4,5,1,6}
Output: 12


Example 2:
Input:
N = 8
arr[] = {7 2 8 9 1 3 6 5}
Output: 16
Explanation: Maximum size of the histogram 
will be 8  and there will be 2 consecutive 
histogram. And hence the area of the 
histogram will be 8x2 = 16.


Your Task:
The task is to complete the function getMaxArea() which takes the array arr[] and its size N as inputs and finds the largest rectangular area possible and returns the answer.

Expected Time Complxity : O(N)
Expected Auxilliary Space : O(N)

Constraints:
1 ≤ N ≤ 106
1 ≤ arr[i] ≤ 1012
*/

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    vector<long long> leftarr(long long arr[], int n){
        stack<pair<long long, int>> st;
        vector<long long> v;
        for(int i=0; i<n; ++i){
            if(st.empty()) v.push_back(-1);
            else if(st.top().first<arr[i]){
                v.push_back(st.top().second);
            }
            else{
                while(!st.empty() && st.top().first>=arr[i]){
                    st.pop();
                }
                if(st.empty()) v.push_back(-1);
                else{
                    v.push_back(st.top().second);
                }
            }
            
            st.push(make_pair(arr[i], i));
        }
        return v;
    }
    
    vector<long long> rightarr(long long arr[], int n){
        stack<pair<long long, int>> st;
        vector<long long> v;
        for(int i=n-1; i>=0; --i){
            if(st.empty()) v.push_back(n);
            else if(st.top().first<arr[i]){
                v.push_back(st.top().second);
            }
            else{
                while(!st.empty() && st.top().first>=arr[i]){
                    st.pop();
                }
                if(st.empty()) v.push_back(n);
                else{
                    v.push_back(st.top().second);
                }
            }
            st.push(make_pair(arr[i], i));
        }
        reverse(v.begin(), v.end());
        return v;
    }
    
    long long getMaxArea(long long arr[], int n)
    {
        vector<long long> left = leftarr(arr, n);
        vector<long long> right = rightarr(arr, n);
        vector<long long> v;
        for(int i=0; i<n; ++i){
            long long mm = arr[i]*(right[i]-left[i]-1);
            v.push_back(mm);
            mm=0;
        }
        
        long long max = v[0];
        for(int i=1; i<n; ++i){
            max =(v[i]>max)?v[i]:max;
        }
        return max;
    }
};


//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}

// } Driver Code Ends
