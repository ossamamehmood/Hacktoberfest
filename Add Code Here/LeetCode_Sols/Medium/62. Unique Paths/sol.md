Summary of the algorithm:

1. Create a 2D array, `temp`, to store the number of unique paths to each cell in the grid.
2. Initialize the first row and column of `temp` to 1, since there is only one unique path to each cell in the first row and column.
3. Iterate over the remaining rows and columns of `temp`:
    * For each cell, calculate the number of unique paths to the cell by adding the number of unique paths to the cell to the left and the number of unique paths to the cell above.
4. Return the value of the last cell in `temp`, which is the number of unique paths to the bottom-right corner of the grid.

This algorithm works by filling in the `temp` array row-by-row, starting with the first row. For each cell in the `temp` array, the algorithm calculates the number of unique paths to the cell by adding the number of unique paths to the cell to the left and the number of unique paths to the cell above. This is because the only way to reach a cell is to come from the left or from above.

