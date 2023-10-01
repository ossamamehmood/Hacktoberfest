#include<iostream>
using namespace std;

int main(){
    
    int arr[4] = {11,55,35,10};

    int n = 4;

    for(int i=0;i<n-1;i++){
        int min = i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[i]){
                min = j;
            }
           
        }
        swap(arr[min],arr[i]);
    }

    for(int i =0;i<n;i++){
        cout<<arr[i]<<",";
    }
   
    return 0;
}