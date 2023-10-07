# Problem #9 ([Palindrome Number](https://leetcode.com/problems/palindrome-number/) | Math)

Given an integer `x`, return `true` if *x is palindrome integer*.

An integer is a *palindrome* when it reads the same backward as forward.

    For example, 121 is a palindrome while 123 is not.

## Example 1
**Input:**

    x = 121
<br/>

**Output:**

    true
<br/>

**Explanation:**

    121 reads as 121 from left to right and from right to left.

## Example 2
**Input:**

    x = -121
<br/>

**Output:**

    false
<br/>

**Explanation:**

    From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.

## Example 3
**Input:**

    x = 10
<br/>

**Output:**

    false
<br/>

**Explanation:**

    Reads 01 from right to left. Therefore it is not a palindrome.

## Constraints
- -2<sup>31</sup> <= x <= 2<sup>31</sup> - 1

### Follow Up: `Could you solve it without converting the integer to a string?`

# Solutions

## Reverse till half then compare

The idea is to compare the left half of `x` to the reverse of its right half. If they are equal then `x` is ***palindrome***.

If `x < 0` or if, when `x != 0` and `x % 10 == 0`, which means that `x` is a multiple of `10`, then `x` is not a ***palindrome***.
<br/>

**The code goes as such:**
```python3
if x < 0 or (x != 0 and x % 10 == 0):
    return False
```
- This means that if `x` is a negative number or if `x` a multiple of `10`, then `x` is not a ***palindrome*** thus `return False`.
<br/>

```python3
rev = 0
```
- variable `rev` will store the reverse of the right half of `x`.
<br/>

```python3
while x > rev:
    rev = rev * 10 + rev // 10
    x //= 10
```
- The while loop will persist until `x` is half its length. *First statement* will change the value of `rev` to the reverse of the right half of `x`. *Second statement* will change the value of `x` to its left half. If the length of `x` is odd then the excess digit which is the middle digit will be added to `rev`.
<br/>

```python3
return x == rev or x == rev//10
```
- This means that if the left half of `x` is equal to the reverse of its right half `rev` then `return True`, if the length of `x` is odd then remove the last digit of `rev`.

### Code
- **Java**
```java
class Solution {
    public boolean isPalindrome(int x) {
        if(x<0 || (x != 0 && x % 10 == 0)) return false;
        int rev = 0;
        while(x > rev){
            rev = rev * 10 + x % 10;
            x /= 10;
        }
        return (x == rev || x == rev/10);
    }
}
```
<br/>

- **C**++
```cpp
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x != 0 && x % 10 == 0)) return false;
        int rev = 0;
        while(x > rev) {
            rev = rev * 10 + x%10;
            x /= 10;
        }
        return (x == rev || x == rev/10);
    }
};
```
<br/>

- **Python3**
```python3
class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x < 0 or (x != 0 and x % 10 == 0):
            return False
        rev = 0
        while x > rev:
            rev = rev * 10 + x % 10
            x //= 10
        return x == rev or x == rev//10
```

### Complexity
- **Time:** `O(log n)`
- **Space:** `O(1)`

<br/>

- **Ruby**
```rb
def is_palindrome(x)
  return false if x < 0
  reverse = 0
  original = x
  while x > 0
    reverse = reverse * 10 + x % 10
    x /= 10
  end
  reverse == original
end

```
