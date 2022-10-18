class SecondLargestWithoutSort {
  final List<int>? number;
  SecondLargestWithoutSort({this.number});
// Logic => we will compare each index with next index and then will check if number is greater with our largest then store it in largest and make second largest  = to largest or if not then check if number is smaller than largest but biger then smaller then add it to smaller.
  void checkSecondLargest(List<int> number) {
    int first = number[0];
    int second = number[1];
    for (int i = 0; i < number.length - 2; i++) {
      if (number[i] < number[i + 1]) {
        if (number[i + 1] > first) {
          second = first;
          first = number[i + 1];
        } else if (number[i + 1] > second && number[i + 1] < first) {
          second = number[i + 1];
        }
      }
    }
    if (second != first) {
      print(second);
      print('first$first');
    } else {
      print('Both are same: $first');
    }
  }
}
