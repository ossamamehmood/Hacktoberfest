#include <iostream>
using namespace std;

class Complex {

private:
    double real;
    double imag;

public:
    Complex() : real(0.0), imag(0.0) {}
    Complex(double r) : real(r), imag(0.0) {}
    Complex(double r, double i) : real(r), imag(i) {}

    friend Complex operator+(const Complex& num1, const Complex& num2);

    void display() const {
        cout << real << " + " << imag << "i";
    }
};

Complex operator+(const Complex& num1, const Complex& num2) {
    return Complex(num1.real + num2.real, num1.imag + num2.imag);
}

int main() {
    double real1, imag1, real2, imag2;

    cout << "Enter real and imaginary parts of the 1st complex number: ";
    cin >> real1 >> imag1;

    cout << "Enter real and imaginary parts of the 2nd complex number: ";
    std::cin >> real2 >> imag2;

    Complex num1(real1, imag1);
    Complex num2(real2, imag2);

    Complex sum = num1 + num2;

    cout << "Sum of the complex numbers: ";
    sum.display();

    return 0;
}