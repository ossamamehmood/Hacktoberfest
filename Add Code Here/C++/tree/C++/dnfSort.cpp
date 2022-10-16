#include<bits/stdc++.h>

using namespace std;

//Code for DNF sort
void DNFsort(int arr[],int n){
    int low=0;
    int mid=0;
    int high=n-1;

    while (mid<=high)
    {
        if(arr[mid]==0){
            swap(arr[low],arr[mid]);
            low++;
            mid++;
        }
        else if(arr[mid]==1){
            mid++;
        }
        else{
            swap(arr[mid],arr[high]);
            high--;
        }
    }
    
}
// main fuction
int main(){
    cout<<"Enter the number of terms:";
    int N;
    cin>>N;         // input number of elements

    int arr[N];

    cout<<"Enter the terms:";

    for(int i=0;i<N;i++){
        cin>>arr[i];        // input array of elements
    }

    // call for DNF sort fuction
    DNFsort(arr,N);
    for(int i=0;i<N;i++){
        cout<<arr[i]<<" ";   // print the sorted array
    }

    return 0;
}