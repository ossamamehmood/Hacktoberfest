#include <iostream>
using namespace std;

class complex;

class calculator
{
public:
    int sumRealcomplex(complex, complex);
    int sumCompcomplex(complex, complex);
};

class complex
{
    int a, b;
    // friend int calculator::sumRealcomplex(complex, complex);
    // friend int calculator::sumCompcomplex(complex, complex);
    //          OR
    friend class calculator;

public:
    void setdata(int v1, int v2)
    {
        a = v1;
        b = v2;
    }
    void display()
    {
        cout << "Your complex number is " << a << " + " << b << "i" << endl;
    }
};

int calculator::sumRealcomplex(complex o1, complex o2)
{
    return (o1.a + o2.a);
}

int calculator::sumCompcomplex(complex o1, complex o2)
{
    return (o1.b + o2.b);
}

int main()
{
    complex o1, o2;
    o1.setdata(8, 4);
    o1.display();
    o2.setdata(2, 9);
    o2.display();

    calculator calc;
    int res1 = calc.sumRealcomplex(o1, o2);
    cout << "Sum of Real part of above mentioned Complex numbers is " << res1 << endl;

    int res2 = calc.sumCompcomplex(o1, o2);
    cout << "Sum of Complex part of above mentioned Complex numbers is " << res2 << "i" << endl;
    return 0;
}
