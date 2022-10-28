#include <bits/stdc++.h>
using namespace std;
int main()
{
    int sum = 0, upper_limit, lower_limit;
    cout << "Enter the lower limit : " << endl;
    cin >> lower_limit;

    cout << "Enter the upper limit : ";
    cin >> upper_limit;

    for (int i = lower_limit; i <= upper_limit; i++)
        sum += i;

    cout << "The Sum of Natural Numbers from " << lower_limit << " to " << upper_limit << " is " << sum << endl;
}
