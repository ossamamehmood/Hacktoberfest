#include <iostream>
using namespace std;

int main() {
    // Declare a variable to store the user input
    int number;

    // Prompt the user to enter an integer
    cout << "Enter an integer: ";
    
    // Read the user input and store it in the 'number' variable
    cin >> number;

    // Check if the number is divisible by 2 using the modulo operator (%)
    if (number % 2 == 0) {
        // If the remainder is 0, the number is even
        cout << number << " is even." << endl;
    } else {
        // If the remainder is not 0, the number is odd
        cout << number << " is odd." << endl;
    }

    return 0;
}