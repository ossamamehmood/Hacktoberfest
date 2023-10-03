using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LeetCode.Easy
{
    internal class SingleNumber
    {
        public int main(int[] nums)
        {
            int numToReturn = 0;
            for (int i = 0; i < nums.Length; i++)
            {
                numToReturn ^= nums[i];
            }
            return numToReturn;
        }
    }
}
