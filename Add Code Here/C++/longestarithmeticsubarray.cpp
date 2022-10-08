/*
Author : Rounak Ghosh
GitHub : rounak-ghosh
Institution : GCETTB
Date : 08/10/2022
*/

#include<iostream>
using namespace std;


void longestsubarray(int arr[], int n)          // GOOGLE KICKSTART PROBLEM
{
    int ans=2;
    int pd = arr[1]-arr[0];
    int i=2;
    int curr=2;

    while(i<n)
    {
        if(pd == arr[i]-arr[i-1])
            curr++;
        else
        {
            pd=arr[i]-arr[i-1];
            curr=2;
        }
        ans=max(ans,curr);
        i++;
    } 
    
    cout<<ans<<endl;
}

int main()              
{
    int n;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    
    longestsubarray(arr, n);
    return 0;
}