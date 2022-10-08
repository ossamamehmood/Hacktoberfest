#include <iostream>
using namespace std;

class employee
{
private:
    int a, b, c;

public:
    int d, e;
    void setdata(int a1, int b1, int c1);
    void getdata()
    {
        cout << "value of a is " << a << endl;
        cout << "value of b is " << b << endl;
        cout << "value of c is " << c << endl;
        cout << "value of d is " << d << endl;
        cout << "value of e is " << e << endl;
    }
};

void employee ::setdata(int a1, int b1, int c1)
{
    a = a1;
    b = b1;
    c = c1;
}
int main()
{
    employee yashveer;
    yashveer.d = 58;
    yashveer.e = 73;
    yashveer.setdata(2, 5, 8);
    yashveer.getdata();
    return 0;
}