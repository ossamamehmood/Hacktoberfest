using LeetCode.Easy;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LeetCode.Medium
{
    internal class MaxSubArray
    {
        public int main(int[] nums)
        {   
            int max = int.MinValue;
            int sum = 0;
            for (int i = 0; i < nums.Length; i++)
            {
                sum += nums[i];
                max = Math.Max(max, sum);
                if( sum < 0 )
                {
                    sum = 0;
                }
            }
            return max;
        }
    }
}
