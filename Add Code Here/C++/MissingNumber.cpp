#include <bits/stdc++.h>
using namespace std;
int main()
{
    cout<<"Enter a number : "<<endl;
    int n;
    cin>>n;
    cout<<"Enter the numbers successively "<<endl;
    vector<int> v(n-1);
    for(int i=0;i<n-1;i++)
    cin>>v[i];
    
    cout<<"The missing number is "<<(n*(n+1))/2-accumulate(v.begin(),v.end(),0);
    
    
    
}
