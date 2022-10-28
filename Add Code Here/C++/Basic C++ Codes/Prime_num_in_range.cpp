#include <iostream>
using namespace std;
void prime(int num)
{
    int div = 0;
    for (int i = 1; i < num; i++)
    {
        if (num % i == 0)
        {
            div++;
        }
    }
    if (div == 2)
    {
        cout << num << endl;
    }
}

int main()
{
    cout << "Enter range: ";
    int ll, ul;
    cin >> ll >> ul;
    cout << "Prime numbers between " << ll << " and " << ul << " are " << endl;
    for (int i = ll; i <= ul; i++)
    {
        prime(i);
    }
}