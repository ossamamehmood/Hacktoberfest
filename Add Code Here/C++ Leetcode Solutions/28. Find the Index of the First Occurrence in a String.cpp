# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
We want to reverse the order of words in the input string while keeping the words as is.

# Approach
<!-- Describe your approach to solving the problem. -->
1. Initialize an empty vector 'temp' to store the words, an integer 'index' to keep track of the current word, and an empty string 'answer' to store the reversed sentence.
2. Iterate through each character in the input string 's'.
    - If it encounters a space character, increment the 'index' to start a new word.
    - Otherwise, append the character to the current word in the 'temp' vector.
3. After processing all characters, reverse and concatenate the words in reverse order. Add spaces between words except for the last one.
- Note: If the needle doesn't fit completely within the remaining characters of the haystack (i.e., i reaches n - m or beyond), then it's impossible for the entire needle to be present in the remaining portion of the haystack.

# Complexity
- Time complexity: O(n)

- Space complexity: O(n)

# Code
```
class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.length();
        int m = needle.length();

        for (int i = 0; i <= n - m; i++) { // Iterate up to n - m
            int j = 0;
            while (j < m && haystack[i + j] == needle[j]) {
                j++;
            }
            if (j == m) {
                return i; // Found a match
            }
        }
        return -1; // Needle not found
    }
};
```
