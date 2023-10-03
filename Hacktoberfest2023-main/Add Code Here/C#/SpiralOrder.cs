using System;
using System.Collections.Generic;
using System.Linq;
using System.Security.AccessControl;
using System.Text;
using System.Threading.Tasks;

namespace LeetCode.Medium
{
    internal class SpiralOrder
    {
        public IList<int> main(int[][] matrix)
        {   //time: 0(mxn)
            int left = 0;
            int top = 0;
            int right = matrix[0].Length -1;
            int bottom = matrix.Length -1;
            IList<int> result = new List<int>();

            while(top <= bottom && left <= right)
            {
                for (int i = left; i <= right; i++)
                {
                    result.Add(matrix[top][i]);
                }
                top++;
                for (int i = top; i <= bottom; i++)
                {

                    result.Add(matrix[i][right]);
                }
                right--;
                if(top <= bottom)
                {
                    for (int i = right; i >= left; i--)
                    {
                        result.Add(matrix[bottom][i]);
                    }
                    bottom--;
                }
                if(left <= right)
                {
                    for (int i = bottom; i >= top; i--)
                    {
                        result.Add(matrix[i][left]);
                    }
                    left++;
                }
                
            }

            

            return result;
        }
    }
}
