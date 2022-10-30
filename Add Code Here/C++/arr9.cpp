#include<iostream>
using namespace std;

int bubbleSort(int arr[],int n)
{
    for (int a=0;a<n;a++) {
        for(int i=0;i<=n-a-1;i++) {
            if(arr[i]>arr[i+1]) {
                int temp=arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=temp;
            }
        }
    }
    return arr[n];
}

int BinarySearch(int arr[],int n,int key){
    int s=0;
    int e=n;
    while(s<=e){
        int mid=(s+e)/2;
        if(arr[mid]==key){
        cout<<endl;
        return mid;
    }else if (arr[mid]<key)
    {
        s=mid+1;
    }else if (arr[mid]>key)
    {
        e=mid-1;
    }
    }cout<<endl;
    return -1;
}

int main()
{
    int n;
    cout<<"Enter a number. \n"; 
    cin>>n;

    int arr[n];
    cout<<"Enter elements. \n";
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }

    int key;
    cout<<"Enter the key to be searched. \n";
    cin>>key;
    cout<<bubbleSort(arr,n)<<endl;
    cout<<"The elements in proper order are:";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<BinarySearch(arr,n,key)<<endl;

    return 0;
}