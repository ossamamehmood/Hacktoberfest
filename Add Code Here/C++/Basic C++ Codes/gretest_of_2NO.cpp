#include <iostream>
using namespace std;
int main()
{
    int a, b;
    cout << "Enter first number: ";
    cin >> a;
    cout << "Enter second number: ";
    cin >> b;
    if (a == b)
    {
        cout << "both are equal ";
    }
    else if (a > b)
    {
        cout << a << " is greater than " << b;
    }
    else
    {
        cout << b << " is greater than " << a;
    }
}