#include <bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int> arr)
{
  int n = arr.size();
  bool swapped = false;
  int i;
  for (i = 0; i < n - 2; i++)
  {
    for (int j = 0; j < n - i - 1; j++)
    {
      if (arr[j] > arr[j + 1])
      {
        // swap
        swap(arr[j], arr[j + 1]); // this is inbuilt function for swapping
        swapped = true;
      }
    }
    // optimizing code =>
    // With this optimization, time complexity of this code will
    // decrease from 'O(n^2)' to 'O(n)'.
    // This optimization will help when array is already sorted or
    // will be sort in 2-3 steps.

    // If array is already sorted then "swapped = false;" will remain as it is,
    // and help to break out of outer loop and whole loop will run for only one time
    // i.e., for i=0.

    // Similarly if array will sort in 2 steps then loop will run for i=0 and i=1
    // and will break after this.

    if (swapped == false)
    {
      break;
    }

    // if swapped is true then again set it to false.
    swapped = false;
    // to see the effect of above line of code, comment it
    // and notice the value of 'Steps' i.e, 'i'.
  }
  // this will show the number of steps taken by code to sort array
  cout << "Steps: " << i << endl;

  for (i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }
}

int main()
{
  vector<int> arr = {8, 22, 7, 9, 31, 5, 13};
  bubbleSort(arr);
  return 0;
}