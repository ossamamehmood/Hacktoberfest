using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LeetCode.Medium
{
    public class RotateMatrix
    {
        //transposr => reverse every row
        public void Rotate(int[][] matrix)
        {
            for (int i = 0; i < matrix.Length; i++)
            {
                for(int j = i; j < matrix[0].Length; j++)
                {
                    (matrix[i][j], matrix[j][i]) = (matrix[j][i], matrix[i][j]);
                }
            }
            for(int i = 0;i < matrix.Length; i++)
            {
                Array.Reverse(matrix[i]);
            }
        }
    }
}
