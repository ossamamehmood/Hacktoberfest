#include <iostream>
using namespace std;
int main()
{
    int sum = 0, ul, ll;
    cout << "Enter the Lower Limit : ";
    cin >> ll;
    cout << "Enter the Upper Limit : ";
    cin >> ul;
    for (int i = ll; i <= ul; i++)
    {
        sum += i;
    }
    cout << "The sum of Natural Number from " << ll << " to " << ul << " is " << sum;
}