# PROBLEM #1486 ([XOR Operation in an Array](https://leetcode.com/problems/xor-operation-in-an-array/) | Math, Bit Manipulation)

You are given an integer n and an integer start.

Define an array `nums` where `nums[i] = start + 2 * i` (**0-indexed**) and `n == nums.length`.

_Return the bitwise XOR of all elements of nums._

***

### Example 1

**Input:** `n = 5`, `start = 0` <br/>
**Output:** `8` <br/>
**Explanation:** Array nums is equal to `[0, 2, 4, 6, 8]` where `(0 ^ 2 ^ 4 ^ 6 ^ 8) = 8`. <br/>

_Where "^" corresponds to bitwise XOR operator._

***

### Example 2

**Input:** `n = 4`, `start = 3` <br/>
**Output:** `8` <br/>
**Explanation:** Array nums is equal to `[3, 5, 7, 9]` where `(3 ^ 5 ^ 7 ^ 9) = 8`.

***

### Constraints

- `1 <= n <= 1000`
- `0 <= start <= 1000`
- `n == nums.length`

***

## SOLUTIONS

### BIT MANIPULATION

- **JAVA**
```java
class Solution {
    public int xorOperation(int n, int start) {
        int res = start;
        for(int i = 1; i < n; i++)
            res ^= (start + 2 * i);
        return res;
    }
}
```
