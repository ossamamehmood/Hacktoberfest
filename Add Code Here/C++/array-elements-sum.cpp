#include<iostream>
using namespace std;

void printSum(int arr[], int size){
    int sum = 0;

    for(int i=0; i<size; i++){
        sum = sum + arr[i];
    }

    cout<<"The sum of the array elements is "<< sum;
}

int main(){
    int size;
    int arr[20]={1,2,3,4,5,6,7,8,9,10};
    cout<<"Enter the size of the array ";

    cin>>size; 

    printSum(arr,size);
}
