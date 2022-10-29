//Bubble Sort
#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter a number. \n";
    cin>>n;
    int arr[n];
    cout<<"Enter elements. \n";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    for(int counter=1;counter<n;counter++){
        for(int i=0;i<n-1;i++){
            if(arr[i]>arr[i+1])
            {
                int temp=arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=temp;
            }
        }
    }
    for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
    }
    return 0;
}