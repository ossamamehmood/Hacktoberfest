# Problem #974 ([Subarray Sums Divisible by K](https://leetcode.com/problems/subarray-sums-divisible-by-k/) | Array, Hash Table, Prefix Sum)

Given an integer array `nums` and an integer `k`, *return the **number of non-empty subarrays** that have a **sum** divisible by `k`*.

*A **subarray** is a contiguous part of an array.*

## Example 1

**Input:**

    nums = [4,5,0,-2,-3,1], k = 5

**Output:**
    
    7

**Explanation:**
```
There are 7 subarrays with a sum divisible by k = 5:
[4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]
```
</br>

## Example 2

**Input:**

    nums = [5], k = 9

**Output:**

    0

## Constraints
- `1 <= nums.length <= 3 * 10⁴`
- `-10⁴ <= nums[i] <= 10⁴`
- `2 <= k <= 10⁴`

<hr>

# Solutions

## Approach 1: `Hash Table and Prefix Sum`

### Code

**Java**
```java
class Solution {
    public int subarraysDivByK(int[] arr, int k) {
        int n = arr.length;
        HashMap<Integer,Integer> map = new HashMap<>();
        int sum = 0;
        int count = 0;
        for(int i = 0; i<n; i++){
            sum+=arr[i];
            if(sum%k==0)
                count++;
            int rem = sum%k;
            if(rem<0)
                rem = rem+k;
            if(map.containsKey(rem))
                count+=map.get(rem);
            map.put(rem,map.getOrDefault(rem,0)+1);
        }
        return count;
    }
}
```

**C++**
```cpp
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> map;
        int sum = 0;
        int count = 0;
        for(int i = 0; i < n; i++) {
            sum += nums[i];
            if(sum % k == 0) count++;
            int rem = sum % k;
            if(rem < 0) rem += k;
            if(map[rem]) count += map[rem];
            map[rem] = map[rem] + 1;
        }
        return count;
    }
};
```

**Python3**
```python3
class Solution:
    def subarraysDivByK(self, nums: List[int], k: int) -> int:
        n = len(nums)
        map = {}
        sum = 0
        count = 0
        for i in range(n):
            sum = sum + nums[i]
            if sum % k == 0: count = count + 1
            rem = sum % k
            if rem < 0: rem = rem + k
            if map.get(rem):
                count = count + map[rem]
                map[rem] = map[rem] + 1
            else:
                map[rem] = 1
        return count
```

### Complexity
- **Time:** `O(n)`
- **Space:** `O(n)`
