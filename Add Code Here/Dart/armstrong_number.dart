class ArmstrongNumbers {
  bool isArmstrongNumber(int value) {
    String number = value.toString();
    int noofDigits = number.length;
    int finalRes = 0;
    for (var x in number.split("")) {
      int current = int.parse(x);
      finalRes += power(current, noofDigits);
    }
    return finalRes == value;
  }

  int power(int a, int b) {
    if (b == 0) return 1;
    return a * power(a, b - 1);
  }
}
