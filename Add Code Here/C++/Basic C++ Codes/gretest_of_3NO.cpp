#include <iostream>
using namespace std;
int main()
{
    int n1, n2, n3;
    cout << "Enter the Numbers : ";
    cin >> n1 >> n2 >> n3;

    if (n1 > n2 && n1 > n3)
    {
        cout << n1 << " is the gretest Number" << endl;
    }
    else if (n2 > n1 && n2 > n3)
    {
        cout << n2 << " is the gretest Number" << endl;
    }
    else
    {
        cout << n3 << " is the gretest Number" << endl;
    }
}