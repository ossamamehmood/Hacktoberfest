using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LeetCode.Medium
{
    internal class SetZeroes
    {   
        //optimizations possible
        //time: o(nxm)
        //space: o(m+n)
        public void main(int[][] matrix)
        {
            int[] row = new int[matrix.Length];
            int[] col = new int[matrix[0].Length];
            for (int i = 0; i < matrix.Length; i++)
            {
                for (int j = 0; j < matrix[i].Length; j++)
                {
                    if (matrix[i][j] == 0)
                    {
                        row[i] = 1;
                        col[j] = 1;
                    }
                }

            }
            for (int i = 0; i < matrix.Length; i++)
            {
                for (int j = 0; j < matrix[i].Length; j++)
                {
                    if (row[i] == 1 || col[j] == 1)
                    {
                        matrix[i][j] = 0;
                    }
                }

            }

        }

        

        }
    }

