# Problem #200 ([Number of Islands](https://leetcode.com/problems/number-of-islands) | Array, Breadth-First Search, Depth-First Search, Matrix, Union Find)

Given an `m x n` 2D binary grid grid which represents a map of `'1's (land)` and `'0's (water)`, *return the number of islands*.

An **island** is surrounded by water and is formed by *connecting adjacent lands horizontally or vertically*. You may assume all four edges of the grid are all surrounded by water.

***

### Example 1
**Input:** `grid = [     ` <br/>
  `["1","1","1","1","0"],` <br/>
  `["1","1","0","1","0"],` <br/>
  `["1","1","0","0","0"],` <br/>
  `["0","0","0","0","0"]]` <br/>
**Output:** `1`

***

### Example 2
**Input:** `grid = [` <br/>
  `["1","1","0","0","0"],` <br/>
  `["1","1","0","0","0"],` <br/>
  `["0","0","1","0","0"],` <br/>
  `["0","0","0","1","1"]]` <br/>
**Output:** `3`

***

### Constraints
- `m == grid.length`
- `n == grid[i].length`
- `1 <= m`, `n <= 300`
- `grid[i][j]` is `'0'` or `'1'`.

## SOLUTIONS

### Depth-First Search

First, create a variable `mat` which copies the original array so as to not overwrite it. Declare a constant array `DIR` which contains indices to be added to the index of the position of the current element in the array to go to its adjacent neighbor:

`DIR = {1, 0, -1, 0, 1}`:
- `{1, 0}` = bottom neighbor
- `{0, -1}` = left neighbor
- `{-1, 0}` = upper neighbor
- `{0, 1}` = right neighbor

**CODE:** <br/>
Construct **two methods**:
- `int numIslands(char[][] grid)` - that accepts a `char array` that represents *`island('1')`* and *`sea('0')`*.
- `void visitIsland(int r, int c)` - that accepts `two integer` values which represents the indices of the island.

First method iterates through the elements of the array to check if an element is `'1'`, if so, pass its position(`index`) to another method which marks it as *visited(`'0'`)* and checks whether adjacent elements are `'1'` or `'0'` and marks them as *visited*.

First method contains `integer variable n` which represents the *number of island(**0** by default)* and a *nested for loop*. First loop *iterates through the rows(`i`)*. Second loop *iterates through the columns(`j`)* and an *if statement* that checks if the current element is `'1'`, if so, *increment `n`* and call the method `visitIsland(i, j)` that passes the indices `[row][column]` of the current element.

Second method is a *recursion*, first statement is an if statement which *exits the method* if:
- `r < 0` - current row is less than 0. <br/>
- `c < 0` - current column is less than 0. <br/>
- `r >= rows` - current row is outside the matrix. <br/>
- `c >= columns` - current column is outside the matrix. <br/>
- `mat[r][c] == '0'` - if current position is not an island.

If current position is an island mark it as visited(`0`). Then perform a for loop which calls the method `visitIsland(r + DIR[i], c + DIR[i + 1])`. For loop iterates through the values of the array `DIR` and adds the two adjacent values to the indices of the current element `next element = mat[current row + DIR[i]][current column + DIR[i + 1]]`.

- **JAVA**
```java
class Solution {
    char[][] mat;
    int[] DIR = {1, 0, -1, 0, 1};
    public int numIslands(char[][] grid) {
        int n = 0;
        mat = grid;
        int rows = mat.length;
        int cols = mat[0].length;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(mat[i][j] == '1') {
                    visitIsland(i, j);
                    n++;
                }
            }
        }
        return n;
    }
    
    public void visitIsland(int r, int c){
        if(r < 0 || c < 0 || r >= mat.length || c >= mat[r].length || mat[r][c] == '0') return;
        mat[r][c] = '0';
        for(int i = 0; i < DIR.length - 1; i++){
            visitIsland(r + DIR[i], c + DIR[i + 1]);
        }
    }
}
```
<br/>

- *C*++
```cpp
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == '1'){
                    n++;
                    visitIsland(grid, i, j);
                }
            }
        }
        return n;
    }
    
private:
    void visitIsland(vector<vector<char>>& grid, int r, int c){
        if(r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size() || grid[r][c] == '0')
            return;
        grid[r][c] = '0';
        visitIsland(grid, r + 1, c);
        visitIsland(grid, r - 1, c);
        visitIsland(grid, r, c + 1);
        visitIsland(grid, r, c - 1);
    }
};
```

### Complexity:
- **Time:** `O(m * n)`
- **Space:** ???
