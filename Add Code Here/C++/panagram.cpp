#include<bits/stdc++.h>
#include<string.h>
using namespace std;
int main()
{
    string a;
    getline(cin,a);
    set<char> myset;
    transform(a.begin(), a.end(), a.begin(), ::tolower);
    for(int i=0;i<a.length();i++)
    {
        if(a[i]>='a' && a[i]<='z')
            myset.insert(a[i]);
    }
    if(myset.size()==26)
            cout<<"panagram";
    else    
        cout<<"not panagram";
    return 0;
}
