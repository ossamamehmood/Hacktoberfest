#include<bits/stdc++.h>
#define        ll     long long int
using namespace std;
int main()
{                              ///this code only works when all the characters are unique, Its to difficult for me to implement
    string target;    ///the code in c++
    int n;
    cin>>target>>n;
    vector<string>words;
    for(int i=0; i<n; i++)
    {
        string s;
        cin>>s;
        words.push_back(s);
    }
    int length=target.size()+1;
    vector<vector<string> >vec;
    for(int i=0; i<length; i++)
    {
        vector<string>s;
        string x="#";
        s.push_back(x);
        vec.push_back(s);
    }
    vec[0].pop_back();
    vec[0].push_back("&");
    for(int i=0; i<length; i++)
    {
        if(vec[i][0][0]!='#')
        {
            for(int j=0; j<words.size(); j++){
                int found=target.find(words[j],i);
                if(found!=-1 and words[j][0]==target[i] and found>=i){
                    int value=words[j].size()+i;
                    if(vec[value][0][0]=='#')vec[value].pop_back();
                    bool flag=false;
                    for(int k=0; k<vec[i].size(); k++){
                        int m=vec[i][k].size()-1;
                         int o=i-1;
                        if(vec[i][k][0]!='&')vec[value].push_back(vec[i][k]);
                        if(vec[i][k][m]==target[o] and i>0){
                                vec[value].push_back(words[j]);
                                flag=true;
                        }
                    }
                    if(!flag)vec[value].push_back(words[j]);
                }
            }
        }
    }
        for(int j=0; j<vec[length-1].size(); j++){
            cout<<vec[length-1][j]<<" ";
            int m=vec[length-1][j].size()-1;
            int o=length-2;
            if(vec[length-1][j][m]==target[o])cout<<endl;
        }
    return 0;
}

