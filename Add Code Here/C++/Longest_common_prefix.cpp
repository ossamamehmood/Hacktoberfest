#include<bits/stdc++.h>
using namespace std;


class Solution{
  public:
   string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        string s = "";
        sort(strs.begin(),strs.end());
        string start = strs[0],end = strs[n-1];
        int i=0;
        while(i<strs[0].length() && start[i]==end[i]){
              s += start[i];
            i++;
        }
        return s;
    }
};


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        vector <string> s = {"flower","flow","flight"};
        Solution obj;
        cout<<obj.minJumps(s)<<endl;
    }
    return 0;
}
