#include <iostream>
using namespace std;
class Complex
{
public:
    int real, img;
    Complex(int real = 0, int img = 0)
    {
        this->real = real;
        this->img = img;
    }
    void display()
    {
        cout << "The no. is " << real << " + " << img << "i" << endl;
    }
    friend Complex operator+(Complex c1, Complex c2);
};
Complex operator+(Complex c1, Complex c2)
    {
        Complex temp;
        temp.real = c1.real + c2.real;
        temp.img = c2.img + c1.img;
        return temp;
    }
int main()
{
    Complex C1(10,20), C2(10,40), C3;
    C3 = C1 + C2;
    C3.display();
    return 0;
}