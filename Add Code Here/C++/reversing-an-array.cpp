#include<iostream>
using namespace std;

void printArray(int arr[],int size){

    for(int i=1 ; i<size; i++ ){
        cout<<arr[i]<<" ";
    }
}

void reverse(int arr[],int size){

    int start=0;
    int end=size-1;

    while(start<=end){
        swap(arr[start],arr[end]);
        start++;
        end--;
    }
}

int main(){

    int arr[6]={2,3,4,5,6};
    int brr[8]={1,2,3,4,5,6,7};

    reverse(arr,6);
    reverse(brr,8);

    printArray(arr,6);
    cout<<endl;
    printArray(brr,8);
}
