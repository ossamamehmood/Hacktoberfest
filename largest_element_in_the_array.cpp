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

    int arr[]={1,24,35,6,7};
    cout<<"The largest number is : "<<largestElement(arr,5)<<endl;

return 0;
}
