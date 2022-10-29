import numpy as np
from numpy import *
  
def split(matrix):
    row,col = matrix.shape
    n = len(matrix)
    row2,col2 = row//2, col//2
    #print(row,col,row2,col2)
    return matrix[:row2, :col2], matrix[:row2, col2:], matrix[row2:, :col2], matrix[row2:, col2:]
    #return matrix[:n//2, :n//2], matrix[:n//2, n//2:], matrix[n//2:, :n//2], matrix[n//2:, n//2:]
    
def strassen(x, y):
    # Base case when size of matrices is 1x1
    if len(x) == 1:
        return x * y
  
    # Splitting the matrices into quadrants. This will be done recursively
    # until the base case is reached.
    a, b, c, d = split(x)
    e, f, g, h = split(y)

    #print(a)
  
    # Computing the 7 products, recursively (p1, p2...p7)
    p1 = strassen(a, f - h)  
    p2 = strassen(a + b, h)        
    p3 = strassen(c + d, e)        
    p4 = strassen(d, g - e)        
    p5 = strassen(a + d, e + h)        
    p6 = strassen(b - d, g + h)  
    p7 = strassen(a - c, e + f)  


    # Computing the values of the 4 quadrants of the final matrix c
    c11 = p5 + p4 - p2 + p6  
    c12 = p1 + p2           
    c21 = p3 + p4            
    c22 = p1 + p5 - p3 - p7  

    #print(np.hstack((c11,c12)))
    #print(c12)
    #print(c21)
    #print(c22)

    


  
    # Combining the 4 quadrants into a single matrix by stacking horizontally and vertically.
    c = np.vstack((np.hstack((c11, c12)), np.hstack((c21, c22)))) 

    #print(c)
    return c

if __name__ =='__main__':


    matrix_a = matrix('1 1 1 1; 2 2 2 2; 3 3 3 3; 2 2 2 2')
    print('Matrix A => \n')

    print(matrix_a)


    matrix_b = matrix('1 1 1 1; 2 2 2 2; 3 3 3 3; 2 2 2 2')

    print('Matrix B => \n')

    print(matrix_b)
  
    # matrix_b = np.array([
    #     [[1, 1, 1, 1 ]],
    #     [[2, 2, 2, 2 ]],
    #     [[3, 3, 3, 3 ]],
    #     [[2, 2, 2, 2 ]]
    # ])

    #print(matrix_b.shape)

    matrix_c = strassen(matrix_a,matrix_b)

    #print(a)
    #print(b)
    print('Matrix C => \n')
    print(matrix_c)
    #print(d)

