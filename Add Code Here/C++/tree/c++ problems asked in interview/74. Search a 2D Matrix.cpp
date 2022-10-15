Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
 

Example 1:


Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true
Example 2:


Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false
 
Solution :

Time Complexity : O(log(n*m))
  
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(!matrix.size())
            return false;
        
        int n = matrix.size(); //number of rows
        int m = matrix[0].size(); // number of coloumns
        
        int low = 0;
        int high = (n*m)-1;
        
        while(low<=high) //using binary search
        {
            int mid = (low+(high-low)/2); //to overcome integer overflow
            if(matrix[mid/m][mid%m] == target) // mid/m gives row number , mid%m gives coloumn number
                return true;
            
            if(matrix[mid/m][mid%m]<target) 
                low = mid+1;
            
            else
                high = mid-1;
        }
        return false;
    }
};
