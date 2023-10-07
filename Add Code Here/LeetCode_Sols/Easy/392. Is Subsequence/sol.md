**Algorithm:**

1. Initialize two pointers, `i` and `j`, to the beginning of the strings `s` and `t`, respectively.
2. While `i` is less than the length of `t`:
    * If the character at `i` in `t` is equal to the character at `j` in `s`:
        * Increment `j`.
    * Increment `i`.
    * If `j` is equal to the length of `s`, then return `true`, indicating that `s` is a subsequence of `t`.
3. Return `false`, indicating that `s` is not a subsequence of `t`.

**Time complexity:** O(n), where n is the length of the string `t`.

**Space complexity:** O(1), as we only use two pointers.

For example, consider the following two strings:

s = "abc"
t = "acb"

The `i` and `j` pointers will be initialized to the beginning of the strings `s` and `t`, respectively.

The `while` loop will then be executed as follows:


Iteration | i | j | t.charAt(i) | s.charAt(j) | Action
------- | --- | --- | --- | --- | ---
1        | 0  | 0  | a           | a           | Increment j
2        | 1  | 1  | c           | b           | Do nothing
3        | 2  | 2  | b           | c           | Increment j


At the end of the loop, `j` will be equal to the length of `s`, indicating that `s` is a subsequence of `t`. The function will then return `true`.