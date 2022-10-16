#include <iostream>
using namespace std;

void printArray(int array[], int size) {
  for (int i = 0; i < size; ++i) {
    cout << "  " << array[i];
  }
  cout << "\n";
}

void bubbleSort(int array[], int size) {
  for (int i = 0; i < size - 1; ++i) {
    int swapped = 0;
    for (int j = 0; j < size - i - 1; ++j) {
      //sorting
      if (array[j] > array[j + 1]) {

        // Swap if greater is at the rear position
        int temp = array[j];
        array[j] = array[j + 1];
        array[j + 1] = temp;
        swapped = 1;
      }
    }

    // If there is not swapping in the last swap, then the array is already sorted.
    if (swapped == 0)
      break;
  }
  printArray(array,size);
}

//sample 
//enter the size5
//enter thr nos.6
// 1
// 23
// 65
// 9
//   1  6  9  23  65


int main(){
    int n;
    cout<<"enter the size : ";
    cin>>n;
    cout<<"enter the nos. ";
    int ar[n];
    for(int i=0;i<n;i++){
      cin>>ar[i];
    }
    bubbleSort(ar,n);
    return 0;
}
