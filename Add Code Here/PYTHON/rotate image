 void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int row=0;row<n;row++){
            for(int col=0;col<=row;col++){
                swap(matrix[row][col],matrix[col][row]);
            }
        }
        for(int row=0;row<n;row++){
            for(int col=0;col<n/2;col++){
                swap(matrix[row][col], matrix[row][n-col-1]);
            }
            
        }
    }
