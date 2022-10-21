/*
Largest number possible 

Easy Accuracy: 43.23% Submissions: 11002 Points: 2
Given two numbers 'N' and 'S' , find the largest number that can be formed with 'N' digits and whose sum of digits should be equals to 'S'.

Example 1:

Input: N = 2, S = 9
Output: 90
Explaination: It is the biggest number 
with sum of digits equals to 9.
Example 2:

Input: N = 3, S = 20
Output: 992
Explaination: It is the biggest number 
with sum of digits equals to 20.
Your Task:
You do not need to read input or print anything. Your task is to complete the function findLargest() which takes N and S as input parameters and 
returns the largest possible number. Return -1 if no such number is possible.

Expected Time Complexity: O(N)
Exepcted Auxiliary Space: O(1)

Constraints:
1 = N = 104
0 = S = 105
*/

// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


// User function Template for C++

class Solution{
public:
    string findLargest(int N, int S){
        // code here
        int a[N],f=0;string s="";
      //  if()
        if(S==0 && N>1)
         return "-1";
        else if(9*N<S)
         return "-1";
        for(int i=0;i<N;i++)
        if(S>=9)
         {s+="9";S=S-9;}
        else 
         {s+=to_string(S);S=0;}
       // else {f=1;break;}
       
      
        
        return s;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, S;
        cin>>N>>S;
        
        Solution ob;
        cout<<ob.findLargest(N, S)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
