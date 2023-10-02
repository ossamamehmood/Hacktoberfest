#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int pivot=1;
    while(pivot<n){
        for(int j=0; j<n-pivot; j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
        pivot++;
    }
    cout<<"SORTED ARRAY : ";
    for(int k=0; k<n; k++){
        
        cout<<arr[k]<<" ";
    }
 return 0;
}