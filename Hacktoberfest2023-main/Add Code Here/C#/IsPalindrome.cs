using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LeetCode.Easy
{
    internal class IsPalindrome
    {
        public int aa(int n)
        {
            int a = 0;
            while (n > 0)
            {
                a = a * 10 + n % 10;
                n = n / 10;
            }
            return a;
        }
        public bool main(int x)
        {
            if (x < 0)
            {
                return false;
            }
            int a = aa(x);
            if (a == x)
            {
                return true;
            }
            return false;

        }

    }
}
