#include <bits/stdc++.h>
using namespace std;

class A
{
public:
    int x;
    void getx()
    {
        cout << "Enet the value of X: ";
        cin >> x;
    }
};
class B
{
public:
    int y;
    void gety()
    {
        cout << "Enter the value of Y : ";
        cin >> y;
    }
};

class c : public A, public B //  getting the properties of class A and B;
{
public:
    void sum()
    {
        cout << "Sum = " << x + y;
    }
};

int main()
{
    c obj1; // Object of derived class c
    obj1.getx();
    obj1.gety();
    obj1.sum();
    return 0;
}