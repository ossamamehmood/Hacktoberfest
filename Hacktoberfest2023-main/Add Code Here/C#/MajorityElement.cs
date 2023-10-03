using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LeetCode.Easy
{
    internal class MajorityElement
    {
        public int Main(int[] nums)
        {
            int current = nums[0];
            int counter = 0;
            int i = 0;
            while (i < nums.Length)
            {
                if(counter == 0)
                {
                    current = nums[i];
                    counter = 1;
                    i++;
                }
                else if(current != nums[i])
                {
                    counter--;
                    i++;
                }
                else if (current == nums[i])
                {
                    counter++;
                    i++;
                }

            }
            return current;
        }
    }
}
