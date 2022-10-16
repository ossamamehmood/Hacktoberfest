pair<int, int> search(vector<vector<int>> matrix, int x)
{
    // Write your code here.
    int row = matrix.size();
    int col = matrix[0].size();
    
    int rowIndex = 0;
    int colIndex = col - 1;
    
    while(rowIndex < row && colIndex >= 0)
    {
        int element = matrix[rowIndex][colIndex];
        
        if(element == x)
            return {rowIndex, colIndex};
        else if(element > x)
            colIndex--;
        else
            rowIndex++;
    }
    return {-1, -1};
}
