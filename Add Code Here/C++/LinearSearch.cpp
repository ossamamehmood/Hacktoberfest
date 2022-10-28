#include <iostream>
using namespace std;

int LinearSearch(int array[], int n, int x) {
// Going through array sequencially
  for (int i = 0; i < n; i++)
    if (array[i] == x)
      return i;
  return -1;
}

int main(void) {
	int n, x;
	cout<<"Enter the length of the array: ";
	cin>>n;
	int arr[n];
	cout<<"Enter the values you want to add to array: ";
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	cout<<"Enter the value you want to find in the array: ";
	cin>>x;
  	int result = LinearSearch(arr, n, x);
  	if (result == -1){
  	cout<<"Value not found in the array"<<endl;
  	}
  	else{
  	cout<<"Value found at index: "<<result<<endl;
  	}
}
