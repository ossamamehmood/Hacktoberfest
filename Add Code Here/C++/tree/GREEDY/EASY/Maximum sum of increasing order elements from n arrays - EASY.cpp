/*
Maximum sum of increasing order elements from n arrays 

Easy Accuracy: 56.6% Submissions: 530 Points: 2
Given n arrays of size m each. Find maximum sum obtained by selecting a number from each array such that the element selected from the i-th array is 
more than the element selected from (i-1)-th array. If maximum sum cannot be obtained then return 0.

Example 1:

​Input : arr[ ] = {{1,7,4,3}, {4,2,5,1}, {9,5,1,8}}
Output : 18
Explanation:
We can select 4 from the first array,
5 from second array and 9 from the third array.

​Example 2:

Input : arr[ ] = {{9,8,7}, {6,5,4}, {3,2,1}} 
Output :  0

Your Task:
This is a function problem. The input is already taken care of by the driver code. You only need to complete the function maximumSum() that takes 
number of row N, a number of Column M, 2-d array (arr), and return the maximum sum if cannot be obtained then return 0. The driver code takes care of 
the printing.

Expected Time Complexity: O(N*M).
Expected Auxiliary Space: O(1).

 

Constraints:
1 = N, M = 500
*/

#include<bits/stdc++.h> 
using namespace std;
void scan(int a[],int n)
{
    for(int i=0;i<n;i++)
	   {
	       cin>>a[i];
	   }
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	   int n,m;
	   cin>>n>>m;
	   int a[n][m];
	   for(int i=0;i<n;i++)
	   {
	       for(int j=0;j<m;j++)
	       cin>>a[i][j];
	   }
	   for(int i=0;i<n;i++)
	   {
	       sort(*(a+i),*(a+i)+m);
	   }
	   int i=n-1,j=m-1,c[n],k=0,p=1;
	   while(i>=0 && j>=0)
	   {
	       if(i==n-1 && j==m-1)
	       {
	           c[k]=a[i][j];
	           k++;
	           i--;
	       }
	       else
	       {
	           if(a[i][0]>=c[k-1])
	           {
	               p=0;
	               break;
	           }
	           else if(a[i][j]>=c[k-1])
	           {
	               j--;
	           }
	           else if(a[i][j]<c[k-1])
	           {
	               c[k]=a[i][j];
	               k++;
	               j=m-1;
	               i--;
	           }
	       }
	   }
	   if(p==0)
	   {
	       cout<<"0"<<"\n";
	   }
	   else
	   {
	   int s=0;
	   for(int i=0;i<n;i++)
	   {
	       s+=c[i];
	   }
	   cout<<s<<"\n";
	   }
	}
	return 0;
}
