#include "iostream"
using namespace std;


void heapify(int arr[], int n, int i){
    int largest = i;
    int leftChild = 2*i+1;
    int rightChild = 2*i+2;

    if(leftChild < n && arr[largest] < arr[leftChild])
        largest = leftChild;

    if(rightChild < n && arr[largest] < arr[rightChild])
        largest = rightChild;

    if(largest != i){
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }

}


void heapSort(int arr[], int n){
    if(n <= 1) return;

    int size = n-1;
    while(size > 0){

        swap(arr[0], arr[size]);
        size--;

        heapify(arr, size+1, 0);
    }

}


int main(){

    int arr[9] = {20,10,8,0,-5,50, 43, 7,8};
    int n=sizeof(arr)/sizeof(arr[0]);

    for(int i=n/2; i>=0; i--){
        heapify(arr, n, i);
    }


    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    heapSort(arr, n);

    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;


    return 0;
}