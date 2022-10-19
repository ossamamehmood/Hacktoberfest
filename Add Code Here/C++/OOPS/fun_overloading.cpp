#include <iostream>
using namespace std;
void dsd()
{
    cout << "without parameter" << endl;
}
void dsd(int x)
{
    cout << "with one parameter and passed value is:" << x << endl;
}
void dsd(int x, int y)
{
    cout << "with two parameter and passed value is:" << x << " AND " << y << endl;
}
int main()
{
    dsd();
    dsd(12);
    dsd(13, 15);
    return 0;
}
