#include<iostream>
using namespace std;

int linearSearch(int arr[],int n,int k)
{
    for(int i=0;i<n;i++)
    {
        if(arr[i]==k)
        {
            return i;
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
    cout<<linearSearch(arr,n,key);

    return 0;
}