#include <iostream>
using namespace std;
class Base
{
public:
   virtual void fun()=0;
};
class Derived : public Base
{
public:
    void fun()
    {
        cout << "Derived class" << endl;
    }
};

int main()
{
    Base b;
    Derived d;
    Base *ptr = &d;
    ptr->fun();
    return 0;
}