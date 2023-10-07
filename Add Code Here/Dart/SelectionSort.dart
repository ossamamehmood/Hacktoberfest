// The selectionSort function takes a list of integers (arr) as input and sorts it using the Selection Sort algorithm.

// The sorting logic within the function follows these steps:

//    1. Iterate through the entire list.
//    2. Find the minimum element in the unsorted part of the list.
//    3. Compare the current element with the rest of the elements to find the minimum.
//    4. Swap the found minimum element with the current element.


// Selection Sort function
void selectionSort(List<int> arr) {
  int n = arr.length;

  // Traverse through the entire list
  for (int i = 0; i < n - 1; i++) {
    // Find the minimum element in the unsorted part of the list
    int minIndex = i;
    
    // Compare the current element with the rest of the elements
    for (int j = i + 1; j < n; j++) {
      if (arr[j] < arr[minIndex]) {
        minIndex = j;
      }
    }

    // Swap the found minimum element with the current element
    int temp = arr[minIndex];
    arr[minIndex] = arr[i];
    arr[i] = temp;
  }
}

void main() {
  List<int> arr = [64, 25, 12, 22, 11];
  print("Original List: $arr");

  // Call the Selection Sort function to sort the list
  selectionSort(arr);

  print("Sorted List: $arr");
}

