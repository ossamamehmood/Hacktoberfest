#include<iostream>
using namespace std;

int binarySearch(int arr[], int size, int key){

    int start = 0;
    int end = size-1;

    int mid = start + (end-start)/2;

    while(start <= end){

        if (arr[mid]==key){
            return mid;
        }

        //go to start wala part
        if (key > arr[mid]){
            start = mid+1;
        }

        else{
            end = mid - 1;
        }

        mid = start + (end-start)/2;
    }
    return -1;
}
int main(){

    int even[8] = {2,4,6,8,12,18,19,58};
    int odd[5] = {3,4,5,6,7};

    int index = binarySearch(even, 6, 8);

    cout<<"Index of 8 is "<<index <<endl;

    int oddIndex = binarySearch(odd, 5, 5);
     
    cout<<"Index of 5 is "<<oddIndex<<endl;

    return 0;

}
