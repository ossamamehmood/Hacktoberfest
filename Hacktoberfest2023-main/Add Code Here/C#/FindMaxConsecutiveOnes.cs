using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LeetCode.Easy
{
    internal class FindMaxConsecutiveOnes
    {
        public int main(int[] nums)
        {
            int absoluteMax = 0;
            int curent = 0;
            int i = 0;
           while (i < nums.Length)
            {
                if ((nums[i] == 1 && curent == 0) || (nums[i] == 1 && curent != 0))
                {
                    curent++;
                    i++;
                }
                else if (nums[i] != 1 && curent != 0)
                {   
                    if(curent > absoluteMax)
                    {
                        absoluteMax = curent;
                    }
                    
                    curent = 0;
                    i++;
                }
                
                
                else if (nums[i] != 1 && curent == 0)
                {
                    i++;
                }

            }
            if (curent > absoluteMax)
            {
                absoluteMax = curent;
            }
            return absoluteMax;

        }
    }
}
