/*
Hungry Pizza Lovers 

Easy Accuracy: 49.48% Submissions: 273 Points: 2
Dominos Pizza has hungry customers waiting in the queue. Each unique order is placed by a customer at time x[i], and the order takes y[i] units of 
time to complete.
You have information on all n orders, Find the order in which all customers will receive their pizza and return it. If two or more orders are 
completed at the same time then sort them by non-decreasing order number.

Example 1:

​Input : arr[ ] = {{4,1}, {6,2}, {7,6}, 
                       {8,1}, {1,3}}
Output : 5 1 2 4 3
Explanation:
Here an array can be transform to 
{5, 8, 13, 9, 4}. Here 5th index order 
received first then 1st order, 2nd order...
return {5, 1, 2, 4, 3}

​Example 2:

Input : arr[ ] = {{1,1}, {1,1}, {1,1}} 
Output :  1 2 3 
 

Your Task:
This is a function problem. The input is already taken care of by the driver code. You only need to complete the function permute() that takes 2-d 
array (arr), sizeOfArray (n), and return the array of order in which customers will receive their pizza. The driver code takes care of the printing.

Expected Time Complexity: O(N*LOG(N)).
Expected Auxiliary Space: O(N).

Constraints:
1 = N = 105
1 = arr[i][0], arr[i][1] = 105
*/

#include<bits/stdc++.h>
using namespace std;
bool comp(const pair<int,int>&a,const pair<int,int>&b){
    if(a.first==b.first)
     return a.second<b.second;
    return a.first<b.first;
}
int main() {
	//code
	int t;cin>>t;
	while(t--){
	    int n,a,b;cin>>n;vector<pair<int,int>>v;
	    for(int i=0;i<n;i++){
	        cin>>a>>b;
	        v.push_back(make_pair(a+b,i+1));
	    }
	    sort(v.begin(),v.end(),comp);
	    for(int i=0;i<n;i++)
	     cout<<v[i].second<<endl;
	}
	return 0;
}
