#include <iostream>
using namespace std;
int main()
{
    int i, num, div = 0;
    cout << "Enter number :";
    cin >> num;
    for (i = 1; i <= num; i++)
    {
        if (num % i == 0)
        {
            div++;
        }
    }
    if (div == 2)
    {
        cout << num << " is number a prime";
    }
    else
    {
        cout << num << " is not prime number";
    }
}