#include<iostream>
using namespace std;

int pivotNum(int arr[], int n){
    int start = 0;
    int last = n-1;

    while (start < last)
    {
        int mid = start + (last - start) / 2;
        if (arr[mid] >= arr[0])
        {
            start = mid + 1;
        }
        else{
            last = mid;
        }
        
    }
    return arr[start];
    
}
int main(){
    int n;
    cout << "Enter the total value " << endl;
    cin >> n;

    int arr[10];
    cout << "Put the value in an array " << endl;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    cout << "The pivot element is " << pivotNum(arr, n) << endl;
}