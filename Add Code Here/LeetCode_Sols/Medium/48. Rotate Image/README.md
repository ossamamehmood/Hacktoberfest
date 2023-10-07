# Problem #48 ([Rotate Image](https://leetcode.com/problems/rotate-image/) | Array, Math, Matrix)

You are given an `n x n` 2D `matrix` representing an image, rotate the image by ***90*** *degrees (clockwise)*.

You have to rotate the image **`in-place`**, which means you have to modify the input *2D matrix* directly.

**DO NOT allocate another 2D matrix and do the rotation**.

***

### Example 1

![mat1](https://user-images.githubusercontent.com/89616705/187323313-59a3c553-b2d4-4b1b-b7d3-f98c9030eec5.jpg)

**Input:** `matrix = [[1,2,3],[4,5,6],[7,8,9]]` <br/>
**Output:** `[[7,4,1],[8,5,2],[9,6,3]]`

***

### Example 2

![mat2](https://user-images.githubusercontent.com/89616705/187323486-2c4c5aca-4808-43d4-a413-7ef828ec1a4d.jpg)

**Input:** `matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]` <br/>
**Output:** `[[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]`

***

### Constraints
- `n == matrix.length == matrix[i].length`
- `1 <= n <= 20`
- `-1000 <= matrix[i][j] <= 1000`

***

# SOLUTIONS

## Matrix => Transpose => Horizontal Flip(In-place)

This solution is done by getting the *transpose* of the 2D Matrix and *flipping* each of the rows horizontally.

**Matrix:** <br/>
![image](https://user-images.githubusercontent.com/89616705/187324681-4108d2d9-b6c3-4aee-bb51-afacd0c15c07.png)

**Transpose:** <br/>
![image](https://user-images.githubusercontent.com/89616705/187324777-c37997df-8451-49ee-8ed6-5338e63b0ccc.png)
- The *transpose of the matrix* is basically done by swapping the values of `matrix[i][j]` and `matrix[i][j]`.

**Horizontal Flip:** <br/>
![image](https://user-images.githubusercontent.com/89616705/187325117-d2b9e9f0-5abe-440c-a5ee-43ea8aaff8be.png)
- *Flip* the matrix horizontally by swapping the values of `matrix[i][j]` and `matrix[i][matrix.length - 1 - j]`, *where `j < matrix.length/2`*.

**CODE** <br.>

- **JAVA**
```java
class Solution {
    public void rotate(int[][] matrix) {
        for(int i = 0; i < matrix.length; i++){
            for(int j = i; j < matrix[0].length; j++){
                int t = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = t;
            }
        }
        
        for(int i = 0; i < matrix.length; i++){
            for(int j = 0; j < matrix.length/2; j++){
                int t = matrix[i][j];
                matrix[i][j] = matrix[i][matrix.length - 1 - j];
                matrix[i][matrix.length - 1 - j] = t;
            }
        }
    }
}
```

- **C**++
```cpp
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for(int i = 0; i < matrix.size(); i++){
            for(int j = i; j < matrix[0].size(); j++){
                int t = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = t;
            }
        }
        
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix.size()/2; j++){
                int t = matrix[i][j];
                matrix[i][j] = matrix[i][matrix.size() - 1 - j];
                matrix[i][matrix.size() - 1 - j] = t;
            }
        }
    }
};
```

### Complexity:
- **Time:** `O(m * n)`, *where `m` is the number of rows and `n` is the number of columns*.
- **Spaca:** `O(1)`
