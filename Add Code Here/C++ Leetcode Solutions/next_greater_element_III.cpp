#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int nextGreaterElement(int n) {
        string number = to_string(n);
        int i = 0;
        for(i = number.size() - 2; i>=0; i--)
            if(number[i] < number[i+1])
                break;
        if(i == -1)
            return -1;
        int j = 0;
        for( j = number.size() - 1; j>=0; j--)
            if(number[j] > number[i])
                break;
        swap(number[i], number[j]);
        reverse(number.begin() + i + 1, number.end());

        long long result = stoll(number);
        if(result > INT_MAX)
            return -1;
        return result;
    }
};