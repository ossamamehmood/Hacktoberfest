using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LeetCode.Easy
{
    public class Check
    {
        public bool main(int[] nums)
        {   
            int steps = 0;
            for (int i = 0; i < nums.Length && steps <= 1; i++)
            {
                if (nums[i] > nums[(i + 1) % nums.Length])
                {
                    steps++;
                }
            }
            return steps <=1 ? true: false;
        }
    }
}
