/*
Minimum Platforms 

Medium Accuracy: 46.78% Submissions: 71328 Points: 4
Given arrival and departure times of all trains that reach a railway station. Find the minimum number of platforms required for the railway station 
so that no train is kept waiting.
Consider that all the trains arrive on the same day and leave on the same day. Arrival and departure time can never be the same for a train but we 
can have arrival time of one train equal to departure time of the other. At any given instance of time, same platform can not be used for both 
departure of a train and arrival of another train. In such cases, we need different platforms.


Example 1:

Input: n = 6 
arr[] = {0900, 0940, 0950, 1100, 1500, 1800}
dep[] = {0910, 1200, 1120, 1130, 1900, 2000}
Output: 3
Explanation: 
Minimum 3 platforms are required to 
safely arrive and depart all trains.
Example 2:

Input: n = 3
arr[] = {0900, 1100, 1235}
dep[] = {1000, 1200, 1240}
Output: 1
Explanation: Only 1 platform is required to 
safely manage the arrival and departure 
of all trains. 

Your Task:
You don't need to read input or print anything. Your task is to complete the function findPlatform() which takes the array arr[] (denoting the
 arrival times), array dep[] (denoting the departure times) and the size of the array as inputs and returns the minimum number of platforms required
  at the railway station such that no train waits.

Note: Time intervals are in the 24-hour format(HHMM) , where the first two characters represent hour (between 00 to 23 ) and the last two characters
 represent minutes (between 00 to 59).


Expected Time Complexity: O(nLogn)
Expected Auxiliary Space: O(n)


Constraints:
1 = n = 50000
0000 = A[i] = D[i] = 2359
*/

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	sort(arr,arr+n);
    	sort(dep,dep+n);
    	
    	int platform_Needed = 1;
    	int result = 1;
    	int i=1,j=0;
    	
    	while(i<n && j<n){
    	    //In this case there is a train at the platform
    	    //So we will need a new platform
    	    if(arr[i]<=dep[j]){
    	        
    	        //we need a platform
    	        platform_Needed++;
    	        //we move to next arrival train
    	        i++;
    	        
    	    }
    	    //In this case there is no train at one of the previous platform
    	    //required
    	    //So we will decrease the platform
    	    else if(arr[i]>dep[j]){
    	        platform_Needed--;
    	        //Move the departure time pointer further
    	        j++;
    	    }
    	    
    	    result = max(result,platform_Needed);
    	}
    	
    	return result;
    }
};


// { Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}  // } Driver Code Ends
