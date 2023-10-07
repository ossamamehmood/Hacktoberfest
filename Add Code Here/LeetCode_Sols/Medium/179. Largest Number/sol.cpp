#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    string largestNumber(vector<int> &nums)
    {

        vector<string> strNums;
        for (int num : nums)
        {
            strNums.push_back(to_string(num));
        }

        sort(strNums.begin(), strNums.end(), [](string &a, string &b)
             { return a + b > b + a; });

        string ans;
        for (string s : strNums)
        {
            ans += s;
        }

        return ans[0] == '0' ? "0" : ans;
    }
};

int main()
{

    // call the fn here

    return 0;
}