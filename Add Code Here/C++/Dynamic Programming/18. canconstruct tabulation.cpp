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
    bool table[length];
    memset(table,false,sizeof(table));
    table[0]=true;
    for(int i=0; i<length; i++)
    {
        if(table[i])
        {
            for(int j=0; j<v.size(); j++)
            {
                int found=s.find(v[j],i);                           // using find function to check the word is present in the string or not
                if(found!=-1 and v[j][0]==s[i] and found>=i)    // if the word is not present found will be -1
                {
                    int value=v[j].size()+i;
                    table[value]=true;
                }
            }
        }
    }
    if(table[length-1])cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    // for(int i=0;i<length;i++)cout<<table[i]<<endl;
    return 0;
}


