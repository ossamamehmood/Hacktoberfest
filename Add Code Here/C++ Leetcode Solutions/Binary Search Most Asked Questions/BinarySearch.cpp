// Leetcode 704 - Binary Search
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int s = 0;
        int e = nums.size() - 1;
        while (s <= e)
        {
            int mid = s + (e - s) / 2;
            if (nums[mid] == target)
            {
                return mid;
            }
            else if (nums[mid] > target)
            {
                e = mid - 1;
            }
            else
            {
                s = mid + 1;
            }
        }
        return -1;
    }
};

// Leetcode 74 -  Search a 2D Matrix
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        int s = 0;
        int e = m * n - 1;
        while (s <= e)
        {
            int mid = s + (e - s) / 2;
            int element = matrix[mid / n][mid % n];
            if (element == target)
            {
                return true;
            }
            else if (element > target)
            {
                e = mid - 1;
            }
            else
            {
                s = mid + 1;
            }
        }
        return false;
    }
};

// Leetcode 875 - Koko Eating Bananas
class Solution
{
public:
    long long solve(vector<int> &piles, int h)
    {
        int totalH = 0;
        for (int i = 0; i < piles.size(); i++)
        {
            totalH += ceil((double)piles[i] / (double)h);
        }
        return totalH;
    }
    int minEatingSpeed(vector<int> &piles, int h)
    {
        int s = 1;
        int e = 10000000000;
        while (s <= e)
        {
            int mid = s + (e - s) / 2;
            int totalH = solve(piles, mid);
            if (totalH <= h)
            {
                e = mid - 1;
            }
            else
            {
                s = mid + 1;
            }
        }
        return s;
    }
};

// Leetcode 153 - Find Minimum in Rotated Sorted Array
class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int s = 0;
        int e = nums.size() - 1;
        while (s <= e)
        {
            if (nums[s] <= nums[e])
            {
                return nums[s];
            }
            int mid = s + (e - s) / 2;
            if (nums[s] <= nums[mid])
            {
                s = mid + 1;
            }
            else
            {
                e = mid;
            }
        }
        return nums[s];
    }
};

// Leetcode 33 - Search in Rotated Sorted Array
class Solution
{
public:
    int pivot(vector<int> &nums, int s, int e)
    {
        while (s <= e)
        {
            if (s == e)
            {
                return e;
            }
            int mid = s + (e - s) / 2;
            if (mid - 1 >= s && nums[mid - 1] > nums[mid])
            {
                return mid - 1;
            }
            if (mid <= e && nums[mid] > nums[mid + 1])
            {
                return mid;
            }
            if (nums[s] >= nums[mid])
            {
                e = mid;
            }
            else
            {
                s = mid + 1;
            }
        }
        return s;
    }
    int binarysearch(vector<int> &nums, int target, int s, int e)
    {
        while (s <= e)
        {
            int mid = s + (e - s) / 2;
            if (nums[mid] == target)
            {
                return mid;
            }
            if (nums[mid] > target)
            {
                e = mid - 1;
            }
            else
            {
                s = mid + 1;
            }
        }
        return -1;
    }
    int search(vector<int> &nums, int target)
    {
        int ans = 0;
        int pivotindex = pivot(nums, 0, nums.size() - 1);
        // WE HAVE TO COMPARE TARGET FROM THE FIRST ELEMENT
        if (target >= nums[0] && nums[pivotindex] >= target)
        {
            ans = binarysearch(nums, target, 0, pivotindex);
        }
        else
        {
            ans = binarysearch(nums, target, pivotindex + 1, nums.size() - 1);
        }
        return ans;
    }
};

// Leetcode 981 - Time Based Key-Value Store
class TimeMap
{
public:
    unordered_map<string, vector<pair<int, string>>> mp;
    TimeMap()
    {
    }
    void set(string key, string value, int timestamp)
    {
        mp[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp)
    {
        if (mp.find(key) == mp.end())
        {
            return "";
        }
        int s = 0;
        int e = mp[key].size() - 1;
        if (mp[key][0].first > timestamp)
        {
            return "";
        }
        string ans = "";
        while (s <= e)
        {
            int mid = s + (e - s) / 2;
            if (mp[key][mid].first == timestamp)
            {
                return mp[key][mid].second;
            }
            else if (mp[key][mid].first < timestamp)
            {
                ans = mp[key][mid].second;
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
        }
        return ans;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */