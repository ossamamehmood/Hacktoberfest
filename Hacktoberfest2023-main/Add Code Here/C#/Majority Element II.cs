using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LeetCode.Medium
{
    internal class Majority_Element_II
    {
        public IList<int> MajorityElement(int[] nums)
        {   //time: o(n) + logn(for map)
            //space: o(n)
            IDictionary<int, int> map = new Dictionary<int, int>();
            IList<int> answer = new List<int>();
            
            int min = (int)Math.Floor((double)nums.Length / 3);

            for (int i = 0; i < nums.Length; i++)
            {
                if (!map.ContainsKey(nums[i]))
                {
                    map[nums[i]] = 0;
                }
                map[nums[i]]++;
                if (map[nums[i]] == min + 1)
                {
                    answer.Add(nums[i]);
                }

            }
            return answer;
        }

        public IList<int> optimal(int[] nums)
        {   //time: o(2n)
            //space: o(1)
            IList<int> answer = new List<int>();
            int count1 = 0;
            int count2 = 0;
            int element1 = int.MinValue;
            int element2 = int.MinValue;
            for (int i = 0; i < nums.Length; i++)
            {
                if(count1 == 0 && nums[i] != element2)
                {
                    count1 = 1;
                    element1 = nums[i];
                }
                else if (count2 == 0 && nums[i] != element1)
                {
                    count2 = 1;
                    element2 = nums[i];
                }
                else if(element1 == nums[i]) count1++;
                else if(element2 == nums[i]) count2++;
                else
                {
                    count1--;
                    count2--;
                }
            }
            count1 = 0;count2 = 0;
            for (int i = 0; i < nums.Length; i++)
            {
                if (element1 == nums[i]) count1++;
                if(element2 == nums[i]) count2++;
            }
            int min = (int)Math.Floor((double)nums.Length / 3);
            if(count1 > min)
            {
                answer.Add(element1);
            }
            if(count2 > min)
            {
                answer.Add(element2);
            }

            return answer;
        }
    }
}
