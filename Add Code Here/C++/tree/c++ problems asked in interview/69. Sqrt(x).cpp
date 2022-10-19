Given a non-negative integer x, compute and return the square root of x.
Since the return type is an integer, the decimal digits are truncated, and only the integer part of the result is returned.
Note: You are not allowed to use any built-in exponent function or operator, such as pow(x, 0.5) or x ** 0.5.

Solution :

class Solution {
public:
    int mySqrt(int x) {
        if(x<2)
            return x;
        
        long long int res;
        long long int start = 1;
        long long int end = x/2;
        
        while(start<=end)
        {
            long long int mid = start + (end-start)/2;
            if(mid*mid==x)
                return mid;
            
            else if(mid*mid<x)
            {
                start = mid+1;
                res = mid;
            }
            
            else
                end = mid-1;
        }
        return res;
    }
};
