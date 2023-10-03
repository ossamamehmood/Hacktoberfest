using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LeetCode.Medium
{
    public class SortColors
    {
        public void main(int[] nums)
        {
            int zero = 0;
            int two = nums.Length - 1;
            for (int i = 0; i <= two;)
            {
                if (nums[i] == 0)
                {
                    nums[i] = nums[zero];
                    nums[zero] = 0;
                    zero++;
                    i = i + 1;
                }
                else if (nums[i] == 2)
                {
                    nums[i] = nums[two];
                    nums[two] = 2;
                    two--;


                }
                else
                {
                    i++;
                }


            }

        }
    }
}
