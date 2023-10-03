#include <iostream>
#include <string>
#include <random>

using namespace std;

string generate_password(int length) {
    const string charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+{}:;<>,.?";

    random_device rd;
    mt19937 generator(rd());
    uniform_int_distribution<int> distribution(0, charset.size() - 1);

    string password;
    for(int i = 0; i < length; ++i) {
        password += charset[distribution(generator)];
    }

    return password;
}

int main() {
    int length;
    cout << "Enter the length of the password: ";
    cin >> length;

    string password = generate_password(length);
    cout << "Generated Password: " << password << endl;

    return 0;
}
