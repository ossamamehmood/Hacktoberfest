/*
Problem Statement => 
Given N activities with their start and finish day given in array start[ ] and end[ ]. Select the maximum number of activities that can be performed by a single person, assuming that a person can only work on a single activity at a given day.
Note : Duration of the activity includes both starting and ending day.
Example - 1
Input -> N = 2 
        start[] = {2 ,1}
        end[] = {2 ,2}
Output -> 1 
Explanation - A person can perform only one of the given activities.


Example - 2
Input-> N = 4 
        start[] = {1 ,3 ,2 ,5}
        end[] = {2 ,4 ,3, 6}
Output -> 3
Explanation -> A person can perform activities 1, 2 and 4.


Your Task :
You don't need to read input or print anything. Your task is to complete the function activityselection() which takes array start[ ], array end[ ] and integer N as input parameters and returns the maximum number of activities that can be done.

*/
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of activities that can
    //be performed by a single person.
    
    int activitySelection(vector<int> start, vector<int> end, int n)
    {
        // Your code here
        vector<pair<int , int>> result ; 
        for(int i = 0 ; i < n ; i++)
        {
            result.push_back(make_pair(end[i] , start[i])) ; 
        }
        
        sort(result.begin() , result.end()) ; 
        int res = 1 ; 
        int prev = 0 ; 
        for(int i = 1 ; i < n ; i++ ) 
        {
            if(result[i].second > result[prev].first)
            {
                res++ ; 
                prev = i  ;
            }
        }
        return res ; 
        
    }
};
// { Driver Code Starts 
int main()
{
    int t ; 
    // testcases 
    cin >> t ; 
    while(t--)
    {
        // size of array 
        int n ; 
        cin >> n ; 
        vector<int> start(n) , end(n) ; 
        // adding elements to arrays start and end
        for(int i = 0 ; i < n ; i++)
        {
            cin >> start[i] ; 
        }
        for(int i = 0 ; i < n ; i++)
        {
            cin >> end[i] ; 
        }
        Solution ob ; 
        // function call 
        cout << ob.activitySelection(start,end, n) << endl ;
    } 
}

// } Driver Code Ends
