#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int minTaps(int n, vector<int> &ranges)
    {

        vector<int> taps(n + 1, 0);

        for (int i = 0; i < ranges.size(); i++)
        {
            if (ranges[i] == 0)
                continue;
            int left = max(0, i - ranges[i]);
            taps[left] = max(taps[left], i + ranges[i]);
        }

        int cnt = 0, end = 0, far = 0;

        for (int i = 0; i <= n; i++)
        {
            if (i > end)
            {
                if (far <= end)
                    return -1;
                end = far;
                cnt++;
            }
            far = max(far, taps[i]);
        }

        return cnt + (end < n ? 1 : 0);
    }
};

int main()
{
    // call the fn here

    return 0;
}