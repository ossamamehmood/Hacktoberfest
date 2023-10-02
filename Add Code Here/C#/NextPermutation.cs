using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;

namespace LeetCode.Medium
{
    internal class NextPermutation
    {
        public void main(int[] nums)
        {
            int swapPosition = 0;
            int index = -1;

            for (int i = nums.Length - 2; i >= 0; i--)
            {
                if (nums[i] < nums[i + 1])
                {
                    index = i;
                    break;
                }
            }
            if (index < 0)
            {
                Array.Reverse(nums);
            }
            else
            {
                for (int j = nums.Length - 1; j > index; j--)
                {
                    if (nums[j] > nums[index])
                    {
                        (nums[j], nums[index]) = (nums[index], nums[j]);
                        break;
                    }
                }

                Array.Sort(nums, index + 1, nums.Length - index - 1);
            }

        }
    }
}
