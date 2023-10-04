using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LeetCode.Medium
{
    public class FindTriangularSumofanArray
    {   
        //better possible
        public int TriangularSum(int[] nums)
        {

            for (int i = nums.Length - 1; i >= 0; i--)
            {
                for (int j = 1; j <= i; j++)
                {
                    nums[j - 1] = (nums[j - 1] + nums[j]) % 10;
                }
            }
            return nums[0];
        }
    }
}
