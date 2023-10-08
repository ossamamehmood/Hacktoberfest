#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {
    int lowerLimit = 1;
    int upperLimit = 100;
    int secretNumber, guess;
    int attempts = 0;

    srand(static_cast<unsigned int>(time(0)));

    secretNumber = rand() % (upperLimit - lowerLimit + 1) + lowerLimit;

    cout << "Welcome to the Number Guessing Game!" << endl;
    cout << "I've selected a number between " << lowerLimit << " and " << upperLimit << ". Try to guess it." << endl;

    do {
        cout << "Enter your guess: ";
        cin >> guess;
        attempts++;

        if (guess < secretNumber) {
            cout << "Too low! Try again." << endl;
        } else if (guess > secretNumber) {
            cout << "Too high! Try again." << endl;
        } else {
            cout << "Congratulations! You've guessed the secret number (" << secretNumber << ") in " << attempts << " attempts!" << endl;
        }
    } while (guess != secretNumber);

    return 0;
}
