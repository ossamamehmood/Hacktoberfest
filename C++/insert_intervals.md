[My Github Profile](https://github.com/Hg03)

[Problem Statement](https://leetcode.com/problems/insert-interval)

## Approach :- In this approach, There would be two case, first is new interval is not overlapping and other it's overlapping.

**For first case (Not overlapping)** - We'll just iterate the intervals and check if its end point is smaller than newInterval's start point, if yes means no overlapping

**For second case (overlapping)**
- In this, we'll create a vector for new merged interval and assign minimum of interval's starting and newInterval's starting point in new merged interval's starting point.
- Then assign we'll assign maximum of interval's ending point and newInterval's ending point in new merged interval's ending point.

**Third case is ,remaining intervals** - We'll simply push it into our result vector.

```cpp
// Time Complexity - O(n)             Space Complexity - O(n)
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        int i = 0, n = intervals.size();
        // For first case (Not overlapping)
        while(i < n && intervals[i][1] < newInterval[0]) result.push_back(intervals[i++]);
        
        // Second case (overlapping)
        
        vector<int> mI = newInterval;
        while(i < n && intervals[i][0] <= newInterval[1])
        {
            mI[0] = min(mI[0],intervals[i][0]);
            mI[1] = max(mI[1],intervals[i][1]);
            i++;
        }
        result.push_back(mI);
        
        // Third case
        
        while(i<n) result.push_back(intervals[i++]);
        
        return result;
    }
};
```
