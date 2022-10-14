/*Given an array of intervals intervals where intervals[i] = [start, end]
return the minimum number of intervals you need to remove
to make the rest of the intervals non-overlapping.*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {

        int ans = 0;

        int n = intervals.size();

        if (n == 1)
            return 0;

        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b) -> bool
             {
            if(a[1]==b[1])
                return a[0]<b[0];
            return a[1]<b[1]; });

        vector<int> p = intervals[0];

        for (int i = 1; i < n; i++)
        {
            if (p[1] > intervals[i][0])
                ans++;
            else
                p = intervals[i];
        }
        return ans;
    }
};

int main()
{
    vector<vector<int>> intervals = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
    Solution obj;
    cout << obj.eraseOverlapIntervals(intervals);

    return 0;
}
