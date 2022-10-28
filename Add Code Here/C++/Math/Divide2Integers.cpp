/*
https://leetcode.com/problems/divide-two-integers/
*/

class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        if (dividend == 0)
            return 0;
        if (divisor == 0)
            return INT_MAX;
        long long res = double(exp(log(fabs(dividend)) - log(fabs(divisor))));
        if ((dividend < 0) ^ (divisor < 0))
            res = -res;
        if (res > INT_MAX)
            res = INT_MAX;
        return res;
    }
};