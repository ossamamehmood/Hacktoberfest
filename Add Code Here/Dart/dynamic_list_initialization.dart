//Dynamic Initialization of List in Dart
import "dart:io";

void main() {
  print("Enter the size of List: ");
  int size = int.parse(stdin.readLineSync()!);
  //Takes the size of the list from the user

  List newlist = new List.filled(size, null, growable: false);
  //Declaring a list with the size user entered
  print("Enter the elements");
  //Loop for taking each value
  int i;
  for (i = 0; i < size; ++i) {
    newlist[i] = stdin.readLineSync()!;
  }
  print("The elements in the list are: ");
  print(newlist);
  //Print all the values user entered in the List

  print("The elements in the list with its index are: ");
  for (i = 0; i < size; ++i) {
    print("Element at Index $i is ${newlist[i]}");
  }
}
