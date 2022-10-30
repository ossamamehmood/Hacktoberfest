#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

int lcs(int, int, string, string);

int main()
{
    int t,n,k,x,y;
    
    cin>>t;
    while(t--)
    {
        cin>>x>>y;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        
        cout << lcs(x, y, s1, s2) << endl;
    }
    return 0;
}
// } Driver Code Ends


// function to find longest common subsequence

int lcs(int m, int n, string s1, string s2){
   
   int t[m+1][n+1];
   
   //Base Case
   for(int i=0;i<m+1;i++)
   {
       for(int j=0;j<n+1;j++)
       {
           if(i==0||j==0)
           t[i][j]=0;
       }
   }
   
   //Main Case
   for(int i=1;i<m+1;i++)
   {
        for(int j=1;j<n+1;j++)
        {
            if(s1[i-1]==s2[j-1])
            {
                t[i][j] = 1 + t[i-1][j-1];
            }
            else
            {
                t[i][j] = max(t[i-1][j],t[i][j-1]);
            }
        }
   }
   return t[m][n];
   
    
}
