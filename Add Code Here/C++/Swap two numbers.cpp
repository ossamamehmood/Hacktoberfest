#include <iostream>
using namespace std;

int main() {
    // Declare variables to store the two numbers and a temporary variable for swapping
    int num1, num2, temp;

    // Ask the user to enter the first number and store it in num1
    cout << "Enter the first number: ";
    cin >> num1;

    // Ask the user to enter the second number and store it in num2
    cout << "Enter the second number: ";
    cin >> num2;

    // Display the numbers before swapping
    cout << "Before swapping: ";
    cout << "First number = " << num1 << ", Second number = " << num2 << endl;

    // Swapping logic using a temporary variable
    temp = num1;    // Store the value of num1 in the temporary variable
    num1 = num2;    // Assign the value of num2 to num1
    num2 = temp;    // Assign the value stored in the temporary variable to num2

    // Display the numbers after swapping
    cout << "After swapping: ";
    cout << "First number = " << num1 << ", Second number = " << num2 << endl;

   
    return 0;
}
