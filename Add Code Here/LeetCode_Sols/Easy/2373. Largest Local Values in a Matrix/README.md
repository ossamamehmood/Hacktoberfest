# Problem #2373 ([Largest Local Values in a Matrix](https://leetcode.com/problems/largest-local-values-in-a-matrix/) | Array, Matrix)

You are given an `n x n` integer matrix grid.

Generate an integer matrix `maxLocal` of size `(n - 2) x (n - 2)` such that:

    - maxLocal[i][j] is equal to the largest value of the 3 x 3 matrix in grid centered around row i + 1 and column j + 1.

In other words, we want to find the *largest valu*e in every contiguous `3 x 3` matrix in grid.

*Return the generated matrix.*

***

### Example 1
![image](https://user-images.githubusercontent.com/89616705/187606960-9bf7b65f-3893-432e-a40e-aaaf307aeab1.png)

**Input:** `grid = [[9,9,8,1],[5,6,2,6],[8,2,6,4],[6,2,2,2]]` <br/>
**Output:** `[[9,9],[8,6]]` <br/>
**Explanation:** The diagram above shows the original matrix and the generated matrix.

*Notice that each value in the generated matrix corresponds to the largest value of a contiguous 3 x 3 matrix in grid.*

***

### Example 2
![image](https://user-images.githubusercontent.com/89616705/187607214-5763512b-aa5d-42e3-99eb-1f7380d29d9c.png)

**Input:** `grid = [[1,1,1,1,1],[1,1,1,1,1],[1,1,2,1,1],[1,1,1,1,1],[1,1,1,1,1]]`
**Output:** `[[2,2,2],[2,2,2],[2,2,2]]`
**Explanation**: Notice that the *2* is contained within every contiguous `3 x 3` matrix in grid.
