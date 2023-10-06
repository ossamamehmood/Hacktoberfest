# PROBLEM #1720 ([Decode XORed Array](https://leetcode.com/problems/decode-xored-array/) | Array, Bit Manipulation)

There is a hidden integer array arr that consists of n non-negative integers.

It was encoded into another integer array encoded of length n - 1, such that encoded[i] = arr[i] XOR arr[i + 1]. For example, if arr = [1,0,2,1], then encoded = [1,2,3].

You are given the encoded array. You are also given an integer first, that is the first element of arr, i.e. arr[0].

Return the original array arr. It can be proved that the answer exists and is unique.

***

### Example 1
**Input:** encoded = [1,2,3], first = 1 <br />
**Output:** [1,0,2,1] <br />
**Explanation:** If arr = [1,0,2,1], then first = 1 and encoded = [1 XOR 0, 0 XOR 2, 2 XOR 1] = [1,2,3]

***

### Example 2
**Input:** encoded = [6,2,7,3], first = 4 <br />
**Output:** [4,2,0,7,4]

***

## SOLUTIONS

### **BIT MANIPULATION**

- **JAVA**
```java
class Solution {
    public int[] decode(int[] encoded, int first) {
        int n = encoded.length;
        int[] decoded = new int[n + 1];
        decoded[0] = first;
        for(int i = 0; i < n; i++){
            decoded[i + 1] = decoded[i] ^ encoded[i];
        }
        return decoded;
    }
}
```
