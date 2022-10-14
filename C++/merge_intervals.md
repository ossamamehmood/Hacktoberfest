[My Github Profile](https://github.com/Hg03)

[Problem Statement](https://leetcode.com/merge-intervals/)

## Approach :- In this approach, First sort the array interval by interval then we'll iterate the array of intervals, and check if point of one interval is greater than beginning point of next interval, then it is overlapping condition. Assign current interval's 0 to next interval's 0 and max of current interval's 1 and next interval's 1. Eventually empty the current interval because we are updating every next interval.

```cpp
// Time Complexity - O(nlogn)              Space Complexity - O(n)
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>> intervals){
      sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b){return a[0] < b[0];});
      for(int i = 0; i < intervals.size()-1; i++){
        if(intervals[i][1] >= intervals[i+1][0]){
          intervals[i+1][0] = intervals[i][0];
          intervals[i+1][1] = max(intervals[i][1], intervals[i+1][1]);
          intervals[i] = *new vector<int>{};
        }
      }
      vector<vector<int>> output;
      for(vector<int> interval : intervals){
        if(interval.size() != 0)
          output.push_back(interval);
      }
      return output;
    }
};
```
