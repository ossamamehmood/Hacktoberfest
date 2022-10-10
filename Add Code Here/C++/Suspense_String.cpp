/*
Codechef Problem: Suspense String
Problem Code:SUSSTR
Description:
Alice and Bob are playing a game with a binary string SS of length NN and an empty string TT.
They both take turns and Alice plays first.

1. In Alice's turn, she picks the first character of string SS, appends the character to either the front or back of string TT and deletes 
   the chosen character from string SS.
2. In Bob's turn, he picks the last character of string SS, appends the character to either the front or back of string TT and deletes the 
   chosen character from string SS.
   
The game stops when SS becomes empty.
Alice wants the resultant string TT to be lexicographically smallest, while Bob wants the resultant string TT to be lexicographically largest possible.

Find the resultant string TT, if both of them play optimally.

Test Cases:
Input:
4
2
10
4
0001
6
010111
10
1110000010

Output:
10
0100
101101
0011011000

*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    string s;
	    cin>>s;
	    string T ="";
	    int i=0;
	    int j=n-1;
	    while(i<=j)
	    {
	        if(s[i]=='0')
	        {
	            T=s[i]+T;
	        }
	        else{
	            T=T+s[i];
	        }
	        if(i<j)
	        {
	            if(s[j]=='0')
	        {
	            T=T+s[j];
	        }
	        else{
	            T=s[j]+T;
	        }
	        j--;
	            
	        }
	        i++;
	    }
	    cout<<T<<endl;
	    
	    
	}
	return 0;
}
