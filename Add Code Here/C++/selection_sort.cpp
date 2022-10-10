#include <iostream>
using namespace std;

void s_s(int arr[], int n){
    for(int i=0; i<=n-2; i++){
        int min_pos = i;
        // finding positon of min element 
        for(int j=i; j<n; j++){
            if(arr[j] < arr[min_pos]){
                min_pos = j;
            }
        }
        // bringing min element to the front
        swap(arr[i],arr[min_pos]);
    }
}

int main(){
    int arr[]={1,2,3,-4,11,4,33,5,6,7,8,9};
    int n = sizeof(arr)/sizeof(int);

   s_s(arr,n);
   for (auto x : arr){
       cout << x << " ";
   }
}
