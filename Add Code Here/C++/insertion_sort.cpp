#include <iostream>
using namespace std;

void i_s(int arr[], int n){
    for(int i=1; i<n; i++){
        int prev= i-1;
        int current= arr[i];
        // loop to find the right index for the current element
        while(prev >= 0 and arr[prev] > current){
            arr[prev+1] = arr[prev];
            prev--;
        }
        arr[prev+1]=current;
    }
}

int main(){
    int arr[]={1,2,3,-4,11,4,33,5,6,7,8,9};
    int n = sizeof(arr)/sizeof(int);

   i_s(arr,n);
   for (auto x : arr){
       cout << x << " ";
   }
}
