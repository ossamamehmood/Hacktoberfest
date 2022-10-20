#include <bits/stdc++.h>
using namespace std;
int binarySearch(int arr[], int l, int r, int x){
    if (r >= l) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);
        return binarySearch(arr, mid + 1, r, x);
    }
    return -1;
}
int main(){
	int size;
	cout<<"Enter size of array: ";
	cin>>size;
	int arr[size];
	cout<<"Enter array elements: \n";
	for(int j=0;j<size;j++){
		cin>>arr[j];
	}
    int x;
    cout<<"Enter the element to be searched: ";
    cin>>x;
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = binarySearch(arr, 0, n - 1, x);
    (result == -1) ? cout << "Element is not present in array"
                   : cout << "Element is present at index " << result;
    return 0;
}
