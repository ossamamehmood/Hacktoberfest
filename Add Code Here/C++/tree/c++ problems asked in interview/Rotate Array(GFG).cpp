Given an unsorted array arr[] of size N, rotate it by D elements (clockwise). 

Input:
The first line of the input contains T denoting the number of testcases. First line of each test case contains two space separated elements, 
N denoting the size of the array and an integer D denoting the number size of the rotation. Subsequent line will be the N space separated array elements.

Output:
For each testcase, in a new line, output the rotated array.
  
Example:
Input:
2
5 2
1 2 3 4 5 
10 3
2 4 6 8 10 12 14 16 18 20

Output:
3 4 5 1 2
8 10 12 14 16 18 20 2 4 6

Explanation :
Testcase 1: 1 2 3 4 5  when rotated by 2 elements, it becomes 3 4 5 1 2.
  
#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	while(t--)
	{
	    int  n,d;
	    cin>>n>>d;
	    int a[n];
	    for(int i=0;i<n;i++)
	    {
	        cin>>a[(i+n-d)%n];
	    }
	    
	    for(int i=0;i<n;i++)
	    {
	        cout<<a[i]<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}

Time Complexity - O(n) , because we are traversing the whole array once. 
