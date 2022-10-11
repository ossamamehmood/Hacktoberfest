// 42. Leetcode {HARD} [DP , Stack]

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int trap(vector<int> &height)
    {

        int n = height.size();
        int l = 0;
        int r = n - 1;
        int leftmax = 0, rightmax = 0;
        int water = 0;

        while (l <= r)
        {

            if (height[l] <= height[r])
            {

                if (height[l] >= leftmax)
                {
                    leftmax = height[l];
                }
                else
                {
                    water += leftmax - height[l];
                }

                l++;
            }

            else
            {
                if (height[r] >= rightmax)
                {
                    rightmax = height[r];
                }
                else
                {
                    water += rightmax - height[r];
                }

                r--;
            }
        }

        return water;
    }
};
