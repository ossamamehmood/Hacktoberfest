#include<bits/stdc++.h>
#define        ll     long long int
using namespace std;
int main()
{
    string s;
    int n;
    cin>>s>>n;
    vector<string> v;
    for(int i=0; i<n; i++)
    {
        string x;
        cin>>x;
        v.push_back(x);
    }
    int length=s.size()+1;
    int table[length];
    memset(table,0,sizeof(table));
    table[0]=1;
    for(int i=0; i<length; i++)
    {
        if(table[i])
        {
            for(int j=0; j<v.size(); j++)
            {
                int found=s.find(v[j],i);
                if(found!=-1 and v[j][0]==s[i] and found>=i)
                {
                    int value=v[j].size()+i;
                    table[value]+=table[i];
                }
            }
        }
    }
    if(table[length-1]>0)cout<<table[length-1]<<endl;
    else cout<<"NO"<<endl;
     //for(int i=0;i<length;i++)cout<<table[i]<<endl;
    return 0;
}


