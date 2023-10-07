using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LeetCode.Easy
{
    public class RemoveDuplicates
    {
        public int main(int[] nums)
        {
            int j = 0;
            for (int i = 0; i < nums.Length; i++)
            {
                if (nums[i] != nums[j])
                {
                    nums[j + 1] = nums[i];
                    j++;
                }
            }
            return j + 1;
        }
    }
    }

