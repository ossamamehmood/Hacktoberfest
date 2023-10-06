#include <iostream>

using namespace std;

const int MOD = 1000000007;

class Solution
{
public:
    int countOrders(int n)
    {

        long long count = 1;

        for (int i = 2; i <= n; i++)
        {
            count = (count * (2 * i - 1) % MOD * i % MOD) % MOD;
        }

        return (int)count;
    }
};

int main()
{
    // call the fn here

    return 0;
}