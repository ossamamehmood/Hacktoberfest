using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LeetCode.Easy
{
    internal class Reverse
    {

        public int main(int x)
        {
            int sign = 0;
            if (x < 0)
            {
                x = -x;
                sign = 1;
            }
            int k = 0;
            int j = k;
            while (x != 0)
            {

                j = k;
                k = (k * 10) + (x % 10);
                x = x / 10;
                if (j != (k) / 10) { return 0; break; }
            }



            if (sign == 1)
            {
                k = -k;

            }
            return k;
        }
    }
}
