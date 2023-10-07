# Problem #72 ([Edit Distance](https://leetcode.com/problems/edit-distance/) | Dynamic Programming, String)

<img src="https://img.shields.io/badge/-Hard-FF4040?style=for-the-badge&logo=LeetCode&logoColor=black" alt="Hard"/>

Given two strings `word1` and `word2`, return _the minimum number of operations required to convert `word1` to `word2`._

You have the following three operations permitted on a word:

- Insert a character
- Delete a character
- Replace a character

### Example 1

| **Input:**  | `word1 = "horse"`, `word2 = ros"` |
| :---------- | :-------------------------------- |
| **Output:** | `3`                               |

**Explanation:**

```
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
```

### Example 2

| **Input:**  | `word1 = "intention"`, `word2 = execution"` |
| :---------- | :------------------------------------------ |
| **Output:** | `5`                                         |

**Explanation:**

```
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')
```

### Constraints

- `0 <= word1.length, word2.length <= 500`
- `word1` and `word2` consist of lowercase English letters.

---

# Solutions

## Approach: Dynamic Programming

- [Levenshtein Distance](./Levenshtein/README.md)
