#include <iostream>
using namespace std;
int numberof1(int n)
{
    int count = 0;
    while (n)
    {
        n = n & (n - 1);
        count++;
    }
    return count;
}
int main()
{
    int n;
    cout << "Enter an number, to count number of 1s in binary representation of that number --" << endl;
    cin >> n;
    cout << "number of 1's : " << numberof1(n);
    return 0;
}