#include<bits/stdc++.h>
using namespace std;

int32_t main()
{
    int mx=INT_MIN;
    int n;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        mx=max(mx,arr[i]);
        cout<<mx<<" ";
    }

    return 0;
}