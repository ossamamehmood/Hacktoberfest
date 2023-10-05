# Problem #36 ([Valid Sudoku](https://leetcode.com/problems/valid-sudoku/submissions/) | Array, Hash Table, Matrix)

Determine if a `9 x 9` Sudoku board is *valid*. Only the filled cells need to be validated according to the following rules:

    - Each row must contain the digits 1-9 without repetition.
    - Each column must contain the digits 1-9 without repetition.
    - Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
<br/>

**Note:**

    - A Sudoku board (partially filled) could be valid but is not necessarily solvable.
    - Only the filled cells need to be validated according to the mentioned rules.

***

### Example 1
![image](https://user-images.githubusercontent.com/89616705/187617901-bcf09e97-29e0-4cd2-a567-36b013794fd7.png)

**Input:**

    board = 
    [["5","3",".",".","7",".",".",".","."]
    ,["6",".",".","1","9","5",".",".","."]
    ,[".","9","8",".",".",".",".","6","."]
    ,["8",".",".",".","6",".",".",".","3"]
    ,["4",".",".","8",".","3",".",".","1"]
    ,["7",".",".",".","2",".",".",".","6"]
    ,[".","6",".",".",".",".","2","8","."]
    ,[".",".",".","4","1","9",".",".","5"]
    ,[".",".",".",".","8",".",".","7","9"]]
    
**Output:** `true`

***

### Example 2

**Input:**

    board = 
    [["8","3",".",".","7",".",".",".","."]
    ,["6",".",".","1","9","5",".",".","."]
    ,[".","9","8",".",".",".",".","6","."]
    ,["8",".",".",".","6",".",".",".","3"]
    ,["4",".",".","8",".","3",".",".","1"]
    ,["7",".",".",".","2",".",".",".","6"]
    ,[".","6",".",".",".",".","2","8","."]
    ,[".",".",".","4","1","9",".",".","5"]
    ,[".",".",".",".","8",".",".","7","9"]]

**Output:** `false`
**Explanation:** Same as Example 1, except with the 5 in the top left corner being modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.

# SOLUTIONS

## HashSet

The idea is to create a `HashSet` that stores *<Characters>* for each:

    - row
    - column
    - and 3 x 3 sub-boxes of the grid.

And loop through each row, column and sub-box of the grid whilst adding the elements to the HashSet.
    
First is the create two for loops that loops through the row(`[i]`, *column for the `column` HashSet*) and columns(`[j]`, *row for the `column` HashSet*) of the grid. As for the sub-boxes, indices are calculated as such:

    - rowIndex = (3*(i/3)) + j/3.
    - columnIndex = (3*(j%3)) + j%3.
    
At the outer for loop is where the `HashSets` for row, column and sub-box are created.

Inside the inner for loop are three conditional statements:
    
    - a condition whether the current element at row is not '.' and is already added to the row HashSet. If condition is true then Sudoku is invalid, thus return false.
    - a condition whether the current element at column is not '.' and is already added to the column HashSet. If condition is true then Sudoku is invalid, thus return false.
    - a condition whether the current element at sub-box is not '.' and is already added to the sub-box HashSet. If condition is true then Sudoku is invalid, thus return false.

If we looped to the whole array then `return true`, which means that it is a valid Sudoku.

### CODE

- **JAVA**
```java
class Solution {
    public boolean isValidSudoku(char[][] board) {
        for(int i = 0; i < 9; i++){
            Set<Character> row = new HashSet<Character>();
            Set<Character> col = new HashSet<Character>();
            Set<Character> sqr = new HashSet<Character>();
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.' && !row.add(board[i][j])) return false;
                if(board[j][i] != '.' && !col.add(board[j][i])) return false;
                int rowIdx = (3*(i/3)) + j/3;
                int colIdx = (3*(i%3)) + j%3;
                if(board[rowIdx][colIdx] != '.' && !sqr.add(board[rowIdx][colIdx])) return false;
            }
        }
        return true;
    }
}
```

### COMPLEXITY
- **Time:** `O(n^2)` <br/>
