using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LeetCode.Easy
{
    public class MaxProfit
    {
        public int main(int[] prices)
        {
            int minimal = prices[0];
            int maxprofot = int.MinValue;
            for (int i = 0; i < prices.Length; i++)
            {
                minimal = Math.Min(minimal, prices[i]);
                int temp = prices[i] - minimal;
                maxprofot = Math.Max(maxprofot, temp);
            }
            return maxprofot;
        }
    }
}
