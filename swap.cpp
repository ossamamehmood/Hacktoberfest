#include <iostream>
using namespace std;
int main()
{

        int a = 1, b = 4;
        b = a ^ b;
        a = a ^ b;
        b = a ^ b;
        cout << a << b;
}