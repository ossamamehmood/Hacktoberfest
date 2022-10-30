#include<iostream>
#include<climits>
using namespace std;

int main()
{
    int n;
    cout<<"Enter a number. \n";
    cin>>n;

    int array[4]={n};
    for(int i=0;i<n;i++)
    {
        cout<<"Enter an element. \n";
        cin>>array[i];
    }
    int maxNo=INT_MIN;
    int minNo=INT_MAX;

    for(int i=0;i<n;i++)
    {
        maxNo=max(maxNo,array[i]);
        minNo=min(minNo,array[i]);
    } 
    cout<<maxNo<<" "<<minNo;

    return 0;
}