//Order Agnostic Binary Search in C++
//Binary Search in sorted array of both ascending and descending order
#include<bits/stdc++.h>
using namespace std;
int binarySearch(int arr[],int target,int n){
    int start=0;
    int end=n-1;
    bool isAscending=arr[start]<arr[end];
    while(start<=end){
        int mid=start+(end-start)/2;
        if(arr[mid]==target)
        return mid;
        if(isAscending){
            if(target<arr[mid]){
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        else{
            if(target>arr[mid]){
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
    }
    return -1;
}
int main(){
    int arr[]={6,5,4,3,2,1};
    int target=1;
    int len=sizeof(arr)/sizeof(arr[0]);
    int index=binarySearch(arr,target,len);
    cout<<"The value of the index of the target element is:"<<index<<endl;
    return 0;
}