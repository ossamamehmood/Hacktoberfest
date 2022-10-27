#include <iostream>
using namespace std;
int binarySearch(int arr[], int size, int key){

    int start = 0;
    int end = size - 1;

    while (start <= end){
        
        int mid = (start + (end-start)/2 );

        if(arr[mid] == key){
        return mid;
        }

        if( key > arr[mid]){
            start = mid+1;
        }
        else{
            end = mid-1;
        }
    }
    cout<<"Element not found"<<endl;
    return -1;
}

int main(){
    int oddArr[5] = {23, 27, 35, 47, 89};
    int evenArr[6] = {12, 15, 17, 49, 67, 89};

    cout<<"The index of 47 in odd waala array is: "<<binarySearch(oddArr, 5, 47)<<endl;
    cout<<"The index of 23 in odd waala array is: "<<binarySearch(oddArr, 5, 23)<<endl;

    cout<<"The index of 89 in even waala array is: "<<binarySearch(evenArr, 6, 89)<<endl;
    cout<<"The index of 15 in even waala array is: "<<binarySearch(evenArr, 6, 15)<<endl;

    cout<<"The index of 100 in even waala array is: "<<binarySearch(evenArr, 6, 100)<<endl;


    return 0;
}
