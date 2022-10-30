#include<bits/stdc++.h>
#define        ll     long long int
using namespace std;
vector<string>vec;
bool flag=false;
bool constructstring(string target,vector<string>v)
{
   if(target.size()==0){
    for(int i=0;i<vec.size();i++)cout<<vec[i]<<" ";    //prints the construction way
    cout<<endl;
    vec.pop_back();
    flag=true;
    return true;
    }
    for(int i=0;i<v.size();i++){
     int found=target.find(v[i]);       //finds the word is present in the string or not.
      if(found==0){                     // checks the word is at the beginning of the string or not
         string s;
          s=target;
         s.erase(0,v[i].size());
         vec.push_back(v[i]);
         constructstring(s,v);
     }
   }
  vec.pop_back();
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
        if(flag)cout<<"Yes"<<endl;
        else cout<<"no"<<endl;
    return 0;
}
