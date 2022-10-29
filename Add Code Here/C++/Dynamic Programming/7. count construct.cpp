#include<bits/stdc++.h>
#define        ll     long long int
using namespace std;
bool flag=false;
int cnt=0;
bool constructstring(string target,vector<string>v)
{
    if(target.size()==0)
    {
        cnt++;
        flag=true;
        return true;
    }
    for(int i=0; i<v.size(); i++)
    {
        int found=target.find(v[i]);       //finds the word is present in the string or not.
        if(found==0)                      // checks the word is at the beginning of the string or not
        {
            string s;
            s=target;
            s.erase(0,v[i].size());
            constructstring(s,v);
        }
    }
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
    if(flag)cout<<cnt<<endl;
    else cout<<"no"<<endl;
    return 0;
}

