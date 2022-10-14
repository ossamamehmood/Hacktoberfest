#include <iostream>
using namespace std;

class complex
{
    int a, b;

public:
    complex(void);
    void printnumber()
    {
        cout << "complex number is " << a << " + " << b << "i";
    }
};
complex::complex(void)
{
    a = 10;
    b = 20;
}
int main()
{
    complex c;
    c.printnumber();
    return 0;
}