# PROBLEM #1523 ([Count Odd Numbers in an Interval Range](https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/) | Math)

Given two non-negative integers `low` and `high`. Return the count of **odd numbers** between `low` and `high` _(inclusive)_.

---

### Example 1

**Input:** `low = 3`, `high = 7`
**Output:** `3`
**Explanation:** The odd numbers between `3` and `7` are `[3,5,7]`.

---

### Example 2

**Input:** `low = 8`, `high = 10`
**Output:** `1`
**Explanation:** The odd numbers between `8` and `10` are `[9]`.

---

### Constraints

- $1$ <= `low` <= `high` <= $10^9$

---

## SOLUTIONS

### Simple Math

- **JAVA**

```java
class Solution {
    public int countOdds(int low, int high) {
        return low % 2 == 1 || high % 2 == 1
                ? (high - low)/2 + 1
                : (high - low)/2;
    }
}
```

- **C++**

```cpp
class Solution {
public:
    int countOdds(int low, int high) {
        return low % 2 == 1 || high % 2 == 1
                ? (high - low)/2 + 1
                : (high - low)/2;
    }
};
```

- **Python**

```python
class Solution:
    def countOdds(self, low: int, high: int) -> int:
        return (high - low)//2 + 1 if low % 2 == 1 or high % 2 == 1 else (high - low)//2
```
