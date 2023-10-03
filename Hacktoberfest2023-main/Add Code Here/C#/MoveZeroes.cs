using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection.Metadata.Ecma335;
using System.Text;
using System.Threading.Tasks;

namespace LeetCode.Easy
{
    internal class MoveZeroes
    {
        public void main(int[] nums)
        {
            int j = -1;
            
            for (int i = 0; i < nums.Length - 1; i++)
            {
                if (nums[i] == 0)
                {
                    j = i; break;
                }

            }
            if (j > -1)
            {
                int k = j + 1;
                for (; k < nums.Length; k++)
                {
                    if (nums[k] != 0)
                    {
                        nums[j] = nums[k];
                        nums[k] = 0;
                        j++;
                    }
                }
            }

        }
    }
}
