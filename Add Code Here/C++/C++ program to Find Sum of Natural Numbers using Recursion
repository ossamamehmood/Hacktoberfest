#include<iostream>
using namespace std;

int add(int n);

int main() {
    int n;

    cout << "Enter a positive integer: ";
    cin >> n;

    cout << "Sum =  " << add(n);

    return 0;
}

int add(int n) {
    if(n != 0)
        return n + add(n - 1);
    return 0;
}
