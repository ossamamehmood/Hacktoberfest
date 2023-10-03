using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LeetCode.Easy
{
    internal class Fibonacci
    {
        public int Main(int n)
        {
            if (n == 0) return 0;
            if (n == 1) return 1;

            return Main(n - 1) + Main(n - 2);

        }
    }
}
