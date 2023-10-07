using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LeetCode.Medium
{
    internal class RearrangeArray
    {
        public int[] main(int[] nums)
        {
            int odd = 1;
            int even = 0;
            int[] ints = new int[nums.Length];
            for (int i = 0; i < nums.Length; i++)
            {
                if (nums[i] > 0)
                {
                    ints[even] = nums[i];
                    even = even + 2;
                }
                if (nums[i] < 0)
                {
                    ints[odd] = nums[i];
                    odd = odd + 2;
                }

            }
            return ints;
        }
    }
}
