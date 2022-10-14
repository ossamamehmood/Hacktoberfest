#include <bits/stdc++.h>
using namespace std;


class Solution
{
    public:
        string UncommonChars(string A, string B)
        {
            // code here
            int a[26][2] = {0};
            for(int i=0;i<A.size();i++){
                 a[A[i]-'a'][0] = 1;
            }
            for(int i=0;i<B.size();i++){
                a[B[i]-'a'][1] = 1;
            }
            string s="";
            for(int i=0;i<26;i++){
                if((a[i][0] || a[i][1]) && (a[i][0]!=a[i][1])){
                    s += ('a' + i);
                }
            }
            if(s=="")
                return "-1";
            return s;
        }
};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string A,B;
        cin>>A;
        cin>>B;
        Solution ob;
        cout<<ob.UncommonChars(A, B);
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends
