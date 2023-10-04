void bubbleSort(List<int> arr) {
  int n = arr.length;
  bool swapped;

  do {
    swapped = false;
    for (int i = 0; i < n - 1; i++) {
      if (arr[i] > arr[i + 1]) {
        // Swap arr[i] and arr[i + 1]
        int temp = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = temp;
        swapped = true;
      }
    }
  } while (swapped);
}

void main() {
  List<int> numbers = [64, 34, 25, 12, 22, 11, 90];

  print("Original list: $numbers");

  bubbleSort(numbers);

  print("Sorted list: $numbers");
}
