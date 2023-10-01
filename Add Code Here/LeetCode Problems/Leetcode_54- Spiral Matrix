class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>result;
        // if (matrix.empty() || matrix[0].empty()) {
        //     return result;
        // }
        int left = 0;
        int right = matrix[0].size()-1;
        int top = 0;
        int bottom = matrix.size()-1;

        int direction = 0;

        while(left <= right && top <= bottom){
            if(direction == 0){
                for(int i = left;i <= right;i++){
                    result.push_back(matrix[top][i]);
                }
                top ++;
            }
            else if(direction == 1){
                for(int j = top;j <= bottom;j++){
                    result.push_back(matrix[j][right]);
                }
                right--;
            }
            else if(direction == 2){
                for(int i = right;i >= left;i--){
                    result.push_back(matrix[bottom][i]);
                }
                bottom--;
            }
            else{
                for(int j = bottom;j >= top;j--){
                    result.push_back(matrix[j][left]);
                }
                left++;
            }
            direction = (direction + 1)%4;
        }
        
        return result;
        
    }
};
