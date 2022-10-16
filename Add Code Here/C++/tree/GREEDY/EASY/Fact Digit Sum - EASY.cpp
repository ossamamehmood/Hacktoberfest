/*
Fact Digit Sum 

Easy Accuracy: 59.03% Submissions: 797 Points: 2
A(X) for positive integer X is the sum of factorials of its digits. For example, A(154) = 1! + 5! + 4!= 145.
Given a number N, find the minimum number X such that A(X) = N. 

 

Example 1:

Input: N = 40321
Output: 18
Explanation: A(18)=1!+ 8! =40321 
Note that A(80) = A(81) is also 
40321, But 18 is the smallest 
number.
 

Example 2:

Input: N = 5040
Output: 7
Explanation: A(7) = 7! = 5040.
 

Your Task:
You don't need to read or print anything. Your task is to complete the function FactDigit() which takes N as input parameter and returns a list of 
digits which represent the number X.
 

Expected Time Complexity: O(K) where K = 106
Expected Space Complexity: O(K)
 

Constraints:
1 = N = 109
*/

#include<bits/stdc++.h>
using namespace std;
int a[10]={1,1,2,6,24,120,720,5040,40320,362880};
void check(int n,vector<int>&v,int d)
{
    if(n==0)
       return;
    if(a[d]>n)
    {
        d--;
        check(n,v,d);
    }
    else
    {
        n=n-a[d];
        v.push_back(d);
        check(n,v,d);
    }
}
int main()
{
    long long int t,n,s;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int i,j;
        vector<int>v;
        check(n,v,9);
        for(i=v.size()-1;i>=0;i--)
            cout<<v[i];
        cout<<endl;
    }
    return 0;
    
}
