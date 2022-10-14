#include <iostream>
using namespace std;

int k_s(int arr[], int n){
    int cs=0,ms=0,total_sum=0; // current sum and maximum sum
    for(int i=0; i<n; i++){
        total_sum += arr[i];
    }
    for(int k=0; k<n; k++){
        if (arr[k]<0){
            return total_sum;
        }
    }
    for(int i=0; i<n; i++){
        cs += arr[i];
        if(cs<0){
            cs=0;
        }
        ms = max(cs , ms);
    }
    return ms;
}

int main(){
    int arr[]={-3,-6,-9};
    int n = sizeof(arr)/sizeof(int);

    for(int i=0; i< n; i++){
        cout << arr[i] << " "; 
    }  

    cout << endl;  

   int t= k_s(arr,n);
   cout << t;

}
