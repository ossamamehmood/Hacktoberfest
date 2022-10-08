// Case1:
// class B: public A{
//    // Order of execution of constructor -> first A() then B()
// };

// Case2:
// class A: public B, public C{
//     // Order of execution of constructor -> B() then C() and A()
// };

// Case3:
// class A: public B, virtual public C{
//     // Order of execution of constructor -> C() then B() and A()
// };
#include <iostream>
using namespace std;
class Base1
{
    int data1;

public:
    Base1(int i)
    {
        data1 = i;
        cout << "Base1 class constructor called" << endl;
    }
    void printDataBase1(void)
    {
        cout << "The value of data1 is " << data1 << endl;
    }
};

class Base2
{
    int data2;

public:
    Base2(int i)
    {
        data2 = i;
        cout << "Base2 class constructor called" << endl;
    }
    void printDataBase2(void)
    {
        cout << "The value of data2 is " << data2 << endl;
    }
};

class Derived : public Base1, public Base2
//class Derived: public Base2, public Base1
//class Derived: public Base1, public virtual Base2
{
    int derived1, derived2;

public:
    Derived(int a, int b, int c, int d) : Base2(b), Base1(a)
    {
        derived1 = c;
        derived2 = d;
        cout << "Derived class constructor called" << endl;
    }
    void printDataDerived(void)
    {
        cout << "The value of derived1 is " << derived1 << endl;
        cout << "The value of derived2 is " << derived2 << endl;
    }
};
int main()
{
    Derived yashveer(7, 2, 5, 4);
    yashveer.printDataBase1();
    yashveer.printDataBase2();
    yashveer.printDataDerived();
    return 0;
}