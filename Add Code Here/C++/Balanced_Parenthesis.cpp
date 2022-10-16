// Github username: kashika1109
// Aim: Balanced Parenthesis in C++
// Date: 10 October 2022


// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

#include<stack>
class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        // Your code here
        stack<char> str;
        if(x.size()==0) return false;
        for(int i=0;i<x.size();i++){
            if( x[i]=='{' || x[i]=='(' || x[i]=='[' ){ 
                str.push(x[i]);
            }
            else{
                if(str.empty()) return false;
                if(( x[i]==')' && str.top()=='(' )|| (x[i]=='}' && str.top()=='{' ) || (x[i]==']' && str.top()=='[' )){
                    str.pop();
                    continue;
                }
                else{
                    return false;
                }
            }
        }
        if(!str.empty()) return false;
        return true;
    }

};

// { Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}  // } Driver Code Ends
