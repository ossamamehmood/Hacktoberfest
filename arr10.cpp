//Insertion Sort
#include<iostream>
using namespace std;

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
    for(int i=1;i<n;i++)
    {
        int counter=arr[i];
        int j=i-1;
        while(arr[j]>counter && j>=0)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=counter;
    } 
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }

    return 0;
}