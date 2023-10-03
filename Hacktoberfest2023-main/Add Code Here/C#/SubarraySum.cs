using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LeetCode.Medium
{
    internal class SubarraySum
    {
        public int main(int[] nums, int k)
        {   //time: o(N) + time for map
            //sapce: o(n)
            IDictionary<int, int> ht = new Dictionary<int, int>();
            int prefixSum = 0;
            int count = 0;
            ht.Add(0, 1);
            for (int i = 0; i < nums.Length; i++)
            {
                prefixSum += nums[i];
                int remove = prefixSum - k;
                if (ht.ContainsKey(remove))
                {
                    count += ht[remove];
                }

                if (!ht.ContainsKey(prefixSum))
                {
                    ht.Add(prefixSum, 0);
                }

                ht[prefixSum] += 1;
            }
            return count;
        }
    }
}
