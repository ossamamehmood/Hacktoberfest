using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LeetCode.Medium
{
    internal class Rotate
    {
        public void main(int[] nums, int k)
        {
            
            int[] temp = new int[k];
            int l = nums.Length;
            k = k % l;
            for (int i = l - k; i < l; i++)
            {
                temp[i - l + k] = nums[i];
            }
            for (int i = 0; i < l - k; i++)
            {
                nums[l - 1 - i] = nums[l - k - 1 - i];
            }
            for (int i = 0; i < k; i++)
            {
                nums[i] = temp[i];
            }
        }
    }
}
