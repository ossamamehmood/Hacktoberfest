# Problems #63 ([Unique Paths II](https://leetcode.com/problems/unique-paths-ii/) | Array, Dynamic Programming, Matrix)

You are given an `m x n` integer array grid. There is a robot initially located at the **top-left** corner (i.e., `grid[0][0]`). The robot tries to move to the **bottom-right** corner (i.e., `grid[m-1][n-1]`). The robot can only move either down or right at any point in time.

An obstacle and space are marked as `1` or `0` respectively in `grid`. A path that the robot takes cannot include **any** square that is an obstacle.

*Return the number of possible unique paths that the robot can take to reach the bottom-right corner.*

The testcases are generated so that the answer will be less than or equal to `2 * 10⁹`.

## Example 1
![image](https://user-images.githubusercontent.com/89616705/189096558-259028ca-28fa-411a-a674-04265f54a76c.png)

### Input:

    obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]

### Output:

    2

### Explanation:

    There is one obstacle in the middle of the 3x3 grid above.
    There are two ways to reach the bottom-right corner:
    1. Right -> Right -> Down -> Down
    2. Down -> Down -> Right -> Right

## Example 2
![image](https://user-images.githubusercontent.com/89616705/189096825-12d9c172-889d-440d-a04f-da0a232b1fcc.png)

### Input:

    obstacleGrid = [[0,1],[0,0]]

### Output:

    1

## Constraints
- `m == obstacleGrid.length`
- `n == obstacleGrid[i].length`
- `1 <= m, n <= 100`
- `obstacleGrid[i][j] is 0 or 1.`

# Solutions

## Dynamic Programming

### Code

- **Java**
```java
class Solution {
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        if(obstacleGrid[0][0] == 1) return 0;
        int endRow = obstacleGrid.length;
        int endCol = obstacleGrid[0].length;
        int[][] grid = new int[endRow][endCol];
        for(int i = 0; i < endRow; i++){
            if(obstacleGrid[i][0] == 1){
                grid[i][0] = 0;
                break;
            }
            else
                grid[i][0] = 1;
        }
        for(int j = 0; j < endCol; j++){
            if(obstacleGrid[0][j] == 1){
                grid[0][j] = 0;
                break;
            }
            else
                grid[0][j] = 1; 
        }
        for(int i = 1; i < endRow; i++){
            for(int j = 1; j < endCol; j++){
                if(obstacleGrid[i][j] == 1)
                    grid[i][j] = 0;
                else
                    grid[i][j] = grid[i - 1][j] + grid[i][j - 1];
            }
        }
        return grid[endRow - 1][endCol - 1];
    }
}
```
![image](https://user-images.githubusercontent.com/89616705/189095854-50a15486-4beb-4cfa-a7aa-18285bacb1d7.png)

### Complexity
- **Time:** `O(m * n)`
- **Space:** `O(1)`
