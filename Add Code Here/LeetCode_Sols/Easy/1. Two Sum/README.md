# Problem #1 ([Two Sum](https://leetcode.com/problems/two-sum) | Array, Hash Table)

Given an array of integers `nums` and an integer `target`, return _indices of the two numbers such that they add up to `target`_.

You may assume that each input would have **exactly one solution**, and you may not use the same element twice.

You can return the answer in any order.

***

### **Example 1**
**Input:** `nums = [2,7,11,15]`, `target = 9` <br/>
**Output:** `[0,1]` <br/>
**Explanation:** Because `nums[0] + nums[1] == 9`, we `return [0, 1]`.

***

### **Example 2**
**Input:** `nums = [3,2,4]`, `target = 6` <br/>
**Output:** `[1,2]`

***

### **Example 3**
**Input:** `nums = [3,3]`, `target = 6` <br/>
**Output:** `[0,1]`

***

### **Constraint**
- `2 <= nums.length <= 10^4`
- `-10^9 <= nums[i] <= 10^9`
- `-10^9 <= target <= 10^9`
- **Only one valid answer exists.**

***

## SOLUTIONS

### **HashMap**

We create a `HashMap` that contains `<Integer, Integer>`, the _key is the element from the array and value is its index_,

We create a for loop to iterate through each element of the array. Each element is mapped to the `HashMap`,

An operation is perforned `target - element` that is stored to variable `pair`, which represents the number needed to be added to the `current element` to get the `target`. The HashMap is checked if it already contains the number `pair`. If it is, then return the `index of the current element` and the `index of pair`.

- **JAVA**
```java
class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> map = new HashMap<Integer, Integer>();
        for(int i = 0; i < nums.length; i++){
            int pair = target - nums[i];
            if(map.containsKey(pair))
                return new int[]{map.get(pair), i};
            map.put(nums[i], i);
        }
        return new int[]{};
    }
}
```
<br/>

- **C**++
```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map <int, int> map;
        for(int i = 0; i < nums.size(); i++){
            int pair = target - nums[i];
            if(map.count(pair)) return {map[pair], i};
            map[nums[i]] = i;
        }
        return {};
    }
};
```

### **Complexity**
- **Time:** `O(n)`
- **Space:** `O(n)`

<br/>

- **Ruby**
```rb
def two_sum(nums, target)
    hash = {}
    nums.each_with_index do |num, idx|
        complement = target - num
        return [hash[complement], idx] if hash.key?(complement)
        hash[num] = idx
    end
end
```

<br/>

- **Phyton**
```py
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        d = {}
        for i, num in enumerate(nums):
            if target - num in d:
                return [d[target - num], i]
            d[num] = i
        return []

```

<br/>

- **PHP**
```php
class Solution {

    /**
     * @param Integer[] $nums
     * @param Integer $target
     * @return Integer[]
     */
    function twoSum($nums, $target) {
    $map = [];
    for ($i = 0; $i < count($nums); $i++) {
        $complement = $target - $nums[$i];
        if (isset($map[$complement])) {
            return [$map[$complement], $i];
        }
        $map[$nums[$i]] = $i;
    }
}

}

```

<br/>

- **JavaScript**
```js
const twoSum = function (nums, target)
{
    //search of all Array
    for (let i = 0; i < nums.length; i++)
    {
        for (let j = i + 1; j < nums.length; j++)
        {
            // if (nums[j] === target - nums[i])
            if(nums[i] + nums[j] === target)
            {
                return [i, j];
            }
        }
    }
    };


```

<br/>

- **C#**
```cs
public class Solution {
    public int[] TwoSum(int[] nums, int target) {
    Dictionary<int, int> map = new Dictionary<int, int>();
    for (int i = 0; i < nums.Length; i++) {
        int complement = target - nums[i];
        if (map.ContainsKey(complement)) {
            return new int[] { map[complement], i };
        }
        map[nums[i]] = i;
    }
    throw new Exception("No two sum solution");
}

}


```