#include<bits/stdc++.h>
#define        ll     long long int
using namespace std;
unordered_map<string,bool>dp;
bool constructstring(string target,vector<string>v)
{
    if(target.size()==0)
    {
        flag=true;
        return true;
    }
    if(dp.count(target)>0) return dp[target];
    
    for(int i=0; i<v.size(); i++)
    {
        int found=target.find(v[i]);
        if(found==0)
        {
            string s;
            s=target;
            s.erase(0,v[i].size());
            if(constructstring(s,v)==true){ dp[target]=true; return true;}
        }
    }
    dp[target]=false;
    return false;
}
int main()
{
    string s;
    cin>>s;
    int n;
    cin>>n;
    vector<string>v;
    for(int i=0; i<n; i++)
    {
        string x;
        cin>>x;
        v.push_back(x);
    }
    constructstring(s,v);
    if(constructstring(s,v)==true)cout<<"Yes"<<endl;
    else cout<<"no"<<endl;
    return 0;
}

