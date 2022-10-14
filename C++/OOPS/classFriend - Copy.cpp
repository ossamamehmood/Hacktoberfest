#include <iostream>
using namespace std;

class complex
{
    int a, b;
    friend complex sumcomplex(complex o1, complex o2); // permission giving to sumcomplex function to access private data of class
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

complex sumcomplex(complex o1, complex o2)
{
    complex o3;
    o3.setdata((o1.a + o2.a), (o1.b + o2.b));
    return o3;
}
int main()
{
    complex c1, c2, sum;
    c1.setdata(5, 3);
    c1.display();

    c2.setdata(2, 3);
    c2.display();

    sum = sumcomplex(c1, c2);
    sum.display();

    return 0;
}