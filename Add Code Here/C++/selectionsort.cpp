#include<iostream>
using namespace std;
int selectionssort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int minindex=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[minindex]){
                minindex=j;
            }
        }
        swap(arr[minindex],arr[i]);
    }

}
void print(int arr[],int n){
    for(int i=0; i<n;i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int arr[4]={2,5,4,3};
    selectionssort(arr,4);
    print(arr,4);

}
