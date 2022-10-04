#include <iostream>
#include<conio.h>
#include<math.h>

using namespace std;

// fungsi hello() digunkan untuk menampilkan kata 'Hello, World!'
void hello(){
    cout << "KALKULATOR";
}

int main(){

    hello();
    cout << endl;

    int num1, num2, output;
    char oprator;

    cout << "Masukkan angka pertama: ";
    cin >> num1;

    cout << "Masukkan angka kedua: ";
    cin >> num2;

    cout << "Pilih operator(*, /, +, -, ^): ";
    cin >> oprator;

    switch(oprator){
    // 'switch(huruf)' merupakan kondisi.
    // kondisi berupa karakter huruf dari a-d.
        case '+':
            output = num1 + num2;
            cout << output << endl;
            break;
        case '-':
            output = num1 - num2;
            cout << output << endl;
            break;
        case '*':
            output = num1 * num2;
            cout << output << endl;
            break;
        case '/':
            output = num1 / num2;
            cout << output << endl;
            break;
        case '^':
            output = pow(num1, num2);
            cout << output << endl;
            break;
    }

    return 0;
}