#include <iostream>
using namespace std;
int binarySearch(int n)
{
    int start = 0;
    int last = n;
    int ans = -1;

    while (start <= last)
    {
        int mid = start + (last - start) / 2;
        int square = mid * mid;

        if (square == n)
        {
            return mid;
        }
        else if (square > n)
        {
            last = mid - 1;
        }
        else
        {
            ans = mid;
            start = mid + 1;
        }
    }
     return ans;
}
int main()
{
    int n;
    cout << "Enter the number " << endl;
    cin >> n;

    cout << "The square root is " << binarySearch(n) << endl;
}