using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LeetCode.Medium
{
    internal class PeakIndexInMountainArray
    {
        public int main(int[] arr)
        {
            int i = 1;
            for (; i < arr.Length - 1; i++)
            {
                if (arr[i] > arr[i + 1] && arr[i] > arr[i - 1])
                {
                    return i;
                }
            }
            if (arr[arr.Length - 1] > arr[arr.Length - 2])
            {
                return arr.Length - 1;
            }
            return 0;
        }
    }
}
