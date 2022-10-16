#include<iostream>
using namespace std;

int largestElement(int arr[],int n){
    int largest = arr[0];
    for(int i =1;i<n;i++){
        if(largest<arr[i]){
            largest = arr[i];
        }

    }
    return largest;


}


int main(){
     int n;
    cout<<"Enter the length of Array"<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter the Array Elements"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"The largest number is : "<<largestElement(arr,n)<<endl;

return 0;
}
