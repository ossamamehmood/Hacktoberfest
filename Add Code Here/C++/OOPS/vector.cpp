#include<iostream>
#include<vector>
using namespace std;
void display(vector<int> x)
{
    for(int i=0;i<x.size();i++)
    cout<<x.at(i)<<" ";
}

void display_iterator(vector<int> a)
{
    vector<int> :: iterator it;
    for(it=a.begin();it!=a.end();it++)
    cout<<*it<<" ";
}
int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    display(v);
    cout<<endl;
    display_iterator(v);
     

    return 0;
}