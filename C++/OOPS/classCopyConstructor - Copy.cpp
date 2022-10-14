#include <iostream>
using namespace std;
class number
{
    int a;

public:
    number()
    {
        a = 0;
    }
    number(int num)
    {
        a = num;
    }
    number(number &obj)
    {
        cout << "copy constructor" << endl;
        a = obj.a;
    }
    void dispay()
    {
        cout << "The number is " << a << endl;
    }
};
int main()
{
    number z1(25);
    z1.dispay();
    number z2(z1); //copy constructor invoked
    z2.dispay();
    number z3, z5;
    z3.dispay();
    number z4 = z1; // copy constructor invoked
    z4.dispay();
    z5 = z3; //compiler copy constructor invoked
    z5.dispay();

    return 0;
}