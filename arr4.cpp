#include<iostream>
using namespace std;

int binarySearch(int arr[],int n,int k)
{
    int s=0;
    int e=n;
    while(s<=e)
    {
        int mid=(s+e)/2;
        if(mid==k)
        {
            return mid;
        }
        else if(arr[mid]>k)
        {
            e=mid-1;
        }
        else
        {
            s=mid+1;
        }
    }
    return -1;
}

int main()
{
    int n;
    cout<<"Enter a number. \n";
    cin>>n;

    int arr[n];
    cout<<"Enter elements. \n";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int key;
    cout<<"Enter element to be searched. \n";
    cin>>key;

    cout<<binarySearch(arr,n,key);

    return 0;
}