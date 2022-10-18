class SecondLargestWithSort {
  List<int>? number;
  SecondLargestWithSort({this.number});

  void checkSecondLargestWithSort(List<int> list) {
    list.sort();
    int range = list.length;
    print(list[range - 2]);
  }
}
