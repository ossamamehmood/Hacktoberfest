#include<iostream>
using namespace std;
int main(){
    int arr[5]={12, 11, 13, 5, 6};
    int i,j,key;
    int n=5;
    for(int i=0;i<n-1;i++){
       for(int j=0;j<n-i-1;j++){
        if(arr[j]>arr[j+1]){
           swap(arr[j],arr[j+1]);
        }
       }
    }
for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
}
}
