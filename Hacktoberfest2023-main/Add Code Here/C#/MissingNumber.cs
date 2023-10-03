using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LeetCode.Easy
{
    internal class MissingNumber
    {
        public int Main(int[] nums)
        {
            int sum = (nums.Length * (nums.Length + 1))/2;
            for (int i = 0; i < nums.Length; i++)
            {
                sum -= nums[i];
            }
            return sum;
        }
    }
}
