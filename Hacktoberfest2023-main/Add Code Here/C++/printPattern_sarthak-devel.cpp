#include<iostream>

using namespace std;

int main() {
    cout << "======================================" << endl;
    cout << "This code is written by sarthak-devel" << endl;
    cout << "======================================" << endl
         << endl;
    int row;
    cout << "Enter the number of rows: ";
    cin >> row;

    for (int i = 1; i <= row; i++) {
        for (int j = 1; j <= i; j++) {
            cout << j << " ";
        }
        cout << endl;
    }
        return 0;
}