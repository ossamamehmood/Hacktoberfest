using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LeetCode.Easy
{
    internal class TwoSum
    {
        public int[] main(int[] nums, int target)
        {
            Dictionary<int, int> map = new Dictionary<int, int>();
            for (int i = 0; i < nums.Length; i++)
            {
                if (map.ContainsKey(target - nums[i]))
                {
                    return new int[] { i, map[target - nums[i]] };
                }
                // int a = map[nums[i]] + 1;

                map.TryAdd(nums[i], i);
            }
            return null;
        }
    }
}
