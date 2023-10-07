// 744. Find Smallest Letter Greater Than Target

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    char nextGreatestLetter(vector<char> &letters, char target)
    {
        int lo = 0, hi = letters.size() - 1;
        int ans = letters[0];

        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;
            if (letters[mid] > target)
            {
                hi = mid - 1;
                ans = letters[mid];
            }
            else
            {
                lo = mid + 1;
            }
        }
        return ans;
    }
};

